// compilation safegaurds
#ifndef ICT_Date_H_
#define ICT_Date_H_
#include <iostream>
// ict namespace 
namespace ict {
   // Date defined Error values
   #define NO_ERROR 0 //No error - the date is valid
   #define CIN_FAILED 1 //istream failed on accepting information using cin
   #define YEAR_ERROR 2 //Year value is invalid
   #define MON_ERROR 3 //Month value is invalid
   #define DAY_ERROR 4 //Day value is invalid
   #define HOUR_ERROR 5 //Hour value is invalid
   #define MIN_ERROR 6 //Minute value is invalid
   class Date {
   private:
      // member variables
      int m_year;
      int m_mon;
      int m_day;
      int m_hour;
      int m_min;
      int m_readErrorCode;
      bool m_dateOnly;
     // private methods
      int value()const;
      void errCode(int errorCode);
      void set(int year, int mon, int day, int hour, int min);

   public:
      // constructors
      Date();
      Date(int year, int month, int day);
      Date(int year, int month, int day,int hour, int min = 0);
      void set();
      // operator ovrloads
      bool operator==(const Date& D)const;
      bool operator!=(const Date& D)const;
      bool operator<(const Date& D)const;
      bool operator>(const Date& D)const;
      bool operator<=(const Date& D)const;
      bool operator>=(const Date& D)const;
      // methods
      int errCode()const;
      bool bad()const;
      int mdays()const;
      void dateOnly(bool value);
      bool dateOnly()const;
      // istream  and ostream read and write methods
      std::ostream& write(std::ostream& ostr = std::cout)const;
      std::istream& read(std::istream& is = std::cin);
   };
   // operator<< and >> overload prototypes for cout and cin
  std::ostream& operator<<(std::ostream& ostr, const Date& D);
  std::istream& operator>>(std::istream& is, Date& D);
}
#endif