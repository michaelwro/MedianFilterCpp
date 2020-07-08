// MedianFilter.cpp
// ----------------------------------------------------------------------------
// A simple median filter library for C++.
//
// ** LEGAL **
// MIT License
// 
// Copyright (c) 2020 Michael Wrona
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//
// Author: Michael Wrona
// Created: 08 July 2020
// ----------------------------------------------------------------------------


#include "MedianFilter.h"


// ----------------------------------------------------------------------------
// MedianFilter(int windowWidth)
// ----------------------------------------------------------------------------
/**
 * Constructs the median filter class. Specify the window size upon class
 * initialization.
 * 
 * @param windowWidth  Number of elements to use to compute the median, 
 *                     number of past data points to store.
 */
// ----------------------------------------------------------------------------
MedianFilter::MedianFilter(int windowWidth)
{
    // Update window size (N) if input is given
    // N = windowWidth if less than MAX_POINTS. Otherwise, use MAX_POINTS
    this->N = (windowWidth < MAX_POINTS) ? windowWidth : MAX_POINTS;
    this->insertIndex = 0;  // Begin at zero
    
    // Set data array to zeros
    for (int i = 0; i < this->N; i++)
        this->dataPoints[i] = 0.0f;
}


// ----------------------------------------------------------------------------
// Update(float newPoint)
// ----------------------------------------------------------------------------
/**
 * Add point to median filter and return filtered value.
 * 
 * @param newPoint  Noisy point to filter.
 * @return          Median-filtered value.
 */
// ----------------------------------------------------------------------------
float MedianFilter::Update(float newPoint)
{
    float filtValue;  // Filtered/smoothed value to output
    
    // Insert new value into window, update window index
    this->dataPoints[this->insertIndex] = newPoint;
    this->insertIndex = (this->insertIndex + 1) % this->N;

    // Compute mean/average of values in window
    filtValue = 0.0f;
    for (int i = 0; i < this->N; i++)
        filtValue = filtValue + this->dataPoints[i];
    
    return (filtValue / this->N);
}


// ----------------------------------------------------------------------------
// GetWindowSize()
// ----------------------------------------------------------------------------
/**
 * Return median filter window width.
 * @return  Median filter window width.
 */
// ----------------------------------------------------------------------------
int MedianFilter::GetWindowSize()
{
    return this->N;
}


// ----------------------------------------------------------------------------
// GetWindow()
// ----------------------------------------------------------------------------
/**
 * Return pointer to median filter past values/window.
 * @return  Pointer to median filter past values/window.
 */
// ----------------------------------------------------------------------------
float* MedianFilter::GetWindow()
{
    return this->dataPoints;
}
