#include <iostream>
#include<string>
using namespace std;
string line(50,'-');
struct abrsh
{
    string name;
    char sex[100];
    int age;

};
struct abrsh1
{
    abrsh axo;
}z;

int main()
{
   cout<<"what is your name :"<<endl<<">>>>";
   getline(cin,z.axo.name);
   cout<<"enter your sex :"<<endl<<">>>>";
   cin.get(z.axo.sex,100);
   cout<<"Enter your age :"<<endl<<">>>>";
   cin>>z.axo.age;
   cout<<"your data is recorded"<<endl;
   cout<<line<<endl;
   cout<<"your name : "<<z.axo.name<<endl;
   cout<<"your sex : "<<z.axo.sex<<endl;
   cout<<"your age : "<<z.axo.age<<endl;
return 0;
}
