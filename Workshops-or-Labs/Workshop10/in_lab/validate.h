#ifndef ICT_VALIDATE_H_
#define ICT_VALIDATE_H_
namespace ict{
   template <class myType> bool validate(const myType& a,const myType& b,const myType* c,int d,bool* e) {
      int i;
      bool rtn = false;
      int cont = 0;
      for (i = 0;i < d;i++) {
         if (c[i] >= a && c[i] <= b) {
            e[i] = true;
            cont++;
         }
         else {
            e[i] = false;
            cont--;
         }

      }
      if (cont == d) {
         rtn = true;
      }
      else {
         rtn = false;
      }
      return rtn;
   }
}
#endif