// ======================================================================
// \title  ActiveNoArgsPortsOnlyTesterHelpers.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ActiveNoArgsPortsOnly component test harness helper functions
// ======================================================================

#include "ActiveNoArgsPortsOnlyTester.hpp"

// ----------------------------------------------------------------------
// Helper functions
// ----------------------------------------------------------------------

void ActiveNoArgsPortsOnlyTester ::
  connectPorts()
{
  // Connect typed input ports

  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->connect_to_noArgsAsync(
      i,
      this->component.get_noArgsAsync_InputPort(i)
    );
  }

  this->connect_to_noArgsGuarded(
    0,
    this->component.get_noArgsGuarded_InputPort(0)
  );

  this->connect_to_noArgsReturnGuarded(
    0,
    this->component.get_noArgsReturnGuarded_InputPort(0)
  );

  for (NATIVE_UINT_TYPE i = 0; i < 3; i++) {
    this->connect_to_noArgsReturnSync(
      i,
      this->component.get_noArgsReturnSync_InputPort(i)
    );
  }

  // Connect typed output ports

  this->component.set_noArgsOut_OutputPort(
    0,
    this->get_from_noArgsOut(0)
  );

  this->component.set_noArgsReturnOut_OutputPort(
    0,
    this->get_from_noArgsReturnOut(0)
  );
}

void ActiveNoArgsPortsOnlyTester ::
  initComponents()
{
  this->init();
  this->component.init(ActiveNoArgsPortsOnlyTester::TEST_INSTANCE_QUEUE_DEPTH, ActiveNoArgsPortsOnlyTester::TEST_INSTANCE_ID);
}