#include <iostream>
#include <string>

using namespace std;

class BaseAcc {
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
                string acc_num;

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
                        acc_num = id + br + string(c, 5);

                        for (int j = 0; j < i; j++) {
                            if (Acc[j] == acc_num) {
                                isUnique = false;
                                cout << "Account number already exists. Please enter a new one." << endl;
                                break;
                            }
                        }
                    }

                } while (!isUnique);

                Acc[i] = acc_num;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name[i]);

                cout << "Enter balance: ";
                cin >> balance[i];
                cin.ignore();

                string ph;
                bool validph;
                do {
                    validph = true;
                    cout << "Enter registered phone number (10 digits): ";
                    cin >> ph;

                    if (ph.length() != 10) {
                        cout << "Phone number must be exactly 10 digits. Please try again." << endl;
                        validph = false;
                    }

                    for (char digit : ph) {
                        if (!isdigit(digit)) {
                            cout << "Phone number must contain only digits. Please try again." << endl;
                            validph = false;
                            break;
                        }
                    }
                    if (validph) {
            for (int i = 0; i <n; i++) {
                if (phones[i] == ph) {
                    cout << "This phone number is already linked to another account. Please try a different one." << endl;
                    validph = false;
                    break;
                }
            }
        }
                } while (!validph);

                phone[i] = ph;
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

class Account : public BaseAcc {
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
                
            }
        }
        cout << "Account not found." << endl;
    }

    void edit_user(string acc, string new_name) {
        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                name[i] = new_name;
                cout << "Name updated successfully." << endl;
                
            }
        }
        cout << "Account not found." << endl;
    }

    void edit_user(string acc, string new_ph, bool isPhone) {
        if (!isPhone) {
            cout << "Invalid parameter for phone editing." << endl;
            
        }
        if (new_ph.length() != 10) {
            cout << "Phone number must be exactly 10 digits." << endl;
            
        }
        for (char digit : new_ph) {
            if (!isdigit(digit)) {
                cout << "Phone number must contain only digits." << endl;
                
            }
        }

        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                phone[i] = new_ph;
                cout << "Phone number updated successfully." << endl;
                
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
                cout << "Amount credited successfully in your account" << endl;
                cout<<"Current account balance:"<<<< balance[i]<<endl;
                }
        }
        cout << "This account is not registered with us." << endl;
    }

    void amount(string acc, float amount, char type) {
        if (type == 'w') {
            for (int i = 0; i < n; i++) {
                if (Acc[i] == acc) {
                    if (balance[i] >= amount) {
                        balance[i] -= amount;
                        cout << "Amount debited successfully from your account." << endl;
                        cout<<"Current account balance:"<<<< balance[i]<<endl;
                    } else {
                        cout << "Insufficient balance." << endl;
                    }
                   
                }
            }
            cout << "This account is not registered with us." << endl;
        } else {
            cout << "Invalid transaction type." << endl;
        }
    }
void transfer() {
        string sender_acc, receiver_acc;
        float amount;
        bool sender_found = false, receiver_found = false;

        cout << "Enter sender's account number: ";
        cin >> sender_acc;

        int sender;  
        for (int i = 0; i < n; i++) {
            if (Acc[i] == sender_acc) {
                sender_found = true;
                sender= i;
                break;
            }
        }

        if (!sender_found) {
            
            cout << "Sender's account does not exist." << endl;
            
        }
       else{
        cout << "Enter receiver's account number: ";
        cin >> receiver_acc;

        int receiver; 
        for (int i = 0; i < n; i++) {
            if (Acc[i] == receiver_acc) {
                receiver_found = true;
                receiver = i;
                break;
            }
        }

        if (!receiver_found) {
            
            cout << "Receiver's account does not exist." << endl;
        
        }
   else{
        
        cout << "Enter the amount to transfer: ";
        cin >> amount;

        if (balance[sender] < amount) {
            cout << "Insufficient balance in sender's account." << endl;
        
        }
   else{
        
        balance[sender] -= amount;
        balance[receiver] += amount;

        
        cout << "Transfer successful!" << endl;
        cout << "Sender's Current balance: " << balance[sender] << endl;
        cout << "Receiver's Current balance: " << balance[receiver] << endl;
                 }
          }
      }
  }
};

int main() {
    Account account;
    int choice;
    cout<<"\n----------------------Welcome to Cresta Bank----------------------"<<endl;
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
