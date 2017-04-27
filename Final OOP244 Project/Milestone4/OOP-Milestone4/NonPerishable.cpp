#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include "NonPerishable.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
namespace ict {
//ok() function.
bool NonPerishable::ok() const {
      return (m_err.isClear());
}

// error function
void NonPerishable::error(const char* message) {
   m_err.message(message);
}

//signature function
const char NonPerishable::signature()const {
   return 'N';
}

//overloaded save() function.
fstream& NonPerishable::save(fstream& file) const{
   if (file.is_open()) {
      file << signature() << "," << sku() << "," << name() << ","
         << price() << "," << int(taxed())
         << "," << quantity();
   }
   return file;
}

//overloaded load() function.

std::fstream& NonPerishable::load(std::fstream& file) {
   char sk[MAX_SKU_LEN];
   char nam[100];
   double pric = 0.0;
   int tax;
   char ch[5];
   int qty = 0;
   if (file) {
      file.getline(sk, MAX_NO_ITEMS, ',');
      sku(sk);
      file.getline(nam, MAX_NO_ITEMS, ',');
      name(nam);
      file >> pric >> ch[0] >> tax >> ch[1] >> qty >> ch[2] >> ch[3];
      price(pric);
      taxed(tax);
      quantity(qty);
   }
   return file;
}

//overload write() function.
std::ostream& NonPerishable::write(std::ostream& ostr, bool linear) const {  
   if (ok()) {
      if (linear) {
         ostr << setfill(' ') << left << setw(MAX_SKU_LEN) << sku();
         ostr << "|";
         ostr << setfill(' ') << left << setw(20) << name();
         ostr << "|";
         ostr.setf(ios::right);
         ostr.width(7);
         ostr.setf(ios::fixed);
         ostr.precision(2);
         ostr << price();
         ostr << "|";
         if (taxed()) {
            ostr << " T" << signature();
         }
         else {
            ostr << "  " << signature();
         }
         ostr << "|";
         ostr.width(4);
         ostr << quantity();
         ostr << "|";
         ostr.width(9);
         ostr.precision(2);
         ostr << cost() * quantity();
         ostr << "|";
      }
      else{
         ostr << "Name:" << endl;
         ostr << name() << endl;
         ostr << "Sku: " << sku() << endl << "Price: " << price() << endl;
         if (taxed()) {
            ostr << "Price after tax: " << (price() + price() * TAX) << endl;
         }
         else {
            ostr << "Price after tax: N/A" << endl;
         }
         ostr << "Quantity: " << quantity() << endl << "Total Cost: " 
            << cost() * quantity() << endl;
      }
   }
   else {
      ostr << m_err.operator const char *();
   }
   return ostr;
}
std::istream& NonPerishable::read(std::istream& is) {
   char sk[MAX_SKU_LEN];
   char nam[100];
   double pric = 0.0;
   bool tax = false;
   int qty;
   char ch[10];
   cout << "Item Entry:" << endl;
   cout << "Sku: ";
   is >> sk;
   if (!is.fail()) {
      cout << "Name:" << endl;
      is >> nam;
      if (!is.fail()) {
         
         cout << "Price: ";
         is >> pric;
         if (!is.fail()) { 
            cout << "Taxed: ";
            is >> ch;
            if (strlen(ch) == 1) {
               if (ch[0] == 'y' || ch[0] == 'Y') {
                  tax = true;
               }
               else if(ch[0] == 'n' || ch[0] == 'N') {
                  tax = false;
               }
            } 
            else {
               is.setstate(ios::failbit);
            }
            if (!is.fail()) {
               cout << "Quantity: ";
               is >> qty;
               if (is.fail()) {
                  error("Invalid Quantity Entry");
               }
               else{
				  name(nam);
                  taxed(tax);
                  price(pric);
                  sku(sk);
                  quantity(qty);
                  m_err.clear();
               }
            }
            else {
               error("Invalid Taxed Entry, (y)es or (n)o");
            }
         }
         else {
            error("Invalid Price Entry");
         }
      }
      else {
         error("Invalid Name Entry");
      }
   }
   else {
      error("Invalid Sku Entry");
   }
   return is;
}
}

