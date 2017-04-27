#ifndef ICT_CHECKINGACCOUNT_H__
#define ICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class CheckingAccount : public Account {
		private:
			double transactionFee;

			// TODO: chargeFee subtract transaction fee form the balance
         void changeFee();
		public:

			// TODO: constructor initializes balance and transaction fee
         CheckingAccount(double bal, double transaction);
			// TODO: Write a function prototype to override credit function
         virtual void credit(double ammount);
         // TODO: Write a function prototype to override debit function
         virtual bool debit(double a);
			// TODO: Write a function prototype to  override display function
         virtual void display(std::ostream& ostr);
	};
};
#endif
