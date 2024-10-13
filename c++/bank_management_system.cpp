#include <iostream>
#include <string>

using namespace std;

// Base class for common account functionalities
class BaseAccount {
protected:  // Changed to protected to allow access in the derived class
    string Acc[100];
    string name[100];
    float balance[100];
    string phone[100];
    int n;

public:
    // Common methods that can be used in derived class
    void read() {
        cout << "Enter the number of data: ";
        cin >> n;
        string id = "20";
        string br = "10100";

        if (n <= 100) {
            for (int i = 0; i < n; i++) {
                bool isUnique = true;
                char c[5];  // To store the last 5 digits of the account number
                string account_number;

                do {
                    isUnique = true;
                    cout << "Enter last 5 digits of your Account number: ";

                    for (int j = 0; j < 5; j++) {
                        cin >> c[j];
                    }

                    // Check if the digits within 'c' are unique
                    for (int j = 0; j < 5; j++) {
                        for (int k = j + 1; k < 5; k++) {
                            if (c[j] == c[k]) {
                                isUnique = false;
                                cout << "Account number digits are not unique. Please try again." << endl;
                                break;
                            }
                        }
                        if (!isUnique) break;
                    }

                    // Generate the full account number from the unique digits
                    if (isUnique) {
                        account_number = id + br + string(c, 5);  // Corrected string construction

                        // Check if the account number already exists in the array
                        for (int j = 0; j < i; j++) {
                            if (Acc[j] == account_number) {
                                isUnique = false;
                                cout << "Account number already exists. Please enter a new one." << endl;
                                break;
                            }
                        }
                    }

                } while (!isUnique);

                Acc[i] = account_number;

                // Collect other details after ensuring the account number is unique
                cout << "Enter name: ";
                cin.ignore();  // Clear the input buffer to avoid issues with getline
                getline(cin, name[i]);

                cout << "Enter balance: ";
                cin >> balance[i];
                cin.ignore();  // Clear the input buffer again after cin

                // Phone number input and validation
                string phone_number;
                bool validPhone;
                do {
                    validPhone = true;
                    cout << "Enter registered phone number (10 digits): ";
                    cin >> phone_number;

                    // Check if the phone number is exactly 10 digits
                    if (phone_number.length() != 10) {
                        cout << "Phone number must be exactly 10 digits. Please try again." << endl;
                        validPhone = false;
                    }

                    // Check if the input contains only digits
                    for (char digit : phone_number) {
                        if (!isdigit(digit)) {
                            cout << "Phone number must contain only digits. Please try again." << endl;
                            validPhone = false;
                            break;
                        }
                    }
                } while (!validPhone);

                phone[i] = phone_number;  // Store the validated phone number
            }
        } else {
            cout << "Our bank has a limit of 100 users only." << endl;
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << "Account Number: " << Acc[i] << endl;
            cout << "Name: " << name[i] << endl;
            cout << "Balance: " << balance[i] << endl;
            cout << "Phone Number: " << phone[i] << endl;
            cout << endl;
        }
    }

    // Method for withdrawing money
    
    void amount(string acc, float amount) {
        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                balance[i] += amount;
                cout << "Deposit successful. New balance: " << balance[i] << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void amount(string acc, float amount, char type) {
        if (type == 'w') {
            for (int i = 0; i < n; i++) {
                if (Acc[i] == acc) {
                    if (balance[i] >= amount) {
                        balance[i] -= amount;
                        cout << "Withdrawal successful. New balance: " << balance[i] << endl;
                    } else {
                        cout << "Insufficient balance." << endl;
                    }
                    return;
                }
            }
            cout << "Account not found." << endl;
        } else {
            cout << "Invalid transaction type." << endl;
        }
    }
};

// Derived class from BaseAccount
class Account : public BaseAccount {
public:
    // Specific methods for account management
    void del_user() {
        string acc;
        cout << "Enter account number to delete: ";
        cin >> acc;
        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                for (int j = i; j < n - 1; j++) {
                    Acc[j] = Acc[j + 1];
                    name[j] = name[j + 1];
                    balance[j] = balance[j + 1];
                    phone[j] = phone[j + 1];
                }
                n--;
                cout << "Account deleted successfully." << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void search_user() {
        string acc;
        cout << "Enter account number to search: ";
        cin >> acc;
        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                cout << "Account found!" << endl;
                cout << "Name: " << name[i] << endl;
                cout << "Balance: " << balance[i] << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }
 // 2. Overloaded function to edit name directly
    void edit_user(string acc, string new_name) {
        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                name[i] = new_name;
                cout << "Name updated successfully." << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    // 3. Overloaded function to edit phone number directly
    void edit_user(string acc, string new_phone, bool isPhone) {
        if (!isPhone) {
            cout << "Invalid parameter for phone editing." << endl;
            return;
        }
        // Validate new_phone
        if (new_phone.length() != 10) {
            cout << "Phone number must be exactly 10 digits." << endl;
            return;
        }
        for (char digit : new_phone) {
            if (!isdigit(digit)) {
                cout << "Phone number must contain only digits." << endl;
                return;
            }
        }

        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                phone[i] = new_phone;
                cout << "Phone number updated successfully." << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

};


int main() {
    Account account;
    int choice;

    while (true) {
        cout << "\n=== Bank Account Management System ===\n";
        cout << "1. Create Accounts\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Deposit Money\n";
        cout << "5. Delete Account\n";
        cout << "6. Search Account Record\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.read();
                break;
            case 2:
                account.display();
                break;
            case 3: {
                string acc;
                float amount;
                cout << "Enter account number: ";
                cin >> acc;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.amount(acc, amount, 'w');  // Call amount method with 'w' for withdrawal
                break;
            }
            case 4: {
                string acc;
                float amount;
                cout << "Enter account number: ";
                cin >> acc;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.amount(acc, amount);  // Call amount method for deposit
                break;
            }
            case 5:
                account.del_user();
                break;
            case 6:
                account.search_user();
                break;
            case 7:
                cout << "Exiting the program. Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
