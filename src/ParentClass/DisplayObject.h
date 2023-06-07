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

	public:
		DisplayObject();
		virtual void inputUpdateInternal();
		virtual void updateInternal();
		virtual void drawInternal();

		virtual void inputUpdate() {};
		virtual void update() {};
		virtual void draw() {};

		int getObjectID() const { return this->objectID; }
	};
}
