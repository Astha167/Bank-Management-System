# Cresta Bank : Bank Management System

Overview
Cresta Bank is a C++ based Bank Management System that simulates basic banking operations such as account creation, money transfers, deposits, withdrawals, and account management. The system employs Object-Oriented Programming (OOP) principles like inheritance, encapsulation, and polymorphism to model real-world banking functionalities.

Features
Account Management: Create new accounts, display all accounts, delete accounts, and search for specific account details.
Fund Transactions: Deposit money, withdraw money, and transfer funds between accounts.
Edit Account Details: Modify account holder's name or registered phone number.
Unique Account Validation: Ensure account number uniqueness for each customer.
Phone Number Validation: Ensure phone numbers are exactly 10 digits and are unique to each account.
User-Friendly Interface: Provides an interactive menu-driven interface for easy navigation of features.


Project Structure
The project consists of the following classes:

BaseAcc: Handles basic account-related functionalities such as account creation, display, and validation of unique account numbers and phone numbers.
Account: Extends BaseAcc to include account deletion, searching, and editing features.
Transaction: Inherits from Account to manage transactions such as deposits, withdrawals, and money transfers.

Menu Options:
1. Create Accounts: Allows the creation of new accounts (up to 100 accounts).
2. Display All Accounts: View details of all accounts.
3. Withdraw Money: Withdraw money from an account.
4. Deposit Money: Deposit money into an account.
5. Delete Account: Remove an account from the system.
6. Search Account Record: Search for account details using an account number.
7. Edit Account (Name/Phone): Update the name or phone number of an account holder.
8. Transfer Amount: Transfer funds between two accounts.
9. Customer Care Details: Contact information for bank support.
10. Add Account: Add more accounts beyond the initial setup.
11. Exit: Exit the program.

Sample Usage
After running the program, the following example shows how to interact with the system:
----------------------Welcome to Cresta Bank----------------------

=== Bank Account Management System ===
1. Create Accounts
2. Display All Accounts
3. Withdraw Money
4. Deposit Money
5. Delete Account
6. Search Account Record
7. Edit Account (Name/Phone)
8. Transfer amount
9. Customer Care Details
10. Add account
11. Exit

Enter your choice (1-11):


Validation Mechanisms
Unique Account Numbers: Each account is assigned a unique identifier, ensuring no two accounts have the same account number.
Phone Number Validation: The system ensures phone numbers are exactly 10 digits long and unique for each account.
Error Handling: Provides user-friendly messages for invalid inputs, such as non-unique account numbers or incorrectly formatted phone numbers.

Dependencies
Standard C++ libraries (<iostream>, <string>)

Future Enhancements
Implementing a persistent storage system (e.g., file or database) to store account details.
Adding more banking features such as loan management, interest calculations, and transaction history.
Enhancing security with password protection for account access.

Contributing
Contributions to the project are welcome! Please feel free to submit issues or pull requests to enhance the system or add new features.
