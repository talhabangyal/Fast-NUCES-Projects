#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
using namespace std;

class Address {
public:
     string street;
     string country;
     string house;

    Address();
    Address( string street,  string country,  string house);
    ~Address();

    void setStreet(string street);
    void setCountry(string country);
    void setHouse(string house);

    string getStreet() const;
    string getCountry() const;
    string getHouse() const;
};

#endif