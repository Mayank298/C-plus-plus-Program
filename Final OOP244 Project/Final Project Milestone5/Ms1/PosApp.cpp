#define _CRT_SECURE_NO_WARNINGS
#include "PosApp.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
namespace ict {
   
   PosApp::PosApp(const char* filename, const char* billfname) {
      strcpy(m_filename, filename);
      strcpy(m_billfname, billfname);
      m_noOfItems = 0;
   }

   int PosApp::menu() {
      int choice;
      int rtnChoice = -1;
         cout <<"The Sene-Store" << endl
            << "1- List items" << endl
            << "2- Add Perishable item" << endl
            << "3- Add Non - Perishable item" << endl
            << "4- Update item quantity" << endl
            << "5- Show Item" << endl
            << "6- POS" << endl
            << "0- exit program" << endl
            << "> ";
         cin >> choice;
         if (choice >= 0 && choice <= 6) {
            rtnChoice = choice;
         }         
         cout << endl;
         cin.ignore();
         return rtnChoice;
   }

   void PosApp::deallocateItems() {
      int i;
      for (i = 0;i < m_noOfItems;i++) {
         delete m_items[i];
         m_items[i] = nullptr;
      }
      m_noOfItems = 0;
   }

   void PosApp::saveRecs() {
      fstream MyFile;
      int i;
      int qty = 0;
      MyFile.open(m_filename, ios::out);     
      for (i = 0;i < m_noOfItems;i++) {
         qty = m_items[i]->quantity();
         if (qty > 0) {
            m_items[i]->save(MyFile);
            MyFile << endl;
         }
      }
      MyFile.close();
      loadRecs();
   }

   void PosApp::addItem(bool isPerishable) {
     cin.clear();
      if (isPerishable == true) {
         m_items[m_noOfItems] = new Perishable();
      }
      else {
         m_items[m_noOfItems] = new NonPerishable();
      }
      m_items[m_noOfItems]->read(cin);
      if (cin.fail()==true) {
         m_items[m_noOfItems]->write(cout, false);
         cin.clear();
      }
      else {
       //m_items[m_noOfItems] = I;
		 m_noOfItems++;
       saveRecs();
		 cout<<"Item Added."<<endl<<endl;
      }

   }

   void PosApp::loadRecs() {
      deallocateItems();
      char ch;
      fstream MyFile;
      MyFile.open(m_filename, ios::in);
      if (MyFile.fail()) {
         MyFile.clear();
         MyFile.close();
         MyFile.open(m_filename, ios::out);
      }
      else {
         bool chk = true;
         while (chk) {
            MyFile >> ch;
            if (MyFile.fail() == false) {
               if (ch == 'P') {
                  m_items[m_noOfItems] = new Perishable();
               }
               else if (ch == 'N') {
                  m_items[m_noOfItems] = new NonPerishable();
               }
               MyFile.ignore();
               m_items[m_noOfItems]->load(MyFile);
               m_noOfItems++;
            }
            else {
               chk = false;
            }
         }
      }
      MyFile.close();
   }

   int PosApp::searchItems(const char* sku)const {
      int iCap = -1;
      int i;
      for (i = 0;i <m_noOfItems;i++) {
         if (strcmp(m_items[i]->sku(),sku)==0) {
            iCap = i;
         }
      }
      return iCap; 
   }

   void PosApp::updateQty() {
      int find;
      char sk[100]="";
      int qty=0;
      cout << "Please enter the SKU: ";
      cin >> sk;
      find = searchItems(sk);
      if (find == -1) {
         cout << "Not found!" << endl;
      }
      else {

         m_items[find]->write(cout, false);
         cout << "Please enter the number of purchased items : ";
         cin >> qty;
         if (qty > 0) {
            int b = m_items[find]->quantity();
            int a = qty + b;
            m_items[find]->quantity(a);
            //m_items[find]->write(cout, true);
            saveRecs();
            cout << "Updated!" << endl << endl;
         }
      }

   }

   void PosApp::listItems()const {
      double TtlAss = 0.0;
      int i;
      cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
      cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;
      for (i = 0; i < m_noOfItems; i++) {
         cout << setw(4) << setfill(' ') << right << i + 1 << " | ";
         m_items[i]->write(cout, true);//
         cout << endl;
         TtlAss += (m_items[i]->cost() * (m_items[i]->quantity()));
      }

      cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
      cout << setw(48) << setfill(' ') << "Total Asset: $ |" << setw(14) << setfill(' ') << TtlAss << '|' << endl;
      cout << "-----------------------------------------------^--------------^" << endl << endl;
   }

   void PosApp::truncateBillFile() {
      fstream MyFile;
      MyFile.open(m_billfname, ios::out|ios::trunc);
      MyFile.close();
   }

   void PosApp::showBill() {
      fstream MyFile;
      double TtlAss = 0.0;
      char ch;
      bool chk = false;
      
      Date SysDate;
      MyFile.open(m_billfname, ios::in);
      cout << "v--------------------------------------------------------v" << endl;
      cout << "| "<< SysDate<<"                                      |" << endl;
      cout << "| SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
      cout << "|--------|--------------------|-------|---|----|---------|" << endl;
      
      while (!chk) {
         MyFile >> ch;
         Item* MyItmBuff = nullptr;
         if (MyFile.fail() == false) {
            if (ch == 'P') {
               MyItmBuff = new Perishable();
            }
            else {
               MyItmBuff = new NonPerishable();
            }
            MyItmBuff->load(MyFile);
            cout << "| ";
            MyItmBuff->write(cout, true);
            cout << endl;
            TtlAss += (MyItmBuff->cost() * (MyItmBuff->quantity()));
         }
         else {
            chk = true;
         }
         delete MyItmBuff;
      }

      cout << "^--------^--------------------^-------^---^----^---------^" << endl;
      cout << setw(43) << setfill(' ') << "Total Asset: $ |" << setw(14) << setfill(' ') << TtlAss << '|' << endl;
      cout << "^-----------------------------------------^--------------^" << endl << endl;
      MyFile.clear();
      MyFile.close();
      truncateBillFile();
   }
   

   void PosApp::addToBill(Item& I) {
      fstream MyFile;
      int qty;
      qty = I.quantity();
      MyFile.open(m_billfname, ios::out | ios::app);
      if (MyFile.fail()) {
         MyFile.open(m_billfname, ios::out);
      }
      I.quantity(1);
      I.save(MyFile);
      I.quantity(qty - 1);
      saveRecs();
   }

   void PosApp::POS() {
      char sku[101];
      sku[0] = '\0';
      int find;
      fstream MyFile;
      MyFile.open(m_billfname, ios::out | ios::app);
      if (!MyFile) {
         MyFile.open(m_billfname, ios::out);
      }
      while(cout << "Sku: " && cin.getline(sku,101) && strlen(sku) != 0) {
         find = searchItems(sku);
         if (find == -1) {
            cout << "Not found!" << endl;
         }
         else {
            cout << "v------------------->" << endl << "| "
                 << m_items[find]->name() << endl
                 << "^------------------->" << endl;
            
            addToBill(*m_items[find]);
         }
      }
      MyFile.close();
      showBill();
   }

   void PosApp::run() {
      loadRecs();
      int choice;
      do {
         int chk;
         cin.clear();
         fflush(stdin);
         chk = menu();
         choice = chk;
         switch (chk) {
         
         case 1:

            listItems();

            break;
         
         case 2:

            addItem(true);

            break;
         
         case 3:
            addItem(false);
            break;
         
         case 4:
            
            //update item
            updateQty();

            break;

         case 5:

            //search item.
            char sk[100];
            sk[0] = '\0';
            cout << "Please enter the SKU: ";
            cin >> sk;
            int find;
            find = searchItems(sk);
            if (find == -1) {
               cout << "Not found!" << endl;
            }
            else {
               cout << "v-----------------------------------v" << endl;
               m_items[find]->write(cout, false);
               cout << "^-----------------------------------^" << endl;
               cout << endl;
            }

            break;
         
         case 6:

            POS();

            break;
         
         case 0:

            cout <<endl <<"Goodbye!" << endl;

            break;

         default:

            cout << "===Invalid Selection, try again===" << endl << endl;

            break;

         }
      } while (choice != 0);



   }

}

/*
ouputs:
-------------------------------------
update:
Please enter the SKU: 1313
Name:
Paper Tissue
Sku: 1313
Price: 1.22
Price after tax: 1.38
Quantity: 194
Total Cost: 267.45

Please enter the number of purchased items: 12
Updated!

------------------------------
Please enter the SKU: 3434
Not found!

-------------------------------------
add item:
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 1200/10/12
Invalid Year in Date Entry

Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 2017/5/15
Item added.

--------------------------------------------
list item:
 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
-----|--------|--------------------|-------|---|----|---------|
   1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
   2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
   3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
   4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
   5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
   6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
-----^--------^--------------------^-------^---^----^---------^
                               Total Asset: $  |       1436.59|
-----------------------------------------------^--------------^


--------------------------------------
printbill:
v--------------------------------------------------------v
| 2017/04/02, 12:42                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         22.05|
^-----------------------------------------^--------------^

-------------------------------------------------------
POS:
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1313
v------------------->
| Paper Tissue
^------------------->
Sku: 1234
v------------------->
| Milk
^------------------->
Sku: 7654
Not found!
Sku: 5656
v------------------->
| Honey
^------------------->
Sku:
v--------------------------------------------------------v
| 2017/04/02, 12:58                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 1234   |Milk                |   3.99|  P|   1|     3.99|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         32.03|
^-----------------------------------------^--------------^

------------------------------------------------------
run:
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 5656
v-----------------------------------v
Name:
Honey
Sku: 5656
Price: 12.99
Price after tax: 14.68
Quantity: 10
Total Cost: 146.79
Expiry date: 2017/05/15
^-----------------------------------^

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 12345
Not found!

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> five

===Invalid Selection, try again===

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 0

Goodbye!

*/