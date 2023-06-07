#include "SceneManager.h"
#include "../DisplayObjectManager/DisplayObjectManager.h"
#include "../User/User.h"

namespace ogm {
	void SceneManager::init() {
		DisplayObjectManager::Create();
		User::Create();
	}

	void SceneManager::update() {
		User::GetInstance().setObjectID(-1);
		DisplayObjectManager& displayObjectManager = DisplayObjectManager::GetInstance();
		displayObjectManager.update();
	}
}
