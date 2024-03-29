// ======================================================================
// \title  PassiveGetProductPortsOnlyTesterBase.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for PassiveGetProductPortsOnly component test harness base class
// ======================================================================

#include <cstdlib>
#include <cstring>

#include "test-base/PassiveGetProductPortsOnlyTesterBase.hpp"

// ----------------------------------------------------------------------
// Component initialization
// ----------------------------------------------------------------------

void PassiveGetProductPortsOnlyTesterBase ::
  init(NATIVE_INT_TYPE instance)
{
  // Initialize base class
  Fw::PassiveComponentBase::init(instance);
}

// ----------------------------------------------------------------------
// Getters for from ports
// ----------------------------------------------------------------------

Fw::InputDpGetPort* PassiveGetProductPortsOnlyTesterBase ::
  get_from_productGetOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_productGetOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_productGetOut[portNum];
}

Fw::InputDpSendPort* PassiveGetProductPortsOnlyTesterBase ::
  get_from_productSendOut(NATIVE_INT_TYPE portNum)
{
  FW_ASSERT(
    portNum < this->getNum_from_productSendOut(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_from_productSendOut[portNum];
}

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

PassiveGetProductPortsOnlyTesterBase ::
  PassiveGetProductPortsOnlyTesterBase(
      const char* const compName,
      const U32 maxHistorySize
  ) :
    Fw::PassiveComponentBase(compName)
{

}

PassiveGetProductPortsOnlyTesterBase ::
  ~PassiveGetProductPortsOnlyTesterBase()
{

}

// ----------------------------------------------------------------------
// Getters for port counts
// ----------------------------------------------------------------------

NATIVE_INT_TYPE PassiveGetProductPortsOnlyTesterBase ::
  getNum_from_productGetOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_productGetOut));
}

NATIVE_INT_TYPE PassiveGetProductPortsOnlyTesterBase ::
  getNum_from_productSendOut() const
{
  return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_from_productSendOut));
}
