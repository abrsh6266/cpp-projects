#include <iostream>
#include<fstream>
#include<string>
using namespace std;
struct students
{
    unsigned int id;
    float marks[5];
    float average;
    int ran;

}stu[5];

void average1(float mark[5],float &ave)
{
float z=0;
for(int i=0;i<5;i++)
    {
     z+=mark[i];
    }
    z=z/5;
    ave=z;
}
int sum(float mark[5])
{
    float z=0;
    for(int i=0;i<5;i++)
    {
        z+=mark[i];
    }
    return z;
}
void rank1(students stu1[],int x)
{

}

int main()
{
string line(50,'-');
ifstream my_file("scores.txt",ios::app);
string x;
while(getline(my_file,x))
cout<<x;

/*for(int j=0;j<5;j++)
{
    cout<<"enter the student id"<<endl<<">>";
    cin>>stu[j].id;
    my_file<<"student id        :"<<stu[j].id<<endl;
    cout<<"enter 5 subject student marks"<<endl;
    for(int i=0;i<5;i++)
    {cin>>stu[j].marks[i];}
    cout<<"the marks of a student you entered {";
    my_file<<"the mark of a student: "<<sum(stu[j].marks)<<endl;
    for(int i=0;i<5;i++)
    {if(i==4)
        cout<<stu[j].marks[i]<<"}"<<endl;
        else
        cout<<stu[j].marks[i]<<",";}
    average1(stu[j].marks,stu[j].average);
    cout<< "the average is >>"<<stu[j].average<<endl;
     my_file<<"the average of score     :"<<stu[j].average<<endl;
     my_file<<line<<endl;
}
rank1(stu,5);*/
return 0;
}
