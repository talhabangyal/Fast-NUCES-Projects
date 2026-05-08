#include "Search.h"

//parameterised constructer
Search::Search(ContactsBook& book) : book(book) {}

//default distructer
Search::~Search() {}

//search by first name
void Search::searchByFirstName(const  string& firstName) {
    for (int i = 0; i < book.getCount(); i++) {
        if (book.getContact(i).getFirstName() == firstName) {
             cout << "Contact found: " << book.getContact(i).toString() <<  endl;
        }
    }
}

//search by last name
void Search::searchByLastName(const  string& lastName) {
    for (int i = 0; i < book.getCount(); i++) {
        if (book.getContact(i).getLastName() == lastName) {
             cout << "Contact found: " << book.getContact(i).toString() <<  endl;
        }
    }
}

//search by number
void Search::searchByPhoneNumber(const  string& phoneNumber) {
    for (int i = 0; i < book.getCount(); i++) {
        if (book.getContact(i).getPhone() == phoneNumber) {
             cout << "Contact found: " << book.getContact(i).toString() <<  endl;
        }
    }
}