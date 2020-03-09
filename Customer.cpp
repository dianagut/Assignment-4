//------------------------------------------------Customer.cpp------------------------------------------------------ -
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified:
// --------------------------------------------------------------------------------------------------------------------
// Purpose: 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions. 
// --------------------------------------------------------------------------------------------------------------------  

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

ostream & operator<<(ostream &output, const Customer &cust) {
    output << cust.getID() << " " << cust.firstName << " " << cust.lastName;
    return output;
}

bool Customer::setData(istream& infile) {
    std::string temp;
    std::getline(infile, temp, ' ');
    customerID = std::stoi(temp);
    std::getline(infile, firstName, ' ');
    std::getline(infile, lastName);
    return !infile.eof();       // eof function is true when eof char is read
}

void Customer::storeHistory(char t) {
   // TBD
}

void Customer::showHistory(ostream &output) {
   // TBD
}
