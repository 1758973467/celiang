//getdata
#include"common.h"
#include"calc.h"
bool GetData(Degvector&dega,Dvector&da,pos&start)
{
	assert(dega.size()==0);
	assert(da.size()==0);
	
	GetPos(start);
	
	int deg_number=GetDegreeData(dega);
	int d_number=GetLengthData(da);
	
	if(deg_number==d_number)
		return true;
	else return false;
}
int GetDegreeData(Degvector&a)//返回a的大小
{
	using namespace std;
	cout<<"请输入角度值（例 90 36 40）按回车键输入，输入-1结束："<<endl;
	int du,fen,miao;
	int temp=0;
	while(1)
	{
		cin>>temp;
		if(temp=-1)
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
	cout<<"请输入长度值（例 1.23）按回车键输入，输入-1结束："<<endl;
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
