#include "DxLib.h"
#include "src\gameapplication\GameAppliacation.h"

//=====================================
//���C��
//=====================================

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){

	CGameAppliacation &app = CGameAppliacation::GetInstance();
	while (ProcessMessage() == 0){
		app.Update();
	}
	return 0;
}