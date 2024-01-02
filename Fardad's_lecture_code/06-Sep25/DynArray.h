#ifndef SDDS_DYNARRAY
#define SDDS_DYNARRAY

/*
    Note: A template can be created for every single scope you have in your program.
    Classes do not carry any signature like functions.
    Example:
        Lets stay for a DynArray Class (without template for a specific type lets say for an int),
            We want to make an objects that holds dynamic array of double, int, char etc.
            In this case if we instatiate an object like "DynArray D" and we do not have any template, then It is not gonna be applicable. It would only work for int.
        To solve, We have to have a class with template so we can tell compiler like "DynArray<double> D" so it can create an object that works for the duble array.
            That is given below:
*/

/*
    More about Class Templates: https://www.notion.so/Templates-2cfe7c9094fd4f9286ee4cef4eb5f129
*/

#include <iostream>
namespace sdds {
   /*
    1- change the T of the focus of the class to templated T
    2- add the signature of the template to all the Class names other than:
       a- the Name of class coming right after the temaplate
       b- Constructor names
       c- Destructor name
   */
    /*
        After That You have to add template for evry single scope
    */
template <typename T>
  class DynArray {
      T* m_data;
      size_t m_size;
      void resize(size_t newsize);
   public:
      DynArray(size_t size = 1);
      DynArray(const DynArray<T>& cp); // singnature of the template added
      DynArray<T>& operator=(const DynArray<T>& cp);
      size_t size()const;
      T& operator[](size_t index);
      const T& operator[](size_t index)const;
      virtual ~DynArray();
      std::ostream& display(std::ostream& ostr = std::cout)const;
   };
   
   template <typename T> // Templated Added for the scope
   std::ostream& operator<<(std::ostream& ostr, const DynArray<T>& Ro);

   template <typename T> // Templated Added for the scope
   DynArray<T>::DynArray(size_t size) {
      if(size == 0) size = 1;
      m_data = new T[m_size = size];
   }


   template <typename T> // Templated Added for the scope
   DynArray<T>::DynArray(const DynArray<T>& cp) {
      m_data = new T[m_size = cp.m_size];
      for(size_t i = 0; i < m_size; i++) {
         m_data[i] = cp.m_data[i];                                      // copy assignment 
      }
   }

   template <typename T> // Templated Added for the scope
   DynArray<T>& DynArray<T>::operator=(const DynArray<T>& cp) {
      if(this != &cp) {
         delete[] m_data;
         m_data = new T[m_size = cp.m_size];
         for(size_t i = 0; i < m_size; i++) {
            m_data[i] = cp.m_data[i];
         }
      }
      return *this;
   }

   
   template <typename T> // Templated Added for the scope
   DynArray<T>::~DynArray() {
      delete[] m_data;
   }

   template <typename T> // Templated Added for the scope
   size_t DynArray<T>::size() const {
      return m_size;
   }

   template <typename T> // Templated Added for the scope
   T& DynArray<T>::operator[](size_t index) {
      if(index >= m_size) {
         resize(index + 1);
      }
      return m_data[index];
   }

   template <typename T> // Templated Added for the scope
   const T& DynArray<T>::operator[](size_t index)const {
      return m_data[index % m_size];
   }


   template <typename T> // Templated Added for the scope
   std::ostream& DynArray<T>::display(std::ostream& ostr)const {
      ostr << operator[](0);                                         //  T must be insertable into ostream using << operator
      for(size_t i = 1; i < size(); i++) {
         ostr << ", " << (*this)[i];
      }
      return ostr;
   }

   template <typename T> // Templated Added for the scope
   void DynArray<T>::resize(size_t newsize) {
      if(newsize == 0) newsize = 1;
      T* newArray = new T[newsize];                                 // no arg constructor or default constructor
      for(size_t i = 0; i < m_size && i < newsize; i++) {
         newArray[i] = m_data[i];
      }
      m_size = newsize;
      delete[] m_data;
      delete[] m_data;
      m_data = newArray;
   }


   template <typename T> // Templated Added for the scope
   std::ostream& operator<<(std::ostream& ostr, const DynArray<T>& Ro) {
      return Ro.display(ostr);
   }



}

#endif // !SDDS_DYNARRAY