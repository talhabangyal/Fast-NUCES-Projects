#include "Address.h"

Address::Address() : street(""), country(""), house("") {}

Address::Address( string street,  string country,  string house) : street(street), country(country), house(house) {}

Address::~Address() {}

void Address::setStreet( string street) {
    this->street = street;
}

void Address::setCountry( string country) {
    this->country = country;
}

void Address::setHouse( string house) {
    this->house = house;
}

 string Address::getStreet() const {
    return street;
}

 string Address::getCountry() const {
    return country;
}

 string Address::getHouse() const {
    return house;
}