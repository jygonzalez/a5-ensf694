/**
 *  File Name: HashTable.cpp
 *  Assignment: ENSF 694 Summer 2024 - Lab 5 Exercise A
 *  Created by: Mahmood Moussavi
 *  Completed by: Yael Gonzalez
 *  Submission Date: August 2, 2024
 */
#include "HashTable.h"
#include <cmath>
#include <iostream>

// Implemented using Knuth's Multiplicative Method
unsigned int HashTable::hashFunction(const string &flightNumber) const
{
    const double A = (sqrt(5) - 1) / 2; // Knuth's constant
    unsigned int sum = 0;

    for (auto &ch : flightNumber)
    {
        sum += (unsigned int)ch;
    }
    double fractionalPart = sum * A - floor(sum * A); // Same as (sum * A) % 1
    return floor(tableSize * fractionalPart);
}

HashTable::HashTable(unsigned int size) : tableSize(size), numberOfRecords(0)
{
    table.resize(size);
}

void HashTable::insert(const Flight &flight)
{
    table.at(hashFunction(flight.flightNumber)).insert(flight);
    numberOfRecords++;
}

bool HashTable::insertFirstPass(const Flight &flight)
{
    unsigned int index = hashFunction(flight.flightNumber);
    if (table.at(index).isEmpty())
    {
        table.at(index).insert(flight);
        numberOfRecords++;
        return true;
    }
    return false;
}

void HashTable::insertSecondPass(const Flight &flight)
{
    insert(flight);
}

Flight *HashTable::search(const string &flightNumber) const
{
    return table.at(hashFunction(flightNumber)).search(flightNumber);
}

double HashTable::calculatePackingDensity() const
{
    return (double)numberOfRecords / tableSize;
}

double HashTable::calculateHashEfficiency() const
{
    int numberOfReads = 0;
    for (const auto &list : table)
    {
        const Node *curr = list.get_head();
        for (int i = 1; curr != nullptr; i++)
        {
            numberOfReads += i;
            curr = curr->next;
        }
    }
    double averageReads = (double)numberOfReads / numberOfRecords;
    return calculatePackingDensity() / averageReads;
}

void HashTable::display() const
{
    for (unsigned int i = 0; i < tableSize; i++)
    {
        if (!table.at(i).isEmpty())
        {
            cout << "Bucket " << i << ":" << endl;
            table.at(i).display();
        }
    }
}
