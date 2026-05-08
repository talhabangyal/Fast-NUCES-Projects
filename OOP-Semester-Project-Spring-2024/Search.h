#pragma once
#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
#include "ContactsBook.h"
using namespace std;

class Search {
public:
    Search(ContactsBook& book);
    ~Search();

    void searchByFirstName(const  string& firstName);
    void searchByLastName(const  string& lastName);
    void searchByPhoneNumber(const  string& phoneNumber);

private:
    ContactsBook& book;
};

#endif