#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;
#include "Date.h"
#include "POS.h"


namespace ict{
  void Date::set(){
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    m_day = lt.tm_mday;
    m_mon = lt.tm_mon + 1;
    m_year = lt.tm_year + 1900;
    if (dateOnly()){
      m_hour = m_min = 0;
    }
    else{
      m_hour = lt.tm_hour;
      m_min = lt.tm_min;
    }
  }

  int Date::value()const{
    return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
  }

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
  }

  //set the value of the class member...
  void Date::set(int year, int mon, int day, int hour, int min) {
     if (year >= MIN_YEAR && year <= MAX_YEAR) {
        m_year = year;
        if (mon >= 1 && mon <= 12) {
           m_mon = mon;
           if (day >= 1 && day <= this->mdays()) {
              m_day = day;
              if (hour > -1 && hour <= 23) {
                 m_hour = hour;
                 if (min > -1 && min <= 59) {
                    m_min = min;
                    this->errCode(NO_ERROR);
                 }
                 else {
                    this->errCode(MIN_ERROR);
                 }
              }
              else {
                 this->errCode(HOUR_ERROR);
              }
           }
           else {
              this->errCode(DAY_ERROR);
           }
        }
        else {
           this->errCode(MON_ERROR);
        }
     }
     else {
        this->errCode(YEAR_ERROR);
     }
  }
    

  //date with no argument...
  Date::Date() {
     m_dateOnly = false;
     this->set();
  }

  //date with 3 argument...

  Date::Date( int year,  int month,  int day) {
     this->m_dateOnly = true;
     this->set(year, month, day, 0, 0);
   
  }

  //date with 5 argument...

  Date::Date(int year, int month, int day, int hour, int min) {
     this->m_dateOnly = false;
     this->set(year, month, day, hour, min);

  }
  
  ///set errCode according to error of class member
  void Date::errCode(int errorCode){
     this->m_readErrorCode = errorCode;
  }

  /*
  Operator overloading functions Body
  */
  bool Date::operator==(const Date& D)const {
     return (value() == D.value());
  }

  bool Date::operator!=(const Date& D)const {
     return (value() != D.value());
  }

  bool Date::operator<(const Date& D)const {
     return (value() < D.value());
  }

  bool Date::operator>(const Date& D)const {
     return (value() > D.value());
  }

  bool Date::operator<=(const Date& D)const {
     return (value() <= D.value());
  }

  bool Date::operator>=(const Date& D)const {
     return (value() >= D.value());
  }

  int Date::errCode()const {
     return m_readErrorCode;
  }

  bool Date::bad()const {
     return (m_readErrorCode!=NO_ERROR);
  }

  void Date::dateOnly(bool value) {
     m_dateOnly = value;
     if (value) {
        m_hour = 0;
        m_min = 0;
     }
  }

  bool Date::dateOnly()const {
     return m_dateOnly;
  }
 
std::ostream& Date::write(std::ostream& ostr)const {
     if (m_dateOnly == true) {
        ostr << m_year << "/" << setfill('0') << setw(2) << m_mon << "/" << setfill('0') << setw(2) << m_day;
     }
     else {
        ostr << m_year << "/" << setfill('0') << setw(2) << m_mon << "/" << setfill('0') << setw(2) 
           << m_day << ", " << setfill('0') << setw(2) << m_hour << ":" << setfill('0') << setw(2) << m_min;
     }
     return ostr;
  }

std::istream& Date::read(std::istream& is){
   char ch[10];
   if (m_dateOnly == true) {
      is >> m_year >> ch[0] >> m_mon >> ch[1] >> m_day;
  
      if (!(is.fail())) {
         if (!(m_year >= MIN_YEAR && m_year <= MAX_YEAR)) {
            errCode(YEAR_ERROR);
         }
         else if (!(m_mon >= 1 && m_mon <= 12)) {
            errCode(MON_ERROR);
         }
         else if (!(m_day >= 1 && m_day <= mdays())) {
            errCode(DAY_ERROR);
         }
      }
      else {
         m_readErrorCode = CIN_FAILED;
      }
   }
   else {
     
      is >> m_year >> ch[0] >> m_mon >> ch[1] >> m_day >> ch[2] /*>> ch[3]*/>> m_hour >> ch[4] >> m_min;

      if (!(is.fail())) {
         if (!(m_year >= MIN_YEAR && m_year <= MAX_YEAR)) {
            errCode(YEAR_ERROR);
         }
         else if (!(m_mon >= 1 && m_mon <= 12)) {
            errCode(MON_ERROR);
         }
         else if (!(m_day >= 1 && m_day <= mdays())) {
            errCode(DAY_ERROR);
         }
         else if (!(m_hour >= 0 && m_hour <= 23)) {
            errCode(HOUR_ERROR);
         }
         else if (!(m_min >= 0 && m_min <= 59)) {
            errCode(MIN_ERROR);
         }
      }
      else {
         m_readErrorCode = CIN_FAILED;
      }
   }
     return is;
}

  ostream& operator<<(ostream& ostr, const Date& D) {
     
     return D.write(ostr);
  }
  istream& operator>>(istream& is, Date& D){
     
     return D.read(is);
  }

}
