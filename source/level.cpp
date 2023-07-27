#include "level.h"

LEVEL::LEVEL(){
	pos = {200.0,300.0,0.0f};
	size = 50.0f;
}

LEVEL::~LEVEL(){
}

void LEVEL::Update(){

}

void LEVEL::Draw(){
	float	x1=pos.x-(float)size,
			y1=pos.y-(float)size,
			x2=pos.x+(float)size,
			y2=pos.y+(float)size;
	DrawBox(x1,y1,x2,y2,GetColor(25,25,199),true);
}

VECTOR LEVEL::GetPos(){
	return pos;
}
