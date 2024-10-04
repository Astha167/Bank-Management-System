#include <iostream>
#include<string>
using namespace std;

class Account{
    string Acc[100];
    string name[100];
    int balance[100];
    long long int phone[100];
    public:
      int n;
      void read();
      void display();
      void withdraw();
      void deposit();
      void del_user();
};

void Account::read() {
    cout << "Enter the number of data: ";
    cin >> n;
    string id = "20";      
    string br = "10100";   
    if(n<=100){
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

            // Check if the digits within 'c' are unique
            for (int j = 0; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {  // Compare each digit with subsequent digits
                    if (c[j] == c[k]) {
                        isUnique = false;
                        cout << "Account number digits are not unique. Please try again." << endl;
                        break;
                    }
                }
                if (!isUnique) break;  // Exit the loop if a duplicate digit is found
            }

            // Generate the full account number from the unique digits
            if (isUnique) {
                account_number = id + br + string(c, 5);

                // Check if the account number already exists in the array
                for (int j = 0; j < i; j++) {
                    if (Acc[j] == account_number) {
                        isUnique = false;
                        cout << "Account number already exists. Please enter a new one." << endl;
                        break;
                    }
                }
            }

        } while (!isUnique);  // Repeat until the account number is both unique in digits and not a duplicate in the array

        // If the account number is unique, store it in the array
        Acc[i] = account_number;

        // Collect other details after ensuring the account number is unique
        cout << "Enter name: ";
        cin.ignore();  // Clear the newline character left by previous cin
        getline(cin, name[i]);

        cout << "Enter balance: ";
        cin >> balance[i];

        cout << "Enter registered phone number: ";
        cin >> phone[i];
    }
}
  else{
    cout<<"Our bank has the limit of 100 users only"l
}

void Account::display(){
    for (int i=0;i<n;i++){
        cout<<"Account Number: "<<Acc[i]<<endl;
        cout<<"Name: "<<name[i]<<endl;
        cout<<"Balance: "<<balance[i]<<endl;
        cout<<"Phone Number: "<<phone[i]<<endl;
        cout<<endl;
    }
}

void Account::withdraw(){
    string acc;
    int amount;
    cout<<"Enter account number: ";
    cin>>acc;
    cout<<"Enter amount to withdraw: ";
    cin>>amount;
    for(int i=0;i<n;i++){
        if(Acc[i]==acc){
            if(balance[i]>=amount){
                balance[i]-=amount;
                cout<<"Withdrawal successful. New balance: "<<balance[i]<<endl;
            }else{
                cout<<"Insufficient balance."<<endl;
            }
            return;
        }
    }
    cout<<"Account not found."<<endl;
}

void Account::deposit(){
    string acc;
    int amount;
    cout<<"Enter account number: ";
    cin>>acc;
    cout<<"Enter amount to deposit: ";
    cin>>amount;
    for(int i=0;i<n;i++){
        if(Acc[i]==acc){
            balance[i]+=amount;
            cout<<"Deposit successful. New balance: "<<balance[i]<<endl;
            return;
        }
    }
    cout<<"Account not found."<<endl;
}

void Account::del_user(){
    string acc;
    cout<<"Enter account number to delete: ";
    cin>>acc;
    for(int i=0;i<n;i++){
        if(Acc[i]==acc){
            for(int j=i;j<n-1;j++){
                Acc[j]=Acc[j+1];
                name[j]=name[j+1];
                balance[j]=balance[j+1];
                phone[j]=phone[j+1];
            }
            n--;
            cout<<"Account deleted successfully."<<endl;
            return;
        }
    }
    cout<<"Account not found."<<endl;
}

int main() {
    Account account;
    int choice;
    while(true){
        cout<<"1. Read data"<<endl;
        cout<<"2. Display data"<<endl;
        cout<<"3. Withdraw"<<endl;
        cout<<"4. Deposit"<<endl;
        cout<<"5. Delete user"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                account.read();
                break;
            case 2:
                account.display();
                break;
            case 3:
                account.withdraw();
                break;
            case 4:
                account.deposit();
                break;
            case 5:
                account.del_user();
                break;
            case 6:
                return 0;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    return 0;
}
