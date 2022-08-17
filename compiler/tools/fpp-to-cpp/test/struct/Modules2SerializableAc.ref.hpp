// ======================================================================
// \title  Modules2SerializableAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for Modules2 struct
// ======================================================================

#ifndef M_Modules2SerializableAc_HPP
#define M_Modules2SerializableAc_HPP

#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"
#include "Fw/Types/String.hpp"
#include "Modules1SerializableAc.hpp"

namespace M {

  class Modules2 :
    public Fw::Serializable
  {

    public:

      // ----------------------------------------------------------------------
      // Constants
      // ----------------------------------------------------------------------

      enum {
        //! The size of the serial representation
        SERIALIZED_SIZE =
          M::Modules1::SERIALIZED_SIZE
      };

    public:

      // ----------------------------------------------------------------------
      // Constructors
      // ----------------------------------------------------------------------

      //! Constructor (default value)
      Modules2();

      //! Member constructor
      Modules2(const M::Modules1& x);

      //! Copy constructor
      Modules2(
          const Modules2& obj //!< The source object
      );

    public:

      // ----------------------------------------------------------------------
      // Operators
      // ----------------------------------------------------------------------

      //! Copy assignment operator
      Modules2& operator=(
          const Modules2& obj //!< The source object
      );

      //! Equality operator
      bool operator==(
          const Modules2& obj //!< The other object
      ) const;

      //! Inequality operator
      bool operator!=(
          const Modules2& obj //!< The other object
      ) const;

#ifdef BUILD_UT

      //! Ostream operator
      friend std::ostream& operator<<(
          std::ostream& os, //!< The ostream
          const Modules2& obj //!< The object
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

      //! Get member x
      M::Modules1& getx();

      //! Get member x (const)
      const M::Modules1& getx() const;

      // ----------------------------------------------------------------------
      // Setter functions
      // ----------------------------------------------------------------------

      //! Set all members
      void set(const M::Modules1& x);

      //! Set member x
      void setx(const M::Modules1& x);

    protected:

      // ----------------------------------------------------------------------
      // Member variables
      // ----------------------------------------------------------------------

      M::Modules1 x;

  };

}

#endif
