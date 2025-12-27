#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "HotelSystem.hpp"
using namespace std;

void loginUser()
{
    string username, password, u, p;
    bool found = false;
    int attempts = 0;

    while (attempts < 3)
    {
        cout << "Username: ";
        cin >> username;

        // Optional: validate username format
        if (!isUserNameValid(username))
        {
            cout << "Invalid username format.\n";
            attempts++;
            continue;
        }

        cout << "Password: ";
        cin >> password;

        // Optional: validate password format
        if (!isPasswordValid(password))
        {
            cout << "Invalid password format.\n";
            attempts++;
            continue;
        }

        ifstream infile("users.txt");
        found = false;

        while (infile >> u >> p)
        {
            if (u == username)
            {
                found = true;

                if (p == password)
                {
                    cout << "Login successful!\n";
                    infile.close();
                    userMenu(username);
                    return;
                }
                else
                {
                    cout << "Incorrect password.\n";
                    infile.close();

                    char choice;
                    cout << "Do you want to reset your password? (Y/N): ";
                    cin >> choice;

                    if (choice == 'Y' || choice == 'y')
                        forgotPassword();

                    return;
                }
            }
        }

        infile.close();

        if (!found)
        {
            cout << "Account not found. Please register.\n";
            return;
        }

        attempts++;
    }

    cout << "Too many failed login attempts.\n";
}
