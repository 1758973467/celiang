//计算高程
#include"calc.h"

void calcheight(daoxian a)
{
	std::cout<<"1 四等水准测量"<<std::endl<<"2 等外水准测量"<<std::endl;
	std::cout<<"请输入高差等级:"<<std::endl;
	Level rank;
	int temp;
	std::cin>>temp;
	switch(temp)
	{
	case 1:
		rank=FOUR;
		break;
	case 2:
		rank=OVER;
		break;
	default:
			std::cout<<" 类型error"<<std::endl;
	}
	return ;
	switch(a-1)
	{
		case BIHE:
		CalcHeightBIHE(a,rank);
		break;
		case FUHE:
		CalcHeightFUHE(a,rank);
		break;
		case ZHI:
		CalcHeightZHI(a,rank);
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
	
	do{
		cin>>temp;
	if(temp==1||temp==2)
		return temp==1?true:false;
	}while(1);
}
//等外测量


int CalcHeightBIHE(daoxian a,Level level)
{
	if(level!=FOUR||level!=OVER)return 0;
	IntVector heightchai;
	
	GetHeightData(heightchai);
	//区分测站和距离
	int n=heightchai.size();
	//计算高差闭合差
	int sum=0;
	for(int i=0;i<n;++i)
	{
		sum+=heightchai[i];
	}
	bool mark=Selectcezhan_length();//true 为测站，false为距离
	int fhr=0,fhc=0;//fhr fh容,fhc fh测
	if(mark)
	{
		std::vector<UINT> sitevector(n);
		GetSiteData(sitevector);
		
		int cezhan_number=0;
		for(int i=0;i<n;i++)
		{
			cezhan_number+=sitevector[i];
		}
		fhr=static_cast<int>(40*sqrt(cezhan_number));
		if(level==FOUR){
			fhr/=2;
		}
		if(abs(fhr)>abs(fhc))
			reclassifyheight(fhc,sitevector,heightchai);
		else std::cout<<"OVERLIMIT"<<std::endl;
	}
	else {
		Dvector lengthvector(n);
		GetLengthData(lengthvector);
		
		double length_sum=0;//单位以m记
		for(int i=0;i<n;++i)
		{
			length_sum+=lengthvector[i];
		}
		fhr=static_cast<int>(12*sqrt(length_sum/1000));
		if(abs(fhr)>abs(fhc))
			reclassifyheight(fhc,lengthvector,heightchai);
		else std::cout<<"OVERLIMIT"<<std::endl;
	}
	printvector(heightchai,"改正后高差：");
	return 1;
}
template <typename T>
void reclassifyheight(int needclassify,std::vector<T>basic,IntVector&heightchai)//单位为m a是相关依据
{
	int n=basic.size();
 	T sum=0;
	for(int i=0;i<n;++i)
	{
		sum+=basic[i];
	} 
	
	IntVector allocate(n);
	for(int i=0;i<n;++i)
	{
		allocate[i]=static_cast<int>(needclassify/sum*basic[i]);
	}
	int intsum=0;
	for(int i=0;i<n;++i)
	{
		intsum+=allocate[i];
	}
	int chai=needclassify-intsum;
	
	std::vector<alloc<double> >reallocvector(n);
	alloc<double> temp;
	for(int i=1;i<n;++i)
	{
		temp.number=i;
		temp.chai=abs(static_cast<double>(basic[i]-basic[i-1]));
		reallocvector.push_back(temp);
	}
	temp.number=n;
	temp.chai=abs(static_cast<double>(basic[n-1]-basic[0]));
	reallocvector.push_back(temp);
	//sort 将距离差最大的排出来
	
	for(int i=0;i<n;++i)
	{
		for(int j=i;j<n;++j)
		{
			if(reallocvector[i].chai<reallocvector[j].chai)
				std::swap(reallocvector[i],reallocvector[j]);
		}
	}
	//将余差分配
	for(int i=0;i<abs(chai);++i)
	{
		heightchai[reallocvector[i].number-1]+=chai/abs(chai);
	}
	//按公式的分配
	for(int i=0;i<n;++i)
	{
		heightchai[i]+=allocate[i];
	}
	
}




int CalcHeightFUHE(daoxian a,Level level)
{
	return 1;
}
int CalcHeightZHI(daoxian a,Level level)
{
	return 1;
}