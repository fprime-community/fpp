// ======================================================================
// \title  AbsTypeSerializableAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for AbsType struct
// ======================================================================

#ifndef AbsTypeSerializableAc_HPP
#define AbsTypeSerializableAc_HPP

#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"
#include "T.hpp"

class AbsType :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the serial representation
      SERIALIZED_SIZE =
        T::SERIALIZED_SIZE
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    AbsType();

    //! Member constructor
    AbsType(const T& t);

    //! Copy constructor
    AbsType(
        const AbsType& obj //!< The source object
    );

  public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Copy assignment operator
    AbsType& operator=(
        const AbsType& obj //!< The source object
    );

    //! Equality operator
    bool operator==(
        const AbsType& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const AbsType& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const AbsType& obj //!< The object
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

#if FW_SERIALIZABLE_TO_STRING || BUILD_UT

    //! Convert struct to string
    void toString(
        Fw::StringBase& sb //!< The StringBase object to hold the result
    ) const;

#endif

    // ----------------------------------------------------------------------
    // Getter functions
    // ----------------------------------------------------------------------

    //! Get member t
    T& gett();

    //! Get member t (const)
    const T& gett() const;

    // ----------------------------------------------------------------------
    // Setter functions
    // ----------------------------------------------------------------------

    //! Set all members
    void set(const T& t);

    //! Set member t
    void sett(const T& t);

  protected:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    T t;

};

#endif
