#pragma once
#include <Siv3D.hpp>

namespace ogm {
	class DisplayObjectManager;

	class DisplayObject {
	using DO_ptr = std::shared_ptr<DisplayObject>;
	private:
		inline static int CommonObjectID = 0;
		int objectID;

		void init() {
			this->objectID = CommonObjectID++;
		}

	protected:
		bool mouseOver();

	public:
		DisplayObject();
		void inputUpdateInternal();
		void updateInternal();
		void drawInternal();

		virtual void inputUpdate() {};
		virtual void update() {};
		virtual void draw() {};
	};
}
