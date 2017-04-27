#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include "Error.h"

namespace ict{
   // constructors
   Error::Error() {
      m_message = nullptr;
   }

   Error::Error(const char* errorMessage) {
      m_message = nullptr;
      message(errorMessage);
   }

   // destructor
   Error:: ~Error() {
      delete[] m_message;
      m_message = nullptr;
   }
   // deleted constructor and operator=
  

   // operator= for c-style strings
   void Error::operator=(const char* errorMessage) {
      this->message(errorMessage);
   }

   // methods
   void Error::clear() {
      delete[] this->m_message;
      this->m_message = nullptr;
   }

   bool Error::isClear() const{

      return m_message == nullptr;
   }
   void Error::message(const char* value) {
      this->clear();
      int lnt;
      lnt = strlen(value);
      this->m_message = new char[lnt + 1];
      strcpy(this->m_message, value);
      this->m_message[lnt] = '\0';
   }

   // cast overloads
   Error::operator const char*() const {
      return m_message;
   }

   Error::operator bool()const {
      return m_message == nullptr;
   }

   std::ostream& operator<<(ostream& ostr, const Error& E) {
      if (E.isClear()) {

      }
      else{
         ostr << E.operator const char*();
      }
      return ostr;
   }
}