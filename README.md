✅ 1. ABSTRACT

This project is a Microfinance Cooperative Banking Management System written in the C programming language.
It allows users to manage cooperative microfinance banking operations such as registering products (loan types, savings types), storing them to a file, and viewing the stored products.
The system uses file handling to maintain persistent data.

It is designed for small community cooperatives and microfinance institutions that need a simple offline product-management system.

✅ 2. FEATURES OF THE PROGRAM

Add microfinance financial products (loan, savings, insurance)

Store product records in text file (products.txt)

View all stored products

Search product by ID (optional extension)

User-friendly menu system

Data stored permanently using file-handling

Input validation and error handling

✅ 3. TECHNICAL REQUIREMENTS

Language: C

Compiler: GCC / MinGW / Clang

Operating System: Windows, Linux, MacOS

Required Knowledge:

File Handling

Structs

Basic C I/O

Loops & Conditionals

✅ 4. FUNCTIONAL REQUIREMENTS
User should be able to:

Add new microfinance product

Display all products

Search product by ID

Exit system

System should:

Store each product in products.txt

Retrieve stored products when requested

Validate user input

Show menu options clearly

Prevent accidental data loss

✅ 5. HOW TO RUN THE PROGRAM
Linux / Mac
gcc microfinance.c -o microfinance
./microfinance

Windows (MinGW)
gcc microfinance.c -o microfinance.exe
microfinance.exe

✅ 6. DATA STORAGE FILE

All data is stored in:

products.txt


Each product is saved as:

ID | Name | Type | Interest Rate | Min Amount | Max Amount
