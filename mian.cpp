/*
1 printmenu()
*/
//导线计算 1 坐标 2 高程
#include"common.h"
int  printstartmenu()
{
	using namespace std;
	
	cout<<endl;
	int selectfunction=-1;
	cout<<"******************"<<"WECLOME"<<"******************"<<endl;
	cout<<"1 开始计算"<<endl;
	cout<<"2 退出"<<endl;
	cout<<"3 关于"<<endl;
	for(int i=0;i<20;i++)
	{
		cout<<"*";
	}
	
	cin>>selectfunction;
	
	return selectfunction;
}
leixing printcalcmenu()
{
	using namespace std;
	for(int i=0;i<20;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	leixing a;
	cout<<"请选择导线类型："<<endl;
	cout<<"1 闭合导线"<<endl;
	cout<<"2 附合导线"<<endl;
	cout<<"3 支导线"<<endl;
	for(int i=0;i<20;i++)
	{
		cout<<"*";
	}
	int temp;
	cin>>temp;
	a.m_daoxian=static_cast<daoxian>(temp);
	cout<<"请选择要进行的计算："<<endl;
	cout<<"1 高程"<<endl;
	cout<<"2 坐标"<<endl;
	for(int i=0;i<20;i++)
	{
		cout<<"*";
	}

	cin>>temp;
	a.m_calc=static_cast<calc>(temp);
	return a;
}
void  printabout()
{
}
int main()
{
	
	switch(printstartmenu())
	{
		case 1:
		break;
		case 2:
		return 0;
		case 3:
		printabout();
		break;
		default:
		return -1;
	}
	leixing a=printcalcmenu();
	switch (a.m_calc)
	{
		case HEIGHT:
		calcheight(a.daoxian);
		break;
		case POSTION:
		calcposition(a.daoxian);
		break;
		
	}
	return 0;
}