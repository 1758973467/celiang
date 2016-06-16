#ifndef _COMMON_H
#define _COMMON_H
#include<vector>
#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<cassert>
#include<string>
#include"Degree.h"
#include"pos.h"
enum daoxian{BIHE,FUHE,ZHI};
enum calc{HEIGHT,POSTION};
struct leixing
{
	daoxian m_daoxian;
	calc m_calc;
};


template<class T>
inline void printvector(std::vector<T>&a,const char*str="")
{
	using namespace std; 
	int size=a.size();
	if(str!="")
		cout<<str<<endl;
	for(int i=0;i<size;++i)
	{
		cout<<a[i]<<endl;
	}
}
typedef unsigned UINT;
typedef std::vector<double>Dvector;
typedef std::vector<Degree>Degvector;
#endif