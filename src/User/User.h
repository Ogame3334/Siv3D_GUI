#pragma once

#include <Siv3D.hpp>

namespace ogm {
	class User {
	private:
		User() = default;
		~User() = default;
		inline static User* Instance = nullptr;

		int mouseOverObjectID;

		void init() {
			this->mouseOverObjectID = -1;
		}
	public:
		User(const User&) = delete;
		void operator = (const User&) = delete;
		User(User&&) = delete;
		void operator = (User&&) = delete;

		void setObjectID(int id) {
			if (id < 0) this->mouseOverObjectID = -1;
			else		this->mouseOverObjectID = id;
		}
		int getObjectID() {
			return this->mouseOverObjectID;
		}

		static User& GetInstance() {
			return *Instance;
		}

		static void Create() {
			if (!Instance) {
				Instance = new User;
				Instance->init();
			}
		}

		static void Destroy() {
			delete Instance;
			Instance = nullptr;
		}
	};
}
