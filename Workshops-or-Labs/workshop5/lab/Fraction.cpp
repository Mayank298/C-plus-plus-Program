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

    // in_lab

    // TODO: write the implementation of display function HERE
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


    // TODO: write the implementation of isEmpty function HERE
   bool Fraction::isEmpty() const {
      return num == -1 || denom == -1 ;
	}


    // TODO: write the implementation of member operator+= function HERE
	Fraction Fraction:: operator+=(const Fraction& F) {
      bool chkthis = this->isEmpty();
      bool chkcurrent = F.isEmpty();

      if (chkthis != true && chkcurrent != true) {
         this->num = ((this->num * F.denom) + (F.num * this->denom));
         this->denom = (this->denom * F.denom);
      }
      
      return *this;
	}

    
    // TODO: write the implementation of member operator+ function HERE
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

    // TODO: write the implementation of member operator* function HERE
	Fraction Fraction::operator*(Fraction& F)const {
      Fraction c;
      bool chkthis = this->isEmpty();
      bool chkcurrent = F.isEmpty();

      if (chkthis != true && chkcurrent != true) {
         c.num = (this->num *F.num );
         c.denom = (this->denom * F.denom);
      }
      return c;
	}
}