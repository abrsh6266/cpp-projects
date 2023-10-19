#include <iostream>

using namespace std;
class hello
{
  public:
  void display()
  {
    cout<<"hello everyone this is abrham"<<endl;
    cout<<"this is my first coding about class so how is it ?"<<endl;

  }
  string abs()
  {
      return username;
  }
  void display3(string q)
  {
   username=q;
  }
  void display2()
  {
      cout<<"welcome "<<abs()<<endl;
  }
  private:
    string username;
};

int main()
{
    string n;
hello h;
h.display();
cout<<"please enter your name"<<endl;
getline(cin,n);
h.display3(n);
h.display2();
    return 0;
}
