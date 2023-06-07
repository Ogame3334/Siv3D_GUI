#include "DisplayObject.h"
#include "../User/User.h"
#include "../DisplayObjectManager/DisplayObjectManager.h"

namespace ogm {
	DisplayObject::DisplayObject() {
		init();
		DisplayObjectManager::GetInstance() << DO_ptr(this);
	}

	void DisplayObject::inputUpdateInternal() {}
	void DisplayObject::updateInternal() {}
	void DisplayObject::drawInternal() {
		this->draw();
	}
}
