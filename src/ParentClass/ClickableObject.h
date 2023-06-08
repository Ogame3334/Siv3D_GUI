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
		CursorStyle isMouseOverCursorStyle = CursorStyle::Hand;
	public:
		ClickableObject() {
			this->clickableRange = CR();
			this->isClickable = true;
		}

		void setClickableRange(CR range) { this->clickableRange = range; }
		void setCursorStyle(CursorStyle style) { this->isMouseOverCursorStyle = style; }

		void inputUpdateInternal() override{
			if (this->clickableRange.mouseOver())
				this->inputUpdate();
			this->inputUpdate();
		}
		void updateInternal() override {
			if (this->clickableRange.mouseOver()) {
				User::GetInstance().setObjectID(this->getObjectID());
				Cursor::RequestStyle(this->isMouseOverCursorStyle);
			}
			this->update();
		}
	};
}
