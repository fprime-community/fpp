// ======================================================================
// \title  String1ArrayAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for String1 array
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "String1ArrayAc.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

String1 ::
  String1() :
    Serializable()
{
  this->initElements();
  // Construct using element-wise constructor
  *this = String1(
    Fw::String(""),
    Fw::String(""),
    Fw::String("")
  );
}

String1 ::
  String1(const ElementType (&a)[SIZE]) :
    Serializable()
{
  this->initElements();
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = a[index];
  }
}

String1 ::
  String1(const Fw::StringBase& e) :
    Serializable()
{
  this->initElements();
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = e;
  }
}

String1 ::
  String1(
      const Fw::StringBase& e1,
      const Fw::StringBase& e2,
      const Fw::StringBase& e3
  ) :
    Serializable()
{
  this->initElements();
  this->elements[0] = e1;
  this->elements[1] = e2;
  this->elements[2] = e3;
}

String1 ::
  String1(const String1& obj) :
    Serializable()
{
  this->initElements();
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = obj.elements[index];
  }
}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

String1::ElementType& String1 ::
  operator[](const U32 i)
{
  FW_ASSERT(i < SIZE, static_cast<FwAssertArgType>(i), static_cast<FwAssertArgType>(SIZE));
  return this->elements[i];
}

const String1::ElementType& String1 ::
  operator[](const U32 i) const
{
  FW_ASSERT(i < SIZE, static_cast<FwAssertArgType>(i), static_cast<FwAssertArgType>(SIZE));
  return this->elements[i];
}

String1& String1 ::
  operator=(const String1& obj)
{
  if (this == &obj) {
    return *this;
  }

  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = obj.elements[index];
  }
  return *this;
}

String1& String1 ::
  operator=(const ElementType (&a)[SIZE])
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = a[index];
  }
  return *this;
}

String1& String1 ::
  operator=(const ElementType& e)
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = e;
  }
  return *this;
}

bool String1 ::
  operator==(const String1& obj) const
{
  for (U32 index = 0; index < SIZE; index++) {
    if (!((*this)[index] == obj[index])) {
      return false;
    }
  }
  return true;
}

bool String1 ::
  operator!=(const String1& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const String1& obj) {
  Fw::String s;
  obj.toString(s);
  os << s;
  return os;
}

#endif

// ----------------------------------------------------------------------
// Public member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus String1 ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
  for (U32 index = 0; index < SIZE; index++) {
    status = buffer.serialize((*this)[index]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }
  return status;
}

Fw::SerializeStatus String1 ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
  for (U32 index = 0; index < SIZE; index++) {
    status = buffer.deserialize((*this)[index]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }
  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void String1 ::
  toString(Fw::StringBase& sb) const
{
  static const char *formatString = "[ "
    "%s "
    "%s "
    "%s ]";

  sb.format(
    formatString,
    this->elements[0].toChar(),
    this->elements[1].toChar(),
    this->elements[2].toChar()
  );
}

#endif

// ----------------------------------------------------------------------
// Private member functions
// ----------------------------------------------------------------------

void String1 ::
  initElements()
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index].setBuffer(&this->buffers[index][0], sizeof this->buffers[index]);
  }
}
