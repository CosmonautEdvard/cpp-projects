cmake_minimum_required(VERSION 3.22)
project(AudioToolkit)

add_executable(audioToolkit
    audioToolkit.cpp 
    conversions.cpp 
    input.cpp 
)

target_compile_features(audioToolkit PRIVATE cxx_std_17)

target_compile_options(audioToolkit PRIVATE -Wall -Wextra)