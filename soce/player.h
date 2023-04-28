#pragma once
#include<DxLib.h>
class PLAYER {
public:
	PLAYER();
	~PLAYER();
	void Update();
	void Draw();
	VECTOR GetPos() { return pos; }
	float GetAngle() { return angle; }
private:
	int GetBox();
	void Control();
	void GetMousePos();
	void Direction();

	VECTOR pos;
	float size;
	VECTOR mousePos;

	int img;
	VECTOR speed;
	float angle;
};