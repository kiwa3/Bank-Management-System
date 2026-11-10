#pragma once

#include <iostream>
#include <vector>
#include <fstream> 
#include <string>
#include <iomanip> 
using namespace std;
 
namespace MybankLibrarry{
void loginlabil(){
cout<<"-------------------------------------------\n";
cout<<"                   login   \n";
cout<<"-------------------------------------------\n";

}

void Acesslabil(){
cout<<"-------------------------------------------\n";
cout<<"       Access denied,   \n";
cout<<"   you dont have premission to do this,   \n";
cout<<"    plese contact your admin   \n";
cout<<"-------------------------------------------\n";

}
void addclientlabil(){
cout<<"-------------------------------------------\n";
cout<<"                   Add Client   \n";
cout<<"-------------------------------------------\n";

}
void deleteclientlabil(){
cout<<"-------------------------------------------\n";
cout<<"                   Delete Client   \n";
cout<<"-------------------------------------------\n";

}

void updateclientlabil(){
cout<<"-------------------------------------------\n";
cout<<"                   Update Client   \n";
cout<<"-------------------------------------------\n";

}

void findclientlabil(){
cout<<"-------------------------------------------\n";
cout<<"                   find Client   \n";
cout<<"-------------------------------------------\n";

}
void exitlabil(){
cout<<"-------------------------------------------\n";
cout<<"      thank you for using this program     \n";
cout<<"-------------------------------------------\n";

}

const string filenmae="bankfile.txt";
const string userfilename="userfilename.txt";
struct client_data
{
    string Acount_num;
    string pincode;
    string nmae;
    string phone_num;
    double AcountBalnace;
    bool MarkForDelete = false;
    
};   
struct stusernameandpass
{
    string username;
    string pass;
    int premition;
     bool MarkForDelete = false;
};
enum enmageusers{
enListusers,
enadduser,
endeleteuser,
enupdateuser,
enfinduser,
enmanemenue
};

enum encasewanted {
    enShowClintList=1,
    enaddingnewclinet=2,
    enDelteClient=4,
    enupdateclient=8,
    enFindclient=16,
    etransact=32,
    enmangeusers=64,
    enexit=128
};   
    
enum entransaction{
eDeposet=1,ewithdraw=2,
etotalblance=3,emainmenue=4
};    
client_data currentclient;

int getnumberformainmeune(){
int number;
do
{
    cout<<"Chooes what do you want from 1 to 8\n";
    cin>>number;
    
} while (number<1||number>8);
return number;



}  
int choiceAtmnumber(){
    int number;
    do
    {
        cout<<"choose waht do you want to do ? [1 to 5]?";
        cin>>number;

    } while (number<1||number>5);
    
return number;



}

int getnumberfortransaction(){
int number;
do
{
    cout<<"Chooes what do you want from 1 to 4\n";
    cin>>number;
    
} while (number<1||number>4);
return number;



}    


void Pause() {
string c;
    cout << "Press any key and Enter to continue...";
    cin>>c; 
}


                                                                                                                                                                                                       
vector <string> LineToVector(string S1,string delimter="#//#"){
int pos;
string word;
vector <string> temp;
while ((pos=S1.find(delimter)) != std::string::npos)                                                                                      
{
word=S1.substr(0,pos);                                                                                                                                  
if (word !="")
{
    temp.push_back(word);
}
    S1.erase(0,pos+delimter.length());
}
if (S1 !="")
{
    temp.push_back(S1);
}
return temp;


}

client_data stringvectortoclint(vector <string> vlines){
    client_data temp;
    temp.Acount_num=vlines[0];
    temp.pincode=vlines[1];
    temp.nmae=vlines[2];
    temp.phone_num=vlines[3];
    temp.AcountBalnace=stod(vlines[4]);
return temp;



}
vector <client_data> readfromfile(){
    vector <client_data> temp;
ifstream Myfile(filenmae,ios::in);
if (Myfile.is_open())
{
    string line;
    while (getline(Myfile,line))
    {
        temp.push_back(stringvectortoclint(LineToVector(line)));
    }
    
    Myfile.close();
}

return temp;

    
}

void printclintdata(client_data client){
cout<<"| "<<setw(18)<<left<<client.Acount_num;
cout<<"| "<<setw(13)<<left<<client.pincode;
cout<<"| "<<setw(23)<<left<<client.nmae;
cout<<"| "<<setw(13)<<left<<client.phone_num;
cout<<"| "<<setw(13)<<left<<client.AcountBalnace;

}
void printclintdatafortrancation(client_data client){
cout<<"| "<<setw(18)<<left<<client.Acount_num;
cout<<"| "<<setw(23)<<left<<client.nmae;
cout<<"| "<<setw(13)<<left<<client.AcountBalnace;

}
void printclintlinebyline(client_data client){
cout<<"\nthe following clinet detalis:\n";
cout<<"-------------------------------\n";
cout<<"Acount number: "<<client.Acount_num<<endl;
cout<<"Acount pincode: "<<client.pincode<<endl;
cout<<"Acount name: "<<client.nmae<<endl;
cout<<"Acount phone number: "<<client.phone_num<<endl;
cout<<"Acount balance: "<<client.AcountBalnace<<endl;
cout<<"-------------------------------\n";
}
bool isclinetthere(string accountnumber){
vector <client_data> Vclints=readfromfile();
for(client_data &C:Vclints){
if (C.Acount_num==accountnumber)
{
    return true;
}
}
return false;
}
bool isclinetthere(string accountnumber,client_data &clint){
vector <client_data> Vclints=readfromfile();
for(client_data &C:Vclints){
if (C.Acount_num==accountnumber)
{
    clint=C;
    return true;
}
}
return false;
}


client_data saveclintdatawithaccountnumber(string account_number){
client_data client;

client.Acount_num=account_number;
cout<<"enter acount pincode: ";
    getline(cin>>ws,client.pincode);
cout<<"enter acount name: ";
    getline(cin>>ws,client.nmae);
cout<<"enter acount phone number: ";
    getline(cin>>ws,client.phone_num);
    cout<<"enter acount Account balance: ";
cin>>client.AcountBalnace;
return client;

}

string clienttoline(client_data client,string delimter="#//#"){
 string line=client.Acount_num+delimter;
line+=client.pincode+delimter;
line+=client.nmae+delimter;
line+=client.phone_num+delimter;
line+=to_string(client.AcountBalnace);
return line;

}

void clinttofile(client_data client){
ofstream Myfile(filenmae,ios::out|ios::app);
if (Myfile.is_open())
{
string line=clienttoline(client);
Myfile<<line<<endl;

Myfile.close();
}

}

void printusrsdata(stusernameandpass users){
cout<<"| "<<setw(18)<<left<<users.username;
cout<<"| "<<setw(13)<<left<<users.pass;
cout<<"| "<<setw(23)<<left<<users.premition;

}


void writefilefromvecrot(vector <client_data> vclints){

ofstream Myfile(filenmae,ios::out);
if (Myfile.is_open())
{
    string line;
for (client_data&C:vclints)
{
if (!C.MarkForDelete)
{
    line=clienttoline(C);
    Myfile<<line<<endl;
}

}
Myfile.close();
    }


}
void deleteclientfromfile(string accountnumber){
vector <client_data> vclints=readfromfile();
for ( client_data& C:vclints)
{
    if (C.Acount_num==accountnumber)
    {
        C.MarkForDelete=true;
    }
    
    
}

writefilefromvecrot(vclints);


}
void updateclient(string accountnumber){
client_data client=saveclintdatawithaccountnumber(accountnumber);
vector <client_data> vclinets=readfromfile();
for (client_data &C:vclinets)
{
    if (C.Acount_num==accountnumber)
    {
        C=client;
    }
    
}



writefilefromvecrot(vclinets);
}

void updateclient(client_data client){
vector <client_data> vclinets=readfromfile();
for (client_data &C:vclinets)
{
    if (C.Acount_num==client.Acount_num)
    {
        C=client;
    }
    
}



writefilefromvecrot(vclinets);
}


void dotransaction(client_data client,double amount){
vector <client_data> vclints=readfromfile();

for (client_data &C:vclints)
{
    if (C.Acount_num==client.Acount_num)
    {    

        C.AcountBalnace=C.AcountBalnace+amount ;
        break;
    }
    
}
writefilefromvecrot(vclints);

}

stusernameandpass stringvectortousers(vector <string> vlines){
    stusernameandpass temp;
    temp.username=vlines[0];
    temp.pass=vlines[1];
    temp.premition= stoi(vlines[2]);
return temp;

}


vector <stusernameandpass> readfromfilefromuser(){
    vector <stusernameandpass> temp;
ifstream Myfile(userfilename,ios::in);
if (Myfile.is_open())
{
    string line;
    while (getline(Myfile,line))
    {
        temp.push_back(stringvectortousers(LineToVector(line)));
    }
    
    Myfile.close();
}

return temp;

    
}

bool chaeckuser(string &username,string &pass,stusernameandpass &user){
vector <stusernameandpass> vusers=readfromfilefromuser();
for (stusernameandpass U:vusers)
{
    if (username==U.username && pass==U.pass)
    {
        user=U;
        return true ;
    }
     
    
}

return false;



}

bool isuserthere(string username){
vector <stusernameandpass> vusers=readfromfilefromuser();
for (stusernameandpass U: vusers)
{
   if (username==U.username)
   {
    return true;
   }
   
}
return false;


}
bool isuserthere(string username,stusernameandpass &user){
vector <stusernameandpass> vusers=readfromfilefromuser();
for (stusernameandpass U: vusers)
{
   if (username==U.username)
   {
    user=U;
    return true;
   }
   
}
return false;


}

string usertoline(stusernameandpass user,string delimter="#//#"){
string line; 
line=user.username+delimter;
line+=user.pass+delimter;
line+=to_string(user.premition);
return line;


}


void writefilefromvecrot(vector <stusernameandpass> vuser){

ofstream Myfile(userfilename,ios::out);
if (Myfile.is_open())
{
    string line;
for (stusernameandpass& U : vuser)
{
    if (!U.MarkForDelete)
    {
           line=usertoline(U);
    Myfile<<line<<endl;
    }
    
 
}
Myfile.close();
    }


}

void showuserinfo(stusernameandpass user){
cout<<"\nthe following are the client detailds\n";
cout<<"--------------------------------\n";
cout<<"Username"<<setw(10)<<":"<<user.username<<endl;
cout<<"password"<<setw(10)<<":"<<user.pass<<endl;
cout<<"permission"<<setw(10)<<":"<<user.premition<<endl;
cout<<"--------------------------------\n";


}


bool leaodingclint(string username ,string password,client_data &currentclient){
vector <client_data> vclient=readfromfile();
for (client_data &C:vclient)
{
client_data client;
    if (username==C.Acount_num &&password==C.pincode )
    {
        currentclient=C;
        return true;
    }
    
}
return false;





}
bool loginchaeck(string username ,string password){

return leaodingclint(username ,password,currentclient);
}



}






