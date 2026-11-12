#include "dsp.h"
#include <cmath>
#include "conversions.h"

const double PI {3.14159265358979323846};
const double NOISE_FLOOR_DB {-90.0};

std::vector<float> generateSine(double frequencyHz, double durationSec, double amplitude, double sampleRate){

    std::size_t numSamples = static_cast<std::size_t>(sampleRate * durationSec);
    
    std::vector<float> samples(numSamples); 

    for(std::size_t n = 0; n < samples.size(); ++n){
    samples[n] = static_cast<float>(amplitude * std::sin(2*PI * frequencyHz * static_cast<double>(n) / sampleRate));
    }



    // double peakLevelDb(const std::vector<float>& samples);



    return samples;

}


void applyGainDb(std::vector<float>& samples, double gainDb){

    double gain = dbToLinear(gainDb);

    for(std::size_t n = 0; n < samples.size(); ++n){
        samples[n] = static_cast<float>(samples[n] * gain); 
    }     
        
}




double peakLevelDb(const std::vector<float>& samples){

    float peak = 0.0f;

    for(std::size_t n = 0; n < samples.size(); n++){
        
        if (std::abs(samples[n]) > peak){
            peak = std::abs(samples[n]);
        }
    }

    if (peak < dbToLinear(NOISE_FLOOR_DB)){
        return NOISE_FLOOR_DB;
    }


    return linearToDb(peak);
}


