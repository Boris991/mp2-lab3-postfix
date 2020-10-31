#pragma once
#include <iostream>
#include "string"
using namespace std;
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