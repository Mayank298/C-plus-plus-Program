
// OOP244 Workshop 3: Compound types and privacy
// File w3_in_lab.cpp
// Version 2.0
// Date 2017 / 01 / 04
// Author Mayankkumar Patel
// Description
// Revision History
///////////////////////////////////////////////////////////
// Name Date Reason
// 
////////////////////////////////////////////
///////////////
#ifndef CREDITCARD_H
#define CREDITCARD_H

namespace sict {
#define MAX_NAME_LENGTH 41
#define MIN_INST_NUMBER 100
#define MAX_INST_NUMBER 999
#define MIN_EXP_YEAR 2017
#define MAX_EXP_YEAR 2037
#define MIN_CARD_NUMBER 4000000000000000
#define MAX_CARD_NUMBER 4000999999999999
	class CreditCard {
	private:
		char m_cardHolderName[MAX_NAME_LENGTH];
		unsigned long long m_cardNumber;
		int m_institutioncode;
		int m_expiryYear;
		int m_expiryMonth;
		int m_numberInTheBack;
      void writeName() const;
      void writeCardInfo() const;
	public:
		void name(const char cardHolderName[]);
		void initialize(unsigned long long creditCardNumber,
			int instCode, int expiryYear, int exporyMonth,
			int numberInTheBack);
		void write() const;
      void write(bool nme) const;
      void write(bool nme,bool details) const;
		bool isValid() const;
	};
}

#endif
