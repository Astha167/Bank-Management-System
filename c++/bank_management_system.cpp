#include <iostream>
#include <string>

using namespace std;

class BaseAccount {
protected:
    string Acc[100];
    string name[100];
    float balance[100];
    string phone[100];
    int n;

public:
    void read() {
        cout << "Enter the number of data: ";
        cin >> n;
        string id = "20";
        string br = "10100";

        if (n <= 100) {
            for (int i = 0; i < n; i++) {
                bool isUnique = true;
                char c[5];
                string account_number;

                do {
                    isUnique = true;
                    cout << "Enter last 5 digits of your Account number: ";

                    for (int j = 0; j < 5; j++) {
                        cin >> c[j];
                    }

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

                    if (isUnique) {
                        account_number = id + br + string(c, 5);

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

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name[i]);

                cout << "Enter balance: ";
                cin >> balance[i];
                cin.ignore();

                string phone_number;
                bool validPhone;
                do {
                    validPhone = true;
                    cout << "Enter registered phone number (10 digits): ";
                    cin >> phone_number;

                    if (phone_number.length() != 10) {
                        cout << "Phone number must be exactly 10 digits. Please try again." << endl;
                        validPhone = false;
                    }

                    for (char digit : phone_number) {
                        if (!isdigit(digit)) {
                            cout << "Phone number must contain only digits. Please try again." << endl;
                            validPhone = false;
                            break;
                        }
                    }
                } while (!validPhone);

                phone[i] = phone_number;
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
};

class Account : public BaseAccount {
public:
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

    void edit_user(string acc, string new_phone, bool isPhone) {
        if (!isPhone) {
            cout << "Invalid parameter for phone editing." << endl;
            return;
        }
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

class Transaction:public BaseAccount{
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
void transfer() {
        string sender_acc, receiver_acc;
        float amount;
        bool sender_found = false, receiver_found = false;

        // Input and validate sender's account number
        cout << "Enter sender's account number: ";
        cin >> sender_acc;

        int sender_index = -1;  // Track index of sender's account
        for (int i = 0; i < n; i++) {
            if (Acc[i] == sender_acc) {
                sender_found = true;
                sender_index = i;
                break;
            }
        }

        if (!sender_found) {
            // Error handling: sender's account does not exist
            cout << "Error: Sender's account number does not exist." << endl;
            return;
        }

        // Input and validate receiver's account number
        cout << "Enter receiver's account number: ";
        cin >> receiver_acc;

        int receiver_index = -1;  // Track index of receiver's account
        for (int i = 0; i < n; i++) {
            if (Acc[i] == receiver_acc) {
                receiver_found = true;
                receiver_index = i;
                break;
            }
        }

        if (!receiver_found) {
            // Error handling: receiver's account does not exist
            cout << "Error: Receiver's account number does not exist." << endl;
            return;
        }

        // Input the transfer amount
        cout << "Enter the amount to transfer: ";
        cin >> amount;

        // Error handling: Check if the sender has enough balance
        if (balance[sender_index] < amount) {
            cout << "Error: Insufficient balance in sender's account." << endl;
            return;
        }

        // Perform the transfer: deduct from sender and add to receiver
        balance[sender_index] -= amount;
        balance[receiver_index] += amount;

        // Display successful transfer message
        cout << "Transfer successful!" << endl;
        cout << "Sender's new balance: " << balance[sender_index] << endl;
        cout << "Receiver's new balance: " << balance[receiver_index] << endl;
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
        cout << "7. Edit Account (Name/Phone)\n";
        cout << "8. Exit\n";
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
                account.amount(acc, amount, 'w');
                break;
            }
            case 4: {
                string acc;
                float amount;
                cout << "Enter account number: ";
                cin >> acc;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.amount(acc, amount);
                break;
            }
            case 5:
                account.del_user();
                break;
            case 6:
                account.search_user();
                break;
            case 7: {
                string acc, new_value;
                int edit_choice;
                cout << "Enter account number to edit: ";
                cin >> acc;
                cout << "What would you like to edit?\n";
                cout << "1. Edit Name\n";
                cout << "2. Edit Phone Number\n";
                cout << "Enter your choice: ";
                cin >> edit_choice;

                if (edit_choice == 1) {
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, new_value);
                    account.edit_user(acc, new_value);
                } else if (edit_choice == 2) {
                    cout << "Enter new phone number (10 digits): ";
                    cin >> new_value;
                    account.edit_user(acc, new_value, true);
                } else {
                    cout << "Invalid choice. Returning to the main menu." << endl;
                }
                break;
            }
            case 8:
                cout << "Exiting the program. Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
