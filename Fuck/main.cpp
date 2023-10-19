#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
// An example function whose solution is pre-determined using
// Bisection Method.
// The function is e^x + 4x^3 - 5
float eq(float);
float deveq(float);
float fixeq1(float);
float fixeq2(float);
float fixeq3(float);
string checking(float);
string bisection_method(float,float,float);
string secant_method(float,float,float);
string False_position_method(float,float,float);
string newton_method(float,float);
float fixed_point_iteration_method(float,float);
void back();
void input(int);
// Driver program to test above
main()
{
    string chk;
    //choose the method to solve
    while(true)
    {
    cout<<"---------Finding the root of  f(x) = e^x + 4x^3 - 5--------"<<endl;
    cout<<"choose the method of finding the root>>>"<<endl;
    cout<<"enter 1 for Bisection method."<<endl<<
    "enter 2 for secant_method."<<endl<<
    "enter 3 for False position method."<<endl<<
    "enter 4 for Newtons method."<<endl<<
    "enter 5 for fixed point iteration method."<<endl<<
    "enter 6 for checking the value of f(x)."<<endl<<
    "enter 7 to EXIT."<<endl;
    cout<<"Option>>>>";cin>>chk;
    if(chk=="1"||chk=="2"||chk=="3"||chk=="4"||chk=="5"||chk=="6")
    {
        input((stoi(chk)));
        break;
    }
    else if (chk=="7")
    {
        return 0;
    }
    else
    {
        cout<<"please enter the correct option!"<<endl;
    }
    }
}
void back()
{
    string x;
    cout<<"enter any key to return to menu";
    cin>>x;
    x="a";
    if(x=="a")
    {
        system("cls");
        main();
    }
}
// Function to find the root
float eq(float a)
{
    return  (4*(pow(a,3))) - 5 + exp(a);
}
// Derivative of the above function
float deveq(float a)
{
    return exp(a)+(12*pow(a,2));
}
float fixeq1(float a)
{
    return pow((5-(exp(a)))/4,1/3);
}
float fixeq2(float a)
{
    return log(5-(4*pow(a,3)));
}
float fixeq3(float a)
{
    return pow((5-(exp(a)))/(4*a),1/2);
}
float fixeq4(float a)
{
    float x = (5 - (exp(a)))/(4*a*a);
    return x;
}
string bisection_method(float num1,float num2,float tlv)
{
    int count = 0;
    float res;
    if(eq(num2)*eq(num1)>0)
    {
        cout<<"Incorrect initial  guess"<<endl;
        input(1);
        return "";
    }
    else{
    do
    {
        res = (num1+num2)/2;
        if(eq(res)*eq(num2)<0)
        {
            num1 = res;
        }
        else
        {
            num2 = res;
        }
        count++;
    }while (abs(eq(res))>tlv&&abs(num1-num2)>tlv&&count<=300);
    if(count>300)
    {
        return "the number converge or diverge";
    }
    else
    {
        return "it has zeros at "+to_string(res)+"."+"\n The number of iteration is "+to_string(count);
    }}
}
void input(int chk)
{
    float num1,num2,tlv;
    {
        switch(chk)
        {
            case 1:
            {
                cout<<"Enter the first,the second and tolerance value"<<endl;
                cout<<"The First number >>";
                cin>>num1;
                cout<<"The Second number >>";
                cin>>num2;
                cout<<"  Tolerance Value >>";
                cin>>tlv;
                cout<<bisection_method(num1,num2,tlv)<<endl;
                back();
                break;
            }
            case 3:
            {
                cout<<"Enter the first,the second and tolerance value"<<endl;
                cout<<"The First number >>";
                cin>>num1;
                cout<<"The Second number >>";
                cin>>num2;
                cout<<"  Tolerance Value >>";
                cin>>tlv;
                cout<<False_position_method(num1,num2,tlv)<<endl;
                back();
                break;
            }
            case 2:
            {
                cout<<"Enter the first,the second and tolerance value"<<endl;
                cout<<"  The First number >>";
                cin>>num1;
                cout<<"  The Second number >>";
                cin>>num2;
                cout<<"  Tolerance Value >>";
                cin>>tlv;
                cout<<secant_method(num1,num2,tlv)<<endl;
                back();
                break;
            }
            case 4:
            {
                cout<<"Enter the X value and tolerance value"<<endl;
                cout<<"  The X value >>";cin>>num1;
                cout<<"  Tolerance Value >>";
                cin>>tlv;
                cout<<newton_method(num1,tlv)<<endl;
                back();
                break;
            }
            case 5:
            {
                cout<<"Enter the X value and tolerance value"<<endl;
                cout<<"  The X value >>";cin>>num1;
                cout<<"  Tolerance Value >>";
                cin>>tlv;
                if(fixed_point_iteration_method(num1,tlv) == 1)
                {
                    cout<<"the number converge or diverge"<<endl;
                }
                else
                {
                    cout<<"it has zeros at "<<fixed_point_iteration_method(num1,tlv)<<endl;
                }

                back();
                break;
            }
            case 6:
            {
                cout<<"Enter the x value"<<endl;
                cout<<"X =  ";cin>>num1;
                cout<<checking(num1)<<endl;
                back();
                break;
            }
        }
    }
}
float solve( float number, int place) {
   cout << fixed;
   cout << setprecision( place );
   return number;
}
string checking(float num)
{
    return "the  value of f(x) at at "+to_string(num)+" is "+to_string(fixeq4(num))+".";
}
string secant_method(float num1,float num2,float tlv)
{
    int count = 0;
    float swap,res;
    if(eq(num1)<eq(num2))
    {
        swap = num1;
        num1 = num2;
        num2 = swap;
    }
    do
    {
        /* code */
        res = num2 - (eq(num2)*(num1 - num2)/(eq(num1)-eq(num2)));
        num1 = num2;
        num2 = res;
        count++;
    } while (abs(eq(res))>tlv&&count<=300);
    if(count>300)
    {
        return "the number converge or diverge";
    }
    else
    {
        return "it has zero at "+to_string(res)+"."+"\n The number of iteration is "+to_string(count);
    }
}
string False_position_method(float num1,float num2,float tlv)
{
    int count = 0;
    float res;
    do
    {
        res = num2 - (eq(num2)*(num1 - num2)/(eq(num1)-eq(num2)));
        if(eq(res)*eq(num2)<0)
        {
            num1 = res;
        }
        else
        {
            num2 = res;
        }
        count++;
    }while (abs(eq(res))>tlv&&abs(num1-num2)>tlv&&count<=300);
    if(count>300)
    {
        return "the number converge or diverge";
    }
    else
    {
        return "it has zero at "+to_string(res)+"."+"\n The number of iteration is "+to_string(count);
    }
}
string newton_method(float num1,float tlv)
{
    int count = 0;
    float num2;
    if(eq(num1)!=0&&deveq(num1)!=0)
    {
        do
        {
            num2 = num1;
            num1 = num1 - (eq(num1)/deveq(num1));
            count++;
        }while (abs(eq(num1))>tlv&&abs(num1-num2)>tlv&&count<=300);
        if(count>300)
        {
            return "the number converge or diverge";
        }
        else
        {
            return "it has zeros at "+to_string(num1)+"."+"\n The number of iteration is "+to_string(count);
        }
    }
    return "";
}
float fixed_point_iteration_method(float num1,float tlv)
{
    int count = 0;
    float num2;
    /*if(fixeq1(num1)<1)
    {
        do
        {
            num2 = num1;
            num1 = fixeq1(num1);
            count++;
        }while (abs(eq(num1))>tlv&&abs(num1-num2)>tlv);
        return "it has zeros at "+to_string(num1)+"."+"\n The number of iteration is "+to_string(count);
    }
    else if(fixeq2(num1)<1)
    {
        do
        {
            num2 = num1;
            num1 = fixeq2(num1);
            count++;
        }while (abs(eq(num1))>tlv&&abs(num1-num2)>tlv);
        return "it has zeros at "+to_string(num1)+"."+"\n The number of iteration is "+to_string(count);
    }
    else if(fixeq3(num1)<1&&fixeq3(num1)>-1)
    {
        do
        {
            num2 = num1;
            num1 = fixeq3(num1);
            count++;
        }while (abs(eq(num1))>tlv&&abs(num1-num2)>tlv);
        return "it has zeros at "+to_string(num1)+"."+"\n The number of iteration is "+to_string(count);
    }
    else
    {*/
        do
        {
            num2 = num1;
            num1 = fixeq4(num1);
            count++;
        }while (abs(eq(num1))>tlv/*&&abs(num1-num2)>tlv*/&&count<300);
        if(count>=300)
        {
            return 1;
        }
        return num1;
}
