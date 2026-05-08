//#include"question 1.h"
//
////Question 1
////--------------------------------------------
////1.	The Total Number of Relations
////2.	Reflexive Relations
////3.	Irreflexive Relations
////4.	Symmetric Relations
////5.	Anti - Symmetric Relations
////6.	Asymmetric Relations
//
//int main() {
//    int size1 = 0, size2 = 0, size3 = 0;
//    int* set1 = nullptr; int* set2 = nullptr; int* set3 = nullptr;
//    char count = 'NULL';
//    do
//    {
//        cout << "------------------Menu--------------------" << endl;
//        cout << "Press 1 to create a sets" << endl;
//        cout << "Press 2 the Total Number of Relations" << endl;
//        cout << "Press 3 to check a Reflexive relation" << endl;
//        cout << "Press 4 to check an Irreflexive relation" << endl;
//        cout << "Press 5 to check a Symmetric relation" << endl;
//        cout << "Press 6 to check an Anti-Symmetric relation" << endl;
//        cout << "Press 7 to check an Asymmetric relation" << endl;
//        cout << "Press 8 to display cartesian" << endl;
//        cout << "Press 0 to exit" << endl;
//        cout << "\nEnter a value: ";
//        cin >> count;
//        cout << endl;
//        switch (count)
//        {
//        case '1':
//            cout << "Enter size of set 1: ";
//            cin >> size1;
//            cout << "Enter size of set 2: ";
//            cin >> size2;
//            cout << endl;
//            set1 = new int[size1];
//            set2 = new int[size2];
//            cout << "Enter the values for set 1" << endl;
//            inputSet(set1, size1);
//            cout << "Enter the values for set 2" << endl;
//            inputSet(set2, size2);
//
//           break;
//        case '2':
//            if (size1 <= 0 || size2 <= 0)
//            {
//                cout << "Relations not created. Please create relation first." << endl;
//                break;
//            }
//
//            for (int i = 0; i < size1; i++)
//            {
//                for (int j = 0; j < size2; j++) {
//                    size3++; size3++;
//                }
//            }
//
//            cout << "The total number of relations are: " << size3 / 2 << endl;
//            break;
//        case '3':
//            if (size1 <= 0 || size2 <= 0)
//            {
//                cout << "Relations not created. Please create relation first." << endl;
//                break;
//            }
//            reflexive(set1, set2, size1, size2);
//            break;
//        case '4':
//            if (size1 <= 0 || size2 <= 0)
//            {
//                cout << "Relations not created. Please create relation first." << endl;
//                break;
//            }
//            Irreflexive(set1, set2, size1, size2);
//            break;
//        case '5':
//            if (size1 <= 0 || size2 <= 0)
//            {
//                cout << "Relations not created. Please create relation first." << endl;
//                break;
//            }
//            symmetric(set1, set2, size1, size2);
//            break;
//        case '6':
//            if (size1 <= 0 || size2 <= 0)
//            {
//                cout << "Relations not created. Please create relation first." << endl;
//                break;
//            }
//            antiSymmetric(set1, set2, size1, size2);
//            break;
//        case '7':
//            if (size1 <= 0 || size2 <= 0)
//            {
//                cout << "Relations not created. Please create relation first." << endl;
//                break;
//            }
//            asymmetric(set1, set2, size1, size2);
//            break;
//        case '8':
//            if (size1 <= 0 || size2 <= 0)
//            {
//                cout << "Relations not created. Please create relation first." << endl;
//                break;
//            }
//            cartesianDisplay(set1, set2, size1, size2);
//            break;
//        case '0':
//            break;
//        default:
//            cout << "Are you Mad, you entered a wrong value!!" << endl;
//            break;
//        }
//    } while (count != '0');
//    delete[] set1;
//    delete[] set2;
//    delete[] set3;
//    return 0;
//}