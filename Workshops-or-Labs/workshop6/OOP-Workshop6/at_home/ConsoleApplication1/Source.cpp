#include <iostream> 
#include <istream>
using namespace std;
class foo {
public:   int x;};
int main() {
   foo **fp;
   int sz;   cout << "Enter Size of the Pointer: ";   cin >> sz;      int i;   for (i = 0; i < sz; i++) {      fp[i] = new foo;      fp[i]->x = i;        }   for (i = 0; i < sz; i++) {      cout << "FP[" << i << "]->x = " << fp[i]->x << endl << i << endl;
   }   cout << "Yehhhh Its work: ";  
   delete[] fp;
   return 0;
}