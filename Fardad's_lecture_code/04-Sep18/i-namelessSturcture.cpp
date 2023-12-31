#include <iostream>
using namespace std;
class Student {
    // if you want only one instace of a struct or class you can create the struct/ class this way (a Nameless)
   struct {
      string first;
      string last;
   } m_name;

   /*
        Lazy programmer do not want to write struct every time they initialize the struct. So they do this:
        typedef struct {
            string first;
            string last;
        } Name;
        So that they can just initialize by "Name new" instead of "struct Name new"
   */
public:
   void foo() {
      auto n = m_name;
   }

};


int main() {


   return 0;
}