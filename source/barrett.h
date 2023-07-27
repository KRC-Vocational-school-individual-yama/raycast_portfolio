#pragma once
#include<Dxlib.h>

class BARRETT {
public:
	BARRETT();
	~BARRETT();
	void Init(VECTOR _pos,float _angle);
	void Update();
	void Draw();
	void SetAngle(float _angle);
	float GetAngle(){return angle;}
	VECTOR GetPos() { return pos; }

private:
	VECTOR pos;
	VECTOR vectol;
	VECTOR speed;
	float angle;
};