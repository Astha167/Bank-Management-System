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
	BaseAcc() : n(0) {}
	
	
    void read() {
    	
        cout << "Enter the number of accounts to create: ";
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

                    for (int m = 0; m < 5; m++) {
                        cin >> c[m];
                    }

                    for (int r = 0; r < 5; r++) {
                        for (int d = r + 1; d < 5; d++) {
                            if (c[r] == c[d]) {
                                isUnique = false;
                                cout << "Account number digits are not unique. Please try again." << endl;
                                break;
                            }
                        }
                        if (!isUnique) break;
                    }

                    if (isUnique) {
                        acc_num = id + br + string(c, 5);

                        for (int k = 0; k< i; k++) {
                            if (Acc[k] == acc_num) {
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

                    for (int p=0;p<ph.length();p++) {
                        char digit=ph[p];
                        if (!isdigit(digit)) {
                            cout << "Phone number must contain only digits. Please try again." << endl;
                            validph = false;
                            break;
                        }
                    }
                    if (validph) {
                        for (int j = 0; j <i; j++) {
                            if (phone[j] == ph) {
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
    
    
     void add() {
    	int add_more;
        cout << "Enter the number of accounts to you wish to add: ";
        cin >> add_more;
        string id = "20";
        string br = "10100";

        if (n <= 100) {
            for (int i = n; i < n+add_more; i++) {
                bool isUnique = true;
                char c[5];
                string acc_num;

                do {
                    isUnique = true;
                    cout << "Enter last 5 digits of your Account number: ";

                    for (int m = 0; m < 5; m++) {
                        cin >> c[m];
                    }

                    for (int r = 0; r < 5; r++) {
                        for (int d = r + 1; d < 5; d++) {
                            if (c[r] == c[d]) {
                                isUnique = false;
                                cout << "Account number digits are not unique. Please try again." << endl;
                                break;
                            }
                        }
                        if (!isUnique) break;
                    }

                    if (isUnique) {
                        acc_num = id + br + string(c, 5);

                        for (int k = 0; k< i; k++) {
                            if (Acc[k] == acc_num) {
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

                    for (int p=0;p<ph.length();p++) {
                        char digit=ph[p];
                        if (!isdigit(digit)) {
                            cout << "Phone number must contain only digits. Please try again." << endl;
                            validph = false;
                            break;
                        }
                    }
                    if (validph) {
                        for (int j = 0; j <i; j++) {
                            if (phone[j] == ph) {
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
        n=n+add_more;
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

class Account : public BaseAcc{
public:
    void del_user() {
        string acc;
        cout << "Enter account number to delete: ";
        cin >> acc;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                found = true;
                for (int j = i; j < n - 1; j++) {
                    Acc[j] = Acc[j + 1];
                    name[j] = name[j + 1];
                    balance[j] = balance[j + 1];
                    phone[j] = phone[j + 1];
                }
                n--;
                cout << "Account deleted successfully." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Account not found." << endl;
        }
    }

    void search_user() {
        string acc;
        cout << "Enter account number to search: ";
        cin >> acc;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                found = true;
                cout << "Account found!" << endl;
                cout << "Name: " << name[i] << endl;
                cout << "Balance: " << balance[i] << endl;
                cout << "Phone Number: " << phone[i] << endl;
                break;
            }
        }
        if (!found) {
            cout << "Account not found." << endl;
        }
    }

    void edit_user(string acc, string new_name) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                found = true;
                name[i] = new_name;
                cout << "Name updated successfully." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Account not found." << endl;
        }
    }

    void edit_user(string acc, string new_ph, bool isPhone) {
        if (!isPhone) {
            cout << "Invalid parameter for phone editing." << endl;
            return;
        }

        if (new_ph.length() != 10) {
            cout << "Phone number must be exactly 10 digits." << endl;
            return;
        }

        for (int i=0;i<new_ph.length();i++) {
        	char digit=new_ph[i];
            if (!isdigit(digit)) {
                cout << "Phone number must contain only digits." << endl;
                return;
            }
        }

        bool found = false;
        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                found = true;
                phone[i] = new_ph;
                cout << "Phone number updated successfully." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Account not found." << endl;
        }
    }
};

class Transaction : public Account {
public:
    void amount(string acc, float amount) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (Acc[i] == acc) {
                found = true;
                balance[i] += amount;
                cout << "Amount credited successfully in your account." << endl;
                cout << "Current account balance: " << balance[i] << endl;
                break;
            }
        }
        if (!found) {
            cout << "This account is not registered with us." << endl;
        }
    }

    void amount(string acc, float amount, char type) {
        if (type == 'w') {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (Acc[i] == acc) {
                    found = true;
                    if (balance[i] >= amount) {
                        balance[i] -= amount;
                        cout << "Amount debited successfully from your account." << endl;
                        cout << "Current account balance: " << balance[i] << endl;
                    } else {
                        cout << "Insufficient balance." << endl;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "This account is not registered with us." << endl;
            }
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
                sender = i;
                break;
            }
        }

        if (!sender_found) {
            cout << "Sender's account does not exist." << endl;
            return;
        }

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
            return;
        }

        cout << "Enter the amount to transfer: ";
        cin >> amount;

        if (balance[sender] < amount) {
            cout << "Insufficient balance in sender's account." << endl;
            return;
        }

        balance[sender] -= amount;
        balance[receiver] += amount;

        cout << "Transfer successful!" << endl;
        cout << "Sender's Current balance: " << balance[sender] << endl;
        cout << "Receiver's Current balance: " << balance[receiver] << endl;
    }
};

int main() {
    
    Transaction t;
    int choice;
    cout << "\n----------------------Welcome to Cresta Bank----------------------" << endl;
    while (true) {
        cout << "\n=== Bank Account Management System ===\n";
        cout << "1. Create Accounts" << endl;
        cout << "2. Display All Accounts" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Delete Account" << endl;
        cout << "6. Search Account Record" << endl;
        cout << "7. Edit Account (Name/Phone)" << endl;
        cout << "8. Transfer amount" << endl;
        cout << "9. Customer Care Details" << endl;
        cout << "10. Add account"<<endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice (1-11): " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                t.read();
                break;
            case 2:
                t.display();
                break;
            case 3: {
                string acc;
                float amount;
                cout << "Enter account number: ";
                cin >> acc;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                t.amount(acc, amount, 'w');
                break;
            }
            case 4: {
                string acc;
                float amount;
                cout << "Enter account number: ";
                cin >> acc;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                t.amount(acc, amount);
                break;
            }
            case 5:
                t.del_user();
                break;
            case 6:
                t.search_user();
                break;
            case 7: {
                string acc;
                int edit_choice;
                cout << "Enter account number to edit: ";
                cin >> acc;
                cout << "What would you like to edit?\n";
                cout << "1. Edit Name\n";
                cout << "2. Edit Phone Number\n";
                cout << "Enter your choice: ";
                cin >> edit_choice;

                if (edit_choice == 1) {
                    string new_name;
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, new_name);
                    t.edit_user(acc, new_name);
                } else if (edit_choice == 2) {
                    string new_ph;
                    cout << "Enter new phone number (10 digits): ";
                    cin >> new_ph;
                    t.edit_user(acc, new_ph, true);
                } else {
                    cout << "Invalid choice. Returning to the main menu." << endl;
                }
                break;
            }
            case 8:
                t.transfer();
                break;
            case 9:
                cout << "CONTACT US" << endl;
                cout << "Phone number: +020 6193 6255" << endl;
                cout << "Email us at: crestabankmanager@outlook.com" << endl;
                break;
            case 10:
            	t.add();break;
            case 11:
                cout << "Thank you for using our bank system. Have a nice day ahead!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
