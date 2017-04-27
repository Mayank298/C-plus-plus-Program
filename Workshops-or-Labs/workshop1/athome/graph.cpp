#include <iostream>
#include "graph.h"
#include "tools.h"
using namespace std;
using namespace sict;


   void sict::printGraph(int samples[], int noOfSamples) {
      int max = findMax(samples, noOfSamples);
      cout << "Graph:" << endl;
      for (int i = 0; i < noOfSamples; i++) {
         sict::printBar(samples[i], max);
      }
   }
   // prints a scaled bar relevant to the maximum value in samples array
   void sict::printBar(int val, int max) {
      int i;
      for (i = 0; i < 70 * val / max; i++) {
         cout << "*";
      }
      cout << " " << val << endl;
   }

   // Fills the samples array with the statistic samples
   void sict::getSamples(int samples[], int noOfSamples) {
      int i;
      for (i = 0; i < noOfSamples; i++) {
         cout << (i + 1) << "/" << noOfSamples << ": ";
         samples[i] = sict::getInt(1, 1000000);
      }
   }

   // finds the largest sample in the samples array, if it is larger than 70,
   // otherwise it will return 70.
   int sict::findMax(int samples[], int noOfSamples) {
      int max = samples[0];
      int i;
      for (i = 1; i < noOfSamples; i++) {
         if (max < samples[i]) max = samples[i];
      }
      return max < 70 ? 70 : max;
   }
