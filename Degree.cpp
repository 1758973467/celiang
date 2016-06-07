#include"common.h"
typedef unsigned UINT;
class Degree
{
private:
	int m_du, m_fen,m_miao;
	static double PI=3.1415926;
protected:
	void normalize();
public:
	Degree(int du=0,int fen=0,int miao=0);
	Degree operator+(Degree&other);
	Degree operator-(Degree&other);
	bool operator==(Degree&other);
	bool operator<(Degree&other);
	int changmiao();
	double ChangeRAD();
	static ChangePI(double new_PI);
}

//complention
Degree::Degree(int du=0,int fen=0,int miao=0)
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
	answer.m_fen=(other.m_du+m_fen+static_cast<int>((other.m_miao+m_miao)/60))%60;
	answer.du=(other.m_du+m_du+static_cast<int>((other.m_fen+m_fen)/60));
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
	answer.normalize();
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
inline int Degree::changmiao()
{
	return m_du*60*60+m_fen*60+m_miao;
}
double Degree::ChangeRAD()
{
	return 2*(m_du*60*60+m_fen*60+m_miao)/(360*60*60);
}
static Degree::ChangePI(double new_PI)
{
	PI=new_PI;
}