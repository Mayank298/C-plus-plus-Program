//TODO: add header guards here
#ifndef passenger_H
#define passenger_H
// TODO: holiday namespace here
namespace holiday {
   // TODO: declare the class Passenger here

   class Passenger {
   private:
      char m_name[32];
      char m_destination[32];
      int m_departureYear;
      int m_departureMonth;
      int m_departureDay;
      void setEmpty();
      void chekEmpty(const char* name, const char* destination,int year, int month, int day);
   public:
      Passenger();
      Passenger(const char* name, const char* destination);
      Passenger(const char* name, const char* destination, int year, int month, int day);
      void display(bool nameOnly) const;
      bool isEmpty() const;
      bool canTravelWith(const Passenger& P) const;
      void travelWith(const Passenger* P, int size) const;

      void display()const;
      
      // TODO: add the class the attributes,
      
      //       the member function already provided,
      
      //       and the member functions that you must implement


   };

}
#endif
