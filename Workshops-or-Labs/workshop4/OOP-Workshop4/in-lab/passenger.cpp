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
      if ((name != nullptr && destination != nullptr)) {
         strcpy(m_name, name);
         strcpy(m_destination, destination);
         m_departureDay = 1;
         m_departureMonth = 7;
         m_departureYear = 2017;
      }
      else {
         setEmpty();
      }
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
         cout << this->m_name;
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