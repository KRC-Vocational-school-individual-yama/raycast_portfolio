#include "player.h"
#include"config.h"
PLAYER::PLAYER(){
	float x=SCREEN_WIDTH/2.0f,
			y=SCREEN_HEIGHT/2.0f;
	pos = {x,y,0.0f};
	mousePos = pos;
	speed = {5.0f,5.0f,5.0f};
	size =20.0f;
	angle = 0.0f;

	img = GetBox();
}
PLAYER::~PLAYER(){

}
void PLAYER::Update(){
	GetMousePos();
	Control();
	Direction();
	pos = mousePos;
	

}
void PLAYER::Draw(){
	DrawRotaGraph2(pos.x,pos.y,size,size,
		1.0f,DX_PI/180*angle,img,true);
	//DrawBox(pos.x-size,pos.y-size,pos.x+size,pos.y+size,GetColor(255,25,160),false);
	//printfDx("%f\n%f\n%f\n%f\n",pos.x,pos.y,mousePos.x,mousePos.y);

}

int PLAYER::GetBox(){
	int handle = MakeScreen(size*2, size*2, true);
	SetDrawScreen(handle);
	DrawBox(size,size-2,size+size,size+2,GetColor(255,25,160),false);
	DrawBox(0,0,size+size,size+size,GetColor(255,25,160),false);
	SetDrawScreen(DX_SCREEN_BACK);
	return handle;
}

void PLAYER::Control(){
	bool up=CheckHitKey(KEY_INPUT_UP)		|| CheckHitKey(KEY_INPUT_W);
	bool down=CheckHitKey(KEY_INPUT_DOWN)	|| CheckHitKey(KEY_INPUT_S);
	bool left=CheckHitKey(KEY_INPUT_LEFT)	|| CheckHitKey(KEY_INPUT_A);
	bool right=CheckHitKey(KEY_INPUT_RIGHT)	|| CheckHitKey(KEY_INPUT_D);
	if (up) {
		pos.y += -speed.y;
	}
	if (down) {
		pos.y += speed.y;
	}
	if (left) {
		pos.x += -speed.x;
	}
	if (right) {
		pos.x += speed.x;
	}
	bool keyall = up || down || left || right;
	if (keyall) {
		SetMousePoint((int)pos.x, (int)pos.y);
	}
}

void PLAYER::GetMousePos(){
	int x=0, 
		y=0;
	GetMousePoint(&x,&y);
	mousePos = { (float)x, (float)y, 0.0f};

}

void PLAYER::Direction(){
	bool left=CheckHitKey(KEY_INPUT_Q) ==1;
	bool right=CheckHitKey(KEY_INPUT_E)==1;
	if (left) {
		angle += -1;
	}
	if (right) {
		angle += 1;
	}
}
