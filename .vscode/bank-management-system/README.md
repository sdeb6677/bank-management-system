# Bank Management System

## Overview
The Bank Management System is a simple console application that allows users to manage bank accounts. It demonstrates various Object-Oriented Programming (OOP) concepts such as encapsulation, class methods, and user interaction through a menu-driven interface.

## Project Structure
```
bank-management-system
├── include
│   └── account.h
├── src
│   ├── account.cpp
│   └── main.cpp
├── Makefile
└── README.md
```

## Files Description
- **include/account.h**: This header file defines the `Account` class, which includes private properties for `AccountNo`, `Password`, and `Balance`. It also declares public methods for setting and getting these properties, demonstrating encapsulation.

- **src/account.cpp**: This source file implements the methods declared in `account.h`. It includes the logic for setting and retrieving account details, showcasing the implementation of class methods.

- **src/main.cpp**: This file serves as the entry point of the application. It creates an instance of the `Account` class and provides a menu-driven interface for users to interact with the bank management system. It demonstrates the use of loops, conditionals, and user input handling.

- **Makefile**: This file contains the build instructions for compiling the project. It specifies how to compile the source files and link them to create the executable.

## Building the Project
To build the project, navigate to the project directory and run the following command:

```
make
```

This will compile the source files and create the executable.

## Running the Project
After building the project, you can run the application using the following command:

```
./bank_management_system
```

## OOP Concepts Demonstrated
- **Encapsulation**: The `Account` class encapsulates the properties of an account and provides public methods to access and modify these properties.
- **Class Methods**: The project demonstrates the use of class methods for setting and getting account details.
- **User Interaction**: The main application provides a user-friendly interface for interacting with the bank management system, showcasing the use of loops and conditionals.

## Conclusion
This Bank Management System project serves as a practical example of applying OOP principles in C++. It provides a foundation for further enhancements and features that can be added to improve functionality and user experience.