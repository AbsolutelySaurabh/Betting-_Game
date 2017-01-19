#include <iostream>
#include<stdlib.h>

using namespace std;
int cash=100;
void Guess()
{
    cout<<endl;
    if(cash==0)
    {
        cout<<"You are out of Cash "<<endl;
        exit(0);
    }
    char C[3]={'K','Q','J'};
    int bet;
    cout<<endl<<"Enter your bet : $ ";
    cin>>bet;
    if(bet>cash)
    {
        cout<<endl<<"WARNING ::Your bet should be less than or equal to cash"<<endl;
        Guess();
    }
    cout<<"\t"<<"\t"<<"Shuffling........."<<endl;
    for(int i=0;i<5;i++)
    {
        int x=rand()%3;
        int y=rand()%3;
        int temp=C[x];
        C[x]=C[y];
        C[y]=temp;
    }

    int PlayerGuess;
    cout<<"\t"<<"\t"<<"Guess the position of Queen from (1,2,3)  : ";
    cin>>PlayerGuess;
    if(C[PlayerGuess-1]=='Q')
    {
        cash=(cash+bet);
        cout<<"\t"<<"\t"<<"Congratulations You WIN !!"<<endl;
        cout<<"\t"<<"\t"<<"You final balance is $ "<<cash<<endl<<"\t"<<"\t"<<"********************";
    }else
    {
        cash=(cash-bet);
        cout<<"\t"<<"\t"<<"Sorry You Lose !!"<<endl;
        cout<<"\t"<<"\t"<<"The Result was : "<<"{"<<C[0]<<" "<<C[1]<<" "<<C[2]<<"}"<<endl;;
        cout<<"\t"<<"\t"<<"Your final Balance is $ "<<cash<<endl;
    }
    char choice;
    cout<<"\t"<<"\t"<<"Do you want to continue ( Y / N ) :: ";
    cin>>choice;
    if(choice=='Y' || choice=='y')
    {
        Guess();
    }else
    {
        exit(0);
    }

}

int main()
{
    cout<<"\t"<<"\t"<<"Welcome To Saurabh's Game of Guessing"<<endl;
    cout<<"\t"<<"        "<<"*************************************"<<endl;
    cout<<endl<<"\t"<<"\t"<<"Your Cash is : $ "<<cash;

    Guess();
    return 0;
}
