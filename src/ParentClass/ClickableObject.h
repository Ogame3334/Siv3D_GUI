#pragma once

#include "DisplayObject.h"
#include "../User/User.h"

namespace ogm {
	template<typename T>
	concept ClickableRange = requires(T& t) {
		t.mouseOver();
	};
	template<ClickableRange CR>
	class ClickableObject : public DisplayObject {
	private:
		CR clickableRange;
		bool isClickable;
	public:
		void setClickableRange(CR range) { this->clickableRange = range; }

		void inputUpdateInternal() override{
			if (this->clickableRange.mouseOver())
				this->inputUpdate();
			this->inputUpdate();
		}
		void updateInternal() override {
			if (this->clickableRange.mouseOver())
				User::GetInstance().setObjectID(this->getObjectID());
			this->update();
		}
	};
}
