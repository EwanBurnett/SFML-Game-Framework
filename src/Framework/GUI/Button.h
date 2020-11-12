#pragma once
#include "Widget.h"
#include <functional>

namespace UI {
	class Button : public Widget {

	public:
		//Binds the button to a specific function
		void BindFunction(std::function<void(void)> function); 
		void SetText(std::string string);


		// Inherited via Widget
		virtual void Update(sf::Time deltaTime) override;

		virtual void FixedUpdate(float deltaTime) override;

		virtual void Render(sf::RenderWindow& window) override;

		virtual void EventHandler(sf::Event event) override;

		virtual sf::Vector2f SetPosition(sf::Vector2f pos) override;


	private:
		void UpdateText();
		sf::Vector2f m_Position;

		Rect m_Button;
		Text m_Text;
		std::function<void(void)> m_Function = [] () {};

		// Inherited via Widget
		virtual sf::Vector2f GetPosition() override;
	};
}
