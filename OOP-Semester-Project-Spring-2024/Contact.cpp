#include "Contact.h"


Contact::Contact() : firstName(""), lastName(""), phone(""), email(""), address(Address()) {}

Contact::Contact( string firstName,  string lastName,  string phone,  string email, Address address)
    : firstName(firstName), lastName(lastName), phone(phone), email(email), address(address) {}

Contact::~Contact() {}

void Contact::setFirstName( string firstName) {
    this->firstName = firstName;
}

void Contact::setLastName( string lastName) {
    this->lastName = lastName;
}

void Contact::setPhone( string phone) {
    this->phone = phone;
}

void Contact::setEmail( string email) {
    this->email = email;
}

void Contact::setAddress(Address address) {
    this->address = address;
}

 string Contact::getFirstName() const {
    return firstName;
}

 string Contact::getLastName() const {
    return lastName;
}

 string Contact::getPhone() const {
    return phone;
}

 string Contact::getEmail() const {
    return email;
}

Address Contact::getAddress() const {
    return address;
}

 string Contact::toString() const {
     stringstream ss;
    ss << "First name: " << firstName << "\n";
    ss << "Last name: " << lastName << "\n";
    ss << "Phone: " << phone << "\n";
    return ss.str();
}