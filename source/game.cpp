#include"game.h"
#include"config.h"
#include<math.h>

GAME::GAME(){
	player = new PLAYER();
	walls = new LEVEL[WALLMAX];
	collider = new COLLISION();
	barrett = new BARRETT();
	barretts = new BARRETT[MAXRAY];

	line = {};

	walls[0].SetPos({200.0,300.0,0.0f});
	walls[1].SetPos({0.0f,0.0f,0.0f});
	walls[2].SetPos({800.0f,400.0f,0.0f});
	walls[3].SetPos({600.0f,150.0f,0.0f});
	walls[4].SetPos({100.0f,400.0f,0.0f});
	walls[5].SetPos({600.0f,300.0f,0.0f});
}
GAME::~GAME(){
	delete player;
	delete[] walls;
	delete collider;
	delete barrett;
	delete[] barretts;
}
void GAME::Init(){

}
void GAME::Delete(){

}
void GAME::Raycast(BARRETT* barrett){
	VECTOR bp = barrett->GetPos();
	bool up = bp.y < 0;
	bool down = bp.y > SCREEN_HEIGHT;
	bool left = bp.x < 0;
	bool right = bp.x > SCREEN_WIDTH;
	if (!(up || down || left || right)) {//‰æ–ÊŠO‚És‚©‚È‚¢

		while (
			!(collider->Collision(walls[0].GetPos(), walls[0].GetSize(), barrett->GetPos(), 5))&&
			!(collider->Collision(walls[1].GetPos(), walls[1].GetSize(), barrett->GetPos(), 5))&&
			!(collider->Collision(walls[2].GetPos(), walls[2].GetSize(), barrett->GetPos(), 5))&&
			!(collider->Collision(walls[3].GetPos(), walls[3].GetSize(), barrett->GetPos(), 5))&&
			!(collider->Collision(walls[4].GetPos(), walls[4].GetSize(), barrett->GetPos(), 5))&&
			!(collider->Collision(walls[5].GetPos(), walls[5].GetSize(), barrett->GetPos(), 5))
			) {
			barrett->Update();

			VECTOR bp = barrett->GetPos();
			bool up = bp.y < 0;
			bool down = bp.y > SCREEN_HEIGHT;
			bool left = bp.x < 0;
			bool right = bp.x > SCREEN_WIDTH;
			if (up || down || left || right) break;
		}
	}
	//return barrett->GetPos();
}
void GAME::No3D(){
	int cr = GetColor(0, 0, 0);
	int wallline = 20;

	line.x = SCREEN_WIDTH / 2.0f;
	line.y = SCREEN_HEIGHT / 2.0f;
	float ss = 4000 / line.z;
	DrawLine(line.x, line.y - ss,
		line.x, line.y + ss, cr, wallline);
	//‰E”¼•ª
	for (int i = 0; i < MAXRAY / 2; i++) {
		lines[i].x = SCREEN_WIDTH / 2.0f + i * 20;
		lines[i].y = SCREEN_HEIGHT / 2.0f;
		float ss = 4000 / lines[i].z;
		DrawLine(lines[i].x, lines[i].y - ss,
			lines[i].x, lines[i].y + ss, cr, wallline);
	}
	//¶”¼•ª
	for (int i = 0; i < MAXRAY / 2; i++) {
		int j = i + MAXRAY / 2;
		lines[j].x = SCREEN_WIDTH / 2.0f - i * 20;
		lines[j].y = SCREEN_HEIGHT / 2.0f;
		float ss = 4000 / lines[j].z;
		DrawLine(lines[j].x, lines[j].y - ss,
			lines[j].x, lines[j].y + ss, cr, wallline);
	}
}
void GAME::Update(){
	player->Update();
	for (int wall = 0; wall < WALLMAX; wall++) {
		walls[wall].Update();
	}

	for (int wall=0; wall < WALLMAX; wall++) {

		barrett->Init(player->GetPos(), player->GetAngle());//í‚ÉŒvZ‚µ’¼‚·
		Raycast(barrett);//ü‚ğL‚Î‚·
		//‰E”¼•ª
		for (int i = 0; i < MAXRAY / 2; i++) {
			barretts[i].Init(player->GetPos(), player->GetAngle() + i * 5);//í‚ÉŒvZ‚µ’¼‚·
			Raycast(&barretts[i]);//ü‚ğL‚Î‚·
		}
		//¶”¼•ª
		for (int i = 0; i < MAXRAY / 2; i++) {
			int j = i + MAXRAY / 2;
			barretts[j].Init(player->GetPos(), player->GetAngle() + i * -5);//í‚ÉŒvZ‚µ’¼‚·
			Raycast(&barretts[j]);//ü‚ğL‚Î‚·
		}
	}


	//debug|| down || left || right)break;
	bool key = CheckHitKey(KEY_INPUT_R);
	if (key) {
		barrett->Init(player->GetPos(),player->GetAngle());
	}
	


	//Raycast‚Ì‹——£ distance line.z
	VECTOR _p = player->GetPos();
	VECTOR _b = barrett->GetPos();
	VectorSub(&line,&_p,&_b);
	line.z = sqrt(line.x*line.x+line.y*line.y);

	VECTOR* _bs = new VECTOR[MAXRAY]();
	for (int i = 0; i < MAXRAY; i++) {
		_bs[i] = barretts[i].GetPos();
		VectorSub(&lines[i],&_p,&_bs[i]);
		lines[i].z = sqrt(lines[i].x*lines[i].x+lines[i].y*lines[i].y);
	}
	delete[] _bs;
}
void GAME::Draw(){
	//”wŒi
	VECTOR backimg = {SCREEN_WIDTH,SCREEN_HEIGHT,0};
	DrawBox(0,0,backimg.x,backimg.y/2,GetColor(160,160,255),true);
	DrawBox(0, backimg.y / 2,backimg.x,backimg.y,GetColor(255,162,25),true);
	
	//‹^—3D•`‰æ
	No3D();


	int raylinesize = 2;
	//Raycast‚Ìü
	DrawLine(player->GetPos().x,player->GetPos().y,barrett->GetPos().x,barrett->GetPos().y,GetColor(150,150,150), raylinesize);
	//‰E”¼•ª
	for (int i = 0; i < MAXRAY/2; i++) {
		DrawLine(player->GetPos().x, player->GetPos().y, barretts[i].GetPos().x, barretts[i].GetPos().y, GetColor(150, 150, 150), raylinesize);
	}
	//¶”¼•ª
	for (int i = 0; i < MAXRAY/2; i++) {
		int j = i + MAXRAY/2;
		DrawLine(player->GetPos().x, player->GetPos().y, barretts[j].GetPos().x, barretts[j].GetPos().y, GetColor(150, 150, 150), raylinesize);
	}


	player->Draw();
	for (int i = 0; i < WALLMAX; i++) {
	walls[i].Draw();
	}
	barrett->Draw();
	for (int i = 0; i < MAXRAY; i++) {
		barretts[i].Draw();
	}
	
}
