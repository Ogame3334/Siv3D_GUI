#pragma once

namespace ogm {
	class SceneManager {
	private:
		SceneManager() = default;
		~SceneManager() = default;
		inline static SceneManager* Instance = nullptr;

		void init();

	public:
		SceneManager(const SceneManager&) = delete;
		void operator = (const SceneManager&) = delete;
		SceneManager(SceneManager&&) = delete;
		void operator = (SceneManager&&) = delete;

		static SceneManager& GetInstance() {
			return *Instance;
		}

		static void Create() {
			if (!Instance) {
				Instance = new SceneManager;
				Instance->init();
			}
		}

		static void Destroy() {
			delete Instance;
			Instance = nullptr;
		}

		void update();
	};
}
