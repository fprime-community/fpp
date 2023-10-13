// ======================================================================
// \title  PassiveGetPortsOnlyComponentAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for PassiveGetPortsOnly component base class
// ======================================================================

#ifndef PassiveGetPortsOnlyComponentAc_HPP
#define PassiveGetPortsOnlyComponentAc_HPP

#include "FpConfig.hpp"
#include "Fw/Comp/ActiveComponentBase.hpp"
#include "Fw/Dp/DpGetPortAc.hpp"
#include "Fw/Dp/DpResponsePortAc.hpp"
#include "Fw/Dp/DpSendPortAc.hpp"
#include "Fw/Port/InputSerializePort.hpp"
#include "Fw/Port/OutputSerializePort.hpp"

//! \class PassiveGetPortsOnlyComponentBase
//! \brief Auto-generated base for PassiveGetPortsOnly component
//!
//! A passive component with product get and ports only
class PassiveGetPortsOnlyComponentBase :
  public Fw::PassiveComponentBase
{

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    friend class PassiveGetPortsOnlyComponentBaseFriend;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    //! Enumerations for numbers of special input ports
    enum {
      NUM_PRODUCTRECVIN_INPUT_PORTS = 1,
    };

    //! Enumerations for numbers of special output ports
    enum {
      NUM_PRODUCTGETOUT_OUTPUT_PORTS = 1,
      NUM_PRODUCTSENDOUT_OUTPUT_PORTS = 1,
    };

  public:

    // ----------------------------------------------------------------------
    // Component initialization
    // ----------------------------------------------------------------------

    //! Initialize PassiveGetPortsOnlyComponentBase object
    void init(
        NATIVE_INT_TYPE instance = 0 //!< The instance number
    );

  public:

    // ----------------------------------------------------------------------
    // Getters for special input ports
    // ----------------------------------------------------------------------

    //! Get special input port at index
    //!
    //! \return productRecvIn[portNum]
    Fw::InputDpResponsePort* get_productRecvIn_InputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

  public:

    // ----------------------------------------------------------------------
    // Connect input ports to special output ports
    // ----------------------------------------------------------------------

    //! Connect port to productGetOut[portNum]
    void set_productGetOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputDpGetPort* port //!< The input port
    );

    //! Connect port to productSendOut[portNum]
    void set_productSendOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputDpSendPort* port //!< The input port
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serial input ports to special output ports
    // ----------------------------------------------------------------------

    //! Connect port to productSendOut[portNum]
    void set_productSendOut_OutputPort(
        NATIVE_INT_TYPE portNum, //!< The port number
        Fw::InputSerializePort* port //!< The port
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct PassiveGetPortsOnlyComponentBase object
    PassiveGetPortsOnlyComponentBase(
        const char* compName = "" //!< The component name
    );

    //! Destroy PassiveGetPortsOnlyComponentBase object
    virtual ~PassiveGetPortsOnlyComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of special input ports
    // ----------------------------------------------------------------------

    //! Get the number of productRecvIn input ports
    //!
    //! \return The number of productRecvIn input ports
    NATIVE_INT_TYPE getNum_productRecvIn_InputPorts() const;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of special output ports
    // ----------------------------------------------------------------------

    //! Get the number of productGetOut output ports
    //!
    //! \return The number of productGetOut output ports
    NATIVE_INT_TYPE getNum_productGetOut_OutputPorts() const;

    //! Get the number of productSendOut output ports
    //!
    //! \return The number of productSendOut output ports
    NATIVE_INT_TYPE getNum_productSendOut_OutputPorts() const;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for special output ports
    // ----------------------------------------------------------------------

    //! Check whether port productGetOut is connected
    //!
    //! \return Whether port productGetOut is connected
    bool isConnected_productGetOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

    //! Check whether port productSendOut is connected
    //!
    //! \return Whether port productSendOut is connected
    bool isConnected_productSendOut_OutputPort(
        NATIVE_INT_TYPE portNum //!< The port number
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for special input ports
    //
    // Call these functions directly to bypass the corresponding ports
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port productRecvIn
    void productRecvIn_handlerBase(
        NATIVE_INT_TYPE portNum, //!< The port number
        FwDpIdType id, //!< The container ID
        const Fw::Buffer& buffer, //!< The buffer
        const Fw::Success& status //!< The status
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for special async input ports
    //
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default, they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port productRecvIn
    virtual void productRecvIn_preMsgHook(
        NATIVE_INT_TYPE portNum, //!< The port number
        FwDpIdType id, //!< The container ID
        const Fw::Buffer& buffer, //!< The buffer
        const Fw::Success& status //!< The status
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for special output ports
    // ----------------------------------------------------------------------

    //! Invoke output port productGetOut
    Fw::Success productGetOut_out(
        NATIVE_INT_TYPE portNum, //!< The port number
        FwDpIdType id, //!< The container ID
        FwSizeType size, //!< The size of the requested buffer
        Fw::Buffer& buffer //!< The buffer
    );

    //! Invoke output port productSendOut
    void productSendOut_out(
        NATIVE_INT_TYPE portNum, //!< The port number
        FwDpIdType id, //!< The container ID
        const Fw::Buffer& buffer //!< The buffer
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on special input ports
    // ----------------------------------------------------------------------

    //! Callback for port productRecvIn
    static void m_p_productRecvIn_in(
        Fw::PassiveComponentBase* callComp, //!< The component instance
        NATIVE_INT_TYPE portNum, //!< The port number
        FwDpIdType id, //!< The container ID
        const Fw::Buffer& buffer, //!< The buffer
        const Fw::Success& status //!< The status
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Private data product handling functions
    // ----------------------------------------------------------------------

    //! Handler implementation for productRecvIn
    void productRecvIn_handler(
        const NATIVE_INT_TYPE portNum, //!< The port number
        FwDpIdType id, //!< The container id
        const Fw::Buffer& buffer, //!< The buffer
        const Fw::Success& status //!< The buffer status
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Special input ports
    // ----------------------------------------------------------------------

    //! Input port productRecvIn
    Fw::InputDpResponsePort m_productRecvIn_InputPort[NUM_PRODUCTRECVIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Special output ports
    // ----------------------------------------------------------------------

    //! Output port productGetOut
    Fw::OutputDpGetPort m_productGetOut_OutputPort[NUM_PRODUCTGETOUT_OUTPUT_PORTS];

    //! Output port productSendOut
    Fw::OutputDpSendPort m_productSendOut_OutputPort[NUM_PRODUCTSENDOUT_OUTPUT_PORTS];

};

#endif