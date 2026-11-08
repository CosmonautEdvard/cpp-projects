#include "conversions.h"
#include <cmath>

// Constant variables
const double SPEED_OF_SOUND_AT_0C {331.3};
const double VOLTAGE_REFERENCE_LEVEL {0.7746};
const int    TUNING_PITCH_A4 {440};
const int    MIDI_NOTE_A4 {69};


// Conversion definitions
double dbToLinear(double dB){
    
    return std::pow(10.0, dB / 20.0);
}

double linearToDb(double gain){
    
    return 20.0 * std::log10(gain);
}

double dbuToVolts(double dBu){
    
    return VOLTAGE_REFERENCE_LEVEL * std::pow(10.0, dBu / 20.0);
}

double voltsToDbu(double volts){
    
    return 20.0 * std::log10(volts / VOLTAGE_REFERENCE_LEVEL);
}

double distanceToDelay(double meters, double tempC){

    double speedOfSoundAtC = SPEED_OF_SOUND_AT_0C + 0.606 * tempC;
    return meters / speedOfSoundAtC * 1000.0;
}

double frequencyToPeriod(double Hz){

    return 1000.0 / Hz;
}

double midiToFrequency(int note){

    return TUNING_PITCH_A4 * std::pow(2.0, (note - MIDI_NOTE_A4) / 12.0);
}

int frequencyToMidi(double Hz){

    return static_cast<int>(std::round(MIDI_NOTE_A4 + 12 * std::log2(Hz / TUNING_PITCH_A4)));
}