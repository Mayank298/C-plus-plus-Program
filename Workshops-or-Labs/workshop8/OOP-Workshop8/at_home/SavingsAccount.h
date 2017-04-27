#ifndef ICT_SAVINGSACCOUNT_H__
#define ICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class SavingsAccount : public Account{
		private:
    		double m_interestRate; // interest rate (percentage)
		public:
			// TODO: put prototypes here
         SavingsAccount(double bal, double inper);
         double calculateInterest();
         virtual void display(std::ostream& ostr);
   };
};
#endif
