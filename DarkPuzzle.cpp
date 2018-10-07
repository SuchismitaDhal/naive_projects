/**********************************

    Solution to Josephus problem
    (https://en.wikipedia.org/wiki/Josephus_problem)
    using circular singly linked list
    Date : 07 October 2018

***********************************/
#include<iostream>
#include<iomanip>       //for setw()
#include<cstdlib>       //for malloc()
#define N 100           //number of people creating the circle
using namespace std;

struct ele
{
    int val;
    struct ele *next;
};

int main()
{
    struct ele *start = NULL, *ptr = NULL;
    int counter =0;
        //initialisation of the circular list
    for(int i=1; i<=N; ++i)
    {
        struct ele *newele;
        newele = (struct ele*)malloc(sizeof(struct ele));
        newele->val = i;
        newele->next = NULL;

        if(start == NULL)
        {
            start = newele;
            ptr = newele;
        }
        else
        {
            ptr -> next = newele;
            newele -> next = start;
            ptr = ptr -> next;
        }
    }

    struct ele *sword = start;
        /* sword pointer points to the
           person holding the sword    */
    cout<<"\n\n The killing order will be : \n";
    while(start -> next != start)       //the looping stops when the list contains only one element
    {
        if(sword -> next == start)
            start = start->next;
        if(sword == start)
            cout<<"\n Round : "<<++counter<<"\n";
        cout<<"\t"<<setw(4)<<sword->val<<"  killing "<<setw(3)<<(sword->next)->val<<" \n";
        sword -> next = (sword->next)->next;
        sword = sword->next;
    }

    cout<<"\n\t\t THE ONLY SURVIVER : "<<start -> val<<" !!\n";
    return 0;
}


