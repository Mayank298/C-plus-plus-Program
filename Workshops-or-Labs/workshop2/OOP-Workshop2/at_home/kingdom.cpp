// OOP244 Workshop ??: ??????????
// File ???????
// Version 1.0
// Date 29/01/2017
// Author Raj Patel
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////


// TODO: include the necessary headers
#include <iostream>
#include <cstring>
#include "kingdom.h"
// TODO: the westeros namespace
using namespace std;
// TODO:definition for display(...) 

namespace westeros {

   void display(Kingdom k) {
      cout << k.m_name << ", population "
         << k.m_population << endl;
   }
   void display(Kingdom k[], int cnt) {
      cout << "------------------------------" << endl << "Kingdoms of Westeros" << endl
         << "------------------------------" << endl;
      int i;
      int totalPop = 0;
      for (i = 0; i < cnt; i++) {
         cout << (i + 1) << ". " << k[i].m_name << ", population "
            << k[i].m_population << endl;
         totalPop += k[i].m_population;
      }
      cout << "------------------------------" << endl << "Total population of Westeros:" << totalPop << endl <<"------------------------------" << endl;
   }
   void display(Kingdom k[], int cnt, int population) {
      cout << "------------------------------" << endl << "Kingdoms of Westeros with more than "
         << population << " people" << endl
         << "------------------------------" << endl;
      int i;
      for (i = 0; i < cnt; i++) {
         if (k[i].m_population >= population) {
            cout << k[i].m_name << ", population "
               << k[i].m_population << endl;
         }
      }
      cout << "------------------------------" << endl;
   }
   void display(Kingdom k[], int cnt, const char* kngdm) {

      cout << "------------------------------" << endl
         << "Searching for kingdom " << kngdm << " in Westeros" << endl
         << "------------------------------" << endl;
      int i;
      int temp = 0;
      for (i = 0; i < cnt; i++) {
         if (strcmp(kngdm,k[i].m_name)==0) {
            temp=temp+1;
            cout << k[i].m_name << ", population "
               << k[i].m_population << endl;
         }
      }
      if (temp == 0) {
         cout << kngdm << " is not part of Westeros." << endl;
      }
     
      cout << "------------------------------" << endl<<endl;
   }
}
