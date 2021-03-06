// MedianFilter.h
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


#ifndef MEDIANFILT_H
#define MEDIANFILT_H


constexpr int MAX_POINTS = 10;  // Max. number of points to store for filter


class MedianFilter
{
    public:
        MedianFilter(int windowWidth = 3);
        float Update(float newPoint);
        int GetWindowSize();
        float* GetWindow();
    protected:
    private:
        int N;
        int insertIndex;
        float dataPoints[MAX_POINTS];
};


#endif  // MEDIANFILT_H
