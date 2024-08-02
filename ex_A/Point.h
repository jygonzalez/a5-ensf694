/**
 *  File Name: Point.h
 *  Assignment: ENSF 694 Summer 2024 - Lab 5 Exercise A
 *  Created by: Mahmood Moussavi on 2024-05-25
 *  Completed by: Yael Gonzalez
 *  Submission Date: August 2, 2024
 */

#ifndef Point_h
#define Point_h
#include <string>
using namespace std;

class Point
{
public:
    string name;
    Point() = default;
    Point(const string &name);
};

#endif /* Point_h */
