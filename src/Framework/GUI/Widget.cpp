#include "Widget.h"

UI::Widget::Text::Text()
{
	//Sets defaults for Text.

	setCharacterSize(12);
	setOutlineColor(sf::Color::Black);
	setFillColor(sf::Color::White);
	setFont(ResourceManager::GetFont("resources/Fonts/Font_Test.ttf")); // Change to project default font
}


void UI::Widget::Rect::OnSelect(sf::RenderWindow& window)
{
	//TODO: Cursor support
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	bIsSelected = getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y); // Returns whether the mouse is within the rect or not

}

void UI::Widget::Rect::OnDeselect(sf::RenderWindow& window)
{

}
