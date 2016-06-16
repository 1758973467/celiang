//getdata
#include"common.h"
#include"calc.h"
bool GetData(Degvector&dega,Dvector&da,pos&start,Degree&startdegree)
{
	assert(dega.size()==0);
	assert(da.size()==0);
	
	GetPos(start);
	GetDegreeStart(startdegree);
	int deg_number=GetDegreeData(dega);
	int d_number=GetLengthData(da);
	
	if(deg_number==d_number)
		return true;
	else return false;
}
int GetDegreeData(Degvector&a)//返回a的大小
{
	using namespace std;
	cout<<"请输入角度值(度 分 秒)按回车输入-1结束:"<<endl;//有问题
	int du,fen,miao;
	int temp=0;
	while(1)
	{
		cin>>temp;
		if(temp==-1)
		 break;
		du=temp;
		cin>>fen;
		cin>>miao;
		a.push_back(Degree(du,fen,miao));
		
	}
	return a.size();
}
int GetLengthData(Dvector&a)
{
	using namespace std;
	cout<<"请输入长度值,例 1.23"<<endl;
	cout<<"输入-1结束:"<<endl;
	double temp=0.0;
	while(1)
	{
		cin>>temp;
		if(temp==-1)
			break;
		a.push_back(temp);
	}
	return a.size();
}
void GetPos(pos&start)
{
	using namespace std;
	cout<<"请输入起算坐标(例 400534.1 50.341):"<<endl;
	cin>>start.x>>start.y;
	
}
void GetDegreeStart(Degree&start)
{
	using namespace std;
	int du,fen,miao;
	cout<<"请输入起算的坐标方位角:"<<endl;
	cin>>du>>fen>>miao;
	start.set(du,fen,miao);
}
//height
int GetSiteData(std::vector<UINT>&sitevector)
{
	using namespace std;
	cout<<"请输入测站数"<<endl<<"输入-1结束：";
	int temp=0;
	do
	{
		cin>>temp;
		if(temp==-1)
			break;
		sitevector.push_back(static_cast<UINT>(temp));

	}while(1);
	return sitevector.size();
}
int GetHeightData(IntVector&a)
{
	using namespace std;
	cout<<"请输入高差,例 0714"<<endl;
	cout<<"输入-1结束:"<<endl;
	int temp=0;
	while(1)
	{
		cin>>temp;
		if(temp==-1)
			break;
		a.push_back(temp);
	}
	return a.size();
}