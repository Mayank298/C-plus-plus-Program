#ifndef ICT_POSAPP_H_
#define ICT_POSAPP_H_
#include "Item.h"
#include "Date.h"
#include "Error.h"
#include "NonPerishable.h"
#include "Perishable.h"
#include "POS.h"
#include "PosIO.h"

namespace ict {
   class PosApp{
   private:
         char m_filename[128];
         char m_billfname[128];
         Item* m_items[MAX_NO_ITEMS];
         int m_noOfItems;
         //Member Function
         int menu();
  
         void deallocateItems();
         void loadRecs();
         void saveRecs();
         int searchItems(const char* sku)const;
         void updateQty();
         void addItem(bool isPerishable);
         void listItems()const;
         void truncateBillFile();
         void showBill();
         void addToBill(Item& I);
         void POS();
   public:
         PosApp(const PosApp& pa)=delete;
         PosApp& operator=(const PosApp& pa) = delete;
         PosApp(const char* filename, const char* billfname);
         void run();



   };
}









#endif