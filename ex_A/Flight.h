/**
 *  File Name: Flight.h
 *  Assignment: ENSF 694 Summer 2024 - Lab 5 Exercise A
 *  Created by: Mahmood Moussavi on 2024-05-25.
 *  Completed by: Yael Gonzalez
 *  Submission Date: August 2, 2024
 */

#ifndef Flight_hpp
#define Flight_hpp
#include "Point.h"

// Flight class to represent a flight
class Flight
{
public:
    string flightNumber;
    Point origin;
    Point destination;
    string departureDate;
    string departureTime;
    int craftCapacity;

    Flight() = default;
    Flight(const string &flightNumber, const Point &origin, const Point &destination,
           const string &departureDate, const string &departureTime, int craftCapacity);
};

#endif /* Flight_hpp */
