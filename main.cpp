#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y);
void setColor(int c);
void box();

int main()
{
    int x = 1, i;
    box();
    for(i=0; i<=100; i++){

        if(i>66)setColor(0x0c);
        else if(i>33) setColor(0x0e);
        else setColor(0x0a);

        if(i%2 == 0){
            x++;
            if(i!=0)gotoxy(15+x, 12);cout<<(char)219;
        }
        setColor(0x0f);
        gotoxy(69,12);cout<<i<<"%";

        if(i==0)Sleep(500);
        else if(i==56)Sleep(700);
        else if(i==99)Sleep(1200);
        else Sleep(100);
    }
    getch();
    return 0;
}
void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, pos);
}
void setColor(int c)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}
void box()
{
    int x;
    for(x=18; x<68; x++){
        gotoxy(x,11);cout<<(char)196;
        gotoxy(x,13);cout<<(char)196;
    }
    gotoxy(17,11);cout<<(char)218;//top left corner
    gotoxy(17,13);cout<<(char)192;//bottom left corner
    gotoxy(17,12);cout<<(char)179;//left boarder
    gotoxy(68,12);cout<<(char)179;//right boarder
    gotoxy(68,11);cout<<(char)191;//top right corner
    gotoxy(68,13);cout<<(char)217;//bottom right corner
}
