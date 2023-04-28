#include"object.h"


OBJECT::OBJECT(){
	game = new GAME();
}
OBJECT::~OBJECT(){
	delete game;
}

void OBJECT::Init(){
	game->Init();
}
void OBJECT::Update(){
	game->Update();
}
void OBJECT::Draw(){
	game->Draw();
}
void OBJECT::Delete(){
	game->Delete();
}
