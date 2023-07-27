#include "barrett.h"
#include<math.h>

BARRETT::BARRETT(){
	pos = {0.0f,0.0f,0.0f};
	angle = 0.0f;
	speed = {5.0f,5.0f,0.0f};
	float	vx=cos(DX_PI/180*angle)*speed.x,
			vy=sin(DX_PI/180*angle)*speed.y;
	vectol = {vx,vy,0.0f};
}
BARRETT::~BARRETT(){

}
void BARRETT::Init(VECTOR _pos,float _angle){
	pos = _pos;
	speed = { 5.0f,5.0f,0.0f };
	angle = _angle;
	float	vx = cos(DX_PI / 180 * angle) * speed.x,
		vy = sin(DX_PI / 180 * angle) * speed.y;
	vectol = { vx,vy,0.0f };
}
void BARRETT::Update(){
	VectorAdd(&pos,&pos,&vectol);

}
void BARRETT::Draw(){
	int size = 5;
	DrawBox(pos.x-size,pos.y-size,pos.x+size,pos.y+size,GetColor(222,222,222),true);
}

void BARRETT::SetAngle(float _angle){
	angle = _angle;
}
