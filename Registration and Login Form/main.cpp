#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class temp {
    string userName, Email, password;
    string searchName, searchEmail, searchPass;
    fstream file;
public:
    void login();
    void signUp();
    void forgot();
}obj;

int main()
{
    int choice;

    while (true)
    {
        cout << "\n1. Login" << endl;
        cout << "2. Sign Up" << endl;
        cout << "3. Forgot Password" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            obj.login();
            break;
        case 2:
            obj.signUp();
            break;
        case 3:
            obj.forgot();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid Option. Please try again." << endl;
        }
    }
}

void temp :: signUp()
{
    cout << "---Sign Up---" << endl;
    cout << "Enter username:";
    getline(cin, userName);
    cout << "Enter email:";
    getline(cin, Email);
    cout << "Enter password:";
    getline(cin, password);

    file.open("loginData.txt", ios::out|ios::app);
    if(!file){
        cout << "Error opening file!" << endl;
        return;
    }

    file << userName << "*" << Email << "*" << password << endl;
    file.close();
    cout << "Sign Up Successful!" << endl;
}

void temp::login()
{
    cout << "--- LOGIN ---" << endl;
    cout << "Enter username: ";
    getline(cin, searchName);
    cout << "Enter password: ";
    getline(cin, searchPass);

    bool found = false;
    file.open("loginData.txt", ios::in);

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(file, userName, '*') &&
           getline(file, Email, '*') &&
           getline(file, password))
    {
        if (userName == searchName)
        {
            if (password == searchPass)
            {
                cout << "Account Login Successful!" << endl;
                cout << "Username: " << userName << "\nEmail: " << Email << endl;
            }
            else
            {
                cout << "Password is incorrect!" << endl;
            }
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Account not found!" << endl;

    file.close();
}

void temp::forgot()
{
    cout << "--- Forgot Password ---" << endl;
    cout << "Enter username: ";
    getline(cin, searchName);
    cout << "Enter email: ";
    getline(cin, searchEmail);

    bool found = false;
    file.open("loginData.txt", ios::in);

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(file, userName, '*') &&
           getline(file, Email, '*') &&
           getline(file, password))
    {
        if (userName == searchName && Email == searchEmail)
        {
            cout << "Account found!" << endl;
            cout << "Your password is: " << password << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "No matching account found!" << endl;

    file.close();
}
