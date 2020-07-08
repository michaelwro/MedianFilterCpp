// main.cpp
// ----------------------------------------------------------------------------
// Developing a simple median filter library for C++ and plotting it with
// matplotlibcpp.h (See References).
//
// Author: Michael Wrona
// Created: 08 July 2020
// ----------------------------------------------------------------------------
/**
 * References:
 * ~ Generating Random Numbers, cppreference.com:
 *     https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
 * ~ matplotlibcpp C++ plotting library, GitHub User lava:
 *     https://github.com/lava/matplotlib-cpp
 * 
 * Compile Commands (or use makefile):
 *   $ g++ -std=c++11 -c MedianFilter.cpp
 *   $ g++ main.cpp MedianFilter.o -std=c++11 -I/usr/include/python2.7 -lpython2.7 -o runme
 *   $ ./runme
 *   $ open noisy-vs-smoothed.png  # Open the output plot
 */
// ----------------------------------------------------------------------------


#define WITHOUT_NUMPY  // For matplotlibcpp.h

#include <cmath>
#include <random>
#include <cstdlib>
#include <iostream>
#include "MedianFilter.h"
#include "matplotlibcpp.h"  // Header from: https://github.com/lava/matplotlib-cpp


constexpr float PI = 3.141593;  // PI constant
namespace plt = matplotlibcpp;


// Simple class to generate random numbers
class RandNum
{
    public:
        float lowerBd = -1.0;
        float upperBd = 1.0;
        RandNum(float low, float up) {
            this->lowerBd = low;
            this->upperBd = up;
        }
        float Get() {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<float> dis(this->lowerBd, this->upperBd);
            return dis(gen);
        }
};


int main(int argc, char **argv)
{
    // Define simulation constants
    int filtWindowSize  = 5;  // Number of points to use in median filter
    float TSIM  = 5.0f;  // Time to simulate data
    float DT    = 0.01f;  // Time step, [sec]
    int N       = (int) (TSIM / DT);  // Number of data points


    // Define variables
    // Store noisy data, smoothed data, and time steps in a vector
    std::vector<float> noisyData(N), smoothedData(N), TIME(N);

    float SIMTIME;  // Simulation time elapsed, [sec]
    float reading;  // Sensor reading, noisy parameter
    float smoothedReading;  // Output after applying median filter

    // Create classes
    MedianFilter MedianFilt(filtWindowSize);  // Median filter class
    RandNum Noise(-1.0f, 1.0f);  // Random number generator, [-1, 1]


    // Simulate!
    SIMTIME = 0.0f;
    for (int i = 0; i < N; i++)
    {
        // Record 'noisy' data and smooth it
        reading = (3.0f * sinf(2.0f * PI * 2.0f * SIMTIME)) + (0.8f * Noise.Get()) + SIMTIME;
        smoothedReading = MedianFilt.Update(reading);  // Apply filter

        // Record/store data
        noisyData.at(i) = reading;
        smoothedData.at(i) = smoothedReading;
        TIME.at(i) = SIMTIME;
        SIMTIME += DT;
    }


    // Plot results
    plt::figure_size(720, 480);
    plt::named_plot("Noisy Data", TIME, noisyData);
    plt::named_plot("Smoothed Data", TIME, smoothedData);
    plt::title("Noisy vs. Filtered Data");
    plt::xlabel("Time [sec]");
    plt::ylabel("Amplitude");
    plt::grid(true);
    plt::legend();
    plt::save("noisy-vs-smoothed.png");


    std::cout << "Program Complete!" << std::endl;
    return 0;
}

