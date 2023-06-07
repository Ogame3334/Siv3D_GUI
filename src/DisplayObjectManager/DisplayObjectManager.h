#pragma once

#include <Siv3D.hpp>
#include "../ParentClass/DisplayObject.h"

namespace ogm {
	class DisplayObject;
	using DO_ptr = std::shared_ptr<DisplayObject>;
	class DisplayObjectManager {
	private:
		DisplayObjectManager() = default;
		~DisplayObjectManager() = default;
		inline static DisplayObjectManager* Instance = nullptr;

		Array<DO_ptr> displayObjects;
		void init() {
			
		}

	public:
		DisplayObjectManager(const DisplayObjectManager&) = delete;
		void operator = (const DisplayObjectManager&) = delete;
		DisplayObjectManager(DisplayObjectManager&&) = delete;
		void operator = (DisplayObjectManager&&) = delete;

		static DisplayObjectManager& GetInstance() {
			return *Instance;
		}

		static void Create() {
			if (!Instance) {
				Instance = new DisplayObjectManager;
				Instance->init();
			}
		}

		static void Destroy() {
			delete Instance;
			Instance = nullptr;
		}

		void operator << (DO_ptr obj_ptr) {
			this->displayObjects << obj_ptr;
		}

		void update();
	};
}
