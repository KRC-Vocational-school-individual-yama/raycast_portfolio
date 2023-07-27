#pragma once
#include"game.h"

class OBJECT {
public:
	OBJECT();
	~OBJECT();
void Init()	 ;
void Update();
void Draw()	 ;
void Delete();
private:
	GAME* game;
};