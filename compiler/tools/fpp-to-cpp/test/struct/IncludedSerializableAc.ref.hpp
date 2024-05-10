// ======================================================================
// \title  IncludedSerializableAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Included struct
// ======================================================================

#ifndef IncludedSerializableAc_HPP
#define IncludedSerializableAc_HPP

#include "FpConfig.hpp"
#include "Fw/Types/ExternalString.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

class Included :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    //! The type of x
    using Type_of_x = U32;

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the serial representation
      SERIALIZED_SIZE =
        sizeof(U32)
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    Included();

    //! Member constructor
    Included(U32 x);

    //! Copy constructor
    Included(
        const Included& obj //!< The source object
    );

  public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Copy assignment operator
    Included& operator=(
        const Included& obj //!< The source object
    );

    //! Equality operator
    bool operator==(
        const Included& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const Included& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const Included& obj //!< The object
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Member functions
    // ----------------------------------------------------------------------

    //! Serialization
    Fw::SerializeStatus serialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    ) const;

    //! Deserialization
    Fw::SerializeStatus deserialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
    );

#if FW_SERIALIZABLE_TO_STRING

    //! Convert struct to string
    void toString(
        Fw::StringBase& sb //!< The StringBase object to hold the result
    ) const;

#endif

    // ----------------------------------------------------------------------
    // Getter functions
    // ----------------------------------------------------------------------

    //! Get member x
    U32 getx() const
    {
      return this->m_x;
    }

    // ----------------------------------------------------------------------
    // Setter functions
    // ----------------------------------------------------------------------

    //! Set all members
    void set(U32 x);

    //! Set member x
    void setx(U32 x);

  protected:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    U32 m_x;

};

#endif
