#include <iostream>
#include <fstream>
#include <string>
#include "HotelSystem.hpp"

using namespace std;

bool isRoomOccupied(int roomNo, string date)
{
    ifstream in("reservations.txt");
    string user, d;
    int type, room;

    while (in >> user >> type >> room >> d)
    {
        if (room == roomNo && d == date)
        {
            in.close();
            return true;
        }
    }
    in.close();
    return false;
}

void showRoomStatus(string date)
{
    cout << "\n===== ROOM STATUS (" << date << ") =====\n";

    // Floor 1 – Family Rooms (1–7)
    cout << "Family Rooms  | ";
    for (int i = 1; i <= 7; i++)
    {
        if (isRoomOccupied(i, date))
            cout << "[ X ] " << "\t" ;
        else
            cout << "[ " << i << " ] " << "\t" ;
    }
    cout << endl;

    // Floor 2 – Double Rooms (8-14)
    cout << "Double Rooms  | ";
    for (int i = 8; i <= 14; i++)
    {
        if (isRoomOccupied(i, date))
            cout << "[ X ] " << "\t" ;
        else
            cout << "[ " << i << " ] " << "\t" ;
    }
    cout << endl;

    // Floor 3 – Single Rooms (15–22)
    cout << "Single Rooms  | ";
    for (int i = 15; i <= 22; i++)
    {
        if (isRoomOccupied(i, date))
            cout << "[ X ] " << "\t" ;
        else
            cout << "[ " << i << " ] " << "\t" ;
    }
    cout << endl;

    // Floor 4 – Single Rooms (23–30)
    cout << "Single Rooms  | ";
    for (int i = 23; i <= 30; i++)
    {
        if (isRoomOccupied(i, date))
            cout << "[ X ] " << "\t" ;
        else
            cout << "[ " << i << " ] " << "\t" ;
    }
    cout << endl;
}
