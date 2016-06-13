
#include"common.h"
#include"Degree.h"
typedef unsigned UINT;


 double Degree::PI=3.1415926;
//complention
Degree::Degree(int du,int fen,int miao)
:m_du(du),m_fen(fen),m_miao(miao)
{
	normalize();
}
void Degree::normalize()//确保m_du,m_fen,m_miao在正确的范围之内
{
	assert(m_fen<=60&&m_fen>=0);
	assert(m_miao<=60&&m_miao>=0);
	
	if(m_miao==60)
	{
		m_fen+=1;
		m_miao=0;
	}
	if(m_fen==60)
	{
		m_du+=1;
		m_fen=0;
	}
}
Degree Degree::operator+(Degree&other)
{
	Degree answer(0,0,0);
	answer.m_miao=(other.m_miao+m_miao)%60;
	answer.m_fen=(other.m_fen+m_fen+static_cast<int>((other.m_miao+m_miao)/60))%60;
	answer.m_du=(other.m_du+m_du+static_cast<int>((other.m_fen+m_fen)/60));
	answer.normalize();
	return answer;
}
Degree Degree::operator-(Degree&other)
{
	Degree answer(0,0,0);
	
	if(m_miao>other.m_miao)
	{
		if(m_fen<=0)
		{
			m_fen=60;
			m_du-=1;
		}
		m_fen-=1;
		m_miao+=60;
	}
	answer.m_miao=m_miao-other.m_miao;
	if(m_fen<other.m_fen)

	{
		m_du-=1;
		m_fen+=60;
	}
	answer.m_fen=m_fen-other.m_fen;
	answer.m_du=m_du-other.m_du;
	//answer.normalize();
	return answer;
}
bool Degree::operator==(Degree&other)
{
	if(m_du==other.m_du&&m_fen==other.m_fen&&m_miao==other.m_miao)
		return true;
	else return false;
}
bool Degree::operator<(Degree&other)
{
	if(abs(m_du)<abs(other.m_du))
	{
		return true;
	}
	else if(abs(m_du)==abs(other.m_du)&&m_fen<other.m_fen)
	{
		return true;
	}
	else if(abs(m_du)==abs(other.m_du)&&m_fen==other.m_fen&&m_miao<other.m_miao)
	{
		return true;
	}
	else return false;
	
}
std::ostream& operator<<(std::ostream&out,Degree&other)
{
	out<<other.m_du<<"du"<<other.m_fen<<"fen"<<other.m_miao<<"miao";
	return out;
}
 int Degree::changmiao()
{
	return m_du*60*60+m_fen*60+m_miao;
}
double Degree::ChangeRAD()
{
	return 2*(m_du*60*60+m_fen*60+m_miao)/(360*60*60);
}
void Degree::ChangePI(double new_PI)
{
	PI=new_PI;
}