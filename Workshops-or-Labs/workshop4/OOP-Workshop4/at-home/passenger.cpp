// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "passenger.h"
// TODO: add the namespaces that you will be using here
using namespace std;
// TODO: holiday namespace here
namespace holiday {
   // TODO: add the default constructor here
   Passenger::Passenger() {
 
      setEmpty();

   }
   void Passenger::setEmpty() {
      m_name[0] = '\0';
      m_destination[0] = '\0';
      m_departureDay = 0;
      m_departureMonth = 0;
      m_departureYear = 0;
   }
   // TODO: add the constructor with 2 parameters here
   Passenger::Passenger(const char* name, const char* destination) {
      chekEmpty(name, destination, 2017, 7,1 );
   }
   void Passenger::chekEmpty(const char* name, const char* destination, int year, int month, int day) {
      if ((name != nullptr && destination != nullptr && year>=2017 && year<=2020 && month>=1 && month<=12 &&day>=1 && day<=31)) {
         strcpy(m_name, name);
         strcpy(m_destination, destination);
         m_departureDay = day;
         m_departureMonth = month;
         m_departureYear = year;
      }
      else {
         setEmpty();
      }
   }
   Passenger::Passenger(const char* name, const char* destination, int year, int month, int day) {
      chekEmpty(name, destination, year, month, day);
   }

   // TODO: add the canTravelWith(...) function here
   bool Passenger::canTravelWith(const Passenger& P) const {
      bool tmp;
      if (m_departureDay == P.m_departureDay && m_departureMonth == P.m_departureMonth 
         && m_departureYear == P.m_departureYear && strcmp(m_destination, P.m_destination) == 0) {
         tmp = true;
      }
      else {
         tmp = false;
      }
      return tmp;
   }
  
   void Passenger::travelWith(const Passenger* P, int size) const {
      int i;
      bool tmpChk;
      int cnt=0;
      for (i = 0;i < size;i++) {
         
         if (canTravelWith(P[i])) {
            cnt++;
         }
      }
      if (cnt ==0) {
         cout << "Nobody can join "<<this->m_name<<"on vacation!";
      }
      else {
      if (cnt == size) {
         cout << "Everybody can join " << this->m_name << " on vacation!" << endl <<
            this->m_name << " will be accompanied by ";
         for (i = 0;i < size;i++) {
            cout << P[i].m_name << ((i == size - 1) ? "." : ", ");

         }
      }
      else {
         cout << this->m_name << " will be accompanied by ";
         for (i = 0;i < size;i++) {
            cout << P[i].m_name << ((i == size - 1) ? "." : ", ");

         }
      }
      }
      cout << endl;
   }


   // TODO: add the isEmpty() function here
    bool Passenger::isEmpty() const {
      return m_name[0] == 0 || m_destination[0] == 0;
   }
  
   // below is the member function already provided
   // TODO: read it and understand how it accomplishes its task
   void Passenger::display() const{
      cout << this->m_name;
      cout << " will travel to " << this->m_destination << ". "
               << "The journey will start on "
               << this->m_departureYear << "-"
               << this->m_departureMonth << "-"
               << this->m_departureDay
               << "." << endl;
      
   }
    void Passenger::display(bool nameOnly) const{
      if (false == this->isEmpty()){
         cout << m_name << ", " << endl;
         if (false == nameOnly){
            cout << " will travel to " << this->m_destination << ". "
               << "The journey will start on "
               << this->m_departureYear << "-"
               << this->m_departureMonth << "-"
               << this->m_departureDay
               << "." << endl;
         }
      }
      else{
         cout << "Invalid passenger!" << endl;
      }
   }
   
}