#include "gameapplication\GameApplication.h"

int main() {
	CGameApplication *app = CGameApplication::GetInstance();

	while (app->m_app_env->isOpen() && !app->m_app_env->isPushKey(GLFW_KEY_ESCAPE)) {
		app->Update();
	}
}
