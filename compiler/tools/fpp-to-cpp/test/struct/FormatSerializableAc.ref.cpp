// ======================================================================
// \title  FormatSerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Format struct
// ======================================================================

#include <cstdio>
#include <cstring>

#include "FormatSerializableAc.hpp"
#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

Format ::
  Format() :
    Serializable(),
    m_m1(0),
    m_m2(0),
    m_m3(0),
    m_m4(0),
    m_m5(0),
    m_m6(0),
    m_m7(0),
    m_m8(0),
    m_m9(0),
    m_m10(0),
    m_m11(0.0f),
    m_m12(0.0f),
    m_m13(0.0f),
    m_m14(0.0f),
    m_m15(0.0f),
    m_m16(0.0f),
    m_m17(0.0f)
{

}

Format ::
  Format(
      I32 m1,
      U32 m2,
      I32 m3,
      U32 m4,
      I32 m5,
      U32 m6,
      I32 m7,
      U32 m8,
      I32 m9,
      U32 m10,
      F32 m11,
      F32 m12,
      F32 m13,
      F32 m14,
      F32 m15,
      F32 m16,
      F32 m17
  ) :
    Serializable(),
    m_m1(m1),
    m_m2(m2),
    m_m3(m3),
    m_m4(m4),
    m_m5(m5),
    m_m6(m6),
    m_m7(m7),
    m_m8(m8),
    m_m9(m9),
    m_m10(m10),
    m_m11(m11),
    m_m12(m12),
    m_m13(m13),
    m_m14(m14),
    m_m15(m15),
    m_m16(m16),
    m_m17(m17)
{

}

Format ::
  Format(const Format& obj) :
    Serializable(),
    m_m1(obj.m_m1),
    m_m2(obj.m_m2),
    m_m3(obj.m_m3),
    m_m4(obj.m_m4),
    m_m5(obj.m_m5),
    m_m6(obj.m_m6),
    m_m7(obj.m_m7),
    m_m8(obj.m_m8),
    m_m9(obj.m_m9),
    m_m10(obj.m_m10),
    m_m11(obj.m_m11),
    m_m12(obj.m_m12),
    m_m13(obj.m_m13),
    m_m14(obj.m_m14),
    m_m15(obj.m_m15),
    m_m16(obj.m_m16),
    m_m17(obj.m_m17)
{

}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

Format& Format ::
  operator=(const Format& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.m_m1, obj.m_m2, obj.m_m3, obj.m_m4, obj.m_m5, obj.m_m6, obj.m_m7, obj.m_m8, obj.m_m9, obj.m_m10, obj.m_m11, obj.m_m12, obj.m_m13, obj.m_m14, obj.m_m15, obj.m_m16, obj.m_m17);
  return *this;
}

bool Format ::
  operator==(const Format& obj) const
{
  return (
    (this->m_m1 == obj.m_m1) &&
    (this->m_m2 == obj.m_m2) &&
    (this->m_m3 == obj.m_m3) &&
    (this->m_m4 == obj.m_m4) &&
    (this->m_m5 == obj.m_m5) &&
    (this->m_m6 == obj.m_m6) &&
    (this->m_m7 == obj.m_m7) &&
    (this->m_m8 == obj.m_m8) &&
    (this->m_m9 == obj.m_m9) &&
    (this->m_m10 == obj.m_m10) &&
    (this->m_m11 == obj.m_m11) &&
    (this->m_m12 == obj.m_m12) &&
    (this->m_m13 == obj.m_m13) &&
    (this->m_m14 == obj.m_m14) &&
    (this->m_m15 == obj.m_m15) &&
    (this->m_m16 == obj.m_m16) &&
    (this->m_m17 == obj.m_m17)
  );
}

bool Format ::
  operator!=(const Format& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const Format& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus Format ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->m_m1);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m2);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m3);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m4);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m5);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m6);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m7);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m8);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m9);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m10);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m11);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m12);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m13);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m14);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m15);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m16);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.serialize(this->m_m17);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

Fw::SerializeStatus Format ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->m_m1);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m2);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m3);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m4);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m5);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m6);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m7);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m8);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m9);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m10);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m11);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m12);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m13);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m14);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m15);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m16);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  status = buffer.deserialize(this->m_m17);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void Format ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "m1 = %" PRIi32 ", "
    "m2 = %" PRIu32 ", "
    "m3 = %" PRIi32 ", "
    "m4 = %" PRIu32 ", "
    "m5 = %" PRIx32 ", "
    "m6 = %" PRIx32 ", "
    "m7 = %c, "
    "m8 = %c, "
    "m9 = %" PRIo32 ", "
    "m10 = %" PRIo32 ", "
    "m11 = %e, "
    "m12 = %f, "
    "m13 = %g, "
    "m14 = %.3e, "
    "m15 = %.3f, "
    "m16 = %.3g, "
    "m17 = %.3g%%"
    " )";

  char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
  (void) snprintf(
    outputString,
    FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,
    formatString,
    this->m_m1,
    this->m_m2,
    this->m_m3,
    this->m_m4,
    this->m_m5,
    this->m_m6,
    this->m_m7,
    this->m_m8,
    this->m_m9,
    this->m_m10,
    this->m_m11,
    this->m_m12,
    this->m_m13,
    this->m_m14,
    this->m_m15,
    this->m_m16,
    this->m_m17
  );

  outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
  sb = outputString;
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void Format ::
  set(
      I32 m1,
      U32 m2,
      I32 m3,
      U32 m4,
      I32 m5,
      U32 m6,
      I32 m7,
      U32 m8,
      I32 m9,
      U32 m10,
      F32 m11,
      F32 m12,
      F32 m13,
      F32 m14,
      F32 m15,
      F32 m16,
      F32 m17
  )
{
  this->m_m1 = m1;
  this->m_m2 = m2;
  this->m_m3 = m3;
  this->m_m4 = m4;
  this->m_m5 = m5;
  this->m_m6 = m6;
  this->m_m7 = m7;
  this->m_m8 = m8;
  this->m_m9 = m9;
  this->m_m10 = m10;
  this->m_m11 = m11;
  this->m_m12 = m12;
  this->m_m13 = m13;
  this->m_m14 = m14;
  this->m_m15 = m15;
  this->m_m16 = m16;
  this->m_m17 = m17;
}

void Format ::
  setm1(I32 m1)
{
  this->m_m1 = m1;
}

void Format ::
  setm2(U32 m2)
{
  this->m_m2 = m2;
}

void Format ::
  setm3(I32 m3)
{
  this->m_m3 = m3;
}

void Format ::
  setm4(U32 m4)
{
  this->m_m4 = m4;
}

void Format ::
  setm5(I32 m5)
{
  this->m_m5 = m5;
}

void Format ::
  setm6(U32 m6)
{
  this->m_m6 = m6;
}

void Format ::
  setm7(I32 m7)
{
  this->m_m7 = m7;
}

void Format ::
  setm8(U32 m8)
{
  this->m_m8 = m8;
}

void Format ::
  setm9(I32 m9)
{
  this->m_m9 = m9;
}

void Format ::
  setm10(U32 m10)
{
  this->m_m10 = m10;
}

void Format ::
  setm11(F32 m11)
{
  this->m_m11 = m11;
}

void Format ::
  setm12(F32 m12)
{
  this->m_m12 = m12;
}

void Format ::
  setm13(F32 m13)
{
  this->m_m13 = m13;
}

void Format ::
  setm14(F32 m14)
{
  this->m_m14 = m14;
}

void Format ::
  setm15(F32 m15)
{
  this->m_m15 = m15;
}

void Format ::
  setm16(F32 m16)
{
  this->m_m16 = m16;
}

void Format ::
  setm17(F32 m17)
{
  this->m_m17 = m17;
}
