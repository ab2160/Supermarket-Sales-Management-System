#include "Supermarket.h"
#include <iostream>
#include <iomanip>   // Library for setting width(column)
#include <algorithm> // Library for changing letters to lower case
#include <string>
using namespace std;

bool Product::isduplcate(int id)
{
    for (int i = 0; i < food_count; i++)
        if (food_id[i] == id)
            return true;

    for (int i = 0; i < canned_count; i++)
        if (canned_id[i] == id)
            return true;

    for (int i = 0; i < detergent_count; i++)
        if (detergent_id[i] == id)
            return true;

    return false;
}

void Product::addFoodProduct(int add)
{
    for (int i = food_count; i < food_count + add && i < 100; i++)
    {
        cout << "Enter the name of the product: ";
        cin >> food_name[i];

        do
        {
            cout << "Enter the Id of the product: ";
            cin >> food_id[i];
            if (food_id[i] <= 0)
            {
                cout << "Invalid id!!" << endl;
            }
            else if (isduplcate(food_id[i]))
                cout << "Product with the same id exists!!" << endl;

        } while (food_id[i] <= 0 || isduplcate(food_id[i]));
        do
        {
            cout << "Enter the price of the product: ";
            cin >> food_price[i];
            if (food_price[i] <= 0)
            {
                cout << "Invalid price input!!" << endl;
            }
        } while (food_price[i] <= 0);
        do
        {
            cout << "Enter the quantity of the product: ";
            cin >> food_quantity[i];
            if (food_quantity[i] <= 0)
            {
                cout << "Invalid quantity input!!" << endl;
            }
        } while (food_quantity[i] <= 0);
    }
    food_count = food_count + add;

    cout << "You have successfully added a product." << endl;
}

void Product::addDetergentProduct(int add)
{
    for (int i = detergent_count; i < detergent_count + add && i < 100; i++)
    {
        cout << "Enter the name of the product: ";
        cin >> detergent_name[i];

        do
        {
            cout << "Enter the Id of the product: ";
            cin >> detergent_id[i];
            if (detergent_id[i] <= 0)
            {
                cout << "Invalid id!!" << endl;
            }
            else if (isduplcate(detergent_id[i]))
                cout << "Product with the same id exists!!" << endl;
        } while (detergent_id[i] <= 0 ||
            isduplcate(detergent_id[i]));
        do
        {
            cout << "Enter the price of the product: ";
            cin >> detergent_price[i];
            if (detergent_price[i] <= 0)
            {
                cout << "Invalid price input!!" << endl;
            }
        } while (detergent_price[i] <= 0);
        do
        {
            cout << "Enter the quantity of the product: ";
            cin >> detergent_quantity[i];
            if (detergent_quantity[i] <= 0)
            {
                cout << "Invalid quantity input!!" << endl;
            }
        } while (detergent_quantity[i] <= 0);
    }
    detergent_count = detergent_count + add;

    cout << "You have successfully added a product." << endl;
}

void Product::addCannedProduct(int add)
{
    for (int i = canned_count; i < canned_count + add && i < 100; i++)
    {
        cout << "Enter the name of the product: ";
        cin >> canned_name[i];

        do
        {
            cout << "Enter the Id of the product: ";
            cin >> canned_id[i];
            if (canned_id[i] <= 0)
            {
                cout << "Invalid id!!" << endl;
            }
            else if (isduplcate(canned_id[i]))
                cout << "Product with the same id exists!!" << endl;
        } while (canned_id[i] <= 0 || isduplcate(canned_id[i]));
        do
        {
            cout << "Enter the price of the product: ";
            cin >> canned_price[i];
            if (canned_price[i] <= 0)
            {
                cout << "Invalid price input!!" << endl;
            }
        } while (canned_price[i] <= 0);
        do
        {
            cout << "Enter the quantity of the product: ";
            cin >> canned_quantity[i];
            if (canned_quantity[i] <= 0)
            {
                cout << "Invalid quantity input!!" << endl;
            }
        } while (canned_quantity[i] <= 0);
    }
    canned_count = canned_count + add;

    cout << "You have successfully added a product." << endl;
}

void Product::removeFoodProduct()
{
    int r;
    int index = -1;
    cout << "Enter the product id you want to remove: ";
    cin >> r;
    for (int i = 0; i < food_count; i++)
    {
        if (food_id[i] == r)
        {
            index = i;
        }
    }

    if (index == -1)
    {
        cout << "Invalid product id." << endl;
        return;
    }

    for (int i = index; i < food_count - 1; i++)
    {
        food_id[i] = food_id[i + 1];
        food_name[i] = food_name[i + 1];
        food_price[i] = food_price[i + 1];
        food_quantity[i] = food_quantity[i + 1];
    }
    food_count--;
    cout << "You have successfully removed a product." << endl;
}

void Product::removeDetergentProduct()
{
    int r;
    int index = -1;
    cout << "Enter the product id you want to remove: ";
    cin >> r;
    for (int i = 0; i < detergent_count; i++)
    {
        if (detergent_id[i] == r)
        {
            index = i;
        }
    }

    if (index == -1)
    {
        cout << "Invalid product id." << endl;
        return;
    }

    for (int i = index; i < detergent_count - 1; i++)
    {
        detergent_id[i] = detergent_id[i + 1];
        detergent_name[i] = detergent_name[i + 1];
        detergent_price[i] = detergent_price[i + 1];
        detergent_quantity[i] = detergent_quantity[i + 1];
    }
    detergent_count--;
    cout << "You have successfully removed a product." << endl;
}

void Product::removeCannedProduct()
{
    int r;
    int index = -1;
    cout << "Enter the product id you want to remove: ";
    cin >> r;
    for (int i = 0; i < canned_count; i++)
    {
        if (canned_id[i] == r)
        {
            index = i;
        }
    }

    if (index == -1)
    {
        cout << "Invalid product id." << endl;
        return;
    }

    for (int i = index; i < canned_count - 1; i++)
    {
        canned_id[i] = canned_id[i + 1];
        canned_name[i] = canned_name[i + 1];
        canned_price[i] = canned_price[i + 1];
        canned_quantity[i] = canned_quantity[i + 1];
    }
    canned_count--;
    cout << "You have successfully removed a product." << endl;
}

void Product::Foodsale()
{
    string name, receipt;
    int id, q;
    cout << "Enter the product name you want to sell: ";
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    cout << "Enter the product id you want to sell: ";
    cin >> id;

    bool found = false; // track if we found a match
    for (int i = 0; i < food_count; i++)
    {
        string stored_name = food_name[i];
        transform(stored_name.begin(), stored_name.end(), stored_name.begin(), ::tolower);
        if (food_id[i] == id && stored_name == name)
        {
            cout << "Enter the quantity of the product you want to sell: ";
            cin >> q;
            if (q <= food_quantity[i])
            {
                food_sales += food_price[i] * q;
                food_quantity[i] = food_quantity[i] - q;

                cout << "Do you want a receipt(yes/no): ";
                cin >> receipt;
                transform(receipt.begin(), receipt.end(), receipt.begin(), ::tolower);
                if (receipt == "yes")
                {
                    cout << "  ======================\n";
                    cout << "||      receipt        \n";
                    cout << "||name: " << food_name[i] << endl;
                    cout << "||quantity: " << q << endl;
                    cout << "||total price: " << food_price[i] * q << endl;
                    cout << "  ======================\n";
                }
                cout << "You have successfully sold a product." << endl;
            }
            else if (q > food_quantity[i])
            {
                cout << "Insufficient quantity. Available quantity is: " << food_quantity[i] << endl;
            }
            found = true;
            break; // stop once we’ve handled the sale
        }

        if (!found)
        {
            cout << "Product not found!!" << endl;
        }
    }
}

void Product::Detergentsale()
{
    string name, receipt;
    int id, q;
    cout << "Enter the product name you want to sell: ";
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    cout << "Enter the product id you want to sell: ";
    cin >> id;

    bool found = false; // track if we found a match
    for (int i = 0; i < detergent_count; i++)
    {
        string stored_name = detergent_name[i];
        transform(stored_name.begin(), stored_name.end(), stored_name.begin(), ::tolower);
        if (detergent_id[i] == id && stored_name == name)
        {
            cout << "Enter the quantity of the product you want to sell: ";
            cin >> q;
            if (q <= detergent_quantity[i])
            {
                detergent_sales += detergent_price[i] * q;
                detergent_quantity[i] = detergent_quantity[i] - q;
                cout << "Do you want a receipt(yes/no): ";
                cin >> receipt;
                transform(receipt.begin(), receipt.end(), receipt.begin(), ::tolower);
                if (receipt == "yes")
                {
                    cout << "  ======================\n";
                    cout << "||      receipt        \n";
                    cout << "||name: " << detergent_name[i] << endl;
                    cout << "||quantity: " << q << endl;
                    cout << "||total price: " << detergent_price[i] * q << endl;
                    cout << "  ======================\n";
                }
                cout << "You have successfully sold a product.\n";
            }
            else if (q > detergent_quantity[i])
            {
                cout << "Insufficient quantity. Available quantity is: " << detergent_quantity[i] << endl;
            }
            found = true;
            break; // stop once we’ve handled the sale
        }
    }

    if (!found)
    {
        cout << "Product not found!!" << endl;
    }
}

void Product::Cannedsale()
{
    string name, receipt;
    int id, q;
    cout << "Enter the product name you want to sell: ";
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    cout << "Enter the product id you want to sell: ";
    cin >> id;

    bool found = false; // track if we found a match
    for (int i = 0; i < canned_count; i++)
    {
        string stored_name = canned_name[i];
        transform(stored_name.begin(), stored_name.end(), stored_name.begin(), ::tolower);
        if (canned_id[i] == id && stored_name == name)
        {
            cout << "Enter the quantity of the product you want to sell: ";
            cin >> q;
            if (q <= canned_quantity[i])
            {
                canned_sales += canned_price[i] * q;
                canned_quantity[i] = canned_quantity[i] - q;

                cout << "Do you want a receipt(yes/no): ";
                cin >> receipt;
                transform(receipt.begin(), receipt.end(), receipt.begin(), ::tolower);
                if (receipt == "yes")
                {
                    cout << "  ======================\n";
                    cout << "||      receipt        \n";
                    cout << "||name: " << canned_name[i] << endl;
                    cout << "||quantity: " << q << endl;
                    cout << "||total price: " << canned_price[i] * q << endl;
                    cout << "  ======================\n";
                }
                cout << "You have successfully sold a product." << endl;
            }
            else if (q > canned_quantity[i])
            {
                cout << "Insufficient quantity. Available quantity is: " << canned_quantity[i] << endl;
            }
            found = true;
            break; // stop once we’ve handled the sale
        }
    }

    if (!found)
    {
        cout << "Product not found!!" << endl;
    }
}

void Product::totalSale()
{
    total_sales = food_sales + detergent_sales + canned_sales;
    cout << "\" Total sale: " << total_sales << " birr \"" << endl;
}

void Product::displayFood()
{
    cout << "===============Current Food Products========================" << endl;
    cout << left << setw(12) << "Product id" << setw(15) << "Product name"
        << left << setw(12) << "Price" << right << setw(7) << "Quantity" << endl;
    for (int i = 0; i < food_count; i++)
    {
        cout << left << i + 1 << ". " << left << setw(10) << food_id[i] << left
            << setw(15) << food_name[i] << left << setw(10) << food_price[i]
            << right << setw(5) << food_quantity[i] << endl;
    }
}

void Product::displayDetergent()
{
    cout << "===============Current Detergent Products===================" << endl;
    cout << left << setw(12) << "Product id" << setw(25) << "Product name"
        << left << setw(12) << "Price" << right << setw(7) << "Quantity" << endl;
    for (int i = 0; i < detergent_count; i++)
    {
        cout << left << i + 1 << ". " << left << setw(10) << detergent_id[i] << left
            << setw(25) << detergent_name[i] << left << setw(10) << detergent_price[i]
            << right << setw(5) << detergent_quantity[i] << endl;
    }
}

void Product::displayCanned()
{
    cout << "===============Current Canned Products======================" << endl;
    cout << left << setw(12) << "Product id" << setw(25) << "Product name"
        << left << setw(12) << "Price" << right << setw(7) << "Quantity" << endl;
    for (int i = 0; i < canned_count; i++)
    {
        cout << left << i + 1 << ". " << left << setw(10) << canned_id[i] << left
            << setw(25) << canned_name[i] << left << setw(10) << canned_price[i]
            << right << setw(5) << canned_quantity[i] << endl;
    }
}

void Product::displayAll()
{
    displayFood();
    displayDetergent();
    displayCanned();
}

void Product::totalValue()
{
    double total_value = 0; // Reset the value or it'll add up the price of the sold product too
    for (int i = 0; i < food_count; i++)
    {
        total_value += food_quantity[i] * food_price[i];
    }
    for (int i = 0; i < detergent_count; i++)
    {
        total_value += detergent_quantity[i] * detergent_price[i];
    }
    for (int i = 0; i < canned_count; i++)
    {
        total_value += canned_quantity[i] * canned_price[i];
    }
    cout << "\" Total amount of price: " << total_value << " birr \"" << endl;
}

void Product::adminMenu(Product& P)
{
    int choice, i;
    do
    {
        cout << "=== Admin's Page ===" << endl;
        cout << "1. Add product" << endl;
        cout << "2. Remove product" << endl;
        cout << "3. Sale product" << endl;
        cout << "4. Total sales" << endl;
        cout << "5. Total values of product" << endl;
        cout << "6. View all products" << endl;
        cout << "7. Back to main menu" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int choice1;
            cout << "1. Food product" << endl;
            cout << "2. Detergent product" << endl;
            cout << "3. Canned product" << endl;
            cout << "Enter your choice: ";
            cin >> choice1;

            if (choice1 == 1)
            {
                cout << "Enter amount of food product to add: ";
                cin >> i;
                P.addFoodProduct(i);
                P.displayFood();
                P.updateFoodFile();
            }
            else if (choice1 == 2)
            {
                cout << "Enter amount of detergent product to add: ";
                cin >> i;
                P.addDetergentProduct(i);
                P.displayDetergent();
                P.updateDetergentFile();
            }
            else if (choice1 == 3)
            {
                cout << "Enter amount of canned product to add: ";
                cin >> i;
                P.addCannedProduct(i);
                P.displayCanned();
                P.updateCannedFile();
            }
            break;
        case 2:
            int choice2;
            cout << "1. Food product" << endl;
            cout << "2. Detergent product" << endl;
            cout << "3. Canned product" << endl;
            cout << "Enter your choice: ";
            cin >> choice2;
            if (choice2 == 1)
            {
                P.removeFoodProduct();
                P.displayFood();
                P.updateFoodFile();
            }
            else if (choice2 == 2)
            {
                P.removeDetergentProduct();
                P.displayDetergent();
                P.updateDetergentFile();
            }
            else if (choice2 == 3)
            {
                P.removeCannedProduct();
                P.displayCanned();
                P.updateCannedFile();
            }
            break;
        case 3:
            int choice3;
            cout << "1. Food product" << endl;
            cout << "2. Detergent product" << endl;
            cout << "3. Canned product" << endl;
            cout << "Enter your choice: ";
            cin >> choice3;
            if (choice3 == 1)
            {
                P.Foodsale();
                P.displayFood();
                P.updateFoodFile();
            }
            else if (choice3 == 2)
            {
                P.Detergentsale();
                P.displayDetergent();
                P.updateDetergentFile();
            }
            else if (choice3 == 3)
            {
                P.Cannedsale();
                P.displayCanned();
                P.updateCannedFile();
            }
            break;
        case 4:
            P.totalSale();
            break;
        case 5:
            P.totalValue();
            break;
        case 6:
            P.displayAll();
            break;
        case 7:
            cout << "Returning to main menu..." << endl;
            break;
        default:
            cout << "\nInvalid choice!\n" << endl;
        }
    } while (choice != 7);
}

void Product::employeeMenu(Product& P)
{
    int choice;
    do
    {
        cout << "=== Employee's Page ===" << endl;
        cout << "1. Sale product" << endl;
        cout << "2. Total sales" << endl;
        cout << "3. Total values of product" << endl;
        cout << "4. View all products" << endl;
        cout << "5. Back to main menu" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int choice3;
            cout << "1. Food product" << endl;
            cout << "2. Detergent product" << endl;
            cout << "3. Canned product" << endl;
            cout << "Enter your choice: ";
            cin >> choice3;
            if (choice3 == 1)
            {
                P.Foodsale();
                P.displayFood();
                P.updateFoodFile();
            }
            else if (choice3 == 2)
            {
                P.Detergentsale();
                P.displayDetergent();
                P.updateDetergentFile();
            }
            else if (choice3 == 3)
            {
                P.Cannedsale();
                P.displayCanned();
                P.updateCannedFile();
            }
            break;
        case 2:
            P.totalSale();
            break;
        case 3:
            P.totalValue();
            break;
        case 4:
            P.displayAll();
            break;
        case 5:
            cout << "Returning to main menu..." << endl;
            break;
        default:
            cout << "\nInvalid choice!\n" << endl;
        }
    } while (choice != 5);
}