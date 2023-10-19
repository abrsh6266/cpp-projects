#include <iostream>
#include<stdio.h>
#include<string>
#include<fstream>
using namespace std;
struct ab
{
    string name;
    int id;

}x;
int main()
{
    fstream file("person2.txt",ios::trunc|ios::in|ios::out|ios::ate);
    for(int i='0';i<256;i++)
    file.put((char)i);
char a;
/*template<typename t>
void square()
{string line('-',50);
cout<<"what is your name"<<endl;
getline(cin,x.name);
cout<<"what is your ID?"<<endl;
cin>>x.id;
  fstream file(("person.txt"),ios::trunc|ios::out|ios::in|ios::app);
  file.write((char*)&x,sizeof(ab));
  file.close();
}
int main()
{
square<string>();*/
return 0;
}

