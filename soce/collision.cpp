#include "collision.h"

COLLISION::COLLISION(){

}
COLLISION::~COLLISION(){
}

bool COLLISION::Collision(VECTOR _pos1, float size1, VECTOR _pos2, float size2){
	bool	left	=_pos1.x-size1<=_pos2.x+size2,
			right	=_pos1.x+size1>=_pos2.x-size2,
			up		=_pos1.y-size1<=_pos2.y+size2,
			down	=_pos1.y+size1>=_pos2.y-size2;
	bool collision = left && right&& up&& down;

	return collision;
}

