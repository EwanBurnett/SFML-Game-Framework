#pragma once
#include "Widget.h"

namespace UI {

	class TextBox : public Widget {

	public:

		// Inherited via Widget
		virtual void Update(sf::Time deltaTime) override;

		virtual void FixedUpdate(float deltaTime) override;

		virtual void Render(sf::RenderWindow& window) override;

		virtual void EventHandler(sf::Event event) override;

		virtual sf::Vector2f SetPosition(sf::Vector2f  pos) override;

		virtual sf::Vector2f GetPosition() override;

		/*Sets the text to a specified value of type sf::String.
		Leave arguments blank to clear the text.
		*/
		void SetText(sf::String text = " ");
		


	private:
		Rect m_TextBox;
		Text m_Text;

		sf::String m_TextCache;

	

	};

}
