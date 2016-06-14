
#include"pos.h"

 pos pos::operator+(pos &other)
{
	return pos(other.x+x,other.y+y);
}
 std::ostream& operator<<(std::ostream&out,pos&other)
{
	out<<other.x<<" "<<other.y;
	return out;
}