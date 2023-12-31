#include <iostream>
#include "CStr.h"
#include "Tracer.h"

/*
    move : https://www.notion.so/Moving-an-object-74cf2ca2d3ed48199ed9b4d872df6234
    From now on it is rule of Five: 
    1. copy constructor
    2. copy assignment operator
    3. virtual distructor
    4. move constructor
    5. move assignment operator
*/

using namespace std;
using namespace sdds;
class Name {
private:
   char* m_value{};
public:
   Name( const char* value = nullptr ) {
      if ( value ) {
         CStr::allocNcpy( m_value, value );
      }
      tracer << "Create " << m_value << nl;
   }
   Name( const Name& N ) {
      tracer << "Copy " << N.m_value << nl << "  using: ";
      operator=( N );
   }
   Name( Name&& N ) {
      operator=( move(N) ); 
      /* 
        when you explicitly want to call the move assignment you need write move(N), 
        otherwise it will call the copy assignment 
      */
   }
   Name& operator=( const Name& N ) {
      if ( this != &N ) {
         tracer << "Assign " << m_value << " to " << N.m_value << nl;
         delete[] m_value;
         CStr::allocNcpy( m_value, N.m_value );
      }
      return *this;
   }
   Name& operator=( Name&& N ) {
      if ( this != &N ) {
         tracer << " Move assign " << N.m_value << " into " << m_value << " by assignment" << nl;
         delete[] m_value;
         m_value = N.m_value;
         N.m_value = nullptr;
      }
      return *this;
   }

   ~Name( ) {
      tracer << "Remove " << m_value << " from memory" << nl;
      delete[] m_value;
   }
   ostream& print( ostream& os = cout )const {
      return os << (m_value ? m_value : "(Nullstr)");
   }
   istream& read( istream& is = cin ) {
      delete[] m_value;
      m_value = CStr::read( is );
      return is;
   }
};

ostream& operator<< ( ostream& os, const Name& N ) {
   return N.print( os );
}
istream& operator>> ( istream& is, Name& N ) {
   return N.read( is );
}

/*
    This getName fn is kind of returing the nameless,
    First it creates an object then read it and return it, that means
    object is gonna die the moment it gets out of the scope of the fn.
*/

Name getName( ) {
   Name N;
   cout << "Enter a name: ";
   cin >> N;
   return N;
}

int main( ) {
   tracer.trace(  );
   Name A = "Fred";
   Name B = A;
   Name C;
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   cout << "C: " << C << endl;
   tracer << " C = move(A);" << nl;
   C = move( A ); /* this line will call move assignment */
   cout << "A: " << A << endl;
   cout << "B: " << B << endl;
   cout << "C: " << C << endl;
   tracer << "Name D = getName();" << nl;
   Name D = getName( ); 
   /* 
        this line is returning the a nameless object and initialize D with it, 
        So it not gonna call any of the constructors(copy or move or regular). 
        The compiler is very smart, it will just name the nameless to D. 
        (you can check by debugging or setting the tracer to true.) 
   */
   cout << "D: " << D << endl;
   tracer << "D = getName();" << nl;
   D = getName( );
   /*
        This is returing the nameless object and setting it to the D,
        So first it has to delete the current D and then it can do moving.
        So now compiler will call the move assignment.
   */
   cout << "D: " << D << endl;
   tracer << "Name E = move(B);" << nl;
   Name E = move( B ); /* this will call the move constructor */
   cout << "E: " << E << endl;
   cout << "B: " << B << endl;
   return 0;
}