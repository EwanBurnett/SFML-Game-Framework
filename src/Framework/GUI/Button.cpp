#include "Button.h"

void UI::Button::BindFunction(std::function<void(void)> function)
{
    m_Function = std::bind(function); //Binds the parameter function to the button's function.
}

void UI::Button::SetText(std::string string)
{
}

void UI::Button::Update(sf::Time deltaTime)
{
}

void UI::Button::FixedUpdate(float deltaTime)
{
}

void UI::Button::Render(sf::RenderWindow& window)
{
}

void UI::Button::EventHandler(sf::Event event)
{
}

sf::Vector2f UI::Button::SetPosition(sf::Vector2f pos)
{
    return sf::Vector2f();
}

sf::Vector2f UI::Button::GetPosition()
{
    return sf::Vector2f();
}
