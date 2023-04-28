#pragma once
#include"player.h"
#include"level.h"
#include"collision.h"
#include"barrett.h"


class GAME {
public:
	GAME();
	~GAME();
void Init()	 ;
void Update();
void Draw()	 ;
void Delete();
private:
	void Raycast(BARRETT* barrett);
	void No3D();
	static const int MAXRAY= 20;
	static const int WALLMAX= 6;
	LEVEL* walls;
	PLAYER* player;
	COLLISION* collider;
	BARRETT* barrett;
	BARRETT* barretts;
	VECTOR line;
	VECTOR lines[MAXRAY];
};