#pragma once
#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include "Address.h"
#include <sstream>
using namespace std;

class Contact {
private:
     string firstName;
     string lastName;
     string phone;
     string email;
    Address address;
public:
    Contact();
    Contact( string firstName,  string lastName,  string phone,  string email, Address address);
    ~Contact();

    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setPhone(string phone);
    void setEmail(string email);
    void setAddress(Address address);

    string getFirstName() const;
    string getLastName() const;
    string getPhone() const;
    string getEmail() const;
    Address getAddress() const;
    string toString() const;
};

#endif