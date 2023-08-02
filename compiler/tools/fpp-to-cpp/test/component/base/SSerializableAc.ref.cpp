// ======================================================================
// \title  SSerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for S struct
// ======================================================================

#include "cstdio"
#include "cstring"

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"
#include "base/SSerializableAc.hpp"

// ----------------------------------------------------------------------
// StringSize80 class
// ----------------------------------------------------------------------

S::StringSize80 ::
  StringSize80() :
    StringBase()
{
  this->m_buf[0] = 0;
}

S::StringSize80 ::
  StringSize80(const char* src) :
    StringBase()
{
  Fw::StringUtils::string_copy(this->m_buf, src, sizeof(this->m_buf));
}

S::StringSize80 ::
  StringSize80(const Fw::StringBase& src) :
    StringBase()
{
  Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
}

S::StringSize80 ::
  StringSize80(const StringSize80& src) :
    StringBase()
{
  Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
}

S::StringSize80 ::
  ~StringSize80()
{

}

S::StringSize80& S::StringSize80 ::
  operator=(const StringSize80& other)
{
  if (this == &other) {
    return *this;
  }

  Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
  return *this;
}

S::StringSize80& S::StringSize80 ::
  operator=(const Fw::StringBase& other)
{
  if (this == &other) {
    return *this;
  }

  Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
  return *this;
}

S::StringSize80& S::StringSize80 ::
  operator=(const char* other)
{
  Fw::StringUtils::string_copy(this->m_buf, other, sizeof(this->m_buf));
  return *this;
}

const char* S::StringSize80 ::
  toChar() const
{
  return this->m_buf;
}

NATIVE_UINT_TYPE S::StringSize80 ::
  getCapacity() const
{
  return sizeof(this->m_buf);
}

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

S ::
  S() :
    Serializable(),
    x(0),
    y("")
{

}

S ::
  S(
      U32 x,
      const StringSize80& y
  ) :
    Serializable(),
    x(x),
    y(y)
{

}

S ::
  S(const S& obj) :
    Serializable(),
    x(obj.x),
    y(obj.y)
{

}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

S& S ::
  operator=(const S& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.x, obj.y);
  return *this;
}

bool S ::
  operator==(const S& obj) const
{
  return (
    (this->x == obj.x) &&
    (this->y == obj.y)
  );
}

bool S ::
  operator!=(const S& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const S& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus S ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->x);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->y);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

Fw::SerializeStatus S ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->x);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->y);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void S ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "x = %" PRIu32 ", "
    "y = %s"
    " )";

  char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
  (void) snprintf(
    outputString,
    FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,
    formatString,
    this->x,
    this->y.toChar()
  );

  outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
  sb = outputString;
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void S ::
  set(
      U32 x,
      const StringSize80& y
  )
{
  this->x = x;
  this->y = y;
}

void S ::
  setx(U32 x)
{
  this->x = x;
}

void S ::
  sety(const StringSize80& y)
{
  this->y = y;
}
