#pragma once
#include <vector>
#include <string>

// Declaration of Sine Wave Generator
std::vector<float> generateSine(double frequencyHz, double durationSec, double amplitude, double sampleRate);

// Declaration of Gain adjustment and Level reading functions
void applyGainDb(std::vector<float>& samples, double gainDb);
double peakLevelDb(const std::vector<float>& samples);

// File creation function
bool writeSamplesToCsv(const std::vector<float>& samples, const std::string& filename); 