//------------------------------------------------Customer.cpp------------------------------------------------------ -
// Andrea Shirley-Bellande & Diana Gutierrez , 343C
// Created: March 6, 2020
// Last Modified: March 14, 2020 
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Implementation of the customer class
// --------------------------------------------------------------------------------------------------------------------
// Assumptions: File will be formatted correctly
// --------------------------------------------------------------------------------------------------------------------  

#include <iterator>
#include "Customer.h"

using namespace std;

// ---------------------constructor--------------------------------
// Constructor: default constructor
// preconditions: none
// postconditions: sets fname, lname, and customerID
// -------------------------------------------------------------------------
Customer::Customer() 
{
    firstName = "";
    lastName = "";
    customerID = 0;
}

// ---------------------constructor--------------------------------
// Constructor: constructor
// preconditions: none
// postconditions: sets fname, lname, and customerID
// -------------------------------------------------------------------------
Customer::Customer(string first, string last, int ID) 
{
    firstName = first;
    lastName = last;
    customerID = ID;
}

// ---------------------destructor--------------------------------
// destructor: deallocates memory
// preconditions: none
// postconditions: deallocates memory
// -----------------------------------------------------------------
Customer::~Customer() 
{

}

// ---------------------getID--------------------------------
// getID: getter for ID
// preconditions: none
// postconditions: gets the customer ID
// -----------------------------------------------------------------
int Customer::getID()const 
{
    return customerID;
}

// ---------------------getName--------------------------------
// getName:  getter for name
// preconditions: none
// postconditions: get first name and last
// -----------------------------------------------------------------
string Customer::getName() const 
{
    return firstName + " " + lastName;
}

// ---------------------getFirst--------------------------------
// getFirst: getter for first name
// preconditions: none
// postconditions: gets first name
// -----------------------------------------------------------------
string Customer::getFirst()const 
{
    return firstName;
}

// ---------------------getLast--------------------------------
// getLast: getter for last name
// preconditions: none
// postconditions: gets last name
// -----------------------------------------------------------------
string Customer::getLast() const 
{
    return lastName;
}

// ---------------------outputoperator--------------------------------
// outputoperator: produces output
// preconditions: none
// postconditions: displays output 
// -----------------------------------------------------------------
ostream & operator<<(ostream &output, const Customer &cust) 
{
    output << cust.getID() << " " << cust.firstName << " " << cust.lastName;
    return output;
}

// ---------------------setData--------------------------------
// setData: gsets data from file
// preconditions: none
// postconditions: reads data from the file
// -----------------------------------------------------------------
bool Customer::setData(istream& infile) 
{
    if (infile.eof()) 
    {
        return false;
    }
    try 
    {
        string temp;
        getline(infile, temp, ' ');
        if (temp.empty()) 
        {
            return false;
        }
        customerID = stoi(temp);
        getline(infile, firstName, ' ');
        getline(infile, lastName);
    } 
    catch (const char *msg) 
    {
        return false;
    }
    return true;       // eof function is true when eof char is read
}

// ---------------------storeHistory--------------------------------
// storeHistory: store history 
// preconditions: none
// postconditions: pushes store history
// -----------------------------------------------------------------
void Customer::storeHistory(string command) 
{
    history.push_back(command);
}

// ---------------------showhistory--------------------------------
// showhistory: shows history
// preconditions: none
// postconditions: displays history
// -----------------------------------------------------------------
void Customer::showHistory(ostream &output) 
{
    output << "History for " << getName() <<  endl;
    reverse_copy(history.begin(), history.end(), ostream_iterator<string>(output, "\n"));
    output << "-- end of history --" <<  endl;
}

// ---------------------doBorrow--------------------------------
// doBorrow: kets key for borrow
// preconditions: none
// postconditions: put and get hashkey
// -----------------------------------------------------------------
void Customer::doBorrow(Movie* movie) 
{
    if(movie) 
    {
        int qty = 1;
        if ( borrowed.retrieve(movie->getHashKey(), qty)) 
        {
            qty++;
        }
        borrowed.insert(movie->getHashKey(), qty);
    }
}

// ---------------------doReturn--------------------------------
// doReturn: gets key for return
// preconditions: none
// postconditions: put, get, and remove hashkey
// -----------------------------------------------------------------
bool Customer::doReturn(Movie *movie) 
{
    if(movie) 
    {
        int qty = 0;
        if (borrowed.retrieve(movie->getHashKey(), qty) && qty > 0) 
        {
            qty--;
            if (qty>0) 
            {
                borrowed.insert(movie->getHashKey(), qty);
            } 
            else 
            {
                borrowed.removeItem(movie->getHashKey());
            }
        } 
        else 
        {
            return false;
        }
        return true;
    }
    cerr << "Invalid movie"  <<  endl;
    return false;
}
