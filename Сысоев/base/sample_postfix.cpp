#include "postfix.h"
#include <iostream>
using namespace std;
int main()
{
  string expression;
  float f;
  double res;
  setlocale(LC_ALL, "Russian");
  cout << "Введите арифметическое выражение: ";
  getline(cin, expression);
  cout << expression << endl;
  TPostfix postfix(expression);
  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
  //postfix.ToPostfix();
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
  TTable<float>* b;
  b = postfix.getvarieble();
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
  res = postfix.Calculate();
  cout << res << endl;
  return 0;
}
/*
    setlocale(LC_ALL, "");
    string* v;
    string str;
    int m;
    for (int i = 0; i < 1; i++)
    {
        cout << " Введи строку " << endl;
        getline(cin, str);
        TPostfix p(str);
        float f;
        TTable<float>* b;
        b = p.getvarieble();
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
    }
*/