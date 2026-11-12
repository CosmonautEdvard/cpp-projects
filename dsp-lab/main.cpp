   #include <iostream>
   #include "conversions.h"
   #include "dsp.h"

   int main(){

std::vector<float> wave = generateSine(441.0, 1.0, 1.0, 44100.0);

std::cout << "Number of samples: " << wave.size() << '\n';
std::cout << "Sample 0:  " << wave[0]  << '\n';
std::cout << "Sample 25: " << wave[25] << '\n';
std::cout << "Sample 50: " << wave[50] << '\n';
std::cout << "Sample 75: " << wave[75] << '\n';


   }