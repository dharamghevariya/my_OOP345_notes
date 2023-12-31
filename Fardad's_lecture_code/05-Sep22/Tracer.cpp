#include <iostream>
#include "Tracer.h"
using namespace std;
namespace sdds {
   Tracer& tracer = Tracer::instantiate( ); /* This one is for client to use this is just a reference of that T(singleton) */
   /* this variable has been made available to every who use the Tracer.h inside the header file itself. */

   Tracer& Tracer::instantiate( ) {
      static Tracer T;
      return T;
   }
   Tracer& Tracer::trace( bool value ) {
      m_trace = value;
      return *this;
   }
   const Tracer& Tracer::operator<<( const char* message )const {
      if ( m_trace ) cout << (message ? message : "(NULLstr)");
      return *this;
   }
   const Tracer& Tracer::operator<<( int val )const {
      if ( m_trace ) cout << val;
      return *this;
   }
   const Tracer& Tracer::operator<<( double val )const {
      if ( m_trace ) cout << val;
      return *this;
   }
   const Tracer& Tracer::operator<<( char ch )const {
      if ( m_trace ) cout << ch;
      return *this;
   }

}
