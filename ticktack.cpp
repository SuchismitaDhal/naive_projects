//
// THE GAME OF CROSS AND KNOTS
//  possible edits: (for the next version ;))
//        Option for single player
//        with computer playing optimally.
//        Option of ultimate tick-tack-toe as in
//        https://mathwithbaddrawings.com/2013/06/16/ultimate-tic-tac-toe/
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

void TimeWaste();         //for elegant transitions
void PlayerInfo();        //takes Player,s names and assigns initial score
int inst(int, int);       //makes the move or makes changes in the game grid
char sy(int);             //returns the tokens for its integer representation
void format();            //drafts the game grid on screen
int check();              /* checks for the possible winning trio across three
                             rows, 3 columns and 2 diagonals */
void end();               //shows the end message


int main()
{
    int enter,
        cell,
        result,
        status;

    char ch = 'y';

    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t***** THE GAME OF CROSS AND KNOT *****";
    cout<<"\n\t\t\t\t\t Press any key. ";
    enter = getch();

              //my attempt to make a loding.. bar
    cout<<"\n\n\n\n";
    for( int i = 0; i<120; ++i)
    {
        for(long int i=0;i<3500000;++i);
        cout<<char(177);
    }

    PlayerInfo();
    while(ch == 'y' || ch == 'Y')
    {
      system("cls");
      cout<<"\n\n\t\t\t LET'S START....";
      TimeWaste();

            //Initial Conditions
      for(int i=0; i<9; ++i)
        e[i] = 0;

      int j;
      for(j=1; j<=9; ++j)
      {
        system("cls");
        format();

        if(j%2)
            cout<<"\n "<<one.name<<"'s turn : Enter the cell number : ";
        else
            cout<<"\n "<<two.name<<"'s turn : Enter the cell number : ";
        cin>>cell;

        status = inst(cell,(j%2 ? -1:1));
            //status returns 0 when the position is not vacant
        if(!status) {--j;   continue;}

        if(j>=4)
        {
            result = check();
            if(result==-1)
            {
                cout<<"\n\t\t\t"<<one.name<<" WINS.\n";
                ++one.score;
            }
            if(result==1)
            {
                cout<<"\n\t\t\t"<<two.name<<" WINS.\n";
                ++two.score;
            }
            if(result)    //one of the player won
            {
                cout<<"\n\t Want one more try (y/n) : ";
                ch = getche();
                break;
            }
        }
      }

      if(j == 10)
      {
        cout<<"\n\t\t\t It's a tie!!\n";
        cout<<"\n\t Want one more try (y/n) : ";
        ch = getche();
      }
    }

    end();
    return 0;
}
/////////////////////////////////////////////////////////////////////////
void TimeWaste()
{
    for(long int j=-100;j<500000000;++j);
}
/////////////////////////////////////////////////////////////////////////
 void PlayerInfo()
 {
     cout<<"\n\t Enter the name of player 1 : ";
     cin>>one.name;
     cout<<"\n\t Enter the name of player 2 : ";
     cin>>two.name;
     one.score = 0;
     two.score = 0;
 }
/////////////////////////////////////////////////////////////////////////
 int inst(int pos, int mark)
{
    char ch;
    if(e[pos-1])
    {
        cout<<" \n\t\t\t\t already filled position !!   Try again";
        TimeWaste();
        TimeWaste();
        return 0;
    }
    else
    {
        e[pos-1] = mark ;
        return 1;
    }
}
/////////////////////////////////////////////////////////////////////////
char sy(int i)
{
    if(i==0) return ' ';
    if(i==1) return 'O';
    if(i==-1) return 'X';
}
/////////////////////////////////////////////////////////////////////////
void format()
{
    cout<<"\n\t Token X is for "<<one.name<<". Token O is for "<<two.name<<".";
              //As the name of the game is cross and knot
    cout<<"\n\n\t** The cells are numbered from 1-9 horizontally.";
    cout<<"\n\n\n";
    cout<<"\t\t\t \t||\t \t||\t \t\n";
    cout<<"\t\t\t"<<sy(e[0])<<"\t||\t"<<sy(e[1])<<"\t||\t"<<sy(e[2])<<"\t\n";
    cout<<"\t\t\t       1||\t       2||\t       3\n";
    cout<<"\t\t-------------------------------------------------\n";
    cout<<"\t\t\t \t||\t \t||\t \t\n";
    cout<<"\t\t\t"<<sy(e[3])<<"\t||\t"<<sy(e[4])<<"\t||\t"<<sy(e[5])<<"\t\n";
    cout<<"\t\t\t       4||\t       5||\t       6\n";
    cout<<"\t\t-------------------------------------------------\n";
    cout<<"\t\t\t \t||\t \t||\t \t\n";
    cout<<"\t\t\t"<<sy(e[6])<<"\t||\t"<<sy(e[7])<<"\t||\t"<<sy(e[8])<<"\t\n";
    cout<<"\t\t\t       7||\t       8||\t       9\n";

}
/////////////////////////////////////////////////////////////////////////
int check()
{
    //horizontally
    for(int i=0; i<=8; i+=3)
        if(e[i]==e[i+1] && e[i]==e[i+2])
            return e[i];

    //vertically
    for(int i=0; i<=2; ++i)
        if(e[i]==e[i+3] && e[i]==e[i+6])
            return e[i];

    //prime diagonal
    if(e[0]==e[4] && e[0]==e[8])
        return e[0];

    //the other diagonal
    if(e[2]==e[4] && e[2]==e[6])
        return e[2];

    return 0;
}
/////////////////////////////////////////////////////////////////////////
void end()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t***** THANKS FOR PLAYING !! *****";
    cout<<"\n\t\t\t\t   ::::::Final Scoreboard :::::: ";
    cout<<"\n\n\t\t\t\t\t"<<one.name<<" : "<<one.score<<" ::: "<<two.name<<" : "<<two.score;
    cout<<"\n\n\n\n\n\n\n\n";
    exit(0);
}
