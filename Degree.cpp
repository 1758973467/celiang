
#include"common.h"
#include"Degree.h"
#include<iomanip>
typedef unsigned UINT;


 double Degree::PI=3.1415926;
//complention
Degree::Degree(int du,int fen,int miao)
:m_du(du),m_fen(fen),m_miao(miao)
{
	if(m_miao<0||m_du<0||m_du<0){
		plus_minus=false;
	}
	else plus_minus=true;
	m_du=abs(m_du);
	m_fen=abs(m_fen);
	m_miao=abs(m_miao);
	normalize();
}
void Degree::set(int du,int fen,int miao)
{
	m_du=du;
	m_fen=fen;
	m_miao=miao;
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
	//分类
	if(plus_minus)
	{
		if(other.plus_minus==false)
		{
			return *this-(-other);
		}
	}
	else
	{
		if(other.plus_minus)
			return other-(-*this);
		else
			return -(-*this+(-other));
	}
	Degree answer(0,0,0);
	answer.m_miao=(other.m_miao+m_miao)%60;
	answer.m_fen=(other.m_fen+m_fen+static_cast<int>((other.m_miao+m_miao)/60))%60;
	answer.m_du=(other.m_du+m_du+static_cast<int>((other.m_fen+m_fen)/60));
	answer.normalize();
	return answer;
}
Degree Degree::operator-()
{
	plus_minus=!plus_minus;
	return *this;
}
Degree Degree::operator-(Degree&other)
{
	//分类
	if(plus_minus)
	{
		if(!other.plus_minus)
			return *this+(-other);
	}
	else
	{
		if(other.plus_minus)
			return -(-*this+other);
		else
			return -*this+(-other);
	}

	if(*this<other)
	{
		return -(other-*this);
	}
	Degree answer(0,0,0);
	
	if(m_miao<other.m_miao)
	{
		if(m_fen<=0)
		{
			m_fen=60;
			m_du-=1;
		}
		m_fen-=1;
		assert(m_du>=0);
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
Degree Degree::operator%(int number)
{
	//Degree answer(0,0,0);
	m_du=m_du%number;
	return *this;
}
std::ostream& operator<<(std::ostream&out,Degree&other)
{
	using namespace std;
	if(!other.plus_minus)out<<"-";
	out<<other.m_du<<" ";
	cout<<setfill('0')<<setw(2)<<other.m_fen<<" ";
	cout<<setfill('0')<<setw(2)<<other.m_miao<<" ";
	return out;
}
 int Degree::changmiao()
{
	return plus_minus==true?m_du*60*60+m_fen*60+m_miao:-1*(m_du*60*60+m_fen*60+m_miao);
}
double Degree::ChangeRAD()
{
	return plus_minus==true?2*(m_du*60*60+m_fen*60+m_miao)/(360*60*60):-2*(m_du*60*60+m_fen*60+m_miao)/(360*60*60);
}
void Degree::ChangePI(double new_PI)
{
	PI=new_PI;
}