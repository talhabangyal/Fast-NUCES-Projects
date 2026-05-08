#pragma once
#include<iostream>
using namespace std;

/*============================================================================*/

//Question 1
//--------------------------------------------
//1.	The Total Number of Relations
//2.	Reflexive Relations
//3.	Irreflexive Relations
//4.	Symmetric Relations
//5.	Anti - Symmetric Relations
//6.	Asymmetric Relations

/*--------------------------------------------------- Inputing -------------------------------------------*/
//input elements into a set
template<typename T>
void inputSet(T* set, int size) {
    if (size < 3) {
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

/*------------------------------------------------------- end ---------------------------------------------*/

/*---------------------------------------------------- Reflexive ------------------------------------------*/

//Reflexive
void reflexive(const int* set1, const int* set2, int size1, int size2)
{
    int Reflexivecheck = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (set1[i] == set2[j])
            {
                Reflexivecheck = 1;
                break;
            }
            else {
                Reflexivecheck = 0;
            }
        }
    }
    if (Reflexivecheck)
    {
        cout << "Relation is Reflexive." << endl;
    }
    else
    {
        cout << "Relation is not Reflxive." << endl;
    }
}

/*-------------------------------------------------------- end --------------------------------------------*/

/*---------------------------------------------------- Irreflexive ----------------------------------------*/

//Irreflexive
void Irreflexive(const int* set1, const int* set2, int size1, int size2) {
    int irreflexivecheck = 1;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (set1[i] == set2[j])
            {
                irreflexivecheck = 0;
                break;
            }
            else {
                irreflexivecheck = 0;
            }
        }
    }
    // checking reflexive relation
    if (irreflexivecheck)
    {
        cout << "Relation is Irreflexive." << endl;
    }
    else
    {
        cout << "Relation is not irreflxive." << endl;
    }
}

/*------------------------------------------------------ end ---------------------------------------------*/

/*---------------------------------------------------- Symmetric ------------------------------------------*/

//Symmetric
void symmetric(const int* set1, const int* set2, int size1, int size2)
{
    int SymmetricCheck = 0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if ((set1[i] == set2[j] && set1[i + 1] == set2[j + 1]) ||
                (set1[i] == set2[j + 1] && set1[i + 1] == set2[j]))
            {
                SymmetricCheck = 1;
                break;
            }
            else
            {
                SymmetricCheck = 0;
            }
        }
    }
    // checking symmetric relation
    if (SymmetricCheck)
    {
        cout << "Relation is symmetric." << endl;
    }
    else
    {
        cout << "Relation is not symmetric." << endl;
    }
}

/*---------------------------------------------------- end ------------------------------------------------*/

/*----------------------------------------------- Anti-Symmetric ------------------------------------------*/

//Anti-symmetric
void antiSymmetric(const int* set1, const int* set2, int size1, int size2)
{
    int AntiSymmetricCheck = 1;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if ((set1[i] == set2[j] && set1[i + 1] == set2[j + 1]) ||
                (set1[i] == set2[j + 1] && set1[i + 1] == set2[j]))
            {
                AntiSymmetricCheck = 0;
                break;
            }
        }
    }
    // checking antisymmetric relation
    if (AntiSymmetricCheck)
    {
        cout << "Relation is anti-symmetric." << endl;
    }
    else
    {
        cout << "Relation is not anti-symmetric." << endl;
    }
}

/*---------------------------------------------------- end ------------------------------------------*/

/*---------------------------------------------------- Asymmetric ----------------------------------------*/

// Asymmetric
void asymmetric(const int* set1, const int* set2, int size1, int size2)
{
    int asymmetricCheck = 1;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (set1[i] == set2[j])
            {
                asymmetricCheck = 0;
                break;
            }
        }
        if (!asymmetricCheck)
        {
            break;
        }
    }
    // Checking asymmetric relation
    if (asymmetricCheck)
    {
        cout << "Relation is asymmetric." << endl;
    }
    else
    {
        cout << "Relation is not asymmetric." << endl;
    }
}

/*---------------------------------------------------- end ------------------------------------------*/

/*---------------------------------------------------- Display ------------------------------------------*/

//Cartesian product Display
void cartesianDisplay(const int* set1, const int* set2, int size1, int size2) {
    cout << "{";
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << "(" << set1[i] << "," << set2[j] << ") ,";
        }
    }
    cout << "}" << endl;
}