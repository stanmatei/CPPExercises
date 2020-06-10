#include <iostream>
#include <conio.h>
#include <dos.h>

using namespace std;

int i = 1;

void goUp();
void goDown();



int main()
{
    goDown();
    return 0;
}


void goDown(){
    if(++i == 25) goUp();
    else{
        textbackground(0);
        clrscr();
        window(1 , i, 80, i);
        textbackground(5);
        clrscr();
        delay(500);
        goDown();
    }
}

void goDown(){
    if(--i == 1) goDown();
    else{
        textbackground(0);
        clrscr();
        window(1 , i, 80, i);
        textbackground(5);
        clrscr();
        delay(500);
        goUp();
    }
}
