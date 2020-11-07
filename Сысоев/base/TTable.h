#pragma once
#ifndef TTABLE_H
#define TTABLE_H
#include "TRecord.h"
#include <iostream>
using namespace std;
template <class T2>
class TTable
{
private:
	int current;
	int size;
	TRecord<T2>* arr;
public:
	TTable(int size_ = 10)
	{
		if (size_ < 0)
		{
			throw "uncrorrect_size_of_table";
		}
		size = size_;
		current = 0;
		arr = new TRecord<T2>[size];
	}
	TTable(const TTable& tmp)
	{
		size = tmp.size;
		current = tmp.current;
		arr = new TRecord<T2>[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = tmp.arr[i];
		}
	}
	TTable& operator=(const TTable& tmp)
	{
		if (size != 0)
		{
			delete[]arr;
		}
		size = tmp.size;
		current = tmp.current;
		arr = new TRecord<T2>[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = tmp.arr[i];
		}
		return *this;
	}
	int Setch_number(string key)
	{
		int l = -1;
		for (int i = 0; (i < current) && (l == -1); i++)
		{
			if (key == arr[i].GetName())
			{
				l = i;
			}
		}
		return l;
	}
	T2 Setch_value(string key)
	{
		int l = -1;
		for (int i = 0; (i < current) && (l == -1); i++)
		{
			if (key == arr[i].GetName())
			{
				l = i;
			}
		}
		if (l >= 0)
		{
			return arr[l].GetValue();
		}
		else
		{
			return T2(0);
		}
	}
	void SetStr(string Name_, T2 Value_ = 0)
	{

		if (current > size)
		{
			throw "current is large";
		}
		TRecord<T2> newrecord(Name_, Value_);
		int l = Setch_number(Name_);
		if (l == -1)
		{
			arr[current++] = newrecord;
			                                        //cout << current << endl;
		}
		else
		{
			arr[l] = newrecord;
		}
	}
	bool isfull()
	{
		if (size == current)
		{
			return true;         //правда
		}
		else
			return false;        //ложь
	}
	~TTable()
	{
		delete[]arr;
	}
	TRecord<T2>& operator[](int k)
	{
		if ((k >= 0) && (k < current))
		{
			return arr[k];
		}
		else
		{
			TRecord<T2>zero;
			return zero;
		}
	}
	int Getcount()
	{
		return current;
	}
};

#endif
