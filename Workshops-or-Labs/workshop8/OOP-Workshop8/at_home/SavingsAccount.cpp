#include "SavingsAccount.h"
using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
   SavingsAccount::SavingsAccount(double bal, double inper):Account(bal) {
      
      if (inper < 0) {
         m_interestRate = 0;
      }
      else {
         setBalance(bal);
         m_interestRate = inper;
      }
   }
   double SavingsAccount::calculateInterest(void) {
      return getBalance() * m_interestRate;

   }

   void SavingsAccount::display(std::ostream& ostr) {
      ostr << "Account type: Saving" << endl;
      ostr.setf(ios::fixed);
      ostr.precision(2);
      ostr << "Balance: $ " << getBalance() << endl;
      ostr << "Interest Rate (%): " << m_interestRate * 100 << endl;
   }
}