/**
 *  File Name: Flight.cpp
 *  Assignment: ENSF 694 Summer 2024 - Lab 5 Exercise A
 *  Created by: Mahmood Moussavi on 2024-05-25.
 *  Completed by: Yael Gonzalez
 *  Submission Date: August 2, 2024
 */
#include "Point.h"
#include "Flight.h"
Flight::Flight(const string &flightNumber, const Point &origin, const Point &destination,
               const string &departureDate, const string &departureTime, int craftCapacity)
    : flightNumber(flightNumber), origin(origin), destination(destination),
      departureDate(departureDate), departureTime(departureTime), craftCapacity(craftCapacity)
{
}
