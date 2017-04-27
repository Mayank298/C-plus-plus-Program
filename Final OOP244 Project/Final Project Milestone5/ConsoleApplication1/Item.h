#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files

#include "POS.h"
#include "PosIO.h"
namespace ict{
  // class Item
   class Item : public PosIO{
   private:
      char m_sku[MAX_SKU_LEN+1];
      char* m_name;
      double m_price;
      bool m_taxed;
      int m_quantity;
      void setCopy(const Item& it);
   public:
      //Constructor 
      Item();
      Item(const char* sku, const char* name, double price, bool tax = true);
      //Copy Constructor
      Item(const Item& it);
      // Assignment Operator Overload
      Item& operator=(const Item& it);
      //Destructor
      virtual ~Item();
      
      //Setters For the member Variable

      void sku(const char* sk);
      void price(double prc);
      void name(const char* nm);
      void taxed(bool tx);
      void quantity(int qty);
      
      //Getters For the member Variable
     
      const char* sku()const;
      double price()const;
      const char* name()const;
      bool taxed()const;
      int quantity()const;
      double cost()const;
      
      //isEmpty() Checker Function.
      
      bool isEmpty()const;

      //operator overloads

      bool operator==(const char* sku) const;
      int operator+=(int quantity);
      int operator-=(int quantity);
      
      // Defination Of PosIO Function Write() And Read()

      virtual std::ostream& write(std::ostream& ostr,bool linear)const = 0;
      virtual std::istream& read(std::istream& is) = 0;
   };
 
  // operator += 

  double operator+=(double& d, const Item& I);
  
  // operator << and operator >>

  std::ostream& operator<< (std::ostream& ostr, const Item& I);
  std::istream& operator>> (std::istream& is, Item& I);
  
}


#endif