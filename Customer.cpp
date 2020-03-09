//------------------------------------------------Customer.cpp------------------------------------------------------ -
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions. 
// --------------------------------------------------------------------------------------------------------------------  

#include <stdio.h>
#include <string>
#include "Customer.h"
using namespace std;

Customer::Customer() {
    firstName = "";
    lastName = "";
    customerID = 0;
}

Customer::Customer(string first, string last, int ID) {
    firstName = first;
    lastName = last;
    customerID = ID;
}

Customer::~Customer() {

}

int Customer::getID()const {
    return customerID;
}

string Customer::getName() const {
    return firstName + " " + lastName;
}

string Customer::getFirst()const {
    return firstName;
}

string Customer::getLast() const {
    return lastName;
}
