//转化小数位数
#include<string>
#include<cassert>
#include<cstdio>
#include<iostream>
//方法1 sprintf 有缺点
double round(double value,int number)
{
	using namespace std;
	assert(number>=0);
	char*dest=new char[20];
	sprintf_s(dest,20,"%f",value);
	string answer=dest;
	int index=answer.find_first_of(".");
	if(index<0)
	{
		cout<<"convert false;"<<endl;
		return value;
	}
	answer.erase(index,answer.size()-index);
	return atof(answer.data());
}
//方法2 
/*
#include<sstream>
double round(double value,int number)
{
	using namespace std;
	stringstream ss;
	ss<<value;
	string answer;
//	answer<<ss;
	int index=answer.find_first_of(".");
	if(index<0)
	{
		cout<<"convert false;"<<endl;
		return value;
	}
	answer.erase(index,answer.size()-index);
	istringstream iss(answer);
	double new_value;
	iss>>new_value;
	return new_value;
	
}
*/