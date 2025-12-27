#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "HotelSystem.hpp"

using namespace std;

void cancelBooking(string username)
{
    vector<string> records;
    ifstream in("reservations.txt");

    string user, fileDate, inputDate; // Use two different strings for dates
    int type, room;
    bool found = false;

    cout << "Enter date to cancel (YYYY-MM-DD): ";
    cin >> inputDate; // Store user input here

    // Read fileDate from the file instead of overwriting inputDate
    while (in >> user >> type >> room >> fileDate)
    {
        // Check if BOTH the username and the date match
        if (user == username && fileDate == inputDate)
        {
            found = true;
            // We do NOT add this to 'records', so it is effectively deleted
        }
        else
        {
            // Keep all other records
            records.push_back(user + " " + to_string(type) + " " + to_string(room) + " " + fileDate);
        }
    }
    in.close();

    if (!found)
    {
        cout << "No booking found for that date.\n";
        return;
    }

    ofstream out("reservations.txt");
    for (auto &r : records)
        out << r << endl;
    out.close();

    cout << "Booking for " << inputDate << " cancelled successfully.\n";
}
