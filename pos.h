#include"common.h"
#ifndef _POS_H
#define _POS_H
#include<iostream>
class pos
{
public:
	pos(double _x=0.0,double _y=0.0):x(_x),y(_y){};
	double x;
	double y;
	pos operator+(pos&other);
	friend std::ostream& operator<<(std::ostream&out,pos&other);
};
#endif