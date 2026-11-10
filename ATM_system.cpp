#include <iostream>
#include <vector>
#include <fstream> 
#include <string>
#include <iomanip> 
#include "function_banksystem.h"
#include <cmath> 
using namespace std;
using namespace MybankLibrarry;

enum enATMmainmenue {
    enquickwithdrow=1,
    enNormalwithdrwa=2,
    enDeposet=3,
    enchackbalanace=4,
    enlogout=5
};


void mainmune();
void ATMchoice(enATMmainmenue choice);
void login(){

bool loginfail=false;
string username,password;

do
{
   

 system("clear");
 cout<<"------------------------------------\n";
cout<<"            login page             \n";
cout<<"------------------------------------\n";
if (loginfail)
{
    cout<<"invalid username or password\n";
}

cout<<"enter the username: ";
cin>>username;
cout<<"enter the password: ";
cin>>password;

loginfail=!loginchaeck(username,password);



} while (loginfail);

mainmune();
}

void mainmune(){
system("clear");
    int choice;
    cout<<"===========================================\n";
    cout<<"            ATM Main Menue screen          \n";
    cout<<"===========================================\n";
    cout<<"          [1]Quick Withdraw.          \n";
    cout<<"          [2]Normal Withdraw.          \n";
    cout<<"          [3]Deposit          \n";
    cout<<"          [4]check balance         \n";
    cout<<"          [5]Logout          \n";
    cout<<"===========================================\n";

ATMchoice((enATMmainmenue)choiceAtmnumber());





}
int quickwithdrawoptions(int number){
int arry[9]{20,50,100,200,400,600,800,1000,-1};
return arry[number-1];



}
void quiclwithdraw(){

    int amount;
  char witdraw='N';
  bool canwithdraw;
do
{
    system ("clear");
    cout<<"===========================================\n";
    cout<<"            ATM Main Menue screen          \n";
    cout<<"===========================================\n";
    cout<<"        [1]20        [2]50              \n";
    cout<<"        [3]100       [4]200              \n";
    cout<<"        [5]400       [6]600              \n";
    cout<<"        [7]800       [8]1000             \n";
    cout<<"        [9]Exit                          \n";
cout <<"Your account balnce is "<<currentclient.AcountBalnace<<endl;
cout<<"chooes what to withdraw from [1] to [8] ? ";
cin>>amount;
amount=quickwithdrawoptions(amount);
if ((amount>currentclient.AcountBalnace))
{
    cout <<"the amount exceed you balance plese make other choice\n";
    canwithdraw=false;
    Pause();
   
}else{

canwithdraw=true;

}

} while (!canwithdraw);

if (amount!=-1)
{
    cout <<"are you sure you want to make this opration Y/N ?  \n";
    cin>>witdraw;
if (witdraw=='y'||witdraw=='Y')
{
    currentclient.AcountBalnace=currentclient.AcountBalnace-amount;

    cout<<"Done Successfully. new blalance is: "<<currentclient.AcountBalnace<<endl;
}

}



}
int amountinserted( ){
bool accepted=false;
int amount;
do
{
    cout<<"\nEnter an amount multiple of 5's ? ";
     cin >>amount;
    if (amount%5==0)
    {
        accepted=true;
    }
    
    
} while (!accepted);

return amount;

}
void Normalwithdraw(){
    bool canwithdreaw=false;
      char witdraw='N';
int amount;
    do
    {
       amount=amountinserted();
      if (amount>currentclient.AcountBalnace)
      {
            cout <<"the amount exceed you balance plese make other choice.\n";
            canwithdreaw=false;
      }else{

        canwithdreaw=true;
      }
      
    } while (!canwithdreaw);
    
        cout <<"are you sure you want to make this opration Y/N ?  \n";
    cin>>witdraw;
if (witdraw=='y'||witdraw=='Y')
{
    currentclient.AcountBalnace=currentclient.AcountBalnace-amount;

    cout<<"Done Successfully. new blalance is: "<<currentclient.AcountBalnace<<endl;
}



}

int postivnumber(){
int number ;
do
{
    cout <<"enter positive Deposit amount ?";
cin>>number;
} while (number<=0);
return number;


}
void Depsit(){
    char oprate='N';
int amount =postivnumber();
cout<<"are you sure you want to preform this trancaction y/n?\n";
cin>>oprate;
if (oprate=='y'||oprate=='Y')
{
    currentclient.AcountBalnace+=amount;
    cout<<"Done Successfully. new blalance is: "<<currentclient.AcountBalnace<<endl;
}





}
void checkbalance(){

cout<<"you  balance is: "<<currentclient.AcountBalnace<<endl;



}

void ATMchoice(enATMmainmenue choice){


switch (choice)
{
case enATMmainmenue::enquickwithdrow :

 system("clear");
quiclwithdraw();
Pause();

mainmune();
break;

case enATMmainmenue::enNormalwithdrwa :
     system("clear");
Normalwithdraw();
Pause();

mainmune();

    break;

    case enATMmainmenue::enDeposet :
   system("clear");
   Depsit();
   Pause();


   mainmune();
    break;

    case enATMmainmenue::enchackbalanace :
    system("clear");
checkbalance();
 Pause();
    mainmune();
    break;

    case enATMmainmenue::enlogout :
   system("clear");
updateclient(currentclient);
login();
    break;
    

}










}



int main(){


login();


}