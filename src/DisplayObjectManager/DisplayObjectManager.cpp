#include "DisplayObjectManager.h"

namespace ogm {
	void DisplayObjectManager::update() {
		for (auto displayObject : this->displayObjects) {
			displayObject->inputUpdateInternal();
		}
		for (auto displayObject : this->displayObjects) {
			displayObject->updateInternal();
		}
		for (auto displayObject : this->displayObjects) {
			displayObject->drawInternal();
		}
		//Console << this->displayObjects.size();
	}
}
