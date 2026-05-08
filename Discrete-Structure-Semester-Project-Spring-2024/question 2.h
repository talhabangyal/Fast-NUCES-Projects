#pragma once
#include<iostream>
#include <fstream>
using namespace std;

/*============================================================================*/

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

/*------------------------------------------ Inputing & displaying -------------------------------------*/

//input elements into a set(array)
template<typename T>
void inputSet(T* set, int size) {
    if (size < 0) {
        cout << "Size must be 3 or above." << endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> set[i];
        for (int j = 0; j < i; ++j) {
            if (set[i] == set[j]) {
                cout << "Duplicate value! Please enter a different value.\n";
                --i;
                break;
            }
        }
    }
}

// storing sets in txt file
template<typename T>
void inputfile(const T* set1, const T* set2, int size1, int size2, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    outputFile << "Set 1 is: {";
    for (int i = 0; i < size1; i++)
    {
        outputFile << set1[i];
        if (i != size1 - 1)
            outputFile << ",";
    }
    outputFile << "}\n";
    outputFile << "Set 2 is: {";
    for (int i = 0; i < size2; i++)
    {
        outputFile << set2[i];
        if (i != size2 - 1)
            outputFile << ",";
    }
    outputFile << "}\n";
    outputFile.close();
}

//Set Display without txt file
template<typename T>
void setDisplay(const T* set1, const T* set2, int size1, int size2) {
    cout << "Set 1 is: ";
    cout << "{";
    for (int i = 0; i < size1; i++)
    {
        cout << set1[i] << ",";
    }
    cout << "}";
    cout << endl;
    cout << "Set 2 is: ";
    cout << "{";
    for (int i = 0; i < size2; i++)
    {
        cout << set2[i] << ",";
    }
    cout << "}" << endl;
}

/*----------------------------------------------- End --------------------------------------------------*/

/*------------------------------------------- Union / Intersection -------------------------------------*/

//union of two sets(array)
template<typename T>
void setUnion(const T* set1, int size1, const T* set2, int size2) {
    T* set3 = new T[size1 + size2];
    for (int i = 0; i < size1; ++i)
        set3[i] = set1[i];
    int size3 = size1;
    for (int i = 0; i < size2; ++i) {
        bool found = false;
        for (int j = 0; j < size1; ++j) {
            if (set2[i] == set1[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            set3[size3++] = set2[i];
    }
    cout << "Union: { ";
    for (int i = 0; i < size3; ++i)
        cout << set3[i] << " ";
    cout << "}\n";

    delete[] set3;
} //---------------end---------------------
//intersection of two sets(array)
template<typename T>
void setIntersection(const T* set1, int size1, const T* set2, int size2) {
    T* set3 = new T[size1];
    int size3 = 0;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (set1[i] == set2[j]) {
                bool check = false;
                for (int k = 0; k < size3; ++k) {
                    if (set1[i] == set3[k]) {
                        check = true;
                        break;
                    }
                }
                if (!check)
                    set3[size3++] = set1[i];
                break;
            }
        }
    }
    cout << "Intersection: { ";
    for (int i = 0; i < size3; ++i)
        cout << set3[i] << " ";
    cout << "}\n";
    delete[] set3;
}//------------end-----------------
//union of two sets in txt file
template<typename T>
void fileUnion(const T* set1, int size1, const T* set2, int size2, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    T* set3 = new T[size1 + size2];
    for (int i = 0; i < size1; ++i)
        set3[i] = set1[i];
    int size3 = size1;
    for (int i = 0; i < size2; ++i) {
        bool found = false;
        for (int j = 0; j < size1; ++j) {
            if (set2[i] == set1[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            set3[size3++] = set2[i];
    }
    outputFile << "Union: { ";
    for (int i = 0; i < size3; ++i)
        outputFile << set3[i] << " ";
    outputFile << "}\n";
    delete[] set3;
    outputFile.close();
}//-------------end-----------------
// interection of two sets in txt file
template<typename T>
void fileIntersection(const T* set1, int size1, const T* set2, int size2, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    T* set3 = new T[size1];
    int size3 = 0;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (set1[i] == set2[j]) {
                bool check = false;
                for (int k = 0; k < size3; ++k) {
                    if (set1[i] == set3[k]) {
                        check = true;
                        break;
                    }
                }
                if (!check)
                    set3[size3++] = set1[i];
                break;
            }
        }
    }
    outputFile << "Intersection: { ";
    for (int i = 0; i < size3; ++i)
        outputFile << set3[i] << " ";
    outputFile << "}\n";
    delete[] set3;
    outputFile.close();
}//--------------------end------------------------

/*----------------------------------------------- End --------------------------------------------------*/

/*------------------------------------------- subset / superset ----------------------------------------*/

//Set Subset
template<typename T>
bool subset(const T* set1, int size1, const T* set2, int size2) {
    for (int i = 0; i < size1; ++i) {
        bool found = false;
        for (int j = 0; j < size2; ++j) {
            if (set1[i] == set2[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }
    return true;
}//------------------end--------------------

//Superset of sets(array)
template<typename T>
bool superset(const T* set1, int size1, const T* set2, int size2) {
    for (int i = 0; i < size2; ++i) {
        bool found = false;
        for (int j = 0; j < size1; ++j) {
            if (set2[i] == set1[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }
    return true;
}//---------------------end--------------------------

/*----------------------------------------------- End --------------------------------------------------*/

/*------------------------------------------- set difference -------------------------------------------*/

//Set Difference
template<typename T>
void setDifference(const T* set1, int size1, const T* set2, int size2) {
    cout << "Set Difference (Set1 - Set2): { ";
    bool found;
    for (int i = 0; i < size1; ++i) {
        found = false;
        for (int j = 0; j < size2; ++j) {
            if (set1[i] == set2[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            cout << set1[i] << " ";
    }
    cout << "}\n";
}

/*----------------------------------------------- End --------------------------------------------------*/

/*--------------------------------------------- power set ----------------------------------------------*/

//Power Set Generation
template<typename T>
void powerSet(const T* set, int size) {
    cout << "Power Set:\n";
    for (int i = 0; i < (1 << size); ++i) {
        cout << "{ ";
        for (int j = 0; j < size; ++j) {
            if (i & (1 << j))
                cout << set[j] << " ";
        }
        cout << "}\n";
    }
}

/*----------------------------------------------- End --------------------------------------------------*/

/*------------------------------------------- Cardinality ----------------------------------------------*/

//Cardinality Calculation
template<typename T>
void cardinality(const T* set, int size) {
    cout << size;
}

/*----------------------------------------------- End --------------------------------------------------*/

/*--------------------------------------------- equality -----------------------------------------------*/

//Set Equality
template<typename T>
bool setEquality(const T* set1, int size1, const T* set2, int size2) {
    if (size1 != size2)
        return false;
    char* temp1 = new char[size1];
    char* temp2 = new char[size2];
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++) {
            temp1[i] = set1[i];
            temp2[j] = set2[j];
        }
    }
    for (int i = 0; i < size1 - 1; ++i) {
        for (int j = 0; j < size1 - i - 1; ++j) {
            if (temp1[j] > temp1[j + 1]) {
                T temp = temp1[j];
                temp1[j] = temp1[j + 1];
                temp1[j + 1] = temp;
            }
            if (temp2[j] > temp2[j + 1]) {
                T temp = temp2[j];
                temp2[j] = temp2[j + 1];
                temp2[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size1; ++i) {
        if (set1[i] != set2[i])
            return false;
    }
    return true;
}

/*----------------------------------------------- End --------------------------------------------------*/

/*--------------------------------------------- compliment ---------------------------------------------*/

//Set Complement
template<typename T>
void setComplement(T* univeralSet, T* set2, int universalSize, int size2) {
    cout << "{ ";
    bool found;
    for (int i = 0; i < universalSize; ++i) {
        found = false;
        for (int j = 0; j < size2; ++j) {
            if (univeralSet[i] == set2[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            cout << univeralSet[i] << " ";
    }
    cout << "}\n";
}

/*----------------------------------------------- End --------------------------------------------------*/