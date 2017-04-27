#include <iostream>
#include "tools.h"
using namespace std;
using namespace sict;



   int sict::menu() {
      cout << "1- Number of Samples" << endl;
      cout << "2- Sample Entry" << endl;
      cout << "3- Draw Graph" << endl;
      cout << "0- Exit" << endl;
      cout << "> ";
      return sict::getInt(0, 3);
   }

   int sict::getInt(int min, int max) {
      int val;
      bool done = false;
      while (!done) {
         cin >> val;
         if (cin.fail()) {
            cin.clear();
            cout << "Invalid Integer, try again: ";
         }
         else {
            if (val < min || val > max) {
               cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
            }
            else {
               done = true;
            }
         }
         cin.ignore(1000, '\n');
      }
      return val;
   }
