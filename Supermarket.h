#pragma once
#include <string>
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
    void saveToFoodFile();
    void saveToDetergentFile();
    void saveToCannedFile();
    // Load and read from files
    void loadFromFood();
    void loadFromDetergent();
    void loadFromCanned();
    //Update file if changes are made
    void updateFoodFile();
    void updateDetergentFile();
    void updateCannedFile();
};

// This class does add, remove and sale product
// And it displays and calculate total revenue and total sales
class Product : public Supermarket 
{
public:
    bool isduplcate(int id);

    void addFoodProduct(int add);
    void addDetergentProduct(int add);
    void addCannedProduct(int add);

    void removeFoodProduct();
    void removeDetergentProduct();
    void removeCannedProduct();

    void Foodsale();
    void Detergentsale();
    void Cannedsale();

    void totalSale();

    void displayFood();
    void displayDetergent();
    void displayCanned();
    void displayAll();

    void totalValue();

    //Method to distinguish and do the works of admin and employee with its respective choice
    void adminMenu(Product& P);
    void employeeMenu(Product& P);
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
    void setName(string n);
    void setID(int i);
    void setPassword(string p);

    string getName();
    int getId();
    string getPassword();

    //Method to choose role
    void chooseRole(Product& P);
};