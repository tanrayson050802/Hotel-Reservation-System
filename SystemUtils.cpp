#include <iostream>
#include <limits>
#include <cctype>
#include <ctime>
#include <chrono>
#include <string>
#include "HotelSystem.hpp"

using namespace std;

void handleInputError()
{
    cout << "Invalid input. Please enter correct command.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showAppreciation()
{
    cout << "\nThanks for visiting Velvet Vantage Hotel.\n";
    cout << "Wish you have a nice day!\n";
}

bool isValidDateFormat(const string& date)
{
    // Rule 1: Length
    if (date.length() != 10)
        return false;

    // Rule 2: Hyphen positions
    if (date[4] != '-' || date[7] != '-')
        return false;

    // Rule 3: Digits check
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    // Rule 4: Logical month/day check
    int month = stoi(date.substr(5, 2));
    int day   = stoi(date.substr(8, 2));

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    return true;
}

bool isBookingDateLogical(const string& date)
{
    // Convert input date to integers
    int year  = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day   = stoi(date.substr(8, 2));

    // Get current system time (Malaysia uses system local time)
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm localTime = *localtime(&now_time);

    int currYear  = localTime.tm_year + 1900;
    int currMonth = localTime.tm_mon + 1;
    int currDay   = localTime.tm_mday;

    // Compare dates
    if (year < currYear)
        return false;
    if (year == currYear && month < currMonth)
        return false;
    if (year == currYear && month == currMonth && day <= currDay)
        return false;

    // Future date → valid
    return true;
}

bool isUserNameValid(const string& username)
{
    if (username.length() < 6)
        return false;

    bool hasAlpha = false;
    bool hasDigit = false;

    for (char c : username)
    {
        if (isalpha(c))
            hasAlpha = true;
        else if (isdigit(c))
            hasDigit = true;
    }

    return hasAlpha && hasDigit;
}

bool isPasswordValid(const string& password)
{
    if (password.length() < 8)
        return false;

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSymbol = false;

    for (char c : password)
    {
        if (isupper(c))
            hasUpper = true;
        else if (islower(c))
            hasLower = true;
        else if (isdigit(c))
            hasDigit = true;
        else
            hasSymbol = true;
    }

    return hasUpper && hasLower && hasDigit && hasSymbol;
}