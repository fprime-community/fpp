// ======================================================================
// \title  StringSerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for String struct
// ======================================================================

#include <cstdio>
#include <cstring>

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"
#include "StringSerializableAc.hpp"

// ----------------------------------------------------------------------
// StringSize80 class
// ----------------------------------------------------------------------

String::StringSize80 ::
  StringSize80() :
    StringBase()
{
  this->m_buf[0] = 0;
}

String::StringSize80 ::
  StringSize80(const char* src) :
    StringBase()
{
  Fw::StringUtils::string_copy(this->m_buf, src, sizeof(this->m_buf));
}

String::StringSize80 ::
  StringSize80(const Fw::StringBase& src) :
    StringBase()
{
  Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
}

String::StringSize80 ::
  StringSize80(const StringSize80& src) :
    StringBase()
{
  Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
}

String::StringSize80 ::
  ~StringSize80()
{

}

String::StringSize80& String::StringSize80 ::
  operator=(const StringSize80& other)
{
  if (this == &other) {
    return *this;
  }

  Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
  return *this;
}

String::StringSize80& String::StringSize80 ::
  operator=(const Fw::StringBase& other)
{
  if (this == &other) {
    return *this;
  }

  Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
  return *this;
}

String::StringSize80& String::StringSize80 ::
  operator=(const char* other)
{
  Fw::StringUtils::string_copy(this->m_buf, other, sizeof(this->m_buf));
  return *this;
}

const char* String::StringSize80 ::
  toChar() const
{
  return this->m_buf;
}

Fw::StringBase::SizeType String::StringSize80 ::
  getCapacity() const
{
  return sizeof(this->m_buf);
}

// ----------------------------------------------------------------------
// StringSize40 class
// ----------------------------------------------------------------------

String::StringSize40 ::
  StringSize40() :
    StringBase()
{
  this->m_buf[0] = 0;
}

String::StringSize40 ::
  StringSize40(const char* src) :
    StringBase()
{
  Fw::StringUtils::string_copy(this->m_buf, src, sizeof(this->m_buf));
}

String::StringSize40 ::
  StringSize40(const Fw::StringBase& src) :
    StringBase()
{
  Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
}

String::StringSize40 ::
  StringSize40(const StringSize40& src) :
    StringBase()
{
  Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
}

String::StringSize40 ::
  ~StringSize40()
{

}

String::StringSize40& String::StringSize40 ::
  operator=(const StringSize40& other)
{
  if (this == &other) {
    return *this;
  }

  Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
  return *this;
}

String::StringSize40& String::StringSize40 ::
  operator=(const Fw::StringBase& other)
{
  if (this == &other) {
    return *this;
  }

  Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
  return *this;
}

String::StringSize40& String::StringSize40 ::
  operator=(const char* other)
{
  Fw::StringUtils::string_copy(this->m_buf, other, sizeof(this->m_buf));
  return *this;
}

const char* String::StringSize40 ::
  toChar() const
{
  return this->m_buf;
}

Fw::StringBase::SizeType String::StringSize40 ::
  getCapacity() const
{
  return sizeof(this->m_buf);
}

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

String ::
  String() :
    Serializable(),
    m_s1("hello"),
    m_s2("")
{

}

String ::
  String(
      const Fw::StringBase& s1,
      const Fw::StringBase& s2
  ) :
    Serializable(),
    m_s1(s1),
    m_s2(s2)
{

}

String ::
  String(const String& obj) :
    Serializable(),
    m_s1(obj.m_s1),
    m_s2(obj.m_s2)
{

}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

String& String ::
  operator=(const String& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.m_s1, obj.m_s2);
  return *this;
}

bool String ::
  operator==(const String& obj) const
{
  return (
    (this->m_s1 == obj.m_s1) &&
    (this->m_s2 == obj.m_s2)
  );
}

bool String ::
  operator!=(const String& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const String& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus String ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->m_s1);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_s2);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

Fw::SerializeStatus String ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->m_s1);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_s2);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void String ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "s1 = %s, "
    "s2 = %s"
    " )";

  char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
  (void) snprintf(
    outputString,
    FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,
    formatString,
    this->m_s1.toChar(),
    this->m_s2.toChar()
  );

  outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
  sb = outputString;
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void String ::
  set(
      const Fw::StringBase& s1,
      const Fw::StringBase& s2
  )
{
  this->m_s1 = s1;
  this->m_s2 = s2;
}

void String ::
  sets1(const Fw::StringBase& s1)
{
  this->m_s1 = s1;
}

void String ::
  sets2(const Fw::StringBase& s2)
{
  this->m_s2 = s2;
}
