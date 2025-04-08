#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

struct PlayerInfo
{
    int X;
    int Y;
    string Shape;
};

void GotoXY(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


int main()
{
    PlayerInfo* PlayerData;
    PlayerData = new PlayerInfo;

    PlayerData->X = 10;
    PlayerData->Y = 10;
    PlayerData->Shape = "P";

    bool IsRunning = true;

    int input;
    while (IsRunning)
    {
        system("cls");
        int MapSize = 20;
        for (int i = 0; i <= MapSize; i++)
        {
            for (int j = 0; j <= MapSize; j++)
            {
                if (i == 0 || j == 0 || i == MapSize || j == MapSize)
                {
                    GotoXY(i, j);
                    cout << "*";
                }
            }
        }

        GotoXY(PlayerData->X, PlayerData->Y);
        cout << PlayerData->Shape;

        input = _getch();
        if (input == 77 || toupper(input) == 'D') {  //오른쪽
            PlayerData->X += 1;
            if (PlayerData->X == MapSize)
            {
                PlayerData->X -= 1;
            }
        }
        else if (input == 75 || toupper(input) == 'A') { //왼쪽
            PlayerData->X -= 1;
            if (PlayerData->X == 0)
            {
                PlayerData->X += 1;
            }
        }
        else if (input == 72 || toupper(input) == 'W') { //위
            PlayerData->Y -= 1;
            if (PlayerData->Y == 0)
            {
                PlayerData->Y += 1;
            }
        }
        else if (input == 80 || toupper(input) == 'S') { //아래
            PlayerData->Y += 1;
            if (PlayerData->Y == MapSize)
            {
                PlayerData->Y -= 1;
            }
        }
        else if (input == 27)
        {
            IsRunning = false;
        }
    }   
    return 0;
}