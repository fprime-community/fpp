package fpp.compiler.codegen

import fpp.compiler.analysis._
import fpp.compiler.ast._
import fpp.compiler.codegen._

/** Writes out C++ for component data products */
case class ComponentDataProducts (
  s: CppWriterState,
  aNode: Ast.Annotated[AstNode[Ast.DefComponent]]
) extends ComponentCppWriterUtils(s, aNode) {

  def getTypeMembers: List[CppDoc.Class.Member] =
    addAccessTagAndComment(
      "PROTECTED",
      "Types for data products",
      List.concat(
        getContainerIds,
        getContainerPriorities,
        getRecordIds,
        Container.getContainer
      )
    )

  def getVirtualFunctionMembers: List[CppDoc.Class.Member] =
    addAccessTagAndComment(
      "PROTECTED",
      "Handlers to implement for data products",
      containersByName.map((id, container) => getDpRecvHandler(container.getName)),
      CppDoc.Lines.Hpp
    )

  def getProtectedDpFunctionMembers: List[CppDoc.Class.Member] = {
    lazy val dpGetByName = containersByName.map((_, c) => {
      val name = c.getName
      linesClassMember(
        lines(
          s"""|
              |//! Get a buffer and use it to initialize container $name
              |//! \\return The status of the buffer request
              |Fw::Success::T dpGet_$name(
              |    FwSizeType dataSize, //!< The data size (input)
              |    DpContainer& container //!< The container (output)
              |) {
              |  return this->dpGet(
              |    ContainerId::$name,
              |    dataSize,
              |    ContainerPriority::$name,
              |    container
              |  );
              |}"""
        )
      )
    })
    lazy val dpRequestByName = containersByName.map((_, c) => {
      val name = c.getName
      linesClassMember(
        lines(
          s"""|
              |//! Request a $name container
              |void dpRequest_$name(
              |    FwSizeType size //!< The buffer size (input)
              |) {
              |  return this->dpRequest(ContainerId::$name, size);
              |}"""
        )
      )
    })
    lazy val dpSendFunction = functionClassMember(
      Some("Send a data product"),
      "dpSend",
      List(
        CppDoc.Function.Param(
          CppDoc.Type("DpContainer&"),
          "container",
          Some("The data product container")
        ),
        CppDoc.Function.Param(
          CppDoc.Type("Fw::Time"),
          "timeTag",
          Some("The time tag"),
          Some("Fw::ZERO_TIME")
        )
      ),
      CppDoc.Type("void"),
      {
        val invokeProductSend = outputPortInvokerName(productSendPort.get)
        lines(
          s"""|// Update the time tag
              |if (timeTag == Fw::ZERO_TIME) {
              |  // Get the time from the time port
              |  timeTag = this->getTime();
              |}
              |container.setTimeTag(timeTag);
              |// Serialize the header into the packet
              |container.serializeHeader();
              |// Update the data hash
              |container.updateDataHash();
              |// Update the size of the buffer according to the data size
              |const FwSizeType packetSize = container.getPacketSize();
              |Fw::Buffer buffer = container.getBuffer();
              |FW_ASSERT(packetSize <= buffer.getSize(), static_cast<FwAssertArgType>(packetSize),
              |    static_cast<FwAssertArgType>(buffer.getSize()));
              |buffer.setSize(static_cast<U32>(packetSize));
              |// Send the buffer
              |this->$invokeProductSend(0, container.getId(), buffer);"""
        )
      }
    )
    addAccessTagAndComment(
      "PROTECTED",
      "Functions for managing data products",
      guardedList (hasDataProducts) (
        List.concat(
          guardedList (hasProductGetPort) (dpGetByName),
          guardedList (hasProductRequestPort) (dpRequestByName),
          List(dpSendFunction)
        )
      )
    )
  }

  def getPrivateDpFunctionMembers: List[CppDoc.Class.Member] = {
    lazy val dpGet = functionClassMember(
      Some(raw"""|Get a buffer and use it to initialize a data product container
                 |\return The status of the buffer request"""),
      "dpGet",
      List(
        CppDoc.Function.Param(
          CppDoc.Type("ContainerId::T"),
          "containerId",
          Some("The component-local container id (input)")
        ),
        CppDoc.Function.Param(
          CppDoc.Type("FwSizeType"),
          "dataSize",
          Some("The data size (input)")
        ),
        CppDoc.Function.Param(
          CppDoc.Type("FwDpPriorityType"),
          "priority",
          Some("The priority (input)")
        ),
        CppDoc.Function.Param(
          CppDoc.Type("DpContainer&"),
          "container",
          Some("The container (output)")
        )
      ),
      CppDoc.Type("Fw::Success::T"),
      {
        val invokeProductGet = outputPortInvokerName(productGetPort.get)
        lines(s"""|const FwDpIdType baseId = this->getIdBase();
                  |const FwDpIdType globalId = baseId + containerId;
                  |const FwSizeType size = DpContainer::getPacketSizeForDataSize(dataSize);
                  |Fw::Buffer buffer;
                  |const Fw::Success::T status = this->$invokeProductGet(0, globalId, size, buffer);
                  |if (status == Fw::Success::SUCCESS) {
                  |  container.setId(globalId);
                  |  container.setBuffer(buffer);
                  |  container.setBaseId(baseId);
                  |  container.setPriority(priority);
                  |}
                  |return status;""")
      }
    )
    lazy val dpRequest = functionClassMember(
      Some("Request a data product container"),
      "dpRequest",
      List(
        CppDoc.Function.Param(
          CppDoc.Type("ContainerId::T"),
          "containerId",
          Some("The component-local container id")
        ),
        CppDoc.Function.Param(
          CppDoc.Type("FwSizeType"),
          "dataSize",
          Some("The data size")
        )
      ),
      CppDoc.Type("void"),
      {
        val invokeProductRequest = outputPortInvokerName(productRequestPort.get)
        lines(
          s"""|const FwDpIdType globalId = this->getIdBase() + containerId;
              |const FwSizeType size = DpContainer::getPacketSizeForDataSize(dataSize);
              |this->$invokeProductRequest(0, globalId, size);"""
        )
      }
    )
    def getDpRecvHandler(portInstance: PortInstance) = {
      val portName = portInstance.getUnqualifiedName
      functionClassMember(
        Some(s"Handler implementation for ${portName}"),
        s"${portName}_handler",
        List(
          CppDoc.Function.Param(
            CppDoc.Type("const FwIndexType"),
            "portNum",
            Some("The port number")
          ),
          CppDoc.Function.Param(
            CppDoc.Type("FwDpIdType"),
            "id",
            Some("The container id")
          ),
          CppDoc.Function.Param(
            CppDoc.Type("const Fw::Buffer&"),
            "buffer",
            Some("The buffer")
          ),
          CppDoc.Function.Param(
            CppDoc.Type("const Fw::Success&"),
            "status",
            Some("The buffer status")
          )
        ),
        CppDoc.Type("void"),
        if hasDataProducts then
          List.concat(
            lines(
              """|DpContainer container(id, buffer, this->getIdBase());
                 |// Convert global id to local id
                 |const FwDpIdType idBase = this->getIdBase();
                 |FW_ASSERT(id >= idBase, id, idBase);
                 |const FwDpIdType localId = id - idBase;
                 |// Switch on the local id"""
            ),
            wrapInSwitch(
              "localId",
              List.concat(
                containersById.flatMap((id, container) => {
                  val name = container.getName
                  lines(
                    s"""|case ContainerId::$name:
                        |  // Set the priority
                        |  container.setPriority(ContainerPriority::$name);
                        |  // Call the handler
                        |  this->dpRecv_${name}_handler(container, status.e);
                        |  break;"""
                  )
                }),
                lines (
                  """|default:
                     |  FW_ASSERT(0);
                     |  break;"""
                )
              )
            )
          )
        else lines("""|(void) portNum;
                      |(void) id;
                      |(void) buffer;
                      |(void) status;
                      |// No data products defined""")
      )
    }
    addAccessTagAndComment(
      "PRIVATE",
      "Private data product handling functions",
      List.concat(
        guardedList (hasContainers && hasProductGetPort) (List(dpGet)),
        guardedList (hasContainers && hasProductRequestPort) (List(dpRequest)),
        productRecvPort.map(getDpRecvHandler).map(List(_)).getOrElse(Nil)
      )
    )
  }

  private def getContainerIds = containersById match {
    case Nil => Nil
    case _ => List(
      linesClassMember(
        CppDocWriter.writeDoxygenComment("The container ids") ++
        wrapInNamedStruct(
          "ContainerId",
          wrapInNamedEnum(
            "T : FwDpIdType",
            containersById.flatMap((id, container) =>
              writeEnumConstant(container.getName, id)
            )
          )
        )
      )
    )
  }

  private def getContainerPriorities = containersById match {
    case Nil => Nil
    case _ => List(
      linesClassMember(
        CppDocWriter.writeDoxygenComment("The container default priorities") ++
        wrapInNamedStruct(
          "ContainerPriority",
          wrapInNamedEnum(
            "T : FwDpPriorityType",
            containersById.flatMap((id, container) => {
              val priority = container.defaultPriority.getOrElse(BigInt(0))
              writeEnumConstant(container.getName, priority)
            })
          )
        )
      )
    )
  }

  private def getRecordIds = recordsById match {
    case Nil => Nil
    case _ => List(
      linesClassMember(
        CppDocWriter.writeDoxygenComment("The record ids") ++
        wrapInNamedStruct(
          "RecordId",
          wrapInNamedEnum(
            "T : FwDpIdType",
            recordsById.flatMap((id, container) =>
              writeEnumConstant(container.getName, id)
            )
          )
        )
      )
    )
  }

  /** Generates the Container inner class */
  private object Container extends ComponentCppWriterUtils(s, aNode) {

    def getContainer = guardedList (hasDataProducts) (
      List(
        classClassMember(
          Some("A data product container"),
          "DpContainer",
          Some("public Fw::DpContainer"),
          List.concat(
            getConstructionMembers,
            getFunctionMembers,
            getVariableMembers
          )
        )
      )
    )

    private def getConstructionMembers = List(
      linesClassMember(CppDocHppWriter.writeAccessTag("public")),
      constructorClassMember(
        Some("Constructor with custom initialization"),
        List(
          CppDoc.Function.Param(
            CppDoc.Type("FwDpIdType"),
            "id",
            Some("The container id")
          ),
          CppDoc.Function.Param(
            CppDoc.Type("const Fw::Buffer&"),
            "buffer",
            Some("The packet buffer")
          ),
          CppDoc.Function.Param(
            CppDoc.Type("FwDpIdType"),
            "baseId",
            Some("The component base id")
          )
        ),
        List("Fw::DpContainer(id, buffer)", "baseId(baseId)"),
        Nil
      ),
      constructorClassMember(
        Some("Constructor with default initialization"),
        Nil,
        List("Fw::DpContainer()", "baseId(0)"),
        Nil
      ),
    )

    private def singleRecordSerializeFn(name: String, t: Type) = {
      // Get the type name
      val typeName = TypeCppWriter.getName(s, t)
      // Get the parameter type
      // For strings this is a const reference to Fw::StringBase
      // For primitive types it is the type name
      // For othe types it is a const reference to the type name
      val paramType = t match {
        case Type.String(_) => "const Fw::StringBase&"
        case _ =>
          if s.isPrimitive(t, typeName)
          then typeName
          else s"const $typeName&"
      }
      // Construct part 1 of the function body
      // For strings this declares a string of the specified size
      // For other types it is empty
      val body1 = t match {
        case ts: Type.String =>
          val stringSize = StringCppWriter(s).getSize(ts).toString
          lines(
            s"""|char esData[$stringSize];
                |Fw::ExternalString es(esData, sizeof esData, elt);"""
          )
        case _ => Nil
      }
      // Get the serialized size
      // For strings this is the serialized size of the data
      // For other types it is the serialized size of the type
      val serialSize = t match {
        case Type.String(_) => "es.serializedSize()"
        case _ => s.getSerializedSizeExpr(t, typeName)
      }
      // Get the variable holding the element to serialize
      // For strings this is the variable we declared above
      // For other types it is the elt parameter to the function
      val serialElt = t match {
        case Type.String(_) => "es"
        case _ => "elt"
      }
      // Construct part 2 of the function body
      val body2 = lines(
        s"""|const FwSizeType sizeDelta =
            |  sizeof(FwDpIdType) +
            |  $serialSize;
            |Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
            |if (this->m_dataBuffer.getBuffLength() + sizeDelta <= this->m_dataBuffer.getBuffCapacity()) {
            |  const FwDpIdType id = this->baseId + RecordId::$name;
            |  status = this->m_dataBuffer.serialize(id);
            |  FW_ASSERT(status == Fw::FW_SERIALIZE_OK, status);
            |  status = this->m_dataBuffer.serialize($serialElt);
            |  FW_ASSERT(status == Fw::FW_SERIALIZE_OK, status);
            |  this->m_dataSize += sizeDelta;
            |}
            |else {
            |  status = Fw::FW_SERIALIZE_NO_ROOM_LEFT;
            |}
            |return status;"""
      )
      // Construct the function class member
      functionClassMember(
        Some(s"""|Serialize a $name record into the packet buffer
                 |\\return The serialize status"""),
        s"serializeRecord_${name}",
        List(
          CppDoc.Function.Param(
            CppDoc.Type(paramType),
            "elt",
            Some("The element")
          )
        ),
        CppDoc.Type("Fw::SerializeStatus"),
        List.concat(body1, body2)
      )
    }

    private def arrayRecordSerializeFn(name: String, t: Type) = {
      // Get the type name and parameter type
      val typeName = TypeCppWriter.getName(s, t)
      val paramType = t match {
        case Type.String(_) => "const Fw::StringBase**"
        case _ => s"const ${typeName}*"
      }
      // Generate the code for computing the size delta
      val computeSizeDelta = (t match {
        case Type.String(_) =>
          """|FwSizeType sizeDelta = 0;
             |for (FwSizeType i = 0; i < size; i++) {
             |  const Fw::StringBase *const sbPtr = array[i];
             |  FW_ASSERT(sbPtr != nullptr);
             |  sizeDelta += sbPtr->serializedSize();
             |}"""
        case _ =>
          val eltSize = if s.isPrimitive(t, typeName)
                        then s"sizeof($typeName)"
                        else s"${typeName}::SERIALIZED_SIZE"
          s"""|const FwSizeType sizeDelta =
              |  sizeof(FwDpIdType) +
              |  sizeof(FwSizeStoreType) +
              |  size * $eltSize;"""
      }).stripMargin
      // Generate the code for serializing the elements
      val serializeElts = (t match {
        // Optimize the U8 case
        case Type.U8 =>
          """|  status = this->m_dataBuffer.serialize(array, size, Fw::Serialization::OMIT_LENGTH);
             |  FW_ASSERT(status == Fw::FW_SERIALIZE_OK, status);"""
        // Handle the string case
        case Type.String(_) =>
          """|  for (FwSizeType i = 0; i < size; i++) {
             |    const Fw::StringBase *const sbPtr = array[i];
             |    FW_ASSERT(sbPtr != nullptr);
             |    status = this->m_dataBuffer.serialize(*sbPtr);
             |    FW_ASSERT(status == Fw::FW_SERIALIZE_OK, status);
             |  }"""
        // Handle the general case
        case _ =>
          """|  for (FwSizeType i = 0; i < size; i++) {
             |    status = this->m_dataBuffer.serialize(array[i]);
             |    FW_ASSERT(status == Fw::FW_SERIALIZE_OK, status);
             |  }"""
      }).stripMargin
      // Construct the function body
      val body = lines(
        s"""|FW_ASSERT(array != nullptr);
            |$computeSizeDelta
            |Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
            |if (this->m_dataBuffer.getBuffLength() + sizeDelta <= this->m_dataBuffer.getBuffCapacity()) {
            |  const FwDpIdType id = this->baseId + RecordId::$name;
            |  status = this->m_dataBuffer.serialize(id);
            |  FW_ASSERT(status == Fw::FW_SERIALIZE_OK, status);
            |  status = this->m_dataBuffer.serializeSize(size);
            |  FW_ASSERT(status == Fw::FW_SERIALIZE_OK, status);
            |$serializeElts
            |  this->m_dataSize += sizeDelta;
            |}
            |else {
            |  status = Fw::FW_SERIALIZE_NO_ROOM_LEFT;
            |}
            |return status;"""
      )
      // Construct the function class member
      functionClassMember(
        Some(s"""|Serialize a $name record into the packet buffer
                 |\\return The serialize status"""),
        s"serializeRecord_${name}",
        List(
          CppDoc.Function.Param(
            CppDoc.Type(paramType),
            "array",
            Some(
              t match {
                case Type.String(_) => "An array of pointers to StringBase objects"
                case _ => s"An array of $typeName elements"
              }
            )
          ),
          CppDoc.Function.Param(
            CppDoc.Type("FwSizeType"),
            "size",
            Some("The array size")
          )
        ),
        CppDoc.Type("Fw::SerializeStatus"),
        body
      )
    }

    private def getSerializeFunctionMembers =
      recordsByName.map((id, record) => {
        val name = record.getName
        val t = record.recordType
        if record.isArray then arrayRecordSerializeFn(name, t)
        else singleRecordSerializeFn(name, t)
      })

    private val getAccessFunctionsMember = linesClassMember(
      lines(
        raw"""|
              |FwDpIdType getBaseId() const { return this->baseId; }
              |
              |void setBaseId(FwDpIdType baseId) { this->baseId = baseId; }"""
      )
    )

    private def getFunctionMembers =
      linesClassMember(CppDocHppWriter.writeAccessTag("public")) ::
      (getSerializeFunctionMembers :+ getAccessFunctionsMember)

    private def getVariableMembers = List(
      linesClassMember(
        CppDocHppWriter.writeAccessTag("PRIVATE") ++
        CppDocWriter.writeDoxygenComment("The component base id") ++
        lines("FwDpIdType baseId;")
      )
    )

  }

}

