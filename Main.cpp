#include <Siv3D.hpp>
#include "src/User/User.h"
#include "src/ParentClass/DisplayObject.h"
#include "src/SceneManager/SceneManager.h"

namespace ogm {
	class Hoge : public DisplayObject {
	private:
		Rect view;
	public:
		Hoge() {
			this->setClickableRange(Rect(100, 100, 100, 200));
			view = Rect(100, 100, 100, 200);
		}
		void draw() override {
			view.draw(Palette::Black);
		}
	};
	class Fuga : public DisplayObject {
	private:
		Circle view;
	public:
		Fuga() {
			this->setClickableRange(Circle(150, 150, 100));
			view = Circle(150, 150, 100);
		}
		void draw() override {
			view.draw(Palette::Pink);
		}
	};
}

void Main() {
	ogm::SceneManager::Create();

	ogm::SceneManager& manager = ogm::SceneManager::GetInstance();

	Scene::SetBackground(Palette::White);

	ogm::Hoge hoge{};
	ogm::Fuga fuga{};

	Circle circle{ 300, 300, 100 };

	while (System::Update()) {
		manager.update();
		Console << ogm::User::GetInstance().getObjectID();
	}

	return;
}

