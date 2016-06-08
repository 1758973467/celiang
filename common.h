#ifndef _COMMON_H
#define _COMMON_H
#include<vector>
#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<cassert>
#include"Degree.h"
enum daoxian{BIHE,FUHE,ZHI};
enum calc{HEIGHT,POSTION};
struct leixing
{
	daoxian m_daoxian;
	calc m_calc;
};
struct pos
{
	double x;
	double y;
};

typedef unsigned UINT;
typedef std::vector<double>Dvector;
typedef std::vector<Degree>Degvector;
#endif