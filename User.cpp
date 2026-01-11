#include "Supermarket.h"
#include <iostream>
#include <algorithm> // Library for changing letters to lower case
#include <string>
using namespace std;

void User::setName(string n)
{
	name = n;
}

void User::setID(int i)
{
	id = i;
}

void User::setPassword(string p)
{
	password = p;
}

string User::getName()
{
	return name;
}

int User::getId()
{
	return id;
}

string User::getPassword()
{
	return password;
}

void User::chooseRole(Product& P)
{
    int role, id;
    string n, p;
    cout << "1. Admin " << endl;
    cout << "2. Employee" << endl;
    cout << "Enter your choice: ";
    cin >> role;

    if (role == 1)
    {
        cout << "Enter name: ";
        cin >> n;
        transform(n.begin(), n.end(), n.begin(), ::tolower);
        setName(n);
        cout << "Enter Id: ";
        cin >> id;
        setID(id);
        cout << "Enter password: ";
        cin >> p;
        setPassword(p);
        if (getName() == "abebe" && getId() == 11 && getPassword() == "as1234")
        {
            adminMenu(P);
        }
        else if (getName() != "abebe" || getId() != 11 || getPassword() != "as1234")
        {
            cout << "\nIncorrect admin information\n\n";
        }
    }
    else if (role == 2)
    {
        employeeMenu(P);
    }
    else
    {
        cout << "Invalid role!" << endl;
    }
}