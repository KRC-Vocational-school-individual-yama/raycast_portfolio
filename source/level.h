#pragma once
#include<DxLib.h>

class LEVEL {
public:
	LEVEL();
	~LEVEL();
	void Update();
	void Draw();
	VECTOR GetPos();
	void SetPos(VECTOR _pos) {pos=_pos;}
	float GetSize() { return size; }
private:
	VECTOR pos;
	float size;
};