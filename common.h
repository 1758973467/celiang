
#include<vector>
#include<iostream>
#include<camth>
#include<fstream>
#include<iomanip>
enum daoxian{BIHE,FUHE,ZHI};
enum calc{HEIGHT,POSTION};
struct leixing
{
	daoxian m_daoxian;
	calc m_calc;
}
struct pos
{
	double x;
	double y;
}


typedef std::vector<double>Dvector;
typedef std::vector<Degree>Degvector;
