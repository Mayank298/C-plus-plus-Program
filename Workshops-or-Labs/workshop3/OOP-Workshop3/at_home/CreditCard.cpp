// OOP244 Workshop 3: Compound types and privacy
// File w3_in_lab.cpp
// Version 2.0
// Date 2017 / 02 / 05
// Author Raj Patel
// Description
// Revision History
///////////////////////////////////////////////////////////
// Name Date Reason
// 
////////////////////////////////////////////
///////////////
#include <iostream>
#include <cstring>
#include "CreditCard.h"


using namespace std;

namespace sict {
	void CreditCard::name(const char cardHolderName[]) {
      strcpy(m_cardHolderName, cardHolderName);
	}
	void CreditCard::initialize(unsigned long long creditCardNumber,
		int instCode, int expiryYear, int exporyMonth,
		int numberInTheBack) {
		m_cardNumber = creditCardNumber;
		m_institutioncode = instCode;
		m_expiryYear = expiryYear;
		m_expiryMonth = exporyMonth;
		m_numberInTheBack = numberInTheBack;
	}
	 void CreditCard::writeName() const{
      cout << "Cardholder: " << m_cardHolderName;
   }
   void CreditCard::writeCardInfo() const{
      cout << "Card Number: " << m_cardNumber << endl
         << "Institution: " << m_institutioncode << endl << "Expires: " << m_expiryMonth << "/" << m_expiryYear
         << endl << "Number at the back: " << m_numberInTheBack;
   }
	void CreditCard::write() const{
      if (isValid()) {
	   cout << "Cardholder: " << m_cardHolderName << endl << "Card Number: " << m_cardNumber << endl
	   << "Institution: " << m_institutioncode << endl << "Expires: " << m_expiryMonth << "/" << m_expiryYear
	   << endl << "Number at the back: " << m_numberInTheBack;
      }   
	}
  
   void CreditCard::write(bool nme) const {
      if (nme == false) {
         writeCardInfo();
      }
      else {
         write();
      }
   }
   void CreditCard::write(bool nme, bool details) const{
      if(nme==false&&details==false){
      }
      else if(nme == true && details == true){
         write();
      }
      else if (nme == true && details == false) {
         writeName();
      }
      else if(nme == false && details == true){
         writeCardInfo();
      }

   }
	bool CreditCard::isValid() const{
      bool temp;
		if (strlen(m_cardHolderName)>=1 && strlen(m_cardHolderName)<=MAX_NAME_LENGTH) {
	 if (m_cardNumber >= MIN_CARD_NUMBER && m_cardNumber <= MAX_CARD_NUMBER) {
	    if(m_institutioncode>=MIN_INST_NUMBER && m_institutioncode<=MAX_INST_NUMBER){
	       if (m_expiryYear >= MIN_EXP_YEAR && m_expiryYear <= MAX_EXP_YEAR) {
		  if (m_expiryMonth >= 1 && m_expiryMonth <= 12) {
		     if (m_numberInTheBack > 0 && m_numberInTheBack <= 999) {
			temp = true;
		     }
		     else {
			temp = false;
		     }
		  }
		  else {
		     temp = false;
		  }
	       }
	       else {
		  temp = false;
	       }
	    }
	    else {
	       temp = false;
	    }
	 }
	 else {
	    temp = false;
	 }
		}
      else {
	 temp = false;
      }
      return temp;

	}
}
