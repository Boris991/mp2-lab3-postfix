#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "TTable.h"
#include <string>
#include <vector>
#include "stack.h"
#include "TRecord.h"
#include "stow.h"
#include "math.h"
using namespace std;

class TPostfix
{
    string* infix;
    string* postfix;
    int infixcount;
    int postfixcount;
    int infixsize;
    int postfixsize;
    TTable<int> reitings;
    TTable <float>* varieble;
    TStack<TRecord<int>> prior; 
    void StringToWord(string str, string* w, int& k)
    {
        string zn = "+-*/ ^()";
        k = 0;
        w[0] = "";
        for (int i = 0; i < str.length(); i++)
        {
            int l = zn.find(str[i]);

            if (l < 0)
            {
                w[k] += str[i];
                if (i == str.length() - 1)
                {
                    k++;
                }
            }
            else
            {
                if (str[i] == ' ')
                {
                    if (w[k] != "")
                    {
                        w[++k] = "";
                    }
                }
                else
                {
                    if (w[k] != "")
                    {
                        k++;
                    }
                    w[k] = str[i];
                    w[++k] = "";
                }
            }
        }
    }
    void workLeft()
    {
        prior.push(TRecord<int>("(", 0));
    };
    void workRight()
    {
        while ((!(prior.isempty())) && (prior.Top().GetName() != "("))
        {
            postfix[postfixcount++] = prior.pop().GetName();
        }
        prior.pop().GetName();
    }
    void workOperand(string operand)
    {
        varieble->SetStr(operand);
        postfix[postfixcount++] = operand;
    }
    void workEnd()
    {
        while (!(prior.isempty()))
        {
            postfix[postfixcount++] = prior.pop().GetName();
        }
    }
    void workOperation(TRecord<int>tmp)
    {
        while (!(prior.isempty()) && (prior.Top().GetValue() >= tmp.GetValue()))
        {
            postfix[postfixcount++] = prior.pop().GetName();
        }
        prior.push(tmp);
    }
public:
    string ToString()
    {
        string str = "";
        for (int i = 0; i < postfixcount; i++)
        {
            str += postfix[i] + " ";
        }
        return str;
    }

    void madereiting()
    {
        reitings = TTable<int>(10);
        reitings.SetStr("+", 1);
        reitings.SetStr("-", 1);
        reitings.SetStr("*", 2);
        reitings.SetStr("/", 2);
        reitings.SetStr("^", 3);
        reitings.SetStr("sqrt", 3);
        reitings.SetStr("sin", 3);
        reitings.SetStr("cos", 3);
    }
    string ToPostfix(string str)
    {
        postfixcount = 0;
        infixsize = str.length() + 2;
        infix = new string[infixsize];
        postfixsize = str.length() + 2;
        postfix = new string[str.length() + 2];
        StringToWord(str, infix, infixcount);
        for (int i = 0; i < infixcount; i++)
        {
            if (infix[i] == "(")
            {
                workLeft();
            }
            else
            {
                if (infix[i] == ")")
                {
                    workRight();
                }
                else
                {
                    int l = reitings.Setch_number(infix[i]);
                    if (l == -1)
                    {
                        workOperand(infix[i]);
                    }
                    else
                    {
                        workOperation(reitings[l]);
                    }
                }
            }
        }
        workEnd();
        return ToString();
    }
    
    TPostfix(string str)
    {
        madereiting();
        varieble = new TTable<float>(str.length());
        prior = TStack<TRecord<int>>(20);
        ToPostfix(str);
    }
    TPostfix(TPostfix& tmp)
    {
        reitings = tmp.reitings;
        varieble = tmp.varieble;
        prior = TStack<TRecord<int>>(20);
        ToPostfix(tmp.ToString());
    }
    TPostfix& operator=(TPostfix& tmp)
    {
        if (postfixsize != 0)
        {
            delete[]postfix;
        }
        reitings = tmp.reitings;
        varieble = tmp.varieble;
        prior = TStack<TRecord<int>>(20);
        ToPostfix(tmp.ToString());
    }
    ~TPostfix()
    {
        delete[]postfix;
        delete[]infix;
    }
    TTable <float>* getvarieble()
    {
        return varieble;
    }
    string GetPostfix()
    {
        string res="";
        for (int i = 0; i < postfixsize; i++)
        {
            res = res + postfix[i] + " ";
        }
        return res;
    };
    string GetInfix()
    {
        string res = "";
        for (int i = 0; i < infixsize; i++)
        {
            res =res+infix[i]+" ";
        }
        return res;
    };
  double Calculate()
  {
      float Left;
      float Right;
      float Res;
      TStack<float>number(varieble[0].Getcount() + 2);
      for (int j = 0; j < postfixcount; j++)
      {
          int l = varieble[0].Setch_number(postfix[j]);
          if (l >= 0)
          {
              number.push(varieble[0][l].GetValue());
          }
          else
          {
              if (postfix[j] == "+")
              {
                  Right = number.pop();
                  Left = number.pop();
                  Res = Left + Right;
                  number.push(Res);
              }
              if (postfix[j] == "-")
              {
                  Right = number.pop();
                  Left = number.pop();
                  Res = Left - Right;
                  number.push(Res);
              }
              if (postfix[j] == "*")
              {
                  Right = number.pop();
                  Left = number.pop();
                  Res = Left * Right;
                  number.push(Res);
              }
              if (postfix[j] == "/")
              {
                  Right = number.pop();
                  Left = number.pop();
                  Res = Left / Right;
                  number.push(Res);
              }
              if (postfix[j] == "^")
              {
                  Right = number.pop();
                  Left = number.pop();
                  Res = pow(Left,Right);
                  number.push(Res);
              }
              if (postfix[j] == "sqrt")
              {
                  Right = number.pop();
                  Res = sqrt(Right);
                  number.push(Res);
              }
              if (postfix[j] == "sin")
              {
                  Right = number.pop();
                  Res = sin(Right);
                  number.push(Res);
              }
              if (postfix[j] == "cos")
              {
                  Right = number.pop();
                  Res = cos(Right);
                  number.push(Res);
              }
          }
      }
      return number.pop();
     // return number.Top();
  }; // Ввод переменных, вычисление по постфиксной форме
};

#endif
/*
#ifndef __POSTFIX_H__
#define __POSTFIX_H__
#include "TTable.h"
#include <string>
#include <vector>
#include "stack.h"
#include "TRecord.h"
#include "stow.h"
using namespace std;
class TPostfix
{
  string *infix;
  string *postfix;
  int infixcount;
  int postfixcount;
  int infixsize;
  int postfixsize;
  TTable<int> reitings;
  TTable <float>* varieble;
  TStack<TRecord<int>> prior;
  void workLeft()
  {
      prior.push(TRecord<int>("(", 0));
  };
  void workRight()
  {
      while ((!(prior.isempty())) && (prior.Top().GetName() != "("))
      {
          postfix[postfixcount++]= prior.pop().GetName();
      }
      prior.pop().GetName();
  }
  void workOperand(string operand)
  {
      varieble->SetStr(operand);
      postfix[postfixcount++] = operand;
  }
  void workEnd()
  {
      while (!(prior.isempty()))
      {
          postfix[postfixcount++] = prior.pop().GetName();
      }
  }
  void workOperation(TRecord<int>tmp)
  {
      while (!(prior.isempty())&&(prior.Top().GetValue()>=tmp.GetValue()))
      {
          postfix[postfixcount++] = prior.pop().GetName();
      }
      prior.push(tmp);
  }
  void madereiting()
  {
      reitings = TTable<int>(10);
      reitings.SetStr("+", 1);
      reitings.SetStr("-", 1);
      reitings.SetStr("*", 2);
      reitings.SetStr("/", 2);
      reitings.SetStr("^", 3);
      reitings.SetStr("sqrt", 3);
      reitings.SetStr("sin", 3);
      reitings.SetStr("cos", 3);
  }
  void madepolis(string str)
  {
      postfixcount = 0;
      infix = new string[str.length() + 2];
      postfixsize = str.length() + 2;
      postfix = new string[str.length() + 2];
      StringToWord(str, infix, infixcount);
      for (int i = 0; i < infixcount; i++)
      {
          if (infix[i] == "(")
          {
              workLeft();
          }
          else
          {
              if (infix[i] == ")")
              {
                  workRight();
              }
              else
              {
                  int l = reitings.Setch_number(infix[i]);
                  if (l == -1)
                  {
                      workOperand(infix[i]);
                  }
                  else
                  {
                      workOperation(reitings[l]);
                  }
              }
          }
      }
      workEnd();
  }
public:
    TPostfix(string str)
    {
        madereiting();
        varieble = new TTable<float>(str.length());
        prior=TStack<TRecord<int>>(20);
        madepolis(str);
    }
    string ToString()
    {
        string str = "";
        for (int i = 0; i < postfixcount; i++)
        {
            str += postfix[i]+" ";
        }
        return str;
    }
    TPostfix(TPostfix& tmp)
    {
        reitings = tmp.reitings;
        varieble = tmp.varieble;
        prior = TStack<TRecord<int>>(20);
        madepolis(tmp.ToString());
    }
    TPostfix& operator=(TPostfix& tmp)
    {
        if (postfixsize != 0)
        {
            delete[]postfix;
        }
        reitings = tmp.reitings;
        varieble = tmp.varieble;
        prior = TStack<TRecord<int>>(20);
        madepolis(tmp.ToString());
    }
    TTable <float>* getvarieble()
    {
        return varieble;
    }
 // double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
*/