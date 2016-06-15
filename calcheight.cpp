//计算高程
#include"calc.h"

void calcheight(daoxian a)
{
	switch(a-1)
	{
		case BIHE:
		CalcHeightBIHE(a);
		break;
		case FUHE:
		CalcHeightFUHE(a);
		break;
		case ZHI:
		CalcHeightZHI(a);
		break;
		default:
			std::cout<<" 类型error"<<std::endl;
	}
	
}
bool Selectcezhan_length()
{
	using namespace std;
	cout<<"请选择平差依据是："<<endl;
	cout<<"1 测站"<<endl<<"2 距离"<<endl;
	int temp=0;
	
	do(
		cin>>temp;
		if(temp==1||temp==2)
			return temp==1?true:false;
		cout<<"请重新输入"<<endl;
	}while(1)
}
//等外测量
typedef vector<int>IntVector;
int CalcHeightBIHE(daoxian a)
{
	IntVector heightchai;
	
	GetHeightData(heightchai);
	//区分测站和距离
	int n=heightchai.size();
	bool mark=Selectcezhan_length();//true 为测站，false为距离
	if(mark)
	{
		IntVector sitevector(n);
		GetSiteData(sitevector);	
	}
	else {
		Dvector lengthvector(n);
		GetLengthData(lengthvector);
	}
	int sum=0;
	for(int i=0;i<n;++i)
	{
		sum+=heightchai[i];
	}
	int fhr=0,fhc=0;//fhr fh容,fhc fh测
	int cezhan_number,length_sum;
	mark==true?fhr=40*sqrt(cezhan_number):fhr=12*sqrt(length_sum);
	
	if(abs(fhr)>abs(fhc))
		
		mark==true?reclassifyheight(fhc,sitevector,heightchai):
		reclassifyheight(fhc,lengthvector,heightchai);//liangzhongxingshi
	else std::cout<<"OVERLIMIT"<<std::endl;
	Printvector(heightchai,"改正后高差：");
	
	return 1;
}
//template<class T>

void reclassifyheight(double needclassify,vector<T>a,Dvector&heightchai)//单位为m a是相关依据
{
	int n=a.size();
	IntVector allocate(n);
	T sum=0;
	for(int i=0;i<n;++i)
	{
		sum+=a[i];
	}
	for(int i=0;i<n;++i)
	{
		allocate[i]=static_cast<int>(needclassify/sum*a[i]);
	}
	int intsum=0;
	for(int i=0;i<n;++i)
	{
		intsum+=allocate[i];
	}
	int chai=needclassify-intsum;
	assert(chai>=0);
	vector<alloc<T> >allocvector(n);
	alloc<T> temp;
	for(int i=1;i<n;++i)
	{
		temp.number=i;
		temp.chai=abs(a[i]-a[i-1]);
		allocate.push_back(temp);
	}
	temp.number=n;
	temp.chai=abs(a[n-1]-a[0]);
	a.push_back(temp);
	//sort 将距离差最大的排出来
	
	for(int i=0;i<n;++i)
	{
		for(int j=i;j<n;++j)
		{
			if(allocvector[i].chai<allocvector[j].chai)
				std::swap(allocvector[i],allocvector[j]);
		}
	}
	//将余差分配
	for(int i=0;i<abs(chai);++i)
	{
		heightchai[allocvector[i].number-1]+=chai/abs(chai);
	}
	//将公式的分配
	for(int i=0;i<n;++i)
	{
		heightchai[i]+=allocte[i];
	}
	
}



int CalcHeightFUHE(daoxian a)
{
	return 1;
}
int CalcHeightZHI(daoxian a)
{
	return 1;
}