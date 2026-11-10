# Bank Management System

A C++ console-based Bank Management System that provides client management, user management, authentication, permissions, and banking transactions through a menu-driven interface.

## Features

### Client Management
- Display all clients
- Add new clients
- Delete clients
- Update client information
- Find clients by account number

### User Management
- Add new users
- Delete users
- Update user information
- Find users
- Manage user permissions

### Authentication
- Username and password login
- User authentication using data stored in a file
- Permission-based access to system operations

### Permissions System
The system uses a **bitmask-based permission system** to control which operations each user can access.

Available permissions include:

- Show client list
- Add new client
- Delete client
- Update client
- Find client
- Transactions
- Manage users
- Exit

The permissions are represented using enum values and bitwise operations.

### Transactions
The system supports:

- Deposit
- Withdraw
- Total balance
- Client transaction operations

### ATM System
The project also includes a separate ATM console application that uses the bank system functionality.

The ATM provides operations such as:

- Login
- Quick withdrawal
- Normal withdrawal
- Deposit
- Check balance

## Technologies

- **C++**
- File handling
- Structures
- Enums
- Functions
- Vectors
- References
- Bitwise operations
- Console-based menus
- Authentication and authorization

## Project Structure

```text
Bank-Management-System/
│
├── bank_system.cpp
├── ATM_system.cpp
├── function_banksystem.h
├── bankfile.txt
├── userfilename.txt
├── .gitignore
└── README.md
```

### Files

**`bank_system.cpp`**

Contains the main Bank Management System, including the main menu, client management, user management, authentication, permissions, and transactions.

**`ATM_system.cpp`**

Contains the separate ATM application and its menu-based operations.

**`function_banksystem.h`**

Contains the shared data structures, enums, functions, file-handling logic, authentication functions, client operations, user operations, and transaction functionality.

**`bankfile.txt`**

Stores the sample client data used by the system.

**`userfilename.txt`**

Stores the sample user data used for authentication and permissions.

> The data files included in this repository contain dummy/sample data for testing purposes.

## How to Run

Make sure a C++ compiler such as `g++` is installed.

### Compile the Bank Management System

```bash
g++ bank_system.cpp -o bank_system
```

Run it:

```bash
./bank_system
```

### Compile the ATM System

```bash
g++ ATM_system.cpp -o ATM_system
```

Run it:

```bash
./ATM_system
```

## Authentication

The system reads user credentials from:

```text
userfilename.txt
```

Users are authenticated using their username and password.

After successful login, the system checks the user's permissions before allowing access to protected operations.

## Permission System

Permissions are implemented using bitwise operations.

Each permission represents a different operation. Multiple permissions can be combined into a single value, allowing a user to have access to multiple features.

For example, permissions can be checked using bitwise `&` operations.

This approach allows the system to efficiently manage multiple permissions for each user.

## Data Storage

The project uses text files for persistent data storage rather than a database.

Client data is stored in:

```text
bankfile.txt
```

User data is stored in:

```text
userfilename.txt
```

The program reads and updates these files when performing client and user operations.

## Project Purpose

This project was developed to practice building a larger C++ console application by combining multiple programming concepts into one system.

It brings together:

- Functions
- Structures
- Vectors
- File handling
- Enums
- Bitwise operations
- Authentication
- Authorization
- Menu-driven applications

## Author

**Mohamed**

This project is part of my C++ programming practice and software development learning journey.
