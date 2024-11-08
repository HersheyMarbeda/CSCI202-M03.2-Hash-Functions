/*
    Programming Assignment: M03.2: Hash Table
    File: hash-function-HBM.cpp
    
    Programmer: Hershey Marbeda
    Instructor: Dr. Carver
    Course: CSCI 202: Data Structures and Algorithms
    College: Ivy Tech Community College
    Due Date: 11.12.2024
 
    ------------About the Program:--------------
    Program Purpose:
    The program demonstrates the use of hash table with three different hash functions.
 
 
 
 Assignment:
    Write definition of search, isItemAtEqual, retrieve, remove, print, constructor, and destructor
    for class hashT based upon a method of your choice from the powerpoint or otherwise.
    Write a test program to test with at least 3 different hashing functions.
 */



#include <iostream>
#include <functional> // to use hash function
#include <string>

using namespace std;

size_t custom_hash(const string& str)
{
    size_t hash = 0;
    for (char c : str)
    {
        hash = hash * 31 + c;
    }
    return hash;
}

int main()
{
    cout << "Example Hash: " << custom_hash("Hello World") << endl << endl;
    return 0;
}
