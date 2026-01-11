#include "Supermarket.h"
#include <iostream>
#include <fstream>   // Reading and writing from and into file
#include <string>
#include <sstream> //Library to parse and read texts with space gap
using namespace std;

int main()
{
    Supermarket S;
    Product P;
    S.saveToFoodFile();
    S.saveToDetergentFile();
    S.saveToCannedFile();
    // Once the program is compiled we have to comment out or erase these saveTofile methods
    // Because the changes we make won't be saved if we try to compile it again with these methods still running
    // It'll reset and start it again

    P.loadFromFood();
    P.loadFromDetergent();
    P.loadFromCanned();
    User U; // Shared object, never reset
    int choice;

    do
    {
        cout << "Supermarket Management System" << endl;
        cout << "1. Choose your role" << endl;
        cout << "2. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            U.chooseRole(P);
            break;
        case 2:
            cout << "Exiting system..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 2);

    return 0;
}