//
//  Customer.cpp
//  Assignment4
//
//  Created by Diana Gutierrez on 3/6/20.
//  Copyright © 2020 Diana Gutierrez. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Customer.h"
using namespace std;

Customer::Customer(){
    firstName = "";
    lastName = "";
    customerID = 0;
}

Customer::Customer(string first, string last, int ID){
    firstName = first;
    lastName = last;
    customerID = ID;
}

Customer::~Customer(){
    
}

int Customer::getID()const{
    return customerID;
}

string Customer::getName() const{
    return firstName + " " + lastName;
}

string Customer::getFirst()const{
    return firstName;
}

string Customer::getLast() const{
    return lastName;
}

