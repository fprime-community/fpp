// ======================================================================
// \title  PrimitiveI32ArrayAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for PrimitiveI32 array
// ======================================================================

#ifndef M_PrimitiveI32ArrayAc_HPP
#define M_PrimitiveI32ArrayAc_HPP

#include "FpConfig.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

namespace M {

  //! An array of I32 with format string
  class PrimitiveI32 :
    public Fw::Serializable
  {

    public:

      // ----------------------------------------------------------------------
      // Types
      // ----------------------------------------------------------------------

      //! The element type
      typedef I32 ElementType;

    public:

      // ----------------------------------------------------------------------
      // Constants
      // ----------------------------------------------------------------------

      enum {
        //! The size of the array
        SIZE = 3,
        //! The size of the serial representation
        SERIALIZED_SIZE = SIZE * sizeof(I32),
      };

    public:

      // ----------------------------------------------------------------------
      // Constructors
      // ----------------------------------------------------------------------

      //! Constructor (default value)
      PrimitiveI32();

      //! Constructor (user-provided value)
      PrimitiveI32(
          const ElementType (&a)[SIZE] //!< The array
      );

      //! Constructor (single element)
      PrimitiveI32(
          const ElementType& e //!< The element
      );

      //! Constructor (multiple elements)
      PrimitiveI32(
          const ElementType& e1, //!< Element 1
          const ElementType& e2, //!< Element 2
          const ElementType& e3 //!< Element 3
      );

      //! Copy Constructor
      PrimitiveI32(
          const PrimitiveI32& obj //!< The source object
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
      PrimitiveI32& operator=(
          const PrimitiveI32& obj //!< The source object
      );

      //! Copy assignment operator (raw array)
      PrimitiveI32& operator=(
          const ElementType (&a)[SIZE] //!< The source array
      );

      //! Copy assignment operator (single element)
      PrimitiveI32& operator=(
          const ElementType& e //!< The element
      );

      //! Equality operator
      bool operator==(
          const PrimitiveI32& obj //!< The other object
      ) const;

      //! Inequality operator
      bool operator!=(
          const PrimitiveI32& obj //!< The other object
      ) const;

#ifdef BUILD_UT

      //! Ostream operator
      friend std::ostream& operator<<(
          std::ostream& os, //!< The ostream
          const PrimitiveI32& obj //!< The object
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

#if FW_ARRAY_TO_STRING

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

}

#endif
