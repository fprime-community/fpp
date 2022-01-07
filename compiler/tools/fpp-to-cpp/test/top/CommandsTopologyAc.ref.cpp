// ======================================================================
// \title  CommandsTopologyAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Commands topology
//
// \copyright
// Copyright (C) [year] California Institute of Technology.
// U.S. Government sponsorship acknowledged.
// All rights reserved.
// ======================================================================

#include "CommandsTopologyAc.hpp"

namespace M {

  namespace {

    // ----------------------------------------------------------------------
    // Component instances
    // ----------------------------------------------------------------------

    // c1
    C c1(FW_OPTIONAL_NAME("c1"));

    // c2
    C c2(FW_OPTIONAL_NAME("c2"));

    // ----------------------------------------------------------------------
    // Private functions
    // ----------------------------------------------------------------------

    // Initialize components
    void initComponents(const TopologyState& state) {
      c1.init(InstanceIds::c1);
      c2.init(InstanceIds::c2);
    }

    // Set component base Ids
    void setBaseIds() {
      c1.setIdBase(BaseIds::c1);
      c2.setIdBase(BaseIds::c2);
    }

    // Register commands
    void regCommands() {
      c1.regCommandsSpecial();
      c2.regCommands();
    }

  }

  // ----------------------------------------------------------------------
  // Public interface functions
  // ----------------------------------------------------------------------

  void setup(const TopologyState& state) {
    initComponents(state);
    setBaseIds();
    regCommands();
  }

  void teardown(const TopologyState& state) {

  }

}
