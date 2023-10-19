/*
        A BANK ACCOUNTING SYSTEM BY
      NAME                            ID
1. Lewana Kibrom-----------------UGR/9017/14
2. Mohammed Reshad---------------UGR/1155/13
3. Naos Belay--------------------UGR/9846/13
4. Samuel Tesfaye----------------UGR/1153/13
5. Samuel Wondimagegnew----------UGR/1486/13
*/
/*
                THE FILES USED
        File name                    Use
1. registered.txt------------------Stores the users details exept the remaining balance
2. accounts.txt--------------------Stores the users account number and remaning balance
3. numberfile.txt------------------Stores the next account number to be assigned to a newly regitered user
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
string loggerAccount;                   //Holds the account number of the user after logging in
int loggerBalance;                      //Holds the remaining balance of the user
void registration();                    //For the registration of new users(Client or Admin)
int autenticateUser(string,string);     //For login approval
void getAdminMenu();                    //gives the administrative options
void generateNumber();                  //for generating new account number for a new user
void getClientMenu();                   //gives the client options
void activateUser();                    //to activate the account by the admin
void disableUser();                     //to deactivate the account by the admin
void clearFiles();                      //to remove and rename the temporary files
void makeTransaction(string);           //for deposit and withdraw
void checkBalance();                    //to check the balance of the user
void clearscreen();                     //to clear the screen after an input 
int makeTransfer();                     //to transfer cash from one user to another

int main()
{
    char selectedNumber = '0';  //intitialization for the do while loop
    string strUsername;         //Holds the username
    string strPass;             //Holds the password

    clearFiles();               //this function is called specifically inorder for you to see the temporary files created in some of the funcions
                                //and as the position of the function calling indicates it does its job after the temporary file is created
    cout << "\t\t\t XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    cout << "\t\t\t         Welcome to             \n";
    cout << "\t\t\t    SLMNS Banking System          \n";
    cout << "\t\t\t XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n";
    cout << "\n\n\t\t   Select 1 or 2 for the service requested and A to exit\n\n";
while(1)                        //To loop the main options
{   
    clearFiles();
do
{
    cout << "\t\t\t 1.Login \n";
    cout << "\t\t\t 2.New Client Registration Request\n";
    cout << "\t\t\t A.Exit \n";
    cin >> selectedNumber;
    clearscreen();
    if (selectedNumber == 'A')  //TO exit the system
    goto Loop;                  //Goes to the return of the main function
}
while (selectedNumber !='1' &&   selectedNumber !='2');

if(selectedNumber=='1')         //If the user select 1 it prompts the autenticateUser function
{
    cout << "\t\t\t Please Enter UserName : ";
    cin >> strUsername;
    cout << "\n\t\t\t Password:";
    cin >> strPass;
    
    autenticateUser(strUsername,strPass);
}
else if(selectedNumber == '2')    //If the user select 2 it prompts the registration function
{
    registration();
}
}
Loop: return 0;
}

void registration()
{

    string userName,firstName,lastName,accountId;
    string userType,telNo,passWord;
    
    cout << "\n\t\t\t First Name :";
    cin >> firstName;
    
    cout << "\n\t\t\t Last Name : ";
    cin >> lastName;
    
    cout << "\n\t\t\t system username :";
    cin >> userName;
    
    cout << "\n\t\t\t password :";
    cin >> passWord;
    
    cout << "\n\t\t\t UserType : Enter number from 1 to 2 ";
    cout << "\n\t\t\t Admin : 1 , client : 2 "<<endl;
    cin >> userType ;

    cout << "\n\t\t\t MobileNo :";
    cin >> telNo ;

ifstream theF("registered.txt");

int search = 0;

string FirstName,LastName,UserName,TelNo,Status,UserType,AccountId,PassWord;
                                        //The following while loop checks if the username or tel number already exists
while(theF>>Status>>FirstName>>LastName>>UserName>>UserType>>TelNo>>AccountId>>PassWord)  
{
                                      //The following if statement changes the value of the search int for later use
    if (userName == UserName )        //  If it is the username that already exists                     
    {                                 //  The search int becomes 1                    
        search = 1;
        break;
    }

    else if (telNo == TelNo)           //  If it is the tel number that already exists
    {                                  //  The search int becomes 2
        search = 2;
        break;
    }

    else if (userName == UserName  && telNo == TelNo)       // if both already exist
    {                                                       // the searfch int becomes 3
        search = 3;
        break;
    }
}
    theF.close();
if (search==1)
    {
        cout << "\n\t\t\t username already exists\n\n " ;
    }
else if (search==2)
    {
        cout << "\n\t\t\t account with the same phone number already exists\n\n " ;
    }
else if (search==3)
    {
        cout << "\n\t\t\t account already exists\n\n" ;
    }
else if (search==0)        // if neither the username nor the tel number exists it proceeds to the registraion
{ 
    ifstream theFileSeq("numberfile.txt");
    theFileSeq>>accountId;
    
    cout << "\n\t\t\t Your new account number is: " <<
    accountId << "\n\n\t\t\t Give this id to an admin to activate it.\n\n"<<endl;
    
    ofstream file_insert1("registered.txt", ios::app | ios::out);
    ofstream file_insert2("accounts.txt", ios::app | ios::out);

if (!file_insert1) 
{
	cout << "File not created!";
}
else
{
    generateNumber();  // this increases the last account number assigned to a new user by one.

    file_insert1 << "Inactive" << " " << firstName << " " << lastName << " " << userName <<
    " " << userType << " " << telNo << " " << accountId << " " << passWord << "\n";
    file_insert2 << accountId << " " << "0\n";
    
    file_insert1.close();
}
}
}

void getAdminMenu()
{
    char SELECTED ;
    cout << "\n\t\t\t ____ Adminstrator Menu___";
do
{
    cout << "\n\t\t\t Activate  User           : 1";
    cout << "\n\t\t\t Disable User             : 2";
    cout << "\n\t\t\t Make Deposit for a Client: 3\n";
    cin >> SELECTED;
    clearscreen();
}
while (SELECTED!='1' && SELECTED!='2' && SELECTED!='3' );

switch(SELECTED)
{
    case '1':    activateUser();
        break;
    case '2':   disableUser();
        break;
    case '3':   makeTransaction("deposit");
        break;
    default:
        cout << " wrong selection";
}
}

void getClientMenu()
{
    char SELECTED;
    cout << "\n\n\n\t\t\t ____ Client Menu ___ ";
do
{
    cout << "\n\t\t\t Make a Withdraw: 1 ";
    cout << "\n\t\t\t Make a Transfer: 2 ";
    cout << "\n\t\t\t Check Account  : 3 \n";
    

    cin >> SELECTED;
    clearscreen();
}

while(SELECTED !='1' && SELECTED !='2' && SELECTED!='3' ) ;

switch(SELECTED)
{
    case '1':   makeTransaction("withdraw");
        break;
    case '2':   makeTransfer();
        break;
    case '3':   checkBalance();
        break;
    
    default:
        cout << " wrong selection";
}
}

void activateUser()     // first it copies all the contents of registered.txt exept the one being activated and stores it in a temporary file tmp.txt
{
    string AccountNo;
    cout << "\n\n\n\t\t\t ____ Activate  User ___ ";
    cout << "\n\t\t\t Account No : ";
    cin >> AccountNo ;

    ofstream file_insert;
    file_insert.open("tmp.txt");
    
    int checkAccount = 0,checkTel = 0;
    ifstream theFile("registered.txt");

    string FirstName,LastName,UserName,TelNo,Status,AccountId,PassWord,UserType;
    
    while(theFile >> Status >> FirstName >> LastName >> UserName >> UserType >> TelNo >> AccountId >> PassWord)
    {
        if(AccountId==AccountNo)
              file_insert << "Active" << " " << FirstName << " " << LastName << " "
            << UserName <<" " << UserType << " " << TelNo << " " << AccountId << " " << PassWord <<endl;
        else
            file_insert << Status <<" " << FirstName << " " << LastName << " "
            << UserName << " " << UserType << " " << TelNo << " " << AccountId << " " << PassWord << endl;
}
}
void disableUser()     //does the reverse of the activateuser function
{

    string AccountNo;
    
    cout << "\n\n\n\t\t\t ____ Disable User ___ ";
    cout << "\n\t\t\t Account No : ";
    cin >> AccountNo ;

    ofstream file_insert;
    file_insert.open("tmp.txt");
    
    int checkAccount = 0, checkTel = 0;
    ifstream theFile("registered.txt");

    string FirstName,LastName,UserName,TelNo,Status,AccountId,PassWord,UserType;

    while(theFile >> Status >> FirstName >> LastName >> UserName >> UserType >> TelNo >> AccountId >> PassWord){
        if(AccountId == AccountNo)
        {
            file_insert << "Inactive" << " " << FirstName << " " << LastName << " "
            << UserName <<" " << UserType << " " << TelNo << " " << AccountId << " " << PassWord <<endl;
        }
            else
        {
            file_insert << Status <<" " << FirstName << " " << LastName << " "
            << UserName << " " << UserType << " " << TelNo << " " << AccountId << " " << PassWord << endl;
        }
}

}
int makeTransfer()
{
    
    string AccountNoReciver,dataAccount;
    int senderBalance,recieverBlance,amountTransfered,
        dataAmount,intAmount,intTmp,cnt=0;

    cout << "\n\n\n\t\t\t ____ Transfered Amount in Birr : ";
    cin >> amountTransfered;

    cout << "\n\t\t\t Transfered to Account No : ";
    cin >> AccountNoReciver ;

    stringstream ss,tt;


    ifstream theSearchFile("accounts.txt");//for seraching the balance of both sender and reciever balance
    
    while(theSearchFile >> dataAccount >> dataAmount)
    {
        if(dataAccount == loggerAccount)
        {
            tt << dataAmount;
            tt >> senderBalance;
        }

    // for the reciver balance
        if(dataAccount == AccountNoReciver)
        {   
            ss << dataAmount;
            ss >> recieverBlance;
        }

    }

    if(senderBalance < amountTransfered)
    {
        cout << " The requested amount should be less than sender balance: " << senderBalance << endl;
        cout << " Transaction terminated "<<endl;
    
        return 0;
    }

   //  amountTransfered=senderBalance - recieverBlance;
   if(theSearchFile.is_open())
     theSearchFile.close();
    
    ifstream theSearchFile2("accounts.txt");
    int senderCurrentBalance,recieverCurrentbalance;

    recieverCurrentbalance = amountTransfered + recieverBlance;
    senderCurrentBalance = senderBalance - amountTransfered;

    cout << "sender balance:" << senderCurrentBalance << endl;
    ofstream file_insert;
    file_insert.open("tmp2.txt");

    while(theSearchFile2 >> dataAccount >> dataAmount)
    {
        if(dataAccount == AccountNoReciver)
           file_insert << AccountNoReciver <<" " << recieverCurrentbalance <<endl;
        else if(dataAccount == loggerAccount)
            file_insert << loggerAccount << " " << senderCurrentBalance << endl;
        else
           file_insert << dataAccount << " " << dataAmount << endl;
    }

    file_insert.close();
    theSearchFile2.close();

    remove("acounts.txt");
    rename("tmp2.txt","accounts.txt");

    return 1;
}

void checkBalance()
{
    string  dataAccount,dataAmount;
    ifstream theSearchFile("accounts.txt");//for searching the balance of the user
    
    while(theSearchFile>>dataAccount>>dataAmount)
    {
        if(dataAccount==loggerAccount)
        {
            cout << "Client Account Number   : " << dataAccount << "\n";
            cout << "Current Balance in Birr : " << dataAmount<< "\n";
        }
}
}

void makeTransaction(string transaction)
{

    if(transaction=="deposit") cout<<"\n\n\n\t\t\t ____ Deposit Amount in Birr : ";
    else cout<<"\n\n\n\t\t\t ____ Withdrwal Amount Amount in Birr : ";

    string AccountNo,dataAccount;
    int dataAmount,intAmount,intTmp,cnt=0;

    cin >> intAmount;
    cout << "\n\t\t\t Account No : ";
    cin >> AccountNo ;

    ofstream file_insert;
    file_insert.open("tmp2.txt");

    
    ifstream theFile("accounts.txt");
    
    
    stringstream ss;

    while(theFile>>dataAccount>>dataAmount)
{
    
        if(dataAccount==AccountNo)
    {
        ss << dataAmount;
        ss >> intTmp;
        cnt = 1;

        if(transaction == "deposit") intTmp = intTmp + intAmount;
        else if(transaction == "withdraw")
        { intTmp =  intTmp - intAmount;}


            file_insert << AccountNo << " "<< intTmp << endl;
    }

    else file_insert << dataAccount << " " << dataAmount << "\n";
}
  // if the entered account number is wrong
if(cnt == 0)  
{
  if  (transaction == "deposit") file_insert << AccountNo << " " << intAmount << "\n";
}
}

int autenticateUser(string user,string pass)
{
    int found = 0;
    int UserType;
    ifstream theFile("registered.txt");
    
    string FirstName,LastName,UserName,TelNo,Status,AccountId,PassWord;

    while(theFile >> Status >> FirstName >> LastName >> UserName >> UserType >> TelNo >> AccountId >> PassWord)
    {
        if( PassWord == pass && UserName == user && Status == "Active" )            //checks if the username and password eligible and if the user is active
        {
            found = 1;
            loggerAccount = AccountId;
                break;
        }
    }

    if(found == 1)
    {
        switch(UserType)
        {
            case 1 : getAdminMenu(); 
                break;
            case 2 : getClientMenu();
                break;
            default: cout << "Invalid data , Please try again !";
                    
        }
    }
    else cout << "User not Found"<<endl; 
    
    return 1;
}

void generateNumber()
{
    long long id;
    
        fstream in( "numberfile.txt", ios::in );
        in >> id;
    
        id++;

        fstream out( "numberfile.txt" , ios::out );
        out << id;
}

void clearFiles()
{
    if(ifstream("tmp.txt"))
    {
        remove("registered.txt");
        rename("tmp.txt", "registered.txt");
    }

 // for the banking transaction
    if(ifstream("tmp2.txt"))
    {
        remove("accounts.txt");
        rename("tmp2.txt", "accounts.txt");
    }
}
void clearscreen()
{
#ifdef WINDOWS          //For windows OS uses the function system("cls") to clear the function after an input
system("cls");
#else
system("clear");         //For Linux/UNIX OS uses the function system("clear") to clear the function after an input
#endif
}