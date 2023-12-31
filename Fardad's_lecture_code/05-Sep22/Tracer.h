#pragma once
#ifndef SDDS_TRACER_H
#define SDDS_TRACER_H

/*
    If you want to make a class singleton, make the constructor of it private and instantiate 
    it once statically inside the method of the class (static method). So no one can 
    instantiate it and if anyone calls the insatiate function outside it will the return the 
    same object that instantiated once.
    MORE INFO: https://www.notion.so/Singleton-9b63f6b8f2744b1e867057e5be885cc9
*/

namespace sdds {
   constexpr char nl = '\n';
   class Tracer {
      bool m_trace{ };
      Tracer( ) = default; /* private constructor */
   public:
      static Tracer& instantiate( ); 
      /*
        static function that can be called by client(every time they call this fn, it will always return the same object)
      */ 
      Tracer( const Tracer& ) = delete;
      Tracer& operator=( const Tracer& ) = delete;
      Tracer& trace( bool value = true );
      const Tracer& operator<<( const char* message )const;
      const Tracer& operator<<( int val )const;
      const Tracer& operator<<( double val )const;
      const Tracer& operator<<( char ch )const;

   };
   extern Tracer& tracer; 
   /*
        anyone include this file can use this variable which 
        the ref of the singleton created in the .cpp.
   */ 
}

#endif // !SDDS_TRACER_H
