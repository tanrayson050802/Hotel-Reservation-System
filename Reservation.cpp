#include <iostream>
#include <fstream>
#include <string>
#include "HotelSystem.hpp"

using namespace std;

void userMenu(string username)
{
    int choice;

    while (true)
    {
        cout << "\n===== User Menu =====\n";
        cout << "1. View Room Status\n";
        cout << "2. Make Reservation\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            handleInputError();
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            string date;
            int attempts = 0;

            do
            {
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> date;

            if (!isValidDateFormat(date))
            {
                cout << "Invalid date format! Please use YYYY-MM-DD.\n";
            }
            else if (!isBookingDateLogical(date))
            {
                cout << "Invalid booking date. You can only book future dates. \n";
            }
            else
            {
                break;
            }
                attempts++;

            } while (attempts < 2);

            if (attempts == 2)
            {
                cout << "Too many invalid attempts. Reservation cancelled.\n";
                break;
            }

            showRoomStatus(date);
            break;
        }

        case 2:
        {
            int roomType, roomNo;
            string date;
            int attempts = 0;

        do
        {
            cout << "Enter date (YYYY-MM-DD): ";
            cin >> date;

            if (!isValidDateFormat(date))
            {
                cout << "Invalid date format! Please use YYYY-MM-DD.\n";
            }
            else if (!isBookingDateLogical(date))
            {
                cout << "Invalid booking date. You can only book future dates. \n";
            }
            else
            {
                break;
            }

            } while (attempts < 2);

            if (attempts == 2)
            {
                cout << "Too many invalid attempts. Reservation cancelled.\n";
                    break;
            }

        showRoomInfo();
        cout << "Choose room type (1-Single, 2-Double, 3-Family): ";
        cin >> roomType;

        showRoomStatus(date);
        cout << "Choose room number: ";
        cin >> roomNo;

        // Validate room type vs room number
        if (!isRoomTypeValid(roomType, roomNo))
        {
            cout << "Invalid room number for selected room type!\n";
            break;
        }

        // Check occupancy
        if (isRoomOccupied(roomNo, date))
        {
            cout << "Room already booked. Choose another room.\n";
            break;
        }

        // Save reservation
        ofstream out("reservations.txt", ios::app);
        out << username << " " << roomType << " " << roomNo << " " << date << endl;
        out.close();

        generateBill(roomType);
        break;
        }

        case 3:
            cancelBooking(username);
            break;

        case 4:
            showAppreciation();
            return;
        default:
            cout << "Invalid option.\n";
        }
    }
}

    bool isRoomTypeValid(int roomType, int roomNo)
    {
        if (roomType == 1 && roomNo >= 14 && roomNo <= 30)
            return true;
        if (roomType == 2 && roomNo >= 8 && roomNo <= 14)
            return true;
        if (roomType == 3 && roomNo >= 1 && roomNo <= 7)
            return true;

        return false;
    }