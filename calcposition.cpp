#include"calc.h"
#include<algorithm>
#include<cassert>
//计算坐标
bool calcposition(daoxian a)
{
	using namespace std;
	switch(a)
	{
		case BIHE:
		CalcPositionBIHE(a);
		break;
		case FUHE:
		CalcPositionFUHE();
		break;
		case ZHI:
		CalcPositionZHI();
		break;
		default:
		{
			std::cout<<"错误的导线类型"<<std::endl;
			return false;
		}
	}
	return true;
	
}
int CalcPositionBIHE(daoxian a)
{
	using namespace std;
	assert(a==BIHE);
	
	pos start;
	Degvector deg_vector;
	vector<double> length_vector;
	GetData(deg_vector,length_vector,start);
	int n=deg_vector.size();
	Degree sum(0,0,0);
	for(int i=0;i<deg_vector.size();++i)
	{
		sum=sum+deg_vector[i];
	}
	Degree standrad((n-2)*180,0,0);//n为测站数
	Degree chai=sum-standrad;
	UINT miao=abs(chai.changmiao());//转化到秒来比较
	if(miao>40*sqrt(deg_vector.size()))
		return OVER_LIMITED;
	else 
		reclassifydegree(chai.changmiao(),length_vector,deg_vector);//平差
	//计算坐标增量
	std::vector<pos>pos_change_vector;
	calc_pos_change(length_vector,deg_vector,pos_change_vector);
	//计算坐标
	pos srart;//必须
	std::vector<pos>pos_vector;
	pos temp;
	temp.x=start.x;
	temp.y=start.y;
	pos_vector.push_back(temp);
	for(int i=0;i<n;++i)
	{
		temp.x=pos_vector[i].x+pos_change_vector[i].x;
		temp.y=pos_vector[i].y+pos_change_vector[i].y;
		pos_vector.push_back(temp);
	}
}
struct alloc
{
	int number;
	double chai;
};
void reclassifydegree(UINT need_classify,Dvector&length_vector,Degvector&deg_vector)
{
	int n=deg_vector.size();
	UINT average=static_cast<UINT>(need_classify/n);
	UINT chai=need_classify-average*n;
	//得到距离差再平差
	std::vector<alloc>a;
	alloc temp;
	for(int i=1;i<n;++i)
	{
		temp.number=i;
		temp.chai=length_vector[i]-length_vector[i-1];
		a.push_back(temp);
	}
	temp.number=n;
	temp.chai=length_vector[n]-length_vector[0];
	a.push_back(temp);
	//sort 将距离差最大的排出来
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n-i;++j)
		{
			if(a[i].chai<a[j].chai)
				std::swap(a[i],a[j]);
		}
	}
	
	for(int i=0;i<chai;++i)
	{
		deg_vector[i]+Degree(0,0,chai/abs(static_cast<int>(chai)));
	}
	//print Degvector;
	for(int i=0;i<n;++i)
	{
		std::cout<<deg_vector[i]<<" "<<std::endl;
	}
}

int calc_pos_change(Dvector&length_vector,Degvector&deg_vector,std::vector<pos>pos_change_vector)
{
	pos temp;
	int n=deg_vector.size();
	for(int i=0;i<n;++i)
	{
		temp.x=length_vector[i]*cos(deg_vector[i].ChangeRAD());
		temp.y=length_vector[i]*sin(deg_vector[i].ChangeRAD());
		pos_change_vector.push_back(temp);
	}
	double fx=0,fy=0,sum=0,f,K_revese=0;
	for(int i=0;i<n;++i)
	{
		fx+=pos_change_vector[i].x;
		fy+=pos_change_vector[i].y;
		sum+=length_vector[i];
	}
	f=sqrt(fx*fx+fy*fy);
	K_revese=sum/f;
	temp.x=fx;
	temp.y=fy;
	if(K_revese>=2000)
		reclassifypos_change(temp,pos_change_vector,length_vector);
	else std::cout<<"ERROR";
	return OVER_LIMITED;
}
int reclassifypos_change(pos&need_classify,std::vector<pos>&pos_change_vector,Dvector&length_vector)
{
	int num=length_vector.size();
	std::vector<pos>classify_vector;
	double sum=0;
	for(int i=0;i<num;++i)
	{
		sum+=length_vector[i];
	}
	pos temp;
	for(int i=0;i<num;++i)
	{
		temp.x=-1*need_classify.x/sum*length_vector[i];
		temp.y=-1*need_classify.y/sum*length_vector[i];
		classify_vector.push_back(temp);
	}
	//TODO:应保留三位小数
	/*
	*/
	//TODO:确保算出来总数等于总值
	/**/
	//计算坐标增量最终值
	for(int i=0;i<num;++i)
	{
		pos_change_vector[i]=pos_change_vector[i]+classify_vector[i];
	}
	return 1;
}

int CalcPositionFUHE()
{
	return 0;
}
int CalcPositionZHI()
{
	return 0;
}