#pragma once
#ifndef CONTACTSBOOK_H
#define CONTACTSBOOK_H
#include <iostream>
#include "Contact.h"
#include "Address.h"
using namespace std;

class ContactsBook {
public:
    Contact* contacts;
    int size;
    int count;
    ContactsBook(int size);
    ~ContactsBook();
    void addContact(Contact contact);
    void printContacts() const;
    void printContactsSortedByFirstName() const;
    void printContactsSortedByLastName() const;
    void mergeDuplicates();
    void storeToFile(const  string& filename) const;
    void loadFromFile(const  string& filename);
    int getCount() const;
    Contact& getContact(int index);
    const Contact& getContact(int index) const;

    void UpdateContact(string str_first, string str_last);
    void DeleteContact(string str_first, string str_last);


};

#endif