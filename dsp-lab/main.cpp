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

std::cout << "Peak: " << peakLevelDb(wave) << " dB\n";           // about 0
applyGainDb(wave, -6.0);
std::cout << "Peak after -6 dB: " << peakLevelDb(wave) << " dB\n"; // about -6.02

std::vector<float> silence(100);
silence[10] = -0.5f;
std::cout << "Silence: " << peakLevelDb(silence) << " dB\n";       // -90


   }