//solution for the problem "PRIME1" on SPOJ
//building sieve or Erato, step by step
#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;

int n, arr[100];

void preview()
{
    system("cls");
    cout<<"\n\n\t";
    for(int i=0; i<=n-2; ++i)
    {
        if(arr[i]==1)
            cout<<'X'<<"\t";
        else
            cout<<arr[i]<<"\t";
        if((i+1)%10==0)
            cout<<"\n\t";
    }
    cout<<"\n\n Press any key...";
    char ch = getch();
}

int main()
{
    cout<<"\n\n\t Enter the last number : ";
    cin>>n;

    for(int i=0; i<=n-2; ++i)
       arr[i] = i+2;
    preview();

    for(int i=0; i<=n-2; ++i)
    {
        if(arr[i]==1)   continue;
        for(int j=i+1; j<=n-2; ++j)
            if(arr[j]%arr[i]==0)
                arr[j] = 1;
        preview();
    }

    return 0;
}
