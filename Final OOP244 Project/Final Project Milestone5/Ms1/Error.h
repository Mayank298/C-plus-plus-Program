// compilation safegaurds
#ifndef ICT_Error_H_
#define ICT_Error_H_
#include <iostream>
using namespace std;
namespace ict {
   class Error {
      char* m_message;
   public:
   // constructors
      Error();
      Error(const char* errorMessage);
   // destructor
      virtual ~Error();
   // deleted constructor and operator=
      Error(const Error& em) = delete;
      Error& operator=(const Error& em) = delete;

   // operator= for c-style strings
      void operator=(const char* errorMessage);
   // methods
      void clear();
      bool isClear()const;
      void message(const char* value);
   // cast overloads
      operator const char*() const;
      operator bool()const;
   };
   // operator << overload prototype for cout
   ostream& operator<<(ostream& ostr, const Error& E);

}
#endif

