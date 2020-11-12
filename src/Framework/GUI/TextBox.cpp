#include "TextBox.h"


void UI::TextBox::Update(sf::Time deltaTime)
{
    m_TextBox.setPosition(m_Position);
    m_Text.setPosition(m_Position);

    m_TextBox.setSize(sf::Vector2f(m_Text.getLocalBounds().width, m_Text.getLocalBounds().height));
    m_TextBox.setFillColor(sf::Color::Blue);
}

void UI::TextBox::FixedUpdate(float deltaTime)
{
}

void UI::TextBox::Render(sf::RenderWindow& window)
{
    window.draw(m_TextBox);
    window.draw(m_Text);
}

void UI::TextBox::EventHandler(sf::Event event)
{
    switch (event.type) {
    case(sf::Event::TextEntered):
        SetText(event.text.unicode);
    }
}

sf::Vector2f UI::TextBox::SetPosition(sf::Vector2f pos)
{
    m_Position = pos;
    return sf::Vector2f();
}


void UI::TextBox::SetText(sf::String text)
{
    // If the input is valid...
    if (text != " ") {
        m_TextCache += text;
        m_Text.setString(m_TextCache); // <-- Set the text to the cache value
    }
    else {
        m_TextCache.clear();
        m_Text.setString(" "); // <-- Else, clear the text.
    }
}

sf::Vector2f UI::TextBox::GetPosition()
{

    return m_Position;
}
