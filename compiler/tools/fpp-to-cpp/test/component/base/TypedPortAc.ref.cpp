// ======================================================================
// \title  TypedPortAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Typed port
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"
#include "base/TypedPortAc.hpp"

namespace Ports {

  namespace TypedPortStrings {

    // ----------------------------------------------------------------------
    // StringSize80 class
    // ----------------------------------------------------------------------

    StringSize80 ::
      StringSize80() :
        StringBase()
    {
      this->m_buf[0] = 0;
    }

    StringSize80 ::
      StringSize80(const char* src) :
        StringBase()
    {
      Fw::StringUtils::string_copy(this->m_buf, src, sizeof(this->m_buf));
    }

    StringSize80 ::
      StringSize80(const Fw::StringBase& src) :
        StringBase()
    {
      Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
    }

    StringSize80 ::
      StringSize80(const StringSize80& src) :
        StringBase()
    {
      Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
    }

    StringSize80 ::
      ~StringSize80()
    {

    }

    StringSize80& StringSize80 ::
      operator=(const StringSize80& other)
    {
      if (this == &other) {
        return *this;
      }

      Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
      return *this;
    }

    StringSize80& StringSize80 ::
      operator=(const Fw::StringBase& other)
    {
      if (this == &other) {
        return *this;
      }

      Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
      return *this;
    }

    StringSize80& StringSize80 ::
      operator=(const char* other)
    {
      Fw::StringUtils::string_copy(this->m_buf, other, sizeof(this->m_buf));
      return *this;
    }

    const char* StringSize80 ::
      toChar() const
    {
      return this->m_buf;
    }

    NATIVE_UINT_TYPE StringSize80 ::
      getCapacity() const
    {
      return sizeof(this->m_buf);
    }

  }

  namespace {

    // ----------------------------------------------------------------------
    // Port buffer class
    // ----------------------------------------------------------------------

    class TypedPortBuffer : public Fw::SerializeBufferBase {

      public:

        NATIVE_UINT_TYPE getBuffCapacity() const {
          return InputTypedPort::SERIALIZED_SIZE;
        }

        U8* getBuffAddr() {
          return m_buff;
        }

        const U8* getBuffAddr() const {
          return m_buff;
        }

      private:

        U8 m_buff[InputTypedPort::SERIALIZED_SIZE];

    };

  }

  // ----------------------------------------------------------------------
  // Input Port Member functions
  // ----------------------------------------------------------------------

  InputTypedPort ::
    InputTypedPort() :
      Fw::InputPortBase(),
      m_func(nullptr)
  {

  }

  void InputTypedPort ::
    init()
  {
    Fw::InputPortBase::init();
  }

  void InputTypedPort ::
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

  void InputTypedPort ::
    invoke(
        U32 u32,
        F32 f32,
        bool b,
        const TypedPortStrings::StringSize80& str1,
        const E& e,
        const A& a,
        const S& s
    )
  {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

    FW_ASSERT(this->m_comp != nullptr);
    FW_ASSERT(this->m_func != nullptr);

    return this->m_func(this->m_comp, this->m_portNum, u32, f32, b, str1, e, a, s);
  }

#if FW_PORT_SERIALIZATION == 1

  Fw::SerializeStatus InputTypedPort ::
    invokeSerial(Fw::SerializeBufferBase& _buffer)
  {
    Fw::SerializeStatus _status;

#if FW_PORT_TRACING == 1
    this->trace();
#endif

    FW_ASSERT(this->m_comp != nullptr);
    FW_ASSERT(this->m_func != nullptr);

    U32 u32;
    _status = _buffer.deserialize(u32);
    if (_status != Fw::FW_SERIALIZE_OK) {
      return _status;
    }

    F32 f32;
    _status = _buffer.deserialize(f32);
    if (_status != Fw::FW_SERIALIZE_OK) {
      return _status;
    }

    bool b;
    _status = _buffer.deserialize(b);
    if (_status != Fw::FW_SERIALIZE_OK) {
      return _status;
    }

    TypedPortStrings::StringSize80 str1;
    _status = _buffer.deserialize(str1);
    if (_status != Fw::FW_SERIALIZE_OK) {
      return _status;
    }

    E e;
    _status = _buffer.deserialize(e);
    if (_status != Fw::FW_SERIALIZE_OK) {
      return _status;
    }

    A a;
    _status = _buffer.deserialize(a);
    if (_status != Fw::FW_SERIALIZE_OK) {
      return _status;
    }

    S s;
    _status = _buffer.deserialize(s);
    if (_status != Fw::FW_SERIALIZE_OK) {
      return _status;
    }

    this->m_func(this->m_comp, this->m_portNum, u32, f32, b, str1, e, a, s);

    return Fw::FW_SERIALIZE_OK;
  }

#endif

  // ----------------------------------------------------------------------
  // Output Port Member functions
  // ----------------------------------------------------------------------

  OutputTypedPort ::
    OutputTypedPort() :
      Fw::OutputPortBase(),
      m_port(nullptr)
  {

  }

  void OutputTypedPort ::
    init()
  {
    Fw::OutputPortBase::init();
  }

  void OutputTypedPort ::
    addCallPort(InputTypedPort* callPort)
  {
    FW_ASSERT(callPort != nullptr);

    this->m_port = callPort;
    this->m_connObj = callPort;

#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
  }

  void OutputTypedPort ::
    invoke(
        U32 u32,
        F32 f32,
        bool b,
        const TypedPortStrings::StringSize80& str1,
        const E& e,
        const A& a,
        const S& s
    )
  {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT((this->m_port != nullptr) || (this->m_serPort != nullptr));

    if (this->m_port != nullptr) {
      this->m_port->invoke(u32, f32, b, str1, e, a, s);
    }
    else {
      Fw::SerializeStatus _status;
      TypedPortBuffer _buffer;

      _status = _buffer.serialize(u32);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

      _status = _buffer.serialize(f32);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

      _status = _buffer.serialize(b);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

      _status = _buffer.serialize(str1);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

      _status = _buffer.serialize(e);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

      _status = _buffer.serialize(a);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

      _status = _buffer.serialize(s);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));

      _status = this->m_serPort->invokeSerial(_buffer);
      FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<FwAssertArgType>(_status));
    }
#else
    FW_ASSERT(this->m_port != nullptr);
    this->m_port->invoke(u32, f32, b, str1, e, a, s);
#endif
  }

}
