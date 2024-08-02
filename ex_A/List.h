/**
 *  File Name: List.h
 *  Assignment: ENSF 694 Summer 2024 - Lab 5 Exercise A
 *  Created by: Mahmood Moussavi on 2024-05-25
 *  Completed by: Yael Gonzalez
 *  Submission Date: August 2, 2024
 */

#ifndef List_hpp
#define List_hpp
#include "Flight.h"
#include "Node.h"

// Custom List class to handle collisions
class List
{
private:
    Node *head;

public:
    List() : head(nullptr) {}
    void insert(const Flight &data);
    Flight *search(const string &flightNumber) const;
    bool isEmpty() const;
    bool contains(const string &flightNumber) const;
    void display() const;
    const Node *get_head() const;
};

#endif /* List_hpp */
