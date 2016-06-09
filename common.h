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
class pos
{
public:
	pos(double _x=0.0,double _y=0.0):x(_x),y(_y){};
	double x;
	double y;
	pos operator+(pos&other);
};
inline pos pos::operator+(pos &other)
{
	return pos(other.x+x,other.y+y);
}
typedef unsigned UINT;
typedef std::vector<double>Dvector;
typedef std::vector<Degree>Degvector;
#endif