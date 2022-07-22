// ======================================================================
// \title  SerializeTypeEnumAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for SerializeType enum
// ======================================================================

#ifndef M_SerializeTypeEnumAc_HPP
#define M_SerializeTypeEnumAc_HPP

#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"

namespace M {

  //! An enum with serialize type specified
  class SerializeType :
    public Fw::Serializable
  {

    public:

      // ----------------------------------------------------------------------
      // Types
      // ----------------------------------------------------------------------

      //! The serial representation type
      typedef U8 SerialType;

      //! The raw enum type
      typedef enum {
        //! Member X
        X = 0,
        Y = 1,
      } T;

      //! For backwards compatibility
      typedef T t;

    public:

      // ----------------------------------------------------------------------
      // Constants
      // ----------------------------------------------------------------------

      enum {
        //! The size of the serial representation
        SERIALIZED_SIZE = sizeof(SerialType),
        //! The number of enumerated constants
        NUM_CONSTANTS = 2,
      };

    public:

      // ----------------------------------------------------------------------
      // Constructors
      // ----------------------------------------------------------------------

      //! Constructor (default value of X)
      SerializeType();

      //! Constructor (user-provided value)
      SerializeType(
          const T e //!< The raw enum value
      );

      //! Copy constructor
      SerializeType(
          const SerializeType& obj //!< The source object
      );

    public:

      // ----------------------------------------------------------------------
      // Operators
      // ----------------------------------------------------------------------

      //! Copy assignment operator (object)
      SerializeType& operator=(
          const SerializeType& obj //!< The source object
      );

      //! Copy assignment operator (raw enum)
      SerializeType& operator=(
          T e //!< The enum value
      );

      //! Conversion operator
      operator T() const;

      //! Equality operator
      bool operator==(
          T e //!< The other enum value
      ) const;

      //! Inequality operator
      bool operator!=(
          T e //!< The other enum value
      ) const;

#ifdef BUILD_UT

      //! Ostream operator
      friend std::ostream& operator<<(
          std::ostream& os, //!< The ostream
          const SerializeType& obj //!< The object
      );

#endif

    public:

      // ----------------------------------------------------------------------
      // Member functions
      // ----------------------------------------------------------------------

      //! Check raw enum value for validity
      bool isValid() const;

      //! Serialize raw enum value to SerialType
      Fw::SerializeStatus serialize(
          Fw::SerializeBufferBase& buffer //!< The serial buffer
      ) const;

      //! Deserialize raw enum value from SerialType
      Fw::SerializeStatus deserialize(
          Fw::SerializeBufferBase& buffer //!< The serial buffer
      );

#if FW_SERIALIZABLE_TO_STRING || BUILD_UT

      //! Convert enum to string
      void toString(
          Fw::StringBase& sb //!< The StringBase object to hold the result
      ) const;

#endif

    public:

      // ----------------------------------------------------------------------
      // Member variables
      // ----------------------------------------------------------------------

      //! The raw enum value
      T e;

  };

}

#endif
