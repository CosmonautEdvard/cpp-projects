#pragma once

// Conversion declarations
double dbToLinear(double dB);

double linearToDb(double gain);

double dbuToVolts(double dBu);

double voltsToDbu(double volts);

double distanceToDelay(double meters, double tempC);

double frequencyToPeriod(double Hz);

double midiToFrequency(int note);

int frequencyToMidi(double Hz);