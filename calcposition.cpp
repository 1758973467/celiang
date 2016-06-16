#include"calc.h"
#include<algorithm>
#include<cassert>
//计算坐标
bool calcposition(daoxian a)
{
	using namespace std;
	
	switch(a-1)
	{
		case BIHE:
		CalcPositionBIHE(a);
		break;
		case FUHE:
		CalcPositionFUHE(a);
		break;
		case ZHI:
		CalcPositionZHI(a);
		break;
		
	}
	return true;
	
}
int CalcPositionBIHE(daoxian a)
{
	using namespace std;
	assert(a-1==BIHE);
	
	pos start;
	Degvector deg_vector;
	vector<double> length_vector;
	Degree startdegree;
	GetData(deg_vector,length_vector,start,startdegree);
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
		reclassifydegree(-1*chai.changmiao(),length_vector,deg_vector);//平差
	//calc坐标方位角
	Degvector grid_bear(n);
	calcgrid_bearing(deg_vector,startdegree,grid_bear);
	//计算坐标增量
	std::vector<pos>pos_change_vector(n);
	calc_pos_change(length_vector,deg_vector,pos_change_vector);
	//计算坐标
	//pos srart;//必须
	std::vector<pos>pos_vector(n+1);
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
	return 0;
}

void reclassifydegree(int need_classify,Dvector&length_vector,Degvector&deg_vector)
{
	int n=deg_vector.size();
	int average=static_cast<int>(need_classify/n);
	int chai=need_classify-average*n;
	//得到距离差再平差
	std::vector<alloc<double> >a(n);
	alloc<double> temp;
	for(int i=1;i<n;++i)
	{
		temp.number=i;
		temp.chai=abs(length_vector[i]-length_vector[i-1]);
		a.push_back(temp);
	}
	temp.number=n;
	temp.chai=abs(length_vector[n-1]-length_vector[0]);
	a.push_back(temp);
	//sort 将距离差最大的排出来
	
	for(int i=0;i<n;++i)
	{
		for(int j=i;j<n;++j)
		{
			if(a[i].chai<a[j].chai)
				std::swap(a[i],a[j]);
		}
	}

	int number=abs(chai);
	Degree sum(0,0,0);//校验
	for(int i=0;i<number;++i)
	{
		deg_vector[a[i].number-1]=deg_vector[a[i].number-1]+Degree(0,0,chai/abs(chai));
	}
	for(int i=0;i<n;++i)
	{
		deg_vector[i]=deg_vector[i]+Degree(0,0,average);
		sum=sum+deg_vector[i];
	}

	if(sum==Degree((n-2)*180,0,0))
	{
		std::cout<<"success allocte degree"<<std::endl;
	}
	//print Degvector;
	std::cout<<"改正后的角值："<<std::endl;
	for(int i=0;i<n;++i)
	{
		std::cout<<deg_vector[i]<<" "<<std::endl;
	}
}
void calcgrid_bearing(Degvector&deg_vector,Degree&startdegree,Degvector&grid_bear)
{
	int n=deg_vector.size();
	grid_bear[0]=deg_vector[0]+Degree(180,0,0)+startdegree;
	grid_bear[0]=grid_bear[0]%360;
	for(int i=1;i<n;++i)
	{
		grid_bear[i]=deg_vector[i]+Degree(180,0,0)+grid_bear[i-1];
		grid_bear[i]=grid_bear[i]%360;
	}
	using namespace std;
	cout<<"坐标方位角:"<<endl;
	for(int i=0;i<n;++i)
	{
		cout<<grid_bear[i]<<endl;
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
	{
		reclassifypos_change(temp,pos_change_vector,length_vector);
		return 1;
	}
	else{
		std::cout<<"ERROR"<<std::endl;
		return OVER_LIMITED;
	}
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

	std::cout<<"改正后的坐标增量"<<std::endl;
	for(int i=0;i<num;++i)
	{
		std::cout<<pos_change_vector[i]<<std::endl;
	}
	return 1;
}

int CalcPositionFUHE(daoxian a)
{
	return 0;
}
int CalcPositionZHI(daoxian a)
{
	return 0;
}