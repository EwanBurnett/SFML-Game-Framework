#pragma once
#include <SFML/Graphics.hpp>
#include "../ResourceManager.h"

namespace UI
{

	class Widget
	{
	public:
		
		/* Update is called once per frame. */
		virtual void Update(sf::Time deltaTime) = 0; // <-- Called once per frame

		/* FixedUpdate is called once per tick. */
		virtual void FixedUpdate(float deltaTime) = 0; // <-- Called once per tick

		/* Render is called once per frame.
		Draws the widget to the window.*/
		virtual void Render(sf::RenderWindow& window) = 0; //Draws the widget to the window.

		/* EventHandler is called once per frame, at the event polling stage.
		Allows for custom event polling for the widget. */
		virtual void EventHandler(sf::Event event) = 0; //Deals with any events.

		/* SetPosition allows for the widget's position on the screen to be changed, from the widget's origin position. */
		virtual sf::Vector2f SetPosition(sf::Vector2f pos) = 0; //Sets the origin position of the widget.

		virtual sf::Vector2f GetPosition() = 0;

		//A wrapper for sf::Text.
		class Text : public sf::Text {
			public:
				Text();
		};

		//A wrapper for sf::RectangleShape.
		class Rect : public sf::RectangleShape {
			public:
				
				void OnSelect(sf::RenderWindow& window); // <-- Called when the widget is selected - either by a cursor or the mouse
				void OnDeselect(sf::RenderWindow& window); // <-- Called when the widget is deselected.

				bool bIsSelected;
		};

	protected:
		sf::Vector2f m_Position;

	};
}