#include "ContactsBook.h"
#include <fstream>

ContactsBook::ContactsBook(int size) : size(size), count(0) {
    contacts = new Contact[size];
}

/*==========================================end=======================================================*/

ContactsBook::~ContactsBook() {
    delete[] contacts;
}

/*==========================================end=======================================================*/

void ContactsBook::addContact(Contact contact) {
    if (count < size) {
        contacts[count] = contact;
        count++;
    }
    else {
         cerr << "ContactsBook is full." <<  endl;
    }
}

/*==========================================end=======================================================*/

void ContactsBook::printContacts() const {
    for (int i = 0; i < count; i++) {
         cout << "First Name: " << contacts[i].getFirstName() <<  endl;
         cout << "Last Name: " << contacts[i].getLastName() <<  endl;
         cout << "Phone: " << contacts[i].getPhone() <<  endl;
         cout << "Email: " << contacts[i].getEmail() <<  endl;
         cout << "Address: " << contacts[i].getAddress().getStreet() << ", "
            << contacts[i].getAddress().getCountry() << ", "
            << contacts[i].getAddress().getHouse() <<  endl;
         cout <<  endl;
    }
}

/*==========================================end=======================================================*/

void ContactsBook::printContactsSortedByFirstName() const {
    Contact tempContacts[100];
    for (int i = 0; i < count; i++) {
        tempContacts[i] = contacts[i];
    }
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < count; i++) {
            if (tempContacts[i - 1].getFirstName() > tempContacts[i].getFirstName()) {
                Contact temp = tempContacts[i - 1];
                tempContacts[i - 1] = tempContacts[i];
                tempContacts[i] = temp;
                swapped = true;
            }
        }
    } while (swapped);
    for (int i = 0; i < count; i++) {
         cout << "First Name: " << tempContacts[i].getFirstName() <<  endl;
         cout << "Last Name: " << tempContacts[i].getLastName() <<  endl;
         cout << "Phone: " << tempContacts[i].getPhone() <<  endl;
         cout << "Email: " << tempContacts[i].getEmail() <<  endl;
         cout << "Address: " << tempContacts[i].getAddress().getStreet() << ", "
            << tempContacts[i].getAddress().getCountry() << ", "
            << tempContacts[i].getAddress().getHouse() <<  endl;
         cout <<  endl;
    }
}

/*==========================================end=======================================================*/

void ContactsBook::printContactsSortedByLastName() const {
    Contact tempContacts[100];
    for (int i = 0; i < count; i++) {
        tempContacts[i] = contacts[i];
    }
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < count; i++) {
            if (tempContacts[i - 1].getLastName() > tempContacts[i].getLastName()) {
                Contact temp = tempContacts[i - 1];
                tempContacts[i - 1] = tempContacts[i];
                tempContacts[i] = temp;
                swapped = true;
            }
        }
    } while (swapped);
    for (int i = 0; i < count; i++) {
         cout << "First Name: " << tempContacts[i].getFirstName() <<  endl;
         cout << "Last Name: " << tempContacts[i].getLastName() <<  endl;
         cout << "Phone: " << tempContacts[i].getPhone() <<  endl;
         cout << "Email: " << tempContacts[i].getEmail() <<  endl;
         cout << "Address: " << tempContacts[i].getAddress().getStreet() << ", "
            << tempContacts[i].getAddress().getCountry() << ", "
            << tempContacts[i].getAddress().getHouse() <<  endl;
         cout <<  endl;
    }
}

/*==========================================end=======================================================*/

void ContactsBook::mergeDuplicates() {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (contacts[i].getFirstName() == contacts[j].getFirstName() &&
                contacts[i].getLastName() == contacts[j].getLastName()) {
                for (int k = j; k < count - 1; k++) {
                    contacts[k] = contacts[k + 1];
                }
                count--;
                j--;
            }
        }
        for (int j = 0; j < i; j++) {
            if (contacts[i].getFirstName() == contacts[j].getFirstName() &&
                contacts[i].getLastName() == contacts[j].getLastName()) {
                for (int k = i; k > j; k--) {
                    contacts[k] = contacts[k - 1];
                }
                count--;
                break;
            }
        }
    }
}

/*==========================================end=======================================================*/

void ContactsBook::storeToFile(const  string& filename) const {
     ofstream out(filename);
    if (out.is_open()) {
        for (int i = 0; i < count; i++) {
            out << contacts[i].getFirstName() << ","
                << contacts[i].getLastName() << ","
                << contacts[i].getPhone() << ","
                << contacts[i].getEmail() << ","
                << contacts[i].getAddress().getStreet() << ","
                << contacts[i].getAddress().getCountry() << ","
                << contacts[i].getAddress().getHouse() <<  endl;
        }
        out.close();
    }
    else {
         cout << "Unable to open file: " << filename <<  endl;
    }
}

/*==========================================end=======================================================*/

void ContactsBook::loadFromFile(const  string& filename) {
     ifstream in(filename);
    if (in.is_open()) {
        count = 0;
        char comma;
        string firstName, lastName, phone, email, street, country, house;
        while (in >> firstName >> comma >> lastName >> comma >> phone >> comma >> email >> comma >> street >> comma >> country >> comma >> house) {
            Address address(street, country, house);
            Contact contact(firstName, lastName, phone, email, address);
            addContact(contact);
        }
        in.close();
    }
    else {
         cout << "Unable to open file: " << filename <<  endl;
    }
}

/*==========================================end=======================================================*/

int ContactsBook::getCount() const {
    return count;
}

/*==========================================end=======================================================*/

Contact& ContactsBook::getContact(int index) {
    return contacts[index];
}

/*==========================================end=======================================================*/

const Contact& ContactsBook::getContact(int index) const {
    return contacts[index];
}

/*==============================================end===================================================*/


void ContactsBook::UpdateContact(string str_first, string str_last)
{
    int re = 0;
    string mail, num, houseno, city, country, street;
    for (int i = 0; i < count; i++)
    {
        if (str_first == contacts[i].getFirstName() && str_last == contacts[i].getLastName())
        {
            cout << "enter first name:";
            cin >> str_first;
            cout << "enter last name:";
            cin >> str_last;
            cout << "enter mail:";
            cin >> mail;
            cout << "enter mobile number:";
            cin >> num;
            cout << "enter house:";
            cin >> houseno;
            cout << "enter city:";
            cin >> city;
            cout << "enter country:";
            cin >> country;
            cout << "enter street:";
            cin >> street;
            contacts[i].setFirstName(str_first);
            contacts[i].setLastName(str_last);
            contacts[i].setEmail(mail);
            contacts[i].setPhone(num);
            /*contacts[i].address.setStreet(street);
            contacts[i].address.setCountry(country);
            contacts[i].address.setHouse(houseno);*/
            re++;
        }
    }
    if (re == 0)
    {
        cout << "your data is not found in the ContactBook" << endl;
    }
}


void ContactsBook::DeleteContact(std::string str_first, std::string str_last)
{
    for (int i = 0; i < count; i++)
    {
        if (contacts[i].getFirstName() == str_first && contacts[i].getLastName() == str_last)
        {
            contacts[i].setFirstName("-1");
            contacts[i].setFirstName("-1");
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (contacts[i].getFirstName() == "-1" && i + 1 < count)
        {
            swap(contacts[i], contacts[i + 1]);
        }
    }

    int count = 0;
    for (int i = 0; i < count; i++)
    {
        if (contacts[i].getFirstName() != "-1")
        {
            count++;
        }

    }
    count = count;

}