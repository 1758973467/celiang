/*
1 printmenu()
*/
//���߼��� 1 ���� 2 �߳�
#include"common.h"
int  printstartmenu()
{
	using namespace std;
	
	cout<<endl;
	int selectfunction=-1;
	cout<<"******************"<<"WECLOME"<<"******************"<<endl;
	cout<<"1 ��ʼ����"<<endl;
	cout<<"2 �˳�"<<endl;
	cout<<"3 ����"<<endl;
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
	cout<<"��ѡ�������ͣ�"<<endl;
	cout<<"1 �պϵ���"<<endl;
	cout<<"2 ���ϵ���"<<endl;
	cout<<"3 ֧����"<<endl;
	for(int i=0;i<20;i++)
	{
		cout<<"*";
	}
	int temp;
	cin>>temp;
	a.m_daoxian=static_cast<daoxian>(temp);
	cout<<"��ѡ��Ҫ���еļ��㣺"<<endl;
	cout<<"1 �߳�"<<endl;
	cout<<"2 ����"<<endl;
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