#include <iostream>
#include <limits>
#include <cmath>


int main(){



int choice {1};

std::cout << std::fixed;
std::cout.precision(3);

while(choice != 0){

    
    // Printout of the program title and a call to choose the conversion
    std::cout << "-------------------" << '\n' 
              << "-- AUDIO TOOLKIT --" << '\n' 
              << "-------------------" << '\n' << '\n' 
              << "CHOOSE CONVERSION:" << '\n' << '\n'
              << "1. dB -> linear gain" << '\n'
              << "2. Linear gain -> dB" << '\n'
              << "3. dBu -> volts" << '\n'
              << "4. Volts -> dBu" << '\n'
              << "5. Distance (m) -> delay (ms)" << '\n'
              << "6. Frequency (Hz) -> period (ms)" << '\n'
              << "7. MIDI note -> frequency (Hz)" << '\n'
              << "8. Frequency (Hz) -> MIDI note" << '\n'
              << "0. Quit" << '\n' << std::endl;


    // Represents the choices 0-8 and rejects invalid inputs
    while(!(std::cin >> choice) || choice > 8 || choice < 0){

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        std::cout << "Invalid input, enter number corresponding to the choice" << std::endl;
    }

        // 1st choice
        if(choice == 1){
            std::cout << '\n' << "You chose dB -> linear gain, Enter dB value:" << '\n' << std::endl;

            double dB {};
            // Function for failing non type inputs, such as text
            while(!(std::cin >> dB)){

                if(std::cin.fail()){
                 std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << '\n' << "Invalid input, enter a numerical value" << '\n' << std::endl;
                }

            // Conversion equation
            double linearGain = std::pow(10.0, dB / 20.0);
            std::cout << dB << " dB = " << linearGain << " (linear)" << '\n' << std::endl;

        }
        
        // 2nd choice 
        if(choice == 2){
            
            std::cout << "You chose Linear gain -> dB, Enter gain value:" << '\n' << std::endl;

            double gain {};
            while(!(std::cin >> gain) || gain <= 0){

                 if(std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Invalid input, enter a value higher than 0" << '\n' << std::endl;      
            }

            double dB = 20.0 * std::log10(gain);
            std::cout << gain << " (linear) = " << dB << " dB" << '\n' << std::endl;
        }

        // 3rd choice
        if(choice == 3){
            
            std::cout << "You chose dBu -> volts, Enter dBu value:" << '\n' << std::endl;

            double dBu {};
            while(!(std::cin >> dBu)){

                if(std::cin.fail()){
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            std::cout << "Invalid input, enter a numeric value" << '\n' << std::endl;      
            }

            double volts = 0.7746 * std::pow(10, dBu / 20.0);
            std::cout << dBu << " dBu = " << volts << " V" << '\n' << std::endl;

        }

        // 4th choice
        if(choice == 4){

            std::cout << "You chose Volts -> dBu, Enter volts value:" << '\n' << std::endl;

            double volts {};
            while(!(std::cin >> volts) || volts <= 0){

                    if(std::cin.fail()){
                       std::cin.clear();
                       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                std::cout << "Invalid input, enter a number higher than 0" << '\n' << std::endl;      
            }

            double dBu = 20 * std::log10(volts / 0.7746);
            std::cout << volts << " V = " << dBu << " dBu" << '\n' << std::endl;
        }

        // 5th choice
        if(choice == 5){

            std::cout << "You chose Distance (m) -> delay (ms), Enter distance value:" << '\n' << std::endl;

            double distance {};
            while(!(std::cin >> distance) || distance <= 0){

                if(std::cin.fail()){
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Invalid input, enter a distance higher than 0" << '\n' << std::endl;      
            }
            
            std::cout << "For higher accuracy include the temperature value (Celsius):" << '\n' << std::endl;
            
            double temp {};
            while(!(std::cin >> temp) || temp < -273){

                if(std::cin.fail()){
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Invalid input, come on enter a realistic temperature" << '\n' << std::endl;
            }

            double speedOfSound = 331.3 + 0.606 * temp;
            double delay = distance / speedOfSound * 1000.0;
            std::cout << distance << " m = " << delay << " ms" << " at " << temp << " degrees celsius" << '\n' << std::endl;
        }

        // 6th choice
        if(choice == 6){

            std::cout << "You chose Frequency (Hz) -> period (ms), Enter Frequency value:" << '\n' << std::endl;

            double Hz {};
            while(!(std::cin >> Hz) || Hz <= 0){

                if(std::cin.fail()){
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Invalid input, enter a frequency higher than 0" << '\n' << std::endl;      
            }
    
            double period = 1000.0 / Hz;
            std::cout << Hz << " Hz has a " << period << " ms period" << '\n' << std::endl;
        }

        // 7th choice
        if(choice == 7){

            std::cout << "You chose MIDI Note -> Frequency (Hz), Enter MIDI Note (0-127):" << '\n' << std::endl;

            int note {};
            while(!(std::cin >> note) || note < 0 || note > 127){

                if(std::cin.fail()){
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            std::cout << "Invalid input, enter a MIDI Note in the range 0-127" << '\n' << std::endl;      
            }
    
            double Hz = 440 * std::pow(2.0, (note - 69) / 12.0);
            std::cout << note << " note has a frequency of " << Hz << " Hz" << '\n' << std::endl;

        }

        // 8th choice
        if(choice == 8){

            std::cout << "You chose Frequency (Hz) -> MIDI note, Enter frequency (8 - 12 543 Hz):" << '\n' << std::endl;

            double Hz {};
            while(!(std::cin >> Hz) || Hz < 8 || Hz > 12543){

                if(std::cin.fail()){
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Invalid input, enter a frequency within 8 - 12 543" << '\n' << std::endl;      
            }
    
            int note = static_cast<int>(std::round(69 + 12 * std::log2(Hz / 440.0)));
            std::cout << Hz << " Hz is or is closest to " << note << " MIDI note" << '\n' << std::endl;
        }

        // Prompt to return to the main menu or close the program
        if(choice != 0){        
        std::cout << "Do you want to return to the main menu?" << '\n' 
                  << "1 Yes" << '\n'
                  << "0 No" << '\n' << std::endl;
        
            while(!(std::cin >> choice) || choice > 1 || choice < 0){

             if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        
            std::cout << "Invalid input, enter 1 to return to the menu or 0 to quit" << std::endl;
            }
        }

    }

    std::cout << "THANKS FOR USING THE AUDIO TOOLKIT!" << std::endl;

    return 0;
}



