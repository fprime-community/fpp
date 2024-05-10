// ======================================================================
// \title  EmptyPortAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Empty port
// ======================================================================

#include "EmptyPortAc.hpp"
#include "Fw/Types/Assert.hpp"
#include "Fw/Types/ExternalString.hpp"

namespace {

  // ----------------------------------------------------------------------
  // Port buffer class
  // ----------------------------------------------------------------------

  class EmptyPortBuffer : public Fw::SerializeBufferBase {

    public:

      Fw::Serializable::SizeType getBuffCapacity() const {
        return InputEmptyPort::SERIALIZED_SIZE;
      }

      U8* getBuffAddr() {
        return nullptr;
      }

      const U8* getBuffAddr() const {
        return nullptr;
      }

  };

}

// ----------------------------------------------------------------------
// Input Port Member functions
// ----------------------------------------------------------------------

InputEmptyPort ::
  InputEmptyPort() :
    Fw::InputPortBase(),
    m_func(nullptr)
{

}

void InputEmptyPort ::
  init()
{
  Fw::InputPortBase::init();
}

void InputEmptyPort ::
  addCallComp(
      Fw::PassiveComponentBase* callComp,
      CompFuncPtr funcPtr
  )
{
  FW_ASSERT(callComp != nullptr);
  FW_ASSERT(funcPtr != nullptr);

  this->m_comp = callComp;
  this->m_func = funcPtr;
  this->m_connObj = callComp;
}

void InputEmptyPort ::
  invoke()
{
#if FW_PORT_TRACING == 1
  this->trace();
#endif

  FW_ASSERT(this->m_comp != nullptr);
  FW_ASSERT(this->m_func != nullptr);

  return this->m_func(this->m_comp, this->m_portNum);
}

#if FW_PORT_SERIALIZATION == 1

Fw::SerializeStatus InputEmptyPort ::
  invokeSerial(Fw::SerializeBufferBase& _buffer)
{
  (void) _buffer;

#if FW_PORT_TRACING == 1
  this->trace();
#endif

  FW_ASSERT(this->m_comp != nullptr);
  FW_ASSERT(this->m_func != nullptr);

  this->m_func(this->m_comp, this->m_portNum);

  return Fw::FW_SERIALIZE_OK;
}

#endif

// ----------------------------------------------------------------------
// Output Port Member functions
// ----------------------------------------------------------------------

OutputEmptyPort ::
  OutputEmptyPort() :
    Fw::OutputPortBase(),
    m_port(nullptr)
{

}

void OutputEmptyPort ::
  init()
{
  Fw::OutputPortBase::init();
}

void OutputEmptyPort ::
  addCallPort(InputEmptyPort* callPort)
{
  FW_ASSERT(callPort != nullptr);

  this->m_port = callPort;
  this->m_connObj = callPort;

#if FW_PORT_SERIALIZATION == 1
  this->m_serPort = nullptr;
#endif
}

void OutputEmptyPort ::
  invoke()
{
#if FW_PORT_TRACING == 1
  this->trace();
#endif

#if FW_PORT_SERIALIZATION
  FW_ASSERT((this->m_port != nullptr) || (this->m_serPort != nullptr));

  if (this->m_port != nullptr) {
    this->m_port->invoke();
  }
  else {
    Fw::SerializeStatus _status;
    EmptyPortBuffer _buffer;

    _status = this->m_serPort->invokeSerial(_buffer);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));
  }
#else
  FW_ASSERT(this->m_port != nullptr);
  this->m_port->invoke();
#endif
}
