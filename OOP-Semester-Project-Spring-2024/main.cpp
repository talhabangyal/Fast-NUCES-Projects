#include <iostream>
#include <windows.h>
#include <string>
#include "ContactsBook.h"
#include "Search.h"
using namespace std;

void printMenu() 
{
    system("color 6d");
    system("cls");
    cout << "\t\t------------------------------------------------------------------------" << endl;
    cout << "\t\t| Press 1 to Add New Contact" << endl;
    cout << "\t\t| Press 2 to edit Contact" << endl;
    cout << "\t\t| Press 3 to delete Contact" << endl;
    cout << "\t\t| Press 4 to merge Duplicates" << endl;
    cout << "\t\t| Press 5 to store To in File" << endl;
    cout << "\t\t| Press 6 to load From in File" << endl;
    cout << "\t\t| Press 7 to print Contacts Sorted by First Name or Last Name" << endl;
    cout << "\t\t| Press 8 to print all Contacts" << endl;
    cout << "\t\t| Press 9 to search contacts by First Name, Last Name or Number" << endl;
    cout << "\t\t| Press 10 to display Count of Contacts" << endl;
    cout << "\t\t| Press 0 to exit" << endl;
    cout << "\t\t------------------------------------------------------------------------" << endl;
}

int main() 
{
    system("color 0A");
    int size = 0;
    cout << "\n\n\t\t\t---------------------------------------------------- ";
    cout << "\n\t\t\t|                                                   |";
    cout << "\n\t\t\t|              Contact Book C++                     |";
    cout << "\n\t\t\t|                                                   |";
    cout << "\n\t\t\t---------------------------------------------------- \n\n";


    Sleep(5000);
    cout << "\n\n\n\n\t\t\t\t--------------------------------- ";
    cout << "\n\t\t\t\t|                                |";
    cout << "\n\t\t\t\t|    Talha Adullah Bangyal       |";
    cout << "\n\t\t\t\t|       Abdullah Hissan          |";
    cout << "\n\t\t\t\t|                                |";
    cout << "\n\t\t\t\t--------------------------------- \n\n";



    
    Sleep(5000);

    system("CLS");
    cout << "Enter the size of the ContactsBook_____";
    cin >> size;
    ContactsBook book(size);
    cout << endl;

    while (true) {
        printMenu();
        int choice;
        cout << "Enter the value: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            // Add New Contact
            string firstName, lastName, phone, email;
            string street, country, house;

            cout << "Enter first name: ";
            cin.ignore();
            getline(cin, firstName);

            cout << "Enter last name: ";
            getline(cin, lastName);

            cout << "Enter phone: ";
            getline(cin, phone);

            cout << "Enter email: ";
            getline(cin, email);

            cout << "Enter house: ";
            getline(cin, house);

            cout << "Enter street: ";
            getline(cin, street);

            cout << "Enter country: ";
            getline(cin, country);

            Address address(street, country, house);
            Contact contact(firstName, lastName, phone, email, address);
            book.addContact(contact);
            cout << endl;
            break;
        }
        case 2: {
            // Edit Contact
            string first, last;
            cout << "Enter First name: ";
            cin >> first;
            cout << "Enter Last name: ";
            cin >> last;
            book.UpdateContact(first, last);
            break;
        }
        case 3: {
            // delete Contact
            string first, last;
            cout << "Enter First name: ";
            cin >> first;
            cout << "Enter Last name: ";
            cin >> last;
            book.DeleteContact(first, last);
            break;
        }
        case 4: {
            // Merge Duplicates contacts
            book.mergeDuplicates();
            break;
        }
        case 5: {
            // Store To File
            string filename;
            cout << "Enter file name: ";
            cin.ignore();
            getline(cin, filename);
            book.storeToFile(filename);
            cout << endl;
            cout << "Data has been stored in file" << endl;
            break;
        }
        case 6: {
            // Load From File
            string filename;
            cout << "Enter file name: ";
            cin.ignore();
            getline(cin, filename);
            book.loadFromFile(filename);
            cout << endl;
            break;
        }
        case 7: {
            string choice;
            cout << "Press f for first name or l for last name: ";
            cin.ignore();
            getline(cin, choice);
            if (choice == "f" || choice == "F") {
                book.printContactsSortedByFirstName();
            }
            else if (choice == "l" || choice == "L") {
                book.printContactsSortedByLastName();
            }
            else {
                cout << "Wrong input." << endl;
            }
            break;
        }
        case 8: {
            // Print Contacts
            cout << "Contact are " << endl;
            book.printContacts();
            cout << endl;
            break;
        }
        case 9: {
            // Search contacts (all three choices)
            int choice;
            cout << "Press 1 to Search contact by first name" << endl;
            cout << "Press 2 to Search contact by last name" << endl;
            cout << "Press 3 to Search contact phone number" << endl;
            cin >> choice;
            string searchTerm;
            switch (choice) {
            case 1: {
                cout << "Enter first name to search: ";
                cin.ignore();
                getline(cin, searchTerm);
                Search search(book);
                search.searchByFirstName(searchTerm);
                break;
            }
            case 2: {
                cout << "Enter last name to search: ";
                cin.ignore();
                getline(cin, searchTerm);
                Search search(book);
                search.searchByLastName(searchTerm);
                break;
            }
            case 3: {
                cout << "Enter phone number to search: ";
                cin.ignore();
                getline(cin, searchTerm);
                Search search(book);
                search.searchByPhoneNumber(searchTerm);
                break;
            }
            default: {
                cout << "Wrong input" << endl;
            }
                   break;
            }
        }
        case 10: {
            cout << "Count of Contacts are: " << book.getCount() << endl;
            break;
        }
        case 0: {
            return 0;
        }
        default: {
            cout << "Are you mad!!! You entered wrong input." << endl;
        }
        }
    }
    return 0;
}