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


// TODO: header safeguards

#ifndef westeros_kingdom_H_
#define westeros_kingdom_H_


// TODO: westeros namespace
namespace westeros {
   struct Kingdom{ 
      char m_name[32];
      int m_population;
   };
   void display(Kingdom k);
   void display(Kingdom k[], int cnt);
   void display(Kingdom k[], int cnt, int population);
   void display(Kingdom k[], int cnt, const char* city);



}
#endif 


// TODO: define the class Kingdom in the westeros namespace

// TODO: add the declaration for the function display(...),
//         also in the westeros namespace

