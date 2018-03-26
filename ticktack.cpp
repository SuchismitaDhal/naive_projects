//
// THE GAME OF CROSS AND KNOTS
//  possible edits: Option for single player
//                  with computer playing optimally.
//                  Option of ultimate tick-tack-toe as in
//                  https://mathwithbaddrawings.com/2013/06/16/ultimate-tic-tac-toe/
//
#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;

int e[9]={0,0,0,0,0,0,0,0,0}; //the elements global variable
struct player
{
    string name;
    int score;
} one, two;

void TimeWaste();
void PlayerInfo();
int inst(int, int);
void format();
char s(int);
int check();


int main()
{
    int enter,
        cell,
        result,
        status;
    string player1,
           player2;
    char ch = 'y';

    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t***** THE GAME OF CROSS AND KNOT *****";
    cout<<"\n\t\t\t\t\t Press any key. ";
    enter = getch();

    cout<<"\n\n\n\n";
    for( int i = 0; i<120; ++i)
    {
        for(long int i=0;i<3500000;++i);
        cout<<char(177);
    }

    PlayerInfo();
    while(ch=='y' || ch=='Y')
    {
    system("cls");
    cout<<"\n\n\t\t\t LET'S START....";
    TimeWaste();
    for(int j=0; j<=8; ++j)
    {
        system("cls");
        format();
        if(j%2)
            cout<<"\n "<<two.name<<"'s turn : Enter the cell number : ";
        else
            cout<<"\n "<<one.name<<"'s turn : Enter the cell number : ";
        cin>>cell;
        status = inst(cell,(j%2 ? -1:1));
        if(!status) {--j;   continue;}
        if(j>=4)
        {
            result = check();
            if(result==1)
            {
                cout<<"\n\t\t\t"<<one.name<<" WINS./n";
                ++one.score;
            }
            if(result==-1)
            {
                cout<<"\n\t\t\t"<<two.name<<" WINS./n";
                ++two.score;
            }
            if(result)
            {
                cout<<"\n\t Want one more try (y/n) : ";
                ch = getche();
            }
        }
    }
    }

    return 0;
}

void TimeWaste()
{
    for(long int j=-100;j<500000000;++j);
}

 void PlayerInfo()
 {
     cout<<"\n\t Enter the name of player 1 : ";
     cin>>one.name;
     cout<<"\n\t Enter the name of player 2 : ";
     cin>>two.name;
     one.score = 0;
     two.score = 0;
 }

 int inst(int pos, int mark)	//the play graph
{
    char ch;
    if(e[pos])
    {
        cout<<" \n\t\t\t\t already filled position !!   Try again";
        TimeWaste();
        TimeWaste();
        return 0;
    }
    else
    {
        e[pos] = mark ;
        return 1;
    }

}

char sy (int i)
{
    if(i==0) return ' ';
    if(i==1) return 'O';
    if(i==-1) return 'X';
}

void format()
{
    cout<<"\n\t Token O is for "<<one.name<<". Token X is for "<<two.name<<".";
    cout<<"\n\n\t** The cells are numbered from 0-8 horizontally.";
    cout<<"\n\n\n";
    cout<<"\t\t\t \t||\t \t||\t \t\n";
    cout<<"\t\t\t"<<sy(e[0])<<"\t||\t"<<sy(e[1])<<"\t||\t"<<sy(e[2])<<"\t\n";
    cout<<"\t\t\t \t||\t \t||\t \t\n";
    cout<<"\t\t-------------------------------------------------\n";
    cout<<"\t\t\t \t||\t \t||\t \t\n";
    cout<<"\t\t\t"<<sy(e[3])<<"\t||\t"<<sy(e[4])<<"\t||\t"<<sy(e[5])<<"\t\n";
    cout<<"\t\t\t \t||\t \t||\t \t\n";
    cout<<"\t\t-------------------------------------------------\n";
    cout<<"\t\t\t \t||\t \t||\t \t\n";
    cout<<"\t\t\t"<<sy(e[6])<<"\t||\t"<<sy(e[7])<<"\t||\t"<<sy(e[8])<<"\t\n";
    cout<<"\t\t\t \t||\t \t||\t \t\n";

}

int check()
{
    for(int i=0; i<=8; i+=3)
        if(e[i]==e[i+1] && e[i]==e[i+2])
            return e[i];
    for(int i=0; i<=2; ++i)
        if(e[i]==e[i+3] && e[i]==e[i+6])
            return e[i];
    if(e[0]==e[4] && e[0]==e[8])
        return e[0];
    if(e[2]==e[4] && e[2]==e[6])
        return e[2];
    return 0;
}










