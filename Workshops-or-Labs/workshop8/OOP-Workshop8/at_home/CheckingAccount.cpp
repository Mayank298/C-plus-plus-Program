#include "CheckingAccount.h"

using namespace std;

namespace ict{    
	
	// TODO: define CheckingAccount class member functions here  
   void CheckingAccount::changeFee() {
      double bal;
      bal = this->getBalance() - this->transactionFee;
      this->setBalance(bal);
   }
   CheckingAccount::CheckingAccount(double bal, double transaction) : Account(bal) {
      if (transaction < 0) {
         transactionFee = 0;
      }
      else {
         transactionFee = transaction;
      }
   }
   void CheckingAccount::credit(double ammount) {
      Account::credit(ammount);
      changeFee();
   }
   bool CheckingAccount::debit(double a) {
      bool chk = false;
      if (this->transactionFee > 0 && Account::debit(a)) {
         chk = true;
         changeFee();
      }
      return chk;
   }
   void CheckingAccount::display(std::ostream& ostr) {
      ostr << "Account type: Checking" << endl;
      ostr.setf(ios::fixed);
      ostr.precision(2);
      ostr << "Balance: $ " << getBalance() << endl;
      ostr << "Transaction Fee: " << transactionFee<< endl;
   }

}