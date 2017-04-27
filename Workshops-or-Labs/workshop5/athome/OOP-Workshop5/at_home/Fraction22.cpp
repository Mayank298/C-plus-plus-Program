#include "Fraction.h"
#include <iostream>
using namespace std;

namespace sict{
    Fraction::Fraction(){  
            denom =-1;              // safe empty state
    }
    
    Fraction::Fraction(int n, int d) // n: numerator, d: denominator
    { 
        if(n >= 0 && d > 0){
            num = n;
            denom = d;
            reduce();
        }
        else 
            denom =-1;              // set to safe empty state
    }

    int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
    {
        int mn = min();                                        // min of num and denom
        int mx = max();                                        // mX of num and denom

        for (int x=mn ; x > 0 ; x--)                           // find the greatest common divisor
            if( mx % x == 0 &&  mn % x == 0)
                return x;
        return 1;

    } 

    void Fraction::reduce()                                         // simplify the Fraction number  
    {
        int tmp = gcd();
        num /= tmp;
        denom /= tmp;
    }

    int Fraction::max ()
    {
        return (num >= denom) ? num : denom; 
    }

    int Fraction::min()
    {
        return (num >= denom) ? denom : num; 
    }
  
    // TODO: Copy-paste the implementation of member isEmpty function from the in_lab part answer HERE
    bool Fraction::isEmpty() const
    {
      return num == -1 || denom == -1 ;
	}

    // TODO: Copy-paste the implementation of member display function from the in_ab part answer HERE
    void Fraction::display() const {
      if (!isEmpty()) {
         if (denom == 1){
            cout << num;
         }
         else {
           
            cout << num << "/" << denom;
         }
      }
      else {
         cout << "Invalid Fraction Object!";
      }
	}

    // TODO: Copy-paste the implementation of member operator+= function from the in_lab part answer HERE
    Fraction Fraction:: operator+=(const Fraction& F) {
      bool chkthis = this->isEmpty();
      bool chkcurrent = F.isEmpty();

      if (chkthis != true && chkcurrent != true) {
         this->num = ((this->num * F.denom) + (F.num * this->denom));
         this->denom = (this->denom * F.denom);
      }
      int md;
      md = this->num % this->denom;
      return *this;
	}


    // TODO: Copy-paste the implementation of member operator+ function from the in_ab part answer HERE
    Fraction Fraction:: operator+(const Fraction& F)const {
      Fraction c;
      bool chkthis = this->isEmpty();
      bool chkcurrent = F.isEmpty();

      if (chkthis != true && chkcurrent != true) {
         c.num = ((this->num * F.denom) + (F.num * this->denom)) ;
         c.denom = (this->denom * F.denom);
      }
      return c;
	}
	Fraction Fraction::operator+(int a)const {
      Fraction c;
      bool chkthis = this->isEmpty();

      if (chkthis != true && a != -1) {
         c.num = ((this->num * 1) + (a * this->denom));
         c.denom = (this->denom * 1);
      }
      return c;
	}

    // TODO: Copy-paste the implementation of member operator* function from the in_lab part answer HERE
   Fraction Fraction::operator*(Fraction F)const {
      Fraction c;
      bool chkthis = this->isEmpty();
      bool chkcurrent = F.isEmpty();

      if (chkthis != true && chkcurrent != true) {
         c.num = (this->num *F.num );
         c.denom = (this->denom * F.denom);
      }
      return c;
	}

    // TODO: write the implementation of member operator== function HERE
 

   bool Fraction::operator==(const Fraction& F) const
   {
      bool rtn = false;
      Fraction fractOne, fractTwo;
      bool chkthis = this->isEmpty();
      bool chkcurrent = F.isEmpty();

      if (chkthis != true && chkcurrent != true)
      {
         fractOne.num = (this->num * F.denom);
         fractTwo.num = (this->denom * F.num);

         if (fractOne.num == fractTwo.num)
         {
            return true;
         }

         return rtn;

      }
   }

  
    // TODO: write the implementation of member operator!= function HERE
    bool Fraction::operator!=(const Fraction& F)const
    {
       bool rtn = false;
       Fraction fractionOne, fractionTwo;
       bool chkthis = this->isEmpty();
       bool chkcurrent = F.isEmpty();

       if (chkthis != true && chkcurrent != true)
       {
          fractionOne.num = (this->num * F.denom);
          fractionTwo.num = (this->denom * F.num);

          if (fractionOne.num != fractionTwo.num)
          {
             return true;
          }
       }
       return rtn;
    }
   
   // TODO: write the implementation of member operator double () function HERE
   Fraction::operator double()const {
      double tryDone = -1.0;
      bool chk1 = isEmpty();

      if (chk1 != true) {
         tryDone = double(num) / double(denom);
      }
      return tryDone;
   }

   // TODO: write the implementation of member operator double () function HERE
   Fraction::operator int()const {
      int tryDone = -1;
      bool chk1 = this->isEmpty();

      if (chk1 != true) {
         tryDone = this->num / this->denom;
      }
      return tryDone;
   }
}