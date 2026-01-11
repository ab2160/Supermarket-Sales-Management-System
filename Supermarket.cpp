#include "Supermarket.h"
#include <iostream>
#include <iomanip> // Library for set width(column)
#include <string>
#include <fstream> // Reading and writing from and into file
#include <sstream> //Library to parse and read texts with space gap
using namespace std;

void Supermarket::saveToFoodFile()
{
    fstream FoodFile;
    FoodFile.open("Food_stock.txt", ios::out);
    if (FoodFile.is_open())
    {
        FoodFile << left << setw(12) << "101" << setw(15)
            << "Onions" << left << setw(12) << "75" << right << setw(7) << "100" << endl;
        FoodFile << left << setw(12) << "102" << setw(15)
            << "Barley" << left << setw(12) << "95" << right << setw(7) << "70" << endl;
        FoodFile << left << setw(12) << "103" << setw(15)
            << "Coffee" << left << setw(12) << "700" << right << setw(7) << "20" << endl;
        FoodFile << left << setw(12) << "104" << setw(15)
            << "Cooking_oil" << left << setw(12) << "1600" << right << setw(7) << "30" << endl;
        FoodFile << left << setw(12) << "105" << setw(15)
            << "Apples" << left << setw(12) << "140" << right << setw(7) << "30" << endl;
        FoodFile << left << setw(12) << "106" << setw(15)
            << "Oranges" << left << setw(12) << "100" << right << setw(7) << "30" << endl;
        FoodFile << left << setw(12) << "107" << setw(15)
            << "Bottled_water" << left << setw(12) << "25" << right << setw(7) << "100" << endl;
        FoodFile << left << setw(12) << "108" << setw(15)
            << "Lentils" << left << setw(12) << "275" << right << setw(7) << "50" << endl;
        FoodFile << left << setw(12) << "109" << setw(15)
            << "Injera" << left << setw(12) << "25" << right << setw(7) << "100" << endl;
        FoodFile << left << setw(12) << "110" << setw(15)
            << "Beans" << left << setw(12) << "210" << right << setw(7) << "40" << endl;
        FoodFile.close();
    }
}

void Supermarket::saveToDetergentFile()
{
    fstream DetergentFile;
    DetergentFile.open("Detergent_stock.txt", ios::out);
    if (DetergentFile.is_open())
    {
        DetergentFile << left << setw(12) << "201" << setw(25)
            << "Shampoo" << left << setw(12) << "100" << right << setw(7) << "50" << endl;
        DetergentFile << left << setw(12) << "202" << setw(25)
            << "Soap" << left << setw(12) << "60" << right << setw(7) << "100" << endl;
        DetergentFile << left << setw(12) << "203" << setw(25)
            << "Power_Detergent" << left << setw(12) << "120" << right << setw(7) << "40" << endl;
        DetergentFile << left << setw(12) << "204" << setw(25)
            << "Liquid_Detergent" << left << setw(12) << "150" << right << setw(7) << "30" << endl;
        DetergentFile << left << setw(12) << "205" << setw(25)
            << "Dishwashing_Liquid" << left << setw(12) << "100" << right << setw(7) << "50" << endl;

        DetergentFile.close();
    }
}

void Supermarket::saveToCannedFile()
{
    fstream CannedFile;
    CannedFile.open("Canned_stock.txt", ios::out);
    if (CannedFile.is_open())
    {
        CannedFile << left << setw(12) << "301" << setw(25)
            << "Canned_Beans" << left << setw(12) << "100" << right << setw(7) << "50" << endl;
        CannedFile << left << setw(12) << "302" << setw(25)
            << "Canned_Tomatoes" << left << setw(12) << "80" << right << setw(7) << "60" << endl;
        CannedFile << left << setw(12) << "303" << setw(25)
            << "Canned_Tuna" << left << setw(12) << "200" << right << setw(7) << "40" << endl;
        CannedFile << left << setw(12) << "304" << setw(25)
            << "Canned_Peas" << left << setw(12) << "100" << right << setw(7) << "40" << endl;
        CannedFile << left << setw(12) << "305" << setw(25)
            << "Canned_Fruits" << left << setw(12) << "150" << right << setw(7) << "50" << endl;

        CannedFile.close();
    }
}

void Supermarket::loadFromFood()
{
    fstream FoodFile;
    FoodFile.open("Food_stock.txt", ios::in);
    if (FoodFile.is_open())
    {
        string line;
        food_count = 0;
        cout << "===============Food Products===================" << endl;
        cout << left << setw(12) << "Product id" << setw(15) << "Product name"
            << left << setw(12) << "Price" << right << setw(7) << "Quantity" << endl;
        while (getline(FoodFile, line))
        {
            stringstream parse(line);
            parse >> food_id[food_count] >> food_name[food_count] >> food_price[food_count] >> food_quantity[food_count];
            cout << left << setw(12) << food_id[food_count] << setw(15) << food_name[food_count]
                << left << setw(12) << food_price[food_count] << right << setw(7) << food_quantity[food_count] << endl;
            food_count++;
            if (food_count >= 100)
                break;
        }
        FoodFile.close();
    }
}

void Supermarket::loadFromDetergent()
{
    fstream DetergentFile;
    DetergentFile.open("Detergent_stock.txt", ios::in);
    if (DetergentFile.is_open())
    {
        string line;
        detergent_count = 0;
        cout << "===============Detergent Products=========================" << endl;
        cout << left << setw(12) << "Product id" << setw(25) << "Product name"
            << left << setw(12) << "Price" << right << setw(7) << "Quantity" << endl;
        while (getline(DetergentFile, line))
        {
            stringstream parse(line);
            parse >> detergent_id[detergent_count] >> detergent_name[detergent_count] >> detergent_price[detergent_count] >> detergent_quantity[detergent_count];
            cout << left << setw(12) << detergent_id[detergent_count] << setw(25) << detergent_name[detergent_count]
                << left << setw(12) << detergent_price[detergent_count]
                << right << setw(7) << detergent_quantity[detergent_count] << endl;
            detergent_count++;
            if (detergent_count >= 100)
                break;
        }
        DetergentFile.close();
    }
}

void Supermarket::loadFromCanned()
{
    fstream CannedFile;
    CannedFile.open("Canned_stock.txt", ios::in);
    if (CannedFile.is_open())
    {
        string line;
        canned_count = 0;
        cout << "===============Canned Products============================" << endl;
        cout << left << setw(12) << "Product id" << setw(25) << "Product name"
            << left << setw(12) << "Price" << right << setw(7) << "Quantity" << endl;
        while (getline(CannedFile, line))
        {
            stringstream parse(line);
            parse >> canned_id[canned_count] >> canned_name[canned_count] >> canned_price[canned_count] >> canned_quantity[canned_count];
            cout << left << setw(12) << canned_id[canned_count] << setw(25) << canned_name[canned_count]
                << left << setw(12) << canned_price[canned_count]
                << right << setw(7) << canned_quantity[canned_count] << endl;
            canned_count++;
            if (canned_count >= 100)
                break;
        }
        CannedFile.close();
    }
}

void Supermarket::updateFoodFile()
{
    fstream FoodFile("Food_stock.txt", ios::out);
    if (FoodFile.is_open())
    {
        for (int i = 0; i < food_count; i++)
        {
            FoodFile << left << setw(12) << food_id[i] << setw(15)
                << food_name[i] << setw(12) << food_price[i]
                << setw(7) << food_quantity[i] << endl;
        }
        FoodFile.close();
    }
}

void Supermarket::updateDetergentFile()
{
    fstream DetergentFile("Detergent_stock.txt", ios::out);
    if (DetergentFile.is_open())
    {
        for (int i = 0; i < detergent_count; i++)
        {
            DetergentFile << left << setw(12) << detergent_id[i] << setw(25)
                << detergent_name[i] << setw(12) << detergent_price[i]
                << setw(7) << detergent_quantity[i] << endl;
        }
        DetergentFile.close();
    }
}

void Supermarket::updateCannedFile()
{
    fstream CannedFile("Canned_stock.txt", ios::out);
    if (CannedFile.is_open())
    {
        for (int i = 0; i < canned_count; i++)
        {
            CannedFile << left << setw(12) << canned_id[i] << setw(25)
                << canned_name[i] << setw(12) << canned_price[i]
                << setw(7) << canned_quantity[i] << endl;
        }
        CannedFile.close();
    }
}