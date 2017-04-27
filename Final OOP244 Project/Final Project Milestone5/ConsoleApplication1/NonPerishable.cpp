#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include "NonPerishable.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include<string>
#include <iomanip>
using namespace std;
namespace ict {
//ok() function.
bool NonPerishable::ok() const {
      return (m_err.isClear());
}

// error function
void NonPerishable::error(const char* message) {
   m_err = message;
}

//signature function
 char NonPerishable::signature()const {
   return 'N';
}

//overloaded save() function.
fstream& NonPerishable::save(fstream& file) const{
  
     file<< signature() << "," << sku() << "," << name() << ","
         << price() << "," << taxed()
         << "," << quantity();
  
   return file;
}

//overloaded load() function.

std::fstream& NonPerishable::load(std::fstream& file) {
   int tx;
   int qt;
   double prc;
   string sk;
   string nm;
   getline(file, sk, ',');
   this->sku(sk.c_str());
   getline(file, nm, ',');
   this->name(nm.c_str());
   file >> prc;
   this->price(prc);
   file.ignore();
   file >> tx;
   this->taxed(tx);
   file.ignore();
   file >> qt;
   this->quantity(qt);
   
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
         name(nam);
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
               else {
                  is.setstate(ios::failbit);
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
                  is.setstate(ios::failbit);
               }
               else{
                  taxed(tax);
                  price(pric);
                  sku(sk);
                  quantity(qty);
                  m_err.clear();
               }
            }
            else {
               error("Invalid Taxed Entry, (y)es or (n)o");
               is.setstate(ios::failbit);
            }
         }
         else {
            error("Invalid Price Entry");
            is.setstate(ios::failbit);
         }
      }
      else {
         error("Invalid Name Entry");
         is.setstate(ios::failbit);
      }
   }
   else {
      error("Invalid Sku Entry");
      is.setstate(ios::failbit);
   }
   return is;
}
}

