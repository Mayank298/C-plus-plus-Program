#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include <istream> 
#include <cstring>

// inlcude Item and POS header files
#include "Item.h"
#include "POS.h"

using namespace std;
namespace ict{
  // class Item implementaion
   Item::Item() {
      m_sku[0] = '\0';
      m_name = nullptr;
      m_price = 0.0;
      m_quantity = 0;
      m_taxed = true;
      
   }

   Item::Item(const char* sku, const char* name, double price, bool tax) {
      if (sku != nullptr && name != nullptr) {
         strncpy(m_sku, sku, MAX_SKU_LEN);
         m_sku[MAX_SKU_LEN] = '\0';
         int ln = strlen(name);
         m_name = new char[ln + 1];
         strncpy(m_name, name, ln);
         m_name[ln] = '\0';
         m_quantity = 0;
         m_price = price;
         if (tax == 1 || tax == true) {
            m_taxed = true;
         }
         else {
            m_taxed = false;
         }
      }

   }

   void Item::setCopy(const Item& it) {
      strncpy(this->m_sku, it.m_sku, MAX_SKU_LEN);
      this->m_sku[MAX_SKU_LEN] = '\0';
      int ln = strlen(it.m_name);
      this->m_name = new char[ln + 1];
      strncpy(this->m_name, it.m_name, ln);
      this->m_name[ln] = 0;
      this->m_quantity = it.m_quantity;
      this->m_price = it.m_price;
      this->m_taxed = it.m_taxed;
      
   }

   Item::Item(const Item& it) {
      if (!it.isEmpty() && this->m_sku != '\0') {
         this->setCopy(it);
      }
   }

   Item& Item::operator=(const Item& it) {
      if (!it.isEmpty() && this->m_sku != nullptr) {
         this->setCopy(it);
        
      }
      return *this;
   }

   Item::~Item() {
      delete[] m_name;
      m_name = nullptr;
   }

   //setters

   void Item::sku(const char* sk) {
      strncpy(this->m_sku,sk,MAX_SKU_LEN);
      m_sku[MAX_SKU_LEN] = '\0';
   }

   void Item::price(double prc) {
      this->m_price = prc;
   }

   void Item::name(const char* nm) {
      this->m_name = new char[strlen(nm) + 1];
      strncpy(this->m_name, nm, strlen(nm));
      this->m_name[strlen(nm)] = '\0';
   }

   void Item::taxed(bool tx) {
      this->m_taxed = tx;
   }

   void Item::quantity(int qty) {
      this->m_quantity = qty;
   }

   //getters

   const char* Item::sku()const {
      return this->m_sku;
   }

   double Item::price()const {
      return this->m_price;
   }

   const char* Item::name()const {
      return this->m_name;
   }

   bool Item::taxed()const {
      return this->m_taxed;
   }

   int Item::quantity()const {
      return this->m_quantity;
   }

   double Item::cost()const {
      
      return (m_taxed == true)? (this->m_price + (this->m_price * TAX) ): this->m_price;
   }

   bool Item::isEmpty() const{
      return m_sku == nullptr || m_name == nullptr;
   }

   bool Item::operator==(const char* sku) const {
      bool chkmy = false;
      if (strcmp(this->m_sku, sku)!=0) {
         chkmy = true;
      }
      return chkmy;
   }

   int Item::operator+=(int quantity){
      return (this->m_quantity = this->m_quantity + quantity);
   }

   int Item::operator-=(int quantity){
      return (this->m_quantity = this->m_quantity - quantity);
   }
   
   //Non Member function

   double operator+=(double& d, const Item& I) {
      d = I.cost() * I.quantity();
      return d;
   }
   std::ostream& operator<< (std::ostream& ostr, const Item& I) {
      
      return I.write(ostr,!I.isEmpty());
   }

   std::istream& operator>> (std::istream& is, Item& I) {
      
      return I.read(is);
   }
   
}