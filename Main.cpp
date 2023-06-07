#include <Siv3D.hpp>
#include "src/User/User.h"
#include "src/ParentClass/ClickableObject.h"
#include "src/SceneManager/SceneManager.h"

namespace ogm {
	class Hoge : public ClickableObject<Rect> {
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
	class Fuga : public ClickableObject<Circle> {
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
	class Piyo : public ClickableObject<Polygon> {
	private:
		const Polygon view
		{
			Vec2{ 400, 100 }, Vec2{ 600, 300 }, Vec2{ 500, 500 }, Vec2{ 400, 400 }, Vec2{ 300, 500 }, Vec2{ 200, 300 }
		};
	public:
		Piyo() {
			this->setClickableRange(view);
		}
		void draw() override {
			view.draw(Palette::Skyblue);
		}
	};
}

void Main() {
	ogm::SceneManager::Create();

	ogm::SceneManager& manager = ogm::SceneManager::GetInstance();

	Scene::SetBackground(Palette::White);

	ogm::Hoge hoge{};
	ogm::Fuga fuga{};
	ogm::Piyo piyo{};

	while (System::Update()) {
		manager.update();
		Console << ogm::User::GetInstance().getObjectID();
	}

	return;
}

