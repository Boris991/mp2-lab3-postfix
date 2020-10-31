#include "postfix.h"
#include <gtest.h>
#include <iostream>
using namespace std;
TEST(TPostfix, can_create_postfix)
{
    string a = "a+b-c";
    TPostfix p(a);
    cout<<p.ToString()<<endl;
  ASSERT_NO_THROW(TPostfix p(a));
}
TEST(TPostfix, can_calculate_postfix)
{
    string a = "a+b-c";                               
    float f;
    TPostfix p(a);
    TTable<float>* b;
    b=p.getvarieble();
    for (int i = 0; i < b[0].Getcount(); i++)
    {
        cout << b[0][i].GetName() << endl;
    }
    cout << "Enter values" << endl;                    //a=1,b=1,c=2
    for (int i = 0; i < b[0].Getcount(); i++)
    {
        string cf = b[0][i].GetName();
        if ((cf[0] >= 48) && (cf[0] < 58))
        {
            b[0][i].SetValue(stof(cf));
        }
        else
        {
            cout << b[0][i].GetName() << " = ";
            cin >> f;
            b[0][i].SetValue(f);
            cout << endl;
        }
    }
    EXPECT_EQ(0.0,p.Calculate());
}
TEST(TPostfix, can_calculate_sin)
{
    string a = "sin(a+b)";
    float f;
    TPostfix p(a);
    TTable<float>* b;
    b = p.getvarieble();
    for (int i = 0; i < b[0].Getcount(); i++)
    {
        cout << b[0][i].GetName() << endl;
    }
    cout << "Enter values" << endl;                  //a=0,b=0
    for (int i = 0; i < b[0].Getcount(); i++)   
    {
        string cf = b[0][i].GetName();
        if ((cf[0] >= 48) && (cf[0] < 58))
        {
            b[0][i].SetValue(stof(cf));
        }
        else
        {
            cout << b[0][i].GetName() << " = ";
            cin >> f;
            b[0][i].SetValue(f);
            cout << endl;
        }
    }
    EXPECT_EQ(0.0, p.Calculate());
}
TEST(TPostfix, can_calculate_cos)
{
    string a = "cos(a+b)";
    float f;
    TPostfix p(a);
    TTable<float>* b;
    b = p.getvarieble();
    for (int i = 0; i < b[0].Getcount(); i++)
    {
        cout << b[0][i].GetName() << endl;
    }
    cout << "Enter values" << endl;                //a=0,b=0
    for (int i = 0; i < b[0].Getcount(); i++)
    {
        string cf = b[0][i].GetName();
        if ((cf[0] >= 48) && (cf[0] < 58))
        {
            b[0][i].SetValue(stof(cf));
        }
        else
        {
            cout << b[0][i].GetName() << " = ";
            cin >> f;
            b[0][i].SetValue(f);
            cout << endl;
        }
    }
    EXPECT_EQ(1.0, p.Calculate());
}
TEST(TPostfix, can_calculate_sqrt)
{
    string a = "sqrt(a+b)";
    float f;
    TPostfix p(a);
    TTable<float>* b;
    b = p.getvarieble();
    for (int i = 0; i < b[0].Getcount(); i++)
    {
        cout << b[0][i].GetName() << endl;
    }
    cout << "Enter values" << endl;       //a=4,b=5
    for (int i = 0; i < b[0].Getcount(); i++)
    {
        string cf = b[0][i].GetName();
        if ((cf[0] >= 48) && (cf[0] < 58))
        {
            b[0][i].SetValue(stof(cf));
        }
        else
        {
            cout << b[0][i].GetName() << " = ";
            cin >> f;
            b[0][i].SetValue(f);
            cout << endl;
        }
    }
    EXPECT_EQ(3.0, p.Calculate());
}