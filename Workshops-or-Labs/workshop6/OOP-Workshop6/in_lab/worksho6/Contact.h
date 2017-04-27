// TODO: add header guard
#ifndef communication_Cintact_H__
#define communication_Contact_H__

#include <iostream>
// TODO: add namespace here
namespace communication {
   class Contact
   {
   private:
      char m_name[21];
      long long* m_phoneNumbers; 
      int m_noOfPhoneNumbers;
      void setEmpty();
      void discheck(const long long* Number)const; 

   public:
      // TODO: add the default constructor here
      Contact();
      // TODO: add the constructor with parameters here
      Contact(const char* name,const long long* Number,const int noPhNumber);
      // TODO: add the destructor here
      ~Contact();
      // TODO: add the display function here
      void display() const;
      // TODO: add the isEmpty function here
      bool isEmpty() const;
      Contact(const Contact& other) = delete;
      Contact& operator=(const Contact& other) = delete;
   };
}
#endif