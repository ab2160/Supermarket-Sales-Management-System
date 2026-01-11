# Supermarket Management System

A simple C++ console-based supermarket management system that uses object-oriented programming to manage inventory, sales and user roles. It supports both admin and employee operations, including adding, removing, selling products and tracking total sales and inventory value.

```
Supermarket-Management/
│
├── src/                 # Source files
│   ├── main.cpp
│   ├── Product.cpp
│   ├── Supermarket.cpp
│   └── User.cpp
│
├── include/             # Header files
│   └── Supermarket.h
│
├── data/                # Stock files
│   ├── Food.txt
│   ├── Detergent.txt
│   └── Canned.txt
│
├── SupermarketFinalProject.slnx    # Visual Studio solution
├── SupermarketFinalProject.vcxproj # Visual Studio project
└── README.md
```

# Features

- Admin and employee login  
- Add, remove and sell products (Food, Detergent, Canned)  
- Track total sales and inventory value  
- File-based persistence for stock data  
- Safe testing with isolated test files  
- Console-based menu navigation for role-based access  
UML Diagram
The following UML diagram illustrates the class structure of the Supermarket Management System, including inheritance relationships between Supermarket, Product, and User classes.

![UML Diagram](UMLdiagram.drawio.png)
