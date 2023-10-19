#include <iostream>
#include<fstream>
using namespace std;
int main()
{
string ab;
ofstream newfile("abrsh.txt");
newfile << "hi bro what's up with you .this is my first file system to working on it"<<endl<<"am the best in the world";
newfile.close();
ifstream newfileq("abrsh.txt");
while(getline(newfileq,ab))
{
    cout<<ab;
}
return 0;
}
