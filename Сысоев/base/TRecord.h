#pragma once
#include <iostream>
using namespace std;
template <class T2>
class TRecord
{
private:
	string Name;
	T2 Value;
public:
	TRecord(string Name_ = "", T2 Value_ = 0)
	{
		Name = Name_;
		Value = Value_;
	}
	TRecord(const TRecord& tmp)
	{
		Name = tmp.Name;
		Value = tmp.Value;
	}
	TRecord& operator=(const TRecord& tmp)
	{
		Name = tmp.Name;
		Value = tmp.Value;
		return *this;
	}
	T2 GetValue()
	{
		return Value;
	}
	void SetValue(T2 Value_)
	{
		Value = Value_;
	}
	string GetName()
	{
		return Name;
	}
};
/*
#include <iostream>
using namespace std;
template <class T2>
class TRecord
{
private:
	string Name;
	T2 Value;
public:
	TRecord(string Name_="", T2 Value_=0)
	{
		Name = Name_;
		Value = Value_;
	}
	TRecord(const TRecord& tmp)
	{
		Name = tmp.Name;
		Value = tmp.Value;
	}
	TRecord& operator=(const TRecord& tmp)
	{
		Name = tmp.Name;
		Value = tmp.Value;
		return *this;
	}
	T2 GetValue()
	{
		return Value;
	}
	void SetValue(T2 Value_)
	{
		Value = Value_;
	}
	string GetName()
	{
		return Name;
	}
};


*/
