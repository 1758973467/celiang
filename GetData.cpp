//getdata
#include"common.h"
#include"calc.h"
bool GetData(Degvector&dega,Dvector&da,pos&start)
{
	assert(dega.size()==0);
	assert(da.size()==0);
	
	//GetPos(start);
	
	int deg_number=GetDegreeData(dega);
	//int d_number=GetLengthData(da);
	
	//if(deg_number==d_number)
		return true;
	//else return false;
}
int GetDegreeData(Degvector&a)//����a�Ĵ�С
{
	using namespace std;
	cout<<"������Ƕ�ֵ(�� �� ��)���س�����-1����:"<<endl;//������
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
	cout<<"�����볤��ֵ,�� 1.23"<<endl;
	cout<<"����-1����:"<<endl;
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
	cout<<"��������������(�� 400534.1 50.341):"<<endl;
	cin>>start.x>>start.y;
	
}
