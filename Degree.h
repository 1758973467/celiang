#include<iostream>
#ifndef _DEGREE_H
#define _DEGREE_H
class Degree
{
private:
	int m_du, m_fen,m_miao;
	bool plus_minus;//Õý¸º
	static double PI;
protected:
	void normalize();
public:
	Degree(int du=0,int fen=0,int miao=0);
	Degree operator+(Degree&other);
	Degree operator-(Degree&other);
	Degree operator-();
	bool operator==(Degree&other);
	bool operator<(Degree&other);
	friend std::ostream& operator<<(std::ostream&out,Degree&other);
	int changmiao();
	double ChangeRAD();
	static void ChangePI(double new_PI);
};
#endif