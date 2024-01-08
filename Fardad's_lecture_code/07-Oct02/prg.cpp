#include <iostream>
using namespace std;

/*
    For Composition, Aggregation and Association: https://www.notion.so/Composition-Aggregation-and-Association-309ba6330d4a48f9b70c2765bce39213
    Lecture: https://recordings.rna2.blindsidenetworks.com/senecacollege/b3ba287a672f67483331c27b46a1916f1312da0c-1696261014693/capture/
*/

void sum(int mark, int bonus) {
   cout << (mark + bonus) << endl;
}

/*
    The functions sum and prod both have the same function signature.
*/

void prod(int qty, int price) {
   cout << "The product is " << (qty * price) << endl;
}

auto main() -> int {
   
   void (*funcptr)(int, int); // a pointer to function called "funcptr" that can hold the address of any
                              // function that returns a void and recieves two integers....
   /*
        void funcptr(int, int); -- this is a function singature
        void *funcptr(int, int); -- this will confuses the compiler that it is returing the void pointer.\
        so, Final statement to declare the function pointer
        void (*funcptr)(int, int);

        We cannot do this way: -- void (*funcptr)(int a, int b);
        because what is functtion definition has different variable name as an argument. 
   */
   funcptr = sum;
   funcptr(10, 10);

   funcptr = prod;
   funcptr(5, 50);

   return 0;
}
