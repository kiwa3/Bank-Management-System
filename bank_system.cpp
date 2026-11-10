#include <iostream>
#include <vector>
#include <fstream> 
#include <string>
#include <iomanip> 
#include "function_banksystem.h"

#include <cmath>
using namespace std;
using namespace MybankLibrarry;

void mainpage(const stusernameandpass&user);
void loginpage();
void mangeuserimplemintion(const stusernameandpass&user);
void adduser();
void deleteuser();
void updateuser();
void finduser();
void ShowClintList(){
vector <client_data> vClients=readfromfile();

cout<<"                           Client List ("<<vClients.size()<<").\n";
cout<<"_________________________________________________________________________________________________________\n\n";
cout<<setw(20)<<left<<"| Account Number";
cout<<setw(15)<<left<<"| Pin Code";
cout<<setw(25)<<left<<"| Client Nmae";
cout<<setw(15)<<left<<"| Phone";
cout<<setw(15)<<left<<"| Balance";
cout<<endl;
cout<<"_________________________________________________________________________________________________________\n\n";

for (client_data &C:vClients)
{
    printclintdata(C);
    cout<<endl;
    
}


}

void ShowusersList(){
vector <stusernameandpass> vusers=readfromfilefromuser();

cout<<"                           Users List ("<<vusers.size()<<").\n";
cout<<"_________________________________________________________________________________________________________\n\n";
cout<<setw(20)<<left<<"| user name";
cout<<setw(15)<<left<<"| password";
cout<<setw(25)<<left<<"| permission";
cout<<endl;
cout<<"_________________________________________________________________________________________________________\n\n";

for (stusernameandpass &U:vusers)
{
    printusrsdata(U);
    cout<<endl;
    
}


}

void ShowClintListfortransaction(){
vector <client_data> vClients=readfromfile();

cout<<"                           Client List ("<<vClients.size()<<").\n";
 cout<<"_____________________________________________________________________________________\n\n";
 cout<<setw(20)<<left<<"| Account Number";
cout<<setw(25)<<left<<"| Client Nmae";
cout<<setw(15)<<left<<"| Balance";
cout<<endl;
 cout<<"_____________________________________________________________________________________\n\n";
double totalamount=0;
for (client_data &C:vClients)
{
    printclintdatafortrancation(C);
     totalamount+=C.AcountBalnace; 
    cout<<endl;
    
}
 cout<<"_____________________________________________________________________________________\n\n";

 cout<<"                            total balnace="<<totalamount<<endl;
}
string getaccountnumber(){
    string accountnumber;
    bool deblicet=true;
while (deblicet)
{
      cout<<"enter acount number: ";
    getline(cin>>ws,accountnumber);
    deblicet=isclinetthere(accountnumber);
    if (deblicet)
    {
        cout<<"acount number is already exists\n";
    }
    
}
return accountnumber;
}

void addingnewclinet(){
client_data client;
char addmore='N';

do
{
    client.Acount_num=getaccountnumber();
clinttofile(saveclintdatawithaccountnumber(client.Acount_num));
cout<<"clint added successfully, do you wan to add more clients? Y/N ";
cin>>addmore;
} while (addmore=='y'||addmore=='Y');

    
}
void deleteclient(){
    client_data client;
    string accoutnnumber;
    char deleting='N';
    cout<<"enter clint number: ";
    cin>>accoutnnumber;

if (isclinetthere(accoutnnumber,client))
{ 
    printclintlinebyline(client);
    cout<<"Are you sure you want to delete this client? y/n";
    cin>>deleting;
    if (deleting=='y'||deleting=='Y')
    {
        deleteclientfromfile(accoutnnumber);
    }
    
    
}
else{
cout<<"acount number dose not exist\n";


}




}
void updateclient(){
string account_number="";
client_data client;
char deleteing='N';
cout<<"enter account number\n";
cin>>account_number;
do
{
   if (isclinetthere(account_number,client))
{
        printclintlinebyline(client);
    cout<<"Are you sure you want to delete this client? y/n";
    cin>>deleteing;
    if (deleteing=='y'||deleteing=='Y')
    {
        updateclient(account_number);
        cout<<"client changed succesfuly\n";
    }

}
else {

cout<<"there is no clint with this account number please enter right account number\n";

}
} while (!isclinetthere(account_number));


}
void findclient(){
    string account_number="";
client_data client;
cout<<"enter account number\n";
cin>>account_number;
    if (isclinetthere(account_number,client))
    {
        printclintlinebyline(client);
    }
    else{

        cout<<"there is no client with is account number\n ";
    }
    









}

void main_munue(){
cout<<"=====================================\n";
cout<<"         "<<"Main Menue Screen\n";
cout<<"=====================================\n";
cout<<"      "<<"[1] Show client List.\n";
cout<<"      "<<"[2] Add New client.\n";
cout<<"      "<<"[3] Delte Client.\n";
cout<<"      "<<"[4] update client.\n";
cout<<"      "<<"[5] Find client.\n";
cout<<"      "<<"[6] Transaction.\n";
cout<<"      "<<"[7] Manage Users.\n";
cout<<"      "<<"[8] logout.\n";

}
void transactionmenue(){
cout<<"=====================================\n";
cout<<"         "<<"transaction Menue Screen\n";
cout<<"=====================================\n";
cout<<"      "<<"[1] Deposit.\n";
cout<<"      "<<"[2] Withdraw.\n";
cout<<"      "<<"[3] Total Balance.\n";
cout<<"      "<<"[4] main menue.\n";


}
void manageuser_munue(){
cout<<"=====================================\n";
cout<<"  "<<"manage Users Menue screen\n";
cout<<"=====================================\n";
cout<<"      "<<"[1] Listuser.\n";
cout<<"      "<<"[2] Add new user.\n";
cout<<"      "<<"[3] Delte user.\n";
cout<<"      "<<"[4] update user.\n";
cout<<"      "<<"[5] Find user.\n";
cout<<"      "<<"[6] Main menue.\n";


}
void dotransaction_case(entransaction casewanted,const stusernameandpass&user);

void trancationwanted(const stusernameandpass&user){
system("clear");
    transactionmenue();
dotransaction_case(entransaction(getnumberfortransaction()),user);

}
void Deposet(){
string clinetnunmber;
client_data client;
double deposit_amount;
char transacton='N';
cout<<"please enter clinet account number\n";
cin>>clinetnunmber;
if (isclinetthere(clinetnunmber,client))
{
    printclintlinebyline(client);
    cout<<"please enter the deposit amount";
    cin>>deposit_amount;
    cout<<"are you sure you want to  preform this transaction? Y/N";
    cin>>transacton;
    if (transacton=='y'||transacton=='Y')
    {
        dotransaction(client,deposit_amount);
        cout<<"deposit is sucsseful\n";
    }
    

}
else{
cout<<"there is no client with this account number \n";

}



}

void withdraw(){
string clinetnunmber;
client_data client;
double withdraw_amount;
char transacton='N';
cout<<"please enter clinet account number\n";
cin>>clinetnunmber;
if (isclinetthere(clinetnunmber,client))
{
    printclintlinebyline(client);
    do
    {
       cout<<"please enter the deposit amount";
    cin>>withdraw_amount;
    if (client.AcountBalnace-withdraw_amount<0)
    {
        cout<<"Acount Exceed Balance, you can withdraw up to : "<<client.AcountBalnace<<endl;
    }
    
    } while (client.AcountBalnace-withdraw_amount<0);
    
    

    cout<<"are you sure you want to  preform this transaction? Y/N";
    cin>>transacton;

    if (transacton=='y'||transacton=='Y')
    {
        dotransaction(client,-withdraw_amount);
        cout<<"deposit is sucsseful\n";
    }
    

}
else{
cout<<"there is no client with this account number \n";

}



}



void dotransaction_case(entransaction casewanted,const stusernameandpass&user){

switch (casewanted)
{
case entransaction::eDeposet:
    Deposet();
    Pause();
trancationwanted(user);

    break;
case entransaction::ewithdraw:


   
    withdraw();
    Pause();
     trancationwanted(user);
    break;
case entransaction::etotalblance:
    ShowClintListfortransaction();
      Pause();
    trancationwanted(user);
  
    break;
    case entransaction::emainmenue:
    mainpage(user);
    break;
}



}



void docase(encasewanted casewanted,const stusernameandpass&user);

void mainpage(const stusernameandpass&user){

    system("clear");
    main_munue();
docase(encasewanted(pow(2,getnumberformainmeune()-1)),user);


}


void docase(encasewanted casewanted,const stusernameandpass&user){
    switch (casewanted)
    {
    case encasewanted::enShowClintList:
        system("clear");
        if (((user.premition&enShowClintList)==enShowClintList)||user.premition==-1)
        {
        ShowClintList();
        Pause();
        }
        else{
        Acesslabil();
        Pause();
        }
        mainpage(user);
        
        break;
    case encasewanted::enaddingnewclinet:
system("clear");
        if (((user.premition&enaddingnewclinet)==enaddingnewclinet)||user.premition==-1)
        {
        addclientlabil();
        addingnewclinet();
        Pause();
        
        }
        else{
        Acesslabil();
          Pause();
        }
        mainpage(user);
        break;
        case encasewanted::enDelteClient:
        system("clear");
        if (((user.premition&enDelteClient)==enDelteClient)||user.premition==-1)
        {
        deleteclientlabil();
        deleteclient();
        Pause();
        }
        else{
        Acesslabil();
          Pause();
        }        
        mainpage(user);
        break;
case encasewanted::enupdateclient:


   system("clear");
        if (((user.premition & enupdateclient) == enupdateclient)||user.premition==-1)
        {
       updateclientlabil();
        updateclient();
        Pause();
        }
        else{
        Acesslabil();
          Pause();
        }        
        mainpage(user);
        break;

        case encasewanted::enFindclient:
        system("clear");
        if (((user.premition&enFindclient)==enFindclient) ||user.premition==-1)
        {
        findclientlabil();
        findclient();
        Pause();
        }
        else{
        Acesslabil();
          Pause();
        }        
        mainpage(user);
        break;
        case encasewanted::etransact:
                system("clear");
        if (((user.premition&etransact) == etransact) ||user.premition==-1)
        {
          trancationwanted(user);
        Pause();
        }
        else{
        Acesslabil();
          Pause();
          mainpage(user);
        }       
    
        break;
        case encasewanted::enmangeusers:

                 system("clear");
        if ((user.premition&enmangeusers ) == enmangeusers||user.premition==-1)
        {
        mangeuserimplemintion(user);
        Pause();
        }
        else{
        Acesslabil();
          Pause();
          mainpage(user);
        }   
      
    break;

        Pause();
        case encasewanted::enexit:
        system("clear");
        loginpage();
        Pause();
          break;



   
    }



}



void mangeuserscases(enmageusers casewanted,const stusernameandpass&user){



switch (casewanted)
{
case enmageusers::enListusers  :
    system("clear");
ShowusersList();
 Pause();
 mangeuserimplemintion(user);
    break;
case enmageusers::enadduser:
system("clear");
adduser();
 Pause();
 mangeuserimplemintion(user);
    break;
case enmageusers::endeleteuser:
   system("clear");
  deleteuser();
   Pause();
mangeuserimplemintion(user);
    break;
    case enmageusers::enupdateuser:
       system("clear");
    updateuser();
       Pause();
  mangeuserimplemintion(user);

    break;
    case enmageusers::enfinduser:
           system("clear");
            finduser();
            Pause();
              mangeuserimplemintion(user);
    break;
    case enmageusers::enmanemenue:

    mainpage(user);
    break;


}
}

void mangeuserimplemintion(const stusernameandpass&user){

    system("clear");
    manageuser_munue();
mangeuserscases(enmageusers(getnumberformainmeune()-1),user);


}

void loginpage(){

    bool pass=false;
    string username;
    string password;
      stusernameandpass currentuser;
do
{
  
   cout<<"Enter username?";
    cin>>username;
     cout<<"Enter password?";
    cin>>password;
if (chaeckuser(username,password,currentuser))
{
    pass=1;
}
else {

cout<<"Invalid username of password\n";

}




} while (!pass);




 mainpage(currentuser);

}
string getusename(){
    string username;
    bool deblicet=true;
while (deblicet)
{
      cout<<"enter username: ";
    getline(cin>>ws,username);
    deblicet=isuserthere(username);
    if (deblicet)
    {
        cout<<"username is already exists\n";
    }
    
}
return username;
}
int givepremition(){
    char give='N';
    int access=0;
cout<<"want to give full access? Y/N?";
cin>>give;
if (give=='y'||give=='Y')
{
    return -1;
}

cout<<"\nDo you want to give access? y/n";

cout<<"\nShow Client List Y/n?";
cin>>give;
if (give=='y'||give=='Y')
{
    access+=enShowClintList;
    give='N';
}

cout<<"\n Add new Client Y/n?";
cin>>give;
if (give=='y'||give=='Y')
{
    access+=enaddingnewclinet;
    give='N';
}



cout<<"\n Delete Client Y/n?";
cin>>give;
if (give=='y'||give=='Y')
{
    access+=enDelteClient;
    give='N';
}

cout<<"\n update Client Y/n?";
cin>>give;
if (give=='y'||give=='Y')
{
    access+=enupdateclient;
    give='N';
}

cout<<"\n find Client Y/n?";
cin>>give;
if (give=='y'||give=='Y')
{
    access+=enFindclient;
    give='N';
}


cout<<"\n transaction Y/n?";
cin>>give;
if (give=='y'||give=='Y')
{
    access+=etransact;
    give='N';
}

cout<<"\n mange users Y/n?";
cin>>give;
if (give=='y'||give=='Y')
{
    access+=enmangeusers;
    give='N';
}


return access;
}

void adduser(){
char addmore='N';

vector <stusernameandpass> vusers=readfromfilefromuser();
do
{
    stusernameandpass user;
   user.username=getusename();
   cout<<"enter password: ";
   cin>>user.pass;
user.premition=givepremition();
vusers.push_back(user);
writefilefromvecrot(vusers);
cout<<"user added succseefuly\n";
cout<<"want to add new user  Y/n\n";
cin>>addmore;

} while (addmore=='y'||addmore=='Y');






}
void deleteuser(){
vector <stusernameandpass> vusers=readfromfilefromuser();
string username;
stusernameandpass user;
char confirm='N';
cout<<"enter username: ";
cin>>username;
if (isuserthere(username,user))
{
    showuserinfo(user);

    cout<<"\nare you sure you want to delete this user Y/N\\n";
    cin>>confirm;
    if (confirm=='Y'||confirm=='y')
    {
        
for (stusernameandpass &U:vusers)
{
if (U.username==username)
{
    U.MarkForDelete=1;
}
}
writefilefromvecrot(vusers);
cout<<"\nuser have been deleted ";


    }
    
}
else {


    cout<<"No user have this username\n";
}

}

void updateuser(){

vector <stusernameandpass> vusers=readfromfilefromuser();
string username;
stusernameandpass user;
char confirm='N';
cout<<"enter username: ";
cin>>username;
if (isuserthere(username,user))
{
    showuserinfo(user);

    cout<<"\nare you sure you want to update this user Y/N\\n";
    cin>>confirm;
    if (confirm=='Y'||confirm=='y')
    {
        
for (stusernameandpass &U:vusers)
{
if (U.username==username)
{
    cout<<"enter password?";
    cin>>U.pass;
    U.premition=givepremition();
}
}
writefilefromvecrot(vusers);
cout<<"\nuser have been updated ";


    }
    
}
else {


    cout<<"No user have this username\n";
}
}

void finduser(){
string username;
stusernameandpass user;
cout<<"enter username: ";
cin>>username;
if (isuserthere(username,user))
{
    showuserinfo(user);
}
else {
    cout<<"No user have this username\n";
}

}

int main(){
   loginpage();

}