#include"clac.h"
//计算坐标
bool calcposition(daoxian a)
{
	switch(a)
	{
		case BIHE:
		CalcPositionBIHE();
		break;
		case FUHE:
		CalcPositionFUHE();
		break;
		case ZHI:
		CalcPositionZHI();
		break;
		default:
		std::cout<<"错误的导线类型"<<endl;
		return false;
	}
	return true;
	
}
int CalcPositionBIHE()
{
	//
	assert(a.daoxian==BIHE);
	pos start;
	Degvector deg_vector;
	length_vector length_vector;
	GetData(deg_vector,length_vector,start);
	
	Degree sum(0,0,0);
	for(int i=0;i<deg_vector.size();++i)
	{
		sum+=deg_vector[i];
	}
	Degree standrad((n-2)*180,0,0);//n为测站数
	Degree chai=sum-standrad;
	UINT miao=abs(chai.changmiao());//转化到秒来比较
	if(miao>40*sqrt(deg_vector.size()))
		return OVER_LIMITED;
	else 
		reclassifydegree(chai.changmiao(),length_vector,deg_vector);//平差
	//计算坐标增量
	std::vector<pos>pos_cahnge;
	calc_pos_change(length_vector,deg_vector,pos_change);
	//计算坐标
	pos srart;//必须
	std::vector<pos>pos_vector;
	pos_vector.push_back(start.x,start.y);
	for(int i=0;i<num;++i)
	{
		pos_vector.push_back(
		pos_vector[i].x+pos_cahnge_vector[i].x,
		pos_vector[i].y+pos_cahnge_vector[i].y
		);
	}
}

void reclassifydegree(UINT need_classify,Dvector&length_vector,Degvector&deg_vector)
{
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
	a.push_back(n,;length_vector[n]-length_vector[0]);
	//sort 将距离差最大的排出来
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n-i;++j)
		{
			if(a[i].chai<a[j].chai)
				swap(a[i],a[j]);
		}
	}
	
	for(int i=0;i<chai;++i)
	{
		deg_vector[i]+Degree(0,0,chai/abs(chai));
	}
	//print Degvector;
	for(int i=0;i<n;++i)
	{
		std::cout<<deg_vector[i]<<" "<<endl;
	}
}

int calc_pos_change(Dvector&length_vector,Degvector&deg_vector,std::vector<pos>pos_change_vector)
{
	for(int i=0;i<n;++i)
	{
		pos_change_vector.push_back((pos(length_vector[i]*cos(Degvector[i].changRAD()),
		length_vector[i]*sin(Degvector[i].changRAD())));
	}
	double fx=0,fy=0,sum=0,f,K_revese=0;
	for(int i=0;i<n;++i)
	{
		fx+=pos_cahnge_vector[i].x;
		fy+=pos_cahnge_vector[i].y;
		sum+=length_vector[i];
	}
	f=sqrt(fx*fx+fy*fy);
	K_revese=sum/f;
	if(K_revese>=2000)
		reclassifypos_change(pos(fx,fy),pos_cahnge_vector,length_vector);
	else cout<<"ERROR";
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
	for(int i=0;i<num;++i)
	{
		classify_vector.push_back(pos(
		-1*need_classify.x/sum*length_vector[i],
		-1*need_classify.y/sum*length_vector[i])
		);
	}
	//TODO:应保留三位小数
	/*
	*/
	//TODO:确保算出来总数等于总值
	/**/
	//计算坐标增量最终值
	for(int i=0;i<num;++i)
	{
		pos_change_vector[i]+=classify_vector[i];
	}
	return 1;
}