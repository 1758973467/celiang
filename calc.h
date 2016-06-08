
#include"common.h"
#ifndef _CALC_H
#define _CALC_H
#include<vector>
#define OVER_LIMITED 0

//GetData.h
bool GetData(Degvector&dega,Dvector&da,pos&start);
int GetDegreeData(Degvector&a);
int GetLengthData(Dvector&a);
void GetPos(pos&start);
//CalcPosition.h
bool calcposition(daoxian a);//总函数
int CalcPositionBIHE(daoxian a);
void reclassifydegree(UINT need_classify,Dvector&length_vector,Degvector&deg_vector);
int calc_pos_change(Dvector&length_vector,Degvector&deg_vector,std::vector<pos>pos_change_vector);
int reclassifypos_change(pos&need_classify,std::vector<pos>&pos_change_vector,Dvector&length_vector);//

int CalcPositionFUHE();
int CalcPositionZHI();
//Calcheight.h
void calcheight(daoxian a);
#endif