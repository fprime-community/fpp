// ======================================================================
// \title  IncludedSerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Included struct
// ======================================================================

#include <cstdio>
#include <cstring>

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"
#include "IncludedSerializableAc.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

Included ::
  Included() :
    Serializable(),
    m_x(0)
{

}

Included ::
  Included(U32 x) :
    Serializable(),
    m_x(x)
{

}

Included ::
  Included(const Included& obj) :
    Serializable(),
    m_x(obj.m_x)
{

}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

Included& Included ::
  operator=(const Included& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.m_x);
  return *this;
}

bool Included ::
  operator==(const Included& obj) const
{
  return (this->m_x == obj.m_x);
}

bool Included ::
  operator!=(const Included& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const Included& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus Included ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->m_x);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

Fw::SerializeStatus Included ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->m_x);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void Included ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "x = %" PRIu32 ""
    " )";

  char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
  (void) snprintf(
    outputString,
    FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,
    formatString,
    this->m_x
  );

  outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
  sb = outputString;
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void Included ::
  set(U32 x)
{
  this->m_x = x;
}

void Included ::
  setx(U32 x)
{
  this->m_x = x;
}
