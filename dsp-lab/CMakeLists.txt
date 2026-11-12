cmake_minimum_required(VERSION 3.22)
project(DSP_Lab)

add_executable(dspLab
    main.cpp 
    ../audio-toolkit/conversions.cpp 
)

target_compile_features(dspLab PRIVATE cxx_std_17)

target_compile_options(dspLab PRIVATE -Wall -Wextra)

target_include_directories(dspLab PRIVATE ../audio-toolkit)