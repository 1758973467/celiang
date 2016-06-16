
#include"common.h"
#ifndef _CALC_H
#define _CALC_H
#include<vector>
#define OVER_LIMITED 0
template <typename T>
struct alloc
{
	int number;
	T chai;
};
typedef std::vector<int>IntVector;
//GetData.h
bool GetData(Degvector&dega,Dvector&da,pos&start,Degree&startdegree);
void GetDegreeStart(Degree&start);
int GetDegreeData(Degvector&a);
int GetLengthData(Dvector&a);
void GetPos(pos&start);

int GetHeightData(IntVector&a);
int GetSiteData(std::vector<UINT>&sitevector);
//CalcPosition
bool calcposition(daoxian a);//×Üº¯Êý
int CalcPositionBIHE(daoxian a);
int CalcPositionFUHE(daoxian a);
int CalcPositionZHI(daoxian a);
void reclassifydegree(int need_classify,Dvector&length_vector,Degvector&deg_vector);
void calcgrid_bearing(Degvector&deg_vector,Degree&startdegree,Degvector&grid_bear);
int calc_pos_change(Dvector&length_vector,Degvector&deg_vector,std::vector<pos>pos_change_vector);
int reclassifypos_change(pos&need_classify,std::vector<pos>&pos_change_vector,Dvector&length_vector);//

int CalcPositionFUHE();
int CalcPositionZHI();
//Calcheight
void calcheight(daoxian a);
int CalcHeightBIHE(daoxian a);
int CalcHeightFUHE(daoxian a);
int CalcHeightZHI(daoxian a);
template <typename T>
void reclassifyheight(int needclassify,std::vector<T>basic,IntVector&heightchai);
#endif