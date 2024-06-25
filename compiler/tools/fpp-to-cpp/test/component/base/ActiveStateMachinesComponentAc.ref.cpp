// ======================================================================
// \title  ActiveStateMachinesComponentAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ActiveStateMachines component base class
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/ExternalString.hpp"
#if FW_ENABLE_TEXT_LOGGING
#include "Fw/Types/String.hpp"
#endif
#include "base/ActiveStateMachinesComponentAc.hpp"

namespace {
  enum MsgTypeEnum {
    ACTIVESTATEMACHINES_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
    STATEMACHINE_SENDEVENTS,
  };

  // Get the max size by constructing a union of the async input, command, and
  // internal port serialization sizes
  union BuffUnion {
    // Size of statemachine sendEvents
    BYTE sendEventsStatemachineSize[
      Fw::SMEvents::SERIALIZED_SIZE
    ];
  };

  // Define a message buffer class large enough to handle all the
  // asynchronous inputs to the component
  class ComponentIpcSerializableBuffer :
    public Fw::SerializeBufferBase
  {

    public:

      enum {
        // Max. message size = size of data + message id + port
        SERIALIZATION_SIZE =
          sizeof(BuffUnion) +
          sizeof(FwEnumStoreType) +
          sizeof(FwIndexType)
      };

      Fw::Serializable::SizeType getBuffCapacity() const {
        return sizeof(m_buff);
      }

      U8* getBuffAddr() {
        return m_buff;
      }

      const U8* getBuffAddr() const {
        return m_buff;
      }

    private:
      // Should be the max of all the input ports serialized sizes...
      U8 m_buff[SERIALIZATION_SIZE];

  };
}

// ----------------------------------------------------------------------
// Component initialization
// ----------------------------------------------------------------------

void ActiveStateMachinesComponentBase ::
  init(
      FwQueueSizeType queueDepth,
      FwEnumStoreType instance
  )
{
  // Initialize base class
  Fw::ActiveComponentBase::init(instance);

  sm1.init();
  sm2.init();
  sm3.init();
  sm4.init();

  Os::Queue::QueueStatus qStat = this->createQueue(
    queueDepth,
    ComponentIpcSerializableBuffer::SERIALIZATION_SIZE
  );
  FW_ASSERT(
    Os::Queue::QUEUE_OK == qStat,
    static_cast<FwAssertArgType>(qStat)
  );
}

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

ActiveStateMachinesComponentBase ::
  ActiveStateMachinesComponentBase(const char* compName) :
    Fw::ActiveComponentBase(compName),
    sm1(this),
    sm2(this),
    sm3(this),
    sm4(this)
{

}

ActiveStateMachinesComponentBase ::
  ~ActiveStateMachinesComponentBase()
{

}

// ----------------------------------------------------------------------
// State machine function to push events to the input queue
// ----------------------------------------------------------------------

void ActiveStateMachinesComponentBase ::
  stateMachineInvoke(const Fw::SMEvents& ev)
{
  ComponentIpcSerializableBuffer msg;
  Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

  // Serialize the message ID
  _status = msg.serialize(static_cast<FwEnumStoreType>(STATEMACHINE_SENDEVENTS));
  FW_ASSERT (
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  // Fake port number to make message dequeue work
  _status = msg.serialize(static_cast<FwIndexType>(0));
  FW_ASSERT (
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  _status = msg.serialize(ev);
  FW_ASSERT(
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  // Send message
  Os::Queue::QueueBlocking _block = Os::Queue::QUEUE_NONBLOCKING;
  Os::Queue::QueueStatus qStatus = this->m_queue.send(msg, 1, _block);

  FW_ASSERT(
    qStatus == Os::Queue::QUEUE_OK,
    static_cast<FwAssertArgType>(qStatus)
  );
}

// ----------------------------------------------------------------------
// Message dispatch functions
// ----------------------------------------------------------------------

Fw::QueuedComponentBase::MsgDispatchStatus ActiveStateMachinesComponentBase ::
  doDispatch()
{
  ComponentIpcSerializableBuffer msg;
  FwQueuePriorityType priority = 0;

  Os::Queue::QueueStatus msgStatus = this->m_queue.receive(
    msg,
    priority,
    Os::Queue::QUEUE_BLOCKING
  );
  FW_ASSERT(
    msgStatus == Os::Queue::QUEUE_OK,
    static_cast<FwAssertArgType>(msgStatus)
  );

  // Reset to beginning of buffer
  msg.resetDeser();

  FwEnumStoreType desMsg = 0;
  Fw::SerializeStatus deserStatus = msg.deserialize(desMsg);
  FW_ASSERT(
    deserStatus == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(deserStatus)
  );

  MsgTypeEnum msgType = static_cast<MsgTypeEnum>(desMsg);

  if (msgType == ACTIVESTATEMACHINES_COMPONENT_EXIT) {
    return MSG_DISPATCH_EXIT;
  }

  FwIndexType portNum = 0;
  deserStatus = msg.deserialize(portNum);
  FW_ASSERT(
    deserStatus == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(deserStatus)
  );

  switch (msgType) {
    // Handle state machine events 
    case STATEMACHINE_SENDEVENTS: {
      Fw::SMEvents ev;
      deserStatus = msg.deserialize(ev);

      FW_ASSERT(
        Fw::FW_SERIALIZE_OK == deserStatus,
        static_cast<FwAssertArgType>(deserStatus)
      );

      // Make sure there was no data left over.
      // That means the buffer size was incorrect.
      FW_ASSERT(
        msg.getBuffLeft() == 0,
        static_cast<FwAssertArgType>(msg.getBuffLeft())
      );

      // Update the state machine with the event
      switch (ev.getsmId()) {
        case SM1:
          this->sm1.update(&ev);
          break;
                  
        case SM2:
          this->sm2.update(&ev);
          break;
                  
        case SM3:
          this->sm3.update(&ev);
          break;
                  
        case SM4:
          this->sm4.update(&ev);
          break;
                  
      }
      break;
    }

    default:
      return MSG_DISPATCH_ERROR;
  }

  return MSG_DISPATCH_OK;
}
