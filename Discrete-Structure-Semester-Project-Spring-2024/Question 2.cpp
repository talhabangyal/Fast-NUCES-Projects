#include"question 2.h"

// Question 2
//--------------------------------------------
//1.	Set Creation and Display
//2.	Union and Intersection
//3.	Subset and Superset
//4.	Set Difference
//5.	Power Set Generation
//6.	Cardinality Calculation
//7.	Set Equality
//8.	Set Complement

// Prototype for saving data to a file
void saveData(const char* set1, int size1, const char* set2, int size2, const string& filename);

// Prototype for loading data from a file
void loadData(char*& set1, int& size1, char*& set2, int& size2, const string& filename);

int main() {
    char* set1 = nullptr;
    char* set2 = nullptr;
    char* set3 = nullptr;
    char* universalSet = nullptr;
    int size1 = 0, size2 = 0, size3 = 0, universalSize = 0;
    int count = 0;
    string filename = "data.txt";

    do
    {
        cout << "------------------Menu--------------------" << endl;
        cout << "Press 1 to create a set and Display sets" << endl;
        cout << "Press 2 to create and display Union of set or Intersection of set" << endl;
        cout << "Press 3 to create and display Subset of set or Superset of set" << endl;
        cout << "Press 4 to create and display Set Difference of set" << endl;
        cout << "Press 5 to create and display Power Set Generation of set" << endl;
        cout << "Press 6 to create and display Cardinality Calculation of set" << endl;
        cout << "Press 7 to create and display Set Equality of set" << endl;
        cout << "Press 8 to create and display Set Complement of set" << endl;
        cout << "Press 9 to get data from file" << endl;
        cout << "Press 0 to upload data in File" << endl;
        cout << "Press -1 to exit" << endl;
        cout << "\nEnter a value: ";
        cin >> count;
        cout << endl;

        switch (count)
        {
        case 1:
            cout << "Enter size of set 1: ";
            cin >> size1;
            cout << "Enter size of set 2: ";
            cin >> size2;
            cout << endl;
            set1 = new char[size1];
            set2 = new char[size2];
            cout << "Enter the values for set 1" << endl;
            inputSet(set1, size1);
            cout << "Enter the values for set 2" << endl;
            inputSet(set2, size2);
            setDisplay(set1, set2, size1, size2);
            break;
        case 2:
            if (size1 <= 0 || size2 <= 0)
            {
                cout << "Relations not created. Please create relation first." << endl;
                break;
            }
            setUnion(set1, size1, set2, size2);
            setIntersection(set1, size1, set2, size2);
            fileUnion(set1, size1, set2, size2, "union.txt");
            fileIntersection(set1, size1, set2, size2, "intersection.txt");
            break;
        case 3:
            if (size1 <= 0 || size2 <= 0)
            {
                cout << "Relations not created. Please create relation first." << endl;
                break;
            }
            if (subset(set2, size2, set1, size1))
                cout << "Set 2 is a subset of Set 1." << endl;
            else
                cout << "Set 2 is not a subset of Set 1." << endl;

            if (superset(set1, size1, set2, size2))
                cout << "Set 1 is a superset of Set 2." << endl;
            else
                cout << "Set 1 is not a superset of Set 2." << endl;
            break;
        case 4:
            if (size1 <= 0 || size2 <= 0)
            {
                cout << "Relations not created. Please create relation first." << endl;
                break;
            }
            setDifference(set1, size1, set2, size2);
            break;
        case 5:
            set3 = new char[size3];
            cout << "Enter size of set 3: ";
            cin >> size3;
            cout << "Enter the values of set to find power set" << endl;
            inputSet(set3, size3);
            powerSet(set3, size3);
            break;
        case 6:
            if (size1 <= 0 || size2 <= 0)
            {
                cout << "Relations not created. Please create relation first." << endl;
                break;
            }
            cout << "Cardinality of the set 1: ";
            cardinality(set1, size1);
            cout << endl;
            cout << "Cardinality of the set 2: ";
            cardinality(set2, size2);
            cout << endl;
            break;
        case 7:
            if (size1 <= 0 || size2 <= 0)
            {
                cout << "Relations not created. Please create relation first." << endl;
                break;
            }
            if (setEquality(set1, size1, set2, size2))
                cout << "The sets are equal.\n";
            else
                cout << "The sets are not equal.\n";
            break;
        case 8:
            if (size1 <= 0 || size2 <= 0)
            {
                cout << "Relations not created. Please create relation first." << endl;
                break;
            }
            universalSet = new char[universalSize];
            cout << "Enter size of universal set: ";
            cin >> universalSize;
            cout << "Enter the values of set to find Compliment of sets" << endl;
            inputSet(universalSet, universalSize);
            cout << endl;
            cout << "Complement of set 1 is: ";
            setComplement(universalSet, set1, universalSize, size1);
            cout << endl;
            cout << "Complement of set 2 is: ";
            setComplement(universalSet, set2, universalSize, size2);
            break;
        case 9:
            loadData(set1, size1, set2, size2, filename);
            break;
        case 0:
            saveData(set1, size1, set2, size2, filename);
            break;
        case -1:
            break;
        default:
            cout << "Are you Mad, you entered a wrong value!!" << endl;
            break;
        }
    } while (count != -1);
    delete[] set1;
    delete[] set2;
    delete[] set3;
    delete[] universalSet;
    return 0;
}

//Definition of saveData function
void saveData(const char* set1, int size1, const char* set2, int size2, const  string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    //Save the size of sets and then the elements
    outputFile << size1 << endl;
    for (int i = 0; i < size1; ++i)
        outputFile << set1[i] << " ";
    outputFile << endl;

    outputFile << size2 << endl;
    for (int i = 0; i < size2; ++i)
        outputFile << set2[i] << " ";
    outputFile.close();

    cout << "Data saved successfully to " << filename << endl;
}

//Definition of loadData function
void loadData(char*& set1, int& size1, char*& set2, int& size2, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    //Read and display the size of sets
    inputFile >> size1;
    cout << "Size of set 1: " << size1 << endl;
    set1 = new char[size1];
    cout << "Elements of set 1: ";
    for (int i = 0; i < size1; ++i) {
        inputFile >> set1[i];
        cout << set1[i] << " ";
    }
    cout << endl;

    inputFile >> size2;
    cout << "Size of set 2: " << size2 << endl;
    set2 = new char[size2];
    cout << "Elements of set 2: ";
    for (int i = 0; i < size2; ++i) {
        inputFile >> set2[i];
        cout << set2[i] << " ";
    }
    cout << endl;

    inputFile.close();

    cout << "Data taken successfully from " << filename << endl;
}