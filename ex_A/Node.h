/**
 *  File Name: Node.h
 *  Assignment: ENSF 694 Summer 2024 - Lab 5 Exercise A
 *  Created by: Mahmood Moussavi on 2024-05-25
 *  Completed by: Yael Gonzalez
 *  Submission Date: August 2, 2024
 */

#ifndef Node_h
#define Node_h
#include "Flight.h"

class Node
{
public:
    Flight data;
    Node *next;

    Node(const Flight &data) : data(data), next(nullptr) {}
};
#endif /* Node_h */
