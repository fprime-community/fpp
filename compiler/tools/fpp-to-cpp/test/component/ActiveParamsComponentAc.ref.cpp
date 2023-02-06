// ======================================================================
// \title  ActiveParamsComponentAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ActiveParams component base class
// ======================================================================

#include <cstdio>

#include "ActiveParamsComponentAc.hpp"
#include "Fw/Types/Assert.hpp"
#include "Fw/Types/String.hpp"

// ----------------------------------------------------------------------
// Getters for special input ports
// ----------------------------------------------------------------------

Fw::InputCmdPort* ActiveParamsComponentBase ::
  get_cmdIn_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_cmdIn_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_cmdIn_InputPort[portNum];
}

// ----------------------------------------------------------------------
// Getters for typed input ports
// ----------------------------------------------------------------------

InputTypedPort* ActiveParamsComponentBase ::
  get_typedSync_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_typedSync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_typedSync_InputPort[portNum];
}

InputTypedPort* ActiveParamsComponentBase ::
  get_typedGuarded_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_typedGuarded_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_typedGuarded_InputPort[portNum];
}

InputTypedPort* ActiveParamsComponentBase ::
  get_typedAsync_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_typedAsync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_typedAsync_InputPort[portNum];
}

// ----------------------------------------------------------------------
// Getters for serial input ports
// ----------------------------------------------------------------------

Fw::InputSerializePort* ActiveParamsComponentBase ::
  get_serialSync_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_serialSync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_serialSync_InputPort[portNum];
}

Fw::InputSerializePort* ActiveParamsComponentBase ::
  get_serialGuarded_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_serialGuarded_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_serialGuarded_InputPort[portNum];
}

Fw::InputSerializePort* ActiveParamsComponentBase ::
  get_serialAsync_InputPort(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_serialAsync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
   );

  return &this->m_serialAsync_InputPort[portNum];
}

// ----------------------------------------------------------------------
// Connect special input ports to special output ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  set_cmdRegOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputCmdRegPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_cmdRegOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_cmdRegOut_OutputPort[portNum].addCallPort(port);
}

void ActiveParamsComponentBase ::
  set_cmdResponseOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputCmdResponsePort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_cmdResponseOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_cmdResponseOut_OutputPort[portNum].addCallPort(port);
}

void ActiveParamsComponentBase ::
  set_eventOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputLogPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_eventOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_eventOut_OutputPort[portNum].addCallPort(port);
}

#if FW_ENABLE_TEXT_LOGGING == 1

void ActiveParamsComponentBase ::
  set_textEventOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputLogTextPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_textEventOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_textEventOut_OutputPort[portNum].addCallPort(port);
}

#endif

void ActiveParamsComponentBase ::
  set_tlmOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputTlmPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_tlmOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_tlmOut_OutputPort[portNum].addCallPort(port);
}

void ActiveParamsComponentBase ::
  set_prmGetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputPrmGetPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_prmGetOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_prmGetOut_OutputPort[portNum].addCallPort(port);
}

void ActiveParamsComponentBase ::
  set_prmSetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputPrmSetPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_prmSetOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_prmSetOut_OutputPort[portNum].addCallPort(port);
}

void ActiveParamsComponentBase ::
  set_timeGetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputTimePort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_timeGetOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_timeGetOut_OutputPort[portNum].addCallPort(port);
}

#if FW_PORT_SERIALIZATION

// ----------------------------------------------------------------------
// Connect serial input ports to special output ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  set_cmdRegOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveParamsComponentBase ::
  set_cmdResponseOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveParamsComponentBase ::
  set_eventOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

#if FW_ENABLE_TEXT_LOGGING == 1

void ActiveParamsComponentBase ::
  set_textEventOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

#endif

void ActiveParamsComponentBase ::
  set_tlmOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveParamsComponentBase ::
  set_prmGetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveParamsComponentBase ::
  set_prmSetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveParamsComponentBase ::
  set_timeGetOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

#endif

// ----------------------------------------------------------------------
// Connect typed input ports to typed output ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  set_typedOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      InputTypedPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_typedOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_typedOut_OutputPort[portNum].addCallPort(port);
}

#if FW_PORT_SERIALIZATION

// ----------------------------------------------------------------------
// Connect serial input ports to typed output ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  set_typedOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

#endif

#if FW_PORT_SERIALIZATION

// ----------------------------------------------------------------------
// Connect serial input ports to serial output ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  set_serialOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputSerializePort* port
  )
{

}

void ActiveParamsComponentBase ::
  set_serialOut_OutputPort(
      NATIVE_INT_TYPE portNum,
      Fw::InputPortBase* port
  )
{

}

#endif

// ----------------------------------------------------------------------
// Command registration
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  regCommands()
{

}

// ----------------------------------------------------------------------
// Parameter loading
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  loadParameters()
{

}

// ----------------------------------------------------------------------
// Component construction, initialization, and destruction
// ----------------------------------------------------------------------

ActiveParamsComponentBase ::
  ActiveParamsComponentBase(const char* compName) :
    Fw::ActiveComponentBase(compName)
{
  this->m_param_ParamU32_valid = Fw::ParamValid::UNINIT;
  this->m_param_ParamF64_valid = Fw::ParamValid::UNINIT;
  this->m_param_ParamString_valid = Fw::ParamValid::UNINIT;
  this->m_param_ParamEnum_valid = Fw::ParamValid::UNINIT;
  this->m_param_ParamArray_valid = Fw::ParamValid::UNINIT;
  this->m_param_ParamStruct_valid = Fw::ParamValid::UNINIT;
}

void ActiveParamsComponentBase ::
  init(
      NATIVE_INT_TYPE queueDepth,
      NATIVE_INT_TYPE msgSize,
      NATIVE_INT_TYPE instance
  )
{
  // Initialize base class
  Fw::ActiveComponentBase::init(instance);

  // Connect input port cmdIn
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_cmdIn_InputPorts());
    port++
  ) {
    this->m_cmdIn_InputPort[port].init();
    this->m_cmdIn_InputPort[port].addCallComp(
      this,
      m_p_cmdIn_in
    );
    this->m_cmdIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_cmdIn_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_cmdIn_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port typedSync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_typedSync_InputPorts());
    port++
  ) {
    this->m_typedSync_InputPort[port].init();
    this->m_typedSync_InputPort[port].addCallComp(
      this,
      m_p_typedSync_in
    );
    this->m_typedSync_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_typedSync_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_typedSync_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port typedGuarded
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_typedGuarded_InputPorts());
    port++
  ) {
    this->m_typedGuarded_InputPort[port].init();
    this->m_typedGuarded_InputPort[port].addCallComp(
      this,
      m_p_typedGuarded_in
    );
    this->m_typedGuarded_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_typedGuarded_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_typedGuarded_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port typedAsync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_typedAsync_InputPorts());
    port++
  ) {
    this->m_typedAsync_InputPort[port].init();
    this->m_typedAsync_InputPort[port].addCallComp(
      this,
      m_p_typedAsync_in
    );
    this->m_typedAsync_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_typedAsync_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_typedAsync_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port serialSync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_serialSync_InputPorts());
    port++
  ) {
    this->m_serialSync_InputPort[port].init();
    this->m_serialSync_InputPort[port].addCallComp(
      this,
      m_p_serialSync_in
    );
    this->m_serialSync_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_serialSync_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_serialSync_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port serialGuarded
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_serialGuarded_InputPorts());
    port++
  ) {
    this->m_serialGuarded_InputPort[port].init();
    this->m_serialGuarded_InputPort[port].addCallComp(
      this,
      m_p_serialGuarded_in
    );
    this->m_serialGuarded_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_serialGuarded_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_serialGuarded_InputPort[port].setObjName(portName);
#endif
  }

  // Connect input port serialAsync
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_serialAsync_InputPorts());
    port++
  ) {
    this->m_serialAsync_InputPort[port].init();
    this->m_serialAsync_InputPort[port].addCallComp(
      this,
      m_p_serialAsync_in
    );
    this->m_serialAsync_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_serialAsync_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_serialAsync_InputPort[port].setObjName(portName);
#endif
  }

  // Connect output port cmdRegOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_cmdRegOut_OutputPorts());
    port++
  ) {
    this->m_cmdRegOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_cmdRegOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_cmdRegOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port cmdResponseOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_cmdResponseOut_OutputPorts());
    port++
  ) {
    this->m_cmdResponseOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_cmdResponseOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_cmdResponseOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port eventOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_eventOut_OutputPorts());
    port++
  ) {
    this->m_eventOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_eventOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_eventOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port textEventOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_textEventOut_OutputPorts());
    port++
  ) {
    this->m_textEventOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_textEventOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_textEventOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port tlmOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_tlmOut_OutputPorts());
    port++
  ) {
    this->m_tlmOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_tlmOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_tlmOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port prmGetOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_prmGetOut_OutputPorts());
    port++
  ) {
    this->m_prmGetOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_prmGetOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_prmGetOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port prmSetOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_prmSetOut_OutputPorts());
    port++
  ) {
    this->m_prmSetOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_prmSetOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_prmSetOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port timeGetOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_timeGetOut_OutputPorts());
    port++
  ) {
    this->m_timeGetOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_timeGetOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_timeGetOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port typedOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_typedOut_OutputPorts());
    port++
  ) {
    this->m_typedOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_typedOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_typedOut_OutputPort[port].setObjName(portName);
#endif
  }

  // Connect output port serialOut
  for (
    PlatformIntType port = 0;
    port < static_cast<PlatformIntType>(this->getNum_serialOut_OutputPorts());
    port++
  ) {
    this->m_serialOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    char portName[120];
    (void) snprintf(
      portName,
      sizeof(portName),
      "%s_serialOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName,
      port
    );
    this->m_serialOut_OutputPort[port].setObjName(portName);
#endif
  }
}

ActiveParamsComponentBase ::
  ~ActiveParamsComponentBase()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of special input ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_cmdIn_InputPorts()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of typed input ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_typedSync_InputPorts()
{

}

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_typedGuarded_InputPorts()
{

}

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_typedAsync_InputPorts()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of serial input ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_serialSync_InputPorts()
{

}

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_serialGuarded_InputPorts()
{

}

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_serialAsync_InputPorts()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of special output ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_cmdRegOut_OutputPorts()
{

}

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_cmdResponseOut_OutputPorts()
{

}

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_eventOut_OutputPorts()
{

}

#if FW_ENABLE_TEXT_LOGGING == 1

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_textEventOut_OutputPorts()
{

}

#endif

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_tlmOut_OutputPorts()
{

}

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_prmGetOut_OutputPorts()
{

}

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_prmSetOut_OutputPorts()
{

}

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_timeGetOut_OutputPorts()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of typed output ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_typedOut_OutputPorts()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of serial output ports
// ----------------------------------------------------------------------

NATIVE_INT_TYPE ActiveParamsComponentBase ::
  getNum_serialOut_OutputPorts()
{

}

// ----------------------------------------------------------------------
// Connection status queries for special output ports
// ----------------------------------------------------------------------

bool ActiveParamsComponentBase ::
  isConnected_cmdRegOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

bool ActiveParamsComponentBase ::
  isConnected_cmdResponseOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

bool ActiveParamsComponentBase ::
  isConnected_eventOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

#if FW_ENABLE_TEXT_LOGGING == 1

bool ActiveParamsComponentBase ::
  isConnected_textEventOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

#endif

bool ActiveParamsComponentBase ::
  isConnected_tlmOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

bool ActiveParamsComponentBase ::
  isConnected_prmGetOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

bool ActiveParamsComponentBase ::
  isConnected_prmSetOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

bool ActiveParamsComponentBase ::
  isConnected_timeGetOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

// ----------------------------------------------------------------------
// Connection status queries for typed output ports
// ----------------------------------------------------------------------

bool ActiveParamsComponentBase ::
  isConnected_typedOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

// ----------------------------------------------------------------------
// Connection status queries for serial output ports
// ----------------------------------------------------------------------

bool ActiveParamsComponentBase ::
  isConnected_serialOut_OutputPort(NATIVE_INT_TYPE portNum)
{

}

// ----------------------------------------------------------------------
// Handlers to implement for typed input ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  typedSync_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveParamsComponentBase ::
  typedGuarded_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveParamsComponentBase ::
  typedAsync_handler(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

// ----------------------------------------------------------------------
// Port handler base-class functions for typed input ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  typedSync_handlerBase(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveParamsComponentBase ::
  typedGuarded_handlerBase(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveParamsComponentBase ::
  typedAsync_handlerBase(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

// ----------------------------------------------------------------------
// Handlers to implement for serial input ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  serialSync_handler(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveParamsComponentBase ::
  serialGuarded_handler(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveParamsComponentBase ::
  serialAsync_handler(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

// ----------------------------------------------------------------------
// Port handler base-class functions for serial input ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  serialSync_handlerBase(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveParamsComponentBase ::
  serialGuarded_handlerBase(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveParamsComponentBase ::
  serialAsync_handlerBase(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

// ----------------------------------------------------------------------
// Pre-message hooks for typed async input ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  typedAsync_preMsgHook(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

// ----------------------------------------------------------------------
// Pre-message hooks for serial async input ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  serialAsync_preMsgHook(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

// ----------------------------------------------------------------------
// Invocation functions for typed output ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  typedOut_out(
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

// ----------------------------------------------------------------------
// Invocation functions for serial output ports
// ----------------------------------------------------------------------

Fw::SerializeStatus ActiveParamsComponentBase ::
  serialOut_out(
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

// ----------------------------------------------------------------------
// Command response
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  cmdResponse_out(
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdResponse response
  )
{

}

// ----------------------------------------------------------------------
// Parameter update hook
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  parameterUpdated(FwPrmIdType id)
{

}

void ActiveParamsComponentBase ::
  parametersLoaded()
{

}

// ----------------------------------------------------------------------
// Parameter get functions
// ----------------------------------------------------------------------

U32 ActiveParamsComponentBase ::
  paramGet_ParamU32(Fw::ParamValid& isValid)
{

}

F64 ActiveParamsComponentBase ::
  paramGet_ParamF64(Fw::ParamValid& isValid)
{

}

Fw::ParamString ActiveParamsComponentBase ::
  paramGet_ParamString(Fw::ParamValid& isValid)
{

}

E ActiveParamsComponentBase ::
  paramGet_ParamEnum(Fw::ParamValid& isValid)
{

}

A ActiveParamsComponentBase ::
  paramGet_ParamArray(Fw::ParamValid& isValid)
{

}

S ActiveParamsComponentBase ::
  paramGet_ParamStruct(Fw::ParamValid& isValid)
{

}

// ----------------------------------------------------------------------
// Time
// ----------------------------------------------------------------------

Fw::Time ActiveParamsComponentBase ::
  getTime()
{

}

// ----------------------------------------------------------------------
// Mutex operations for guarded ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  lock()
{

}

void ActiveParamsComponentBase ::
  unLock()
{

}

// ----------------------------------------------------------------------
// Message dispatch functions
// ----------------------------------------------------------------------

Fw::QueuedComponentBase::MsgDispatchStatus ActiveParamsComponentBase ::
  doDispatch()
{

}

// ----------------------------------------------------------------------
// Calls for messages received on special input ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  m_p_cmdIn_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      FwOpcodeType opCode,
      U32 cmdSeq,
      Fw::CmdArgBuffer& args
  )
{

}

// ----------------------------------------------------------------------
// Calls for messages received on typed input ports
// ----------------------------------------------------------------------

void ActiveParamsComponentBase ::
  m_p_typedSync_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveParamsComponentBase ::
  m_p_typedGuarded_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

void ActiveParamsComponentBase ::
  m_p_typedAsync_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      U32 u32,
      F32 f32,
      bool b,
      const TypedPortStrings::StringSize80& str,
      const E& e,
      const A& a,
      const S& s
  )
{

}

// ----------------------------------------------------------------------
// Calls for messages received on serial input ports
// ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

void ActiveParamsComponentBase ::
  m_p_serialSync_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveParamsComponentBase ::
  m_p_serialGuarded_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

void ActiveParamsComponentBase ::
  m_p_serialAsync_in(
      Fw::PassiveComponentBase* callComp,
      NATIVE_INT_TYPE portNum,
      Fw::SerializeBufferBase& buffer
  )
{

}

#endif

// ----------------------------------------------------------------------
// Private parameter get function
// ----------------------------------------------------------------------

Fw::ParamValid ActiveParamsComponentBase ::
  getParam(
      FwPrmIdType id,
      Fw::ParamBuffer& buff
  )
{

}

// ----------------------------------------------------------------------
// Parameter set functions
// ----------------------------------------------------------------------

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSet_ParamU32(Fw::SerializeBufferBase& val)
{

}

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSet_ParamF64(Fw::SerializeBufferBase& val)
{

}

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSet_ParamString(Fw::SerializeBufferBase& val)
{

}

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSet_ParamEnum(Fw::SerializeBufferBase& val)
{

}

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSet_ParamArray(Fw::SerializeBufferBase& val)
{

}

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSet_ParamStruct(Fw::SerializeBufferBase& val)
{

}

// ----------------------------------------------------------------------
// Parameter save functions
// ----------------------------------------------------------------------

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSave_ParamU32()
{

}

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSave_ParamF64()
{

}

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSave_ParamString()
{

}

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSave_ParamEnum()
{

}

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSave_ParamArray()
{

}

Fw::CmdResponse ActiveParamsComponentBase ::
  paramSave_ParamStruct()
{

}

#if FW_ENABLE_TEXT_LOGGING == 1

#endif