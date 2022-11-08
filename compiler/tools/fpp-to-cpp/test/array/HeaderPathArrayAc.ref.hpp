// ======================================================================
// \title  HeaderPathArrayAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for HeaderPath array
// ======================================================================

#ifndef HeaderPathArrayAc_HPP
#define HeaderPathArrayAc_HPP

#include "FpConfig.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"
#include "include/T.hpp"

//! Test the include header path of an abstract type
class HeaderPath :
  public Fw::Serializable
{

  public:

    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    //! The element type
    typedef T ElementType;

  public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
      //! The size of the array
      SIZE = 3,
      //! The size of the serial representation
      SERIALIZED_SIZE = SIZE * T::SERIALIZED_SIZE,
    };

  public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Constructor (default value)
    HeaderPath();

    //! Constructor (user-provided value)
    HeaderPath(
        const ElementType (&a)[SIZE] //!< The array
    );

    //! Constructor (multiple elements)
    HeaderPath(
        const ElementType& e1, //!< Element 1
        const ElementType& e2, //!< Element 2
        const ElementType& e3 //!< Element 3
    );

    //! Copy Constructor
    HeaderPath(
        const HeaderPath& obj //!< The source object
    );

    //! Constructor (single element)
    HeaderPath(
        const ElementType& e //!< The element
    );

  public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Subscript operator
    ElementType& operator[](
        const U32 i //!< The subscript index
    );

    //! Const subscript operator
    const ElementType& operator[](
        const U32 i //!< The subscript index
    ) const;

    //! Copy assignment operator (object)
    HeaderPath& operator=(
        const HeaderPath& obj //!< The source object
    );

    //! Copy assignment operator (raw array)
    HeaderPath& operator=(
        const ElementType (&a)[SIZE] //!< The source array
    );

    //! Copy assignment operator (single element)
    HeaderPath& operator=(
        const ElementType& e //!< The element
    );

    //! Equality operator
    bool operator==(
        const HeaderPath& obj //!< The other object
    ) const;

    //! Inequality operator
    bool operator!=(
        const HeaderPath& obj //!< The other object
    ) const;

#ifdef BUILD_UT

    //! Ostream operator
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const HeaderPath& obj //!< The object
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

#if FW_ARRAY_TO_STRING || BUILD_UT

    //! Convert array to string
    void toString(
        Fw::StringBase& sb //!< The StringBase object to hold the result
    ) const;

#endif

  private:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The array elements
    ElementType elements[SIZE];

};

#endif