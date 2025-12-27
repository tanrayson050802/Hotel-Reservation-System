#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "HotelSystem.hpp"
using namespace std;

void registerUser()
{
    string username, password;
    string u, p;

    // -------- Username Input --------
    while (true)
    {
        cout << "Enter new username (Must contain at least 6 characters with at least 1 letters and at least 1 numbers): ";
        cin >> username;

        // Check format
        if (!isUserNameValid(username))
        {
            cout << "Invalid username! Must be at least 6 characters with at least 1 letters and at least 1 numbers.\n";
            continue;
        }

        // Check existing username
        ifstream infile("users.txt");
        bool exists = false;

        while (infile >> u >> p)
        {
            if (u == username)
            {
                exists = true;
                break;
            }
        }
        infile.close();

        if (exists)
        {
            cout << "Account already exists! Please login to your existing account or use other username.\n";
            continue;
        }

        break; // valid & unique username
    }

    // -------- Password Input --------
    while (true)
    {
        cout << "Enter password (Must contain at least 8 characters with at least 1 Uppercase, 1 Lowercase, 1 Numbers and 1 Symbol): ";
        cin >> password;

        if (!isPasswordValid(password))
        {
            cout << "Invalid password! Must contain uppercase, lowercase, number and symbol (min 8 chars).\n";
            continue;
        }

        break;
    }

    // -------- Save User --------
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration successful!\n";
}