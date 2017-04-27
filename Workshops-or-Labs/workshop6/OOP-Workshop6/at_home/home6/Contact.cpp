#include <iostream>
#include "Contact.h"
#include <cstring>
using namespace std;
namespace communication {
   void Contact::setEmpty() {
      m_name[0] = '\0';
      m_noOfPhoneNumbers = -1;
      m_phoneNumbers = 0;
   }
   Contact::Contact() {
      setEmpty();
   }
   Contact::Contact(const char* name, const long long* Number, const int noPhNumber) {
      if (name != nullptr) {
         strncpy(m_name, name, 20);
         m_name[21] = '\0';
         int i;
         int sze = 0;
         if (noPhNumber>0) {
            for (i = 0;i < noPhNumber;i++) {
               if (Number[i] > 10000000000 && Number[i] < 999999999999) {
                  sze = sze + 1;
               }
            }
            m_noOfPhoneNumbers = sze;
            m_phoneNumbers = new long long[sze];
            int j = 0;
            for (i = 0;i < noPhNumber;i++) {
               if (Number[i] > 10000000000 && Number[i] < 999999999999) {
                  m_phoneNumbers[j] = Number[i];
                  j++;
               }
            }
         }
         else if (noPhNumber == 0) {
            m_noOfPhoneNumbers = 0;
            m_phoneNumbers = nullptr;
         }
         else {
            m_noOfPhoneNumbers = -1;
            m_phoneNumbers = 0;
         }
      }
      else {
         setEmpty();
      }
   }
   Contact::~Contact() {
      delete[] m_phoneNumbers;
      m_phoneNumbers = 0;
   }
   void Contact::display() const {

      if (m_name != nullptr && m_name[0] != '\0' && m_name[0] != 0) {
         int p;
         for (p = 0;p < 20;p++) {
            cout << m_name[p];
            if (p == 7 && m_name[p] == 'e') {
               break;
            }
         }
         cout << endl;
         if (m_noOfPhoneNumbers != -1 && m_phoneNumbers != 0) {
            int i;
            for (i = 0;i < m_noOfPhoneNumbers;i++) {
               long long num1 = m_phoneNumbers[i];
               int l, j, n;
               int k[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
               n = 0;
               l = 0;
               while (num1 > 0) {
                  k[n] = num1 % 10;
                  num1 = num1 / 10;
                  n = n + 1;
               }
               l = 11;
               if (n>11) {
                  cout << "(+" << k[l] << k[10] << ") ";
                  for (j = 9;j > 6;j--) {
                     cout << k[j];
                  }
                  cout << " ";
                  for (j = 6;j > 3;j--) {
                     cout << k[j];
                  }
                  cout << "-";
                  for (j = 3;j >= 0;j--) {
                     cout << k[j];
                  }
                  cout << endl;
               }
               else {
                  cout << "(+" << k[10] << ") ";
                  for (j = 9;j > 6;j--) {
                     cout << k[j];
                  }
                  cout << " ";
                  for (j = 6;j > 3;j--) {
                     cout << k[j];
                  }
                  cout << "-";
                  for (j = 3;j >= 0;j--) {
                     cout << k[j];
                  }
                  cout << endl;
               }
            }
         }
         else {
            cout << "Empty contact!" << endl;
         }
      }
   }
   bool Contact::isEmpty() const {
      return m_name == 0;
   }
   Contact::Contact(const Contact& other){
      if (strcmp(this->m_name, other.m_name) != 0) {
         strncpy(this->m_name, other.m_name, 20);
         this->m_name[21] = '\0';
         this->m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
         this->m_phoneNumbers = new long long[other.m_noOfPhoneNumbers];
         int i;
         for (i = 0;i < other.m_noOfPhoneNumbers;i++) {
            this->m_phoneNumbers[i] = other.m_phoneNumbers[i];
         }
      }
   }
   Contact& Contact::operator=(const Contact& other){
      if (strcmp(this->m_name, other.m_name) != 0) {
         strncpy(this->m_name, other.m_name, 20);
         this->m_name[21] = '\0';
         this->m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
         delete[] this->m_phoneNumbers;
         this->m_phoneNumbers = new long long[this->m_noOfPhoneNumbers];
         int i;
         for (i = 0;i < other.m_noOfPhoneNumbers;i++) {
            this->m_phoneNumbers[i] = other.m_phoneNumbers[i];
         }
      }
      return *this;
   }
   void Contact::addPhoneNumber(long long phoneNumber) {
      Contact tmp;
      int i;
      if (this->m_noOfPhoneNumbers == 0) {
         this->m_noOfPhoneNumbers += 1;
         this->m_phoneNumbers = new long long[this->m_noOfPhoneNumbers];
         this->m_phoneNumbers[0] = phoneNumber;
      }
      else {
         tmp.m_phoneNumbers = new long long[this->m_noOfPhoneNumbers];
         for (i = 0;i < this->m_noOfPhoneNumbers;i++) {
            tmp.m_phoneNumbers[i] = this->m_phoneNumbers[i];
         }
         this->m_noOfPhoneNumbers += 1;
         delete[] this->m_phoneNumbers;
         this->m_phoneNumbers = new long long[this->m_noOfPhoneNumbers];
         for (i = 0;i < this->m_noOfPhoneNumbers-1;i++) {
            this->m_phoneNumbers[i] = tmp.m_phoneNumbers[i];
         }
         this->m_phoneNumbers[i] = phoneNumber;
      }
   }
   }