#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <cstring>
#include <fstream>
#include "NonPerishable.h"
#include "Date.h"
#include "Perishable.h"
using namespace std;
namespace ict {
   //signature() function.
const  char Perishable::signature()const {
      return 'P';
}
//constructure
Perishable::Perishable() {
   m_expiry.dateOnly(true);
}
//overloaded save() function.
std::fstream& Perishable::save(std::fstream& file)const {
   NonPerishable::save(file);
   file << "," << m_expiry;
   return file;
}

//overloaded load() function.

std::fstream& Perishable::load(std::fstream& file) {
   char ch;
   NonPerishable::load(file);
   file >> ch;
   file >> m_expiry;
   return file;
}

//overloaded write() function.
std::ostream& Perishable::write(std::ostream& ostr, bool linear) const {

   NonPerishable::write(ostr, linear);
   if (linear == false && ok()) {

      ostr << "Expiry date: " << m_expiry << endl;

   }
   return ostr;
}

//overloaded read() function.
std::istream& Perishable::read(std::istream& is) {
   int chk = 0;
   cout << "Perishable ";
   NonPerishable::read(is);
   if (!is.fail()) {
      cout << "Expiry date (YYYY/MM/DD): ";
      is >> m_expiry;

      if (m_expiry.errCode() == CIN_FAILED) {
         error("Invalid Date Entry");
         chk = 1;

      }
      else if (m_expiry.errCode() == YEAR_ERROR) {
         error("Invalid Year in Date Entry");
         chk = 1;

      }
      else if (m_expiry.errCode() == MON_ERROR) {
         chk = 1;

         error("Invalid Month in Date Entry");
      }
      else if (m_expiry.errCode() == DAY_ERROR) {
         chk = 1;

         error("Invalid Day in Date Entry");
      }
      else if((m_expiry.errCode() == NO_ERROR)) {
         chk = 0;
      }
   }
   if (chk == 1) {
      is.setstate(ios::failbit);
   }
    return is;
}

}