#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
   Account::Account(double bal) {
      if (bal > 0) {
         this->m_balance = bal;
      }
      else {
         this->m_balance = 1.0;
      }
   }
	// credit (add) an amount to the account balance
   void Account::credit(double ammount) {
      m_balance += ammount;
   }
	// debit (subtract) an amount from the account balance return bool 
   bool Account::debit(double a) {
      bool chk = false;
      if (m_balance > a) {
         m_balance -= a;
         chk = true;
      }
      return chk;
   }

	double Account::getBalance() const
	{
		return m_balance;
	} 

	void Account::setBalance( double newBalance )
	{
		m_balance = newBalance;
	} 
}