#include <iostream>
#include <limits>
#include "conversions.h"


// Type and range check for cin int
int readInt(int lowerLimit, int upperLimit){
    int input {};    

    while(!(std::cin >> input) || input > upperLimit || input < lowerLimit){

                if(std::cin.fail()){
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Enter a number between " << lowerLimit << " and " << upperLimit << '\n' << std::endl;
              }
    return input;
}

// Type and range chech for cin double
double readDouble(double lowerLimit, double upperLimit){
    double input {};    

    while(!(std::cin >> input) || input > upperLimit || input < lowerLimit){

                if(std::cin.fail()){
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Enter a numeric value between " << lowerLimit << " and " << upperLimit << '\n' << std::endl;
              }
    return input;
}

// Check if the user wants to continue using the program (update condition for the keepRunning for loop)
int keepRunningCheck(){
    
    std::cout << "Do you want to return to the main menu? \n" 
              << "1 Yes \n" 
              << "0 No  \n" << std::endl;
    
    return readInt(0, 1);
}


//Main menu function
int mainMenu(){

    // Printout of the program title and a call to choose the conversion
    std::cout << "-------------------             \n" 
              << "-- AUDIO TOOLKIT --             \n" 
              << "-------------------           \n\n"

              << "CHOOSE CONVERSION:            \n\n" 

              << "1 dB -> linear gain             \n" 
              << "2 Linear gain -> dB             \n" 
              << "3 dBu -> volts                  \n" 
              << "4 Volts -> dBu                  \n" 
              << "5 Distance (m) -> delay (ms)    \n" 
              << "6 Frequency (Hz) -> period (ms) \n" 
              << "7 MIDI note -> frequency (Hz)   \n" 
              << "8 Frequency (Hz) -> MIDI note   \n" 
              << "0 Quit" << '\n' << std::endl;

        return readInt(0,8);
}


// Functions for menu options

void runDbToLinear(){
    std::cout << "1 dB -> Linear Gain, enter dB value to be converted: \n\n";
    double dB = readDouble(-140, 90);
    std::cout << dB << " dB is " << dbToLinear(dB) << " Voltage/Amplitude linear gain" << "\n\n";
}

void runLinearToDb(){
    std::cout << "2 Linear gain -> dB, enter linear gain value to be converted:" << "\n\n";
    double linearGain = readDouble(0.001, 35000);
    std::cout << linearGain << " Voltage/Amplitude linear gain is " << linearToDb(linearGain) << " dB" << "\n\n";
}

void runDbuToVolts(){
    std::cout << "3 dBu -> volts, enter dBu value to be converted:" << "\n\n";
    double dBu = readDouble(-140, 90);
    std::cout << dBu << " dBu is " << dbuToVolts(dBu) << " volts" << "\n\n";
}

void runVoltsToDbu(){
    std::cout << "4 Volts -> dBu, enter volts value to be converted:" << "\n\n";
    double volts = readDouble(0.001, 35000);
    std::cout << volts << " volts is " << voltsToDbu(volts) << " dBu" << "\n\n";
}

void runDistanceToDelay(){
    std::cout << "5 Distance (m) -> delay (ms), enter distance (m) value to be converted:" << "\n\n";
    double distanceM = readDouble(0, 35000);
    std::cout << "What is the ambient temperature in celsius?" << "\n\n";
    double tempC = readDouble(-60, 60);
    std::cout << distanceM << " m corresponds to a " << distanceToDelay(distanceM, tempC) << " ms delay at " << tempC << " C" << "\n\n";
}

void runFrequencyToPeriod(){
    std::cout << "6 Frequency (Hz) -> period (ms), enter frequency (Hz) to be converted:" << "\n\n";
    double Hz = readDouble(1, 22000);
    std::cout << Hz << " Hz wave has a period of " << frequencyToPeriod(Hz) << " ms" << "\n\n";
}

void runMidiToFrequency(){
    std::cout << "7 MIDI note -> frequency (Hz), enter a MIDI note (0-127) to be converted:" << "\n\n";
    int note = readInt(0, 127);
    std::cout << note << " note has a frequency of " << midiToFrequency(note) << " Hz" << "\n\n";
}

void runFrequencyToMidi(){
    std::cout << "8 Frequency (Hz) -> MIDI note, enter frequency (Hz) to be converted:" << "\n\n";
    double Hz = readDouble(8, 12543);
    std::cout << Hz << " Hz is closest to " << frequencyToMidi(Hz) << " MIDI note" << "\n\n";
}



int main(){

std::cout << std::fixed;
std::cout.precision(3);

// For loop that keeps the user's choice to return to the main menu or to quit
    for(int keepRunning = 1; keepRunning != 0; keepRunning = keepRunningCheck()){

        // mainMenu prints out the conversions list and asks for a choice
        int choice = mainMenu();

        // If choice is 0 (quit) exit the program loop and skip the menuReturnCheck function
        if(choice == 0){ break; }
        
        std::cout << "\n";  // An extra empty line for better user readability

        // switch direct the other 8 choices or an invalid input
        switch(choice){
        
        case 1: runDbToLinear(); break;
        
        case 2: runLinearToDb(); break;
        
        case 3: runDbuToVolts(); break;
        
        case 4: runVoltsToDbu(); break;
        
        case 5: runDistanceToDelay(); break;
        
        case 6: runFrequencyToPeriod(); break;
        
        case 7: runMidiToFrequency(); break;
        
        case 8: runFrequencyToMidi(); break; 

        default:
        std::cout << "Undefined case" << "\n\n";

        }
    
    }

    std::cout << "\n" << "THANKS FOR USING THE AUDIO TOOLKIT!" << std::endl;
    return 0;
}



