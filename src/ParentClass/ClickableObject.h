#pragma once

#include "DisplayObject.h"

namespace ogm {
	template<typename T>
	concept ClickableRange = requires(T& t) {
		t.mouseOver();
	};
	class ClickableObject : DisplayObject {
	private:
		bool isClickable;
		bool mouseOver() override;
	};
}
