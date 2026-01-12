#include <iostream>
#include <iomanip>   // Library for set width(column)
#include <algorithm> // Library for changing letters to lower case
#include <fstream>   // Reading and writing from and into file
#include <string>
#include <sstream> //Library to parse and read texts with space gap
using namespace std;

// This class has declared members
// And features like create and save files,
// Load and read from files and
// Update files
class Supermarket
{
protected:
    // Food products
    int food_id[100];
    string food_name[100];
    double food_price[100];
    int food_quantity[100];
    int food_count = 0;
    double food_sales = 0;
    // Detergent products
    int detergent_id[100];
    string detergent_name[100];
    double detergent_price[100];
    int detergent_quantity[100];
    int detergent_count = 0;
    double detergent_sales = 0;
    // Canned products
    int canned_id[100];
    string canned_name[100];
    double canned_price[100];
    int canned_quantity[100];
    int canned_count = 0;
    double canned_sales = 0;

    double total_sales = 0;
    double total_value = 0;

public:
    // Create and save files
    void saveToFoodFile()
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

    void saveToDetergentFile()
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

    void saveToCannedFile()
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

    // Load and read from files
    void loadFromFood()
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

    void updateFoodFile()
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

    void loadFromDetergent()
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

    void updateDetergentFile()
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

    void loadFromCanned()
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

    void updateCannedFile()
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
};

// This class does add, remove and sale product
// And it displays and calculate total revenue and total sales
class Product : public Supermarket
{
public:
    bool isduplcate(int id)
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

    void addFoodProduct(int add)
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

    void addDetergentProduct(int add)
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

    void addCannedProduct(int add)
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

    void removeFoodProduct()
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

    void removeDetergentProduct()
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

    void removeCannedProduct()
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

    void Foodsale()
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
    void Detergentsale()
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

    void Cannedsale()
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

    void totalSale()
    {
        total_sales = food_sales + detergent_sales + canned_sales;
        cout << "\" Total sale: " << total_sales << " birr \"" << endl;
    }

    void displayFood()
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

    void displayDetergent()
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
    void displayCanned()
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

    void displayAll()
    {
        displayFood();
        displayDetergent();
        displayCanned();
    }
    void totalValue()
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

    void adminMenu(Product& P)
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

    void employeeMenu(Product& P)
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
};

// This class will provide information of the user
// And distinguish admin from employee
class User : public Product
{
private:
    string name;
    int id;
    string password;

public:
    void setName(string n)
    {
        name = n;
    }
    void setID(int i)
    {
        id = i;
    }
    void setPassword(string p)
    {
        password = p;
    }

    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }

    string getPassword()
    {
        return password;
    }

    void chooseRole(Product& P)
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
};

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

/*
Group member               ID No.
1. Abreham Molla           RCD/0889/2017
2. Beka Gizaw              RCD/1612/2017
3. Kalab Belay             RCD/0921/2017
4. Paulos Simeon           RCD/1712/2017
5. Kirubel Seifu           RCD/1811/2017
6. Nahom Yemane            RCD/0092/2018
*/
