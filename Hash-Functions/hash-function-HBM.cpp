// /***************************************************************************************************************
// *   Programming Assignment: M03.2: Hash Table                                                                 *
// *   File: hash-function-HBM.cpp                                                                               *
// *                                                                                                             *
// *   Programmer: Hershey Marbeda                                                                               *
// *   Instructor: Dr. Carver                                                                                    *
// *   Course: CSCI 202: Data Structures and Algorithms                                                          *
// *   College: Ivy Tech Community College                                                                       *
// *   Due Date: 11.12.2024                                                                                      *
// *                                                                                                             *
// *   -------------------------------------About the Program:-------------------------------------------------   *
// *   Program Purpose:                                                                                          *
// *   The program demonstrates using a hash table with three different hash functions.                          *
// *   Last Date Updated: 11.8.2024                                                                              *
// *                                                                                                             *
// *                                                                                                             *
// *   Assignment:                                                                                               *
// *       Write definition of search, isItemAtEqual, retrieve, remove, print, constructor, and destructor       *
// *       for class hashT based upon a method of your choice from the PowerPoint or otherwise.                  *
// *       Write a test program to test with at least 3 different hashing functions.                             *
// *                                                                                                             *
// ***************************************************************************************************************/

#include <iostream>
#include <functional> // to use hash function
#include <string>

using namespace std;


class hashT
{
private:
    int key, value;
    
    hashT(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
    
public:
    hashT **table;
    int size = 1000;
    
    // Constructor
    hashT()
    {
        table = new hashT*[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = nullptr;
        }
    }
    
    // Hash Function
    int hashFunction(int key)
    {
        return key % size;
    }
    
    // Insert Element at a key
    void Insert(int key, int value)
    {
        int hash = hashFunction(key);
        
        while (table[hash] != nullptr && table[hash]->key != key)
        {
            hash = hashFunction(hash + 1);
        }
        
        if (table[hash] != nullptr)
        {
            delete table[hash];
        }
        table [hash] = new hashT(key, value);
    }
    
    // Search Element at a key
    int Search(int key)
    {
        int hash = hashFunction(key);
        
        while (table[hash] != nullptr && table[hash]->key != key)
        {
            hash = hashFunction(hash + 1);
        }
        
        if (table[hash] == nullptr)
        {
            return -1;
        }
        
        else
        {
            return table[hash]->value;
        }
    }
    
    // Remove Element at a key
    void Remove(int key)
    {
        int hash = hashFunction(key);
        
        while (table[hash] != nullptr)
        {
            if (table[hash]->key == key)
                break;
            hash = hashFunction(hash + 1);
        }
        
        if (table[hash] == nullptr)
        {
            cout << "No Element found at key " << key << endl;
            return;
        }
        
        else
        {
            delete table[hash];
        }
        
        cout << "Element Deleted" << endl;
    }
    
    
    // Destructor
    ~hashT()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i] != nullptr)
                delete table[i];
            delete[] table;
        }
    }
    
};


int main()
{
    // Table Heading
    cout << string (100, '-') << endl
         << "\t\t\t\t\t\t\t\t\tHash Function Demonstration\n"
         << "\t\t\t\t\t\t\t\t\t\t M03.2: Hash Table\n"
         << string (100, '-') << endl
         << "Welcome to the Hash Function Demonstration Program!\n\n";
    
    // Declaration of Variables
    hashT hashTable;
    int key, value;
    int choice = 0;
    
    
    do
    {
            // Menu
        cout << "\nPlease enter the number of your choice: \n"
             << "1. Insert Element\n"
             << "2. Search Element\n"
             << "3. Delete Element\n"
             << "4. Exit\n"
             << "Choice: ";
        cin >> choice;
        
            // Input Validation
        while ((cin.fail()) && (choice < 1 || choice > 4))
        {
            cin.clear();
            cin.ignore();
            cout << "\nInvalid Input. Please Enter the number of your choice: ";
            cin >> choice;
        }
        
        switch (choice)
        {
            case 1:
            {
                cout << "\nEnter element to be inserted: ";
                cin >> value;
                
                cout << "Enter key of the elemenet to be inserted: ";
                cin >> key;
                
                hashTable.Insert(key, value);
            }
                break;
                
            case 2:
            {
                cout << "\nEnter key of the elemenet to be searched: ";
                cin >> key;
                
                if (hashTable.Search(key) == -1)
                {
                    cout << "\nNo Element found at key " << key << endl;
                    break;
                }
                
                else
                {
                    cout << "\nElement at key " << key << " : ";
                    cout << hashTable.Search(key) << endl;
                }
                
            }
                break;
                
            case 3:
            {
                cout << "\nEnter key of the elemenet to be deleted: ";
                cin >> key;
                hashTable.Remove(key);
            }
                break;
                
            case 4:
                break;
                
            default:
                cout << "\nInvalid Input. Please restart the program!\n";
                break;
          
        } // end of switch
        
    } while (choice != 4);
    
    cout << "\n\n";
    return 0;
}
