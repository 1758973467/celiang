#include"common.h"
#include<vector>
#define OVER_LIMITED 0
struct alloc
{
	int number;
	double chai;
}

bool GetData(Degvector&dega,Dvector&da,pos&start);
int GetDegreeData(Degvector&a);
int GetLengthData(Dvector&a);
void GetPos(pos&start);

void calcposition(daoxian a);//总函数
int CalcPositionBIHE();
void reclassifydegree(UINT need_classify,Dvector&length_vector,Degvector&deg_vector);
int calc_pos_change(Dvector&length_vector,Degvector&deg_vector,std::vector<pos>pos_change_vector);
int reclassifypos_change(pos&need_classify,std::vector<pos>&pos_change_vector,Dvector&length_vector);//
