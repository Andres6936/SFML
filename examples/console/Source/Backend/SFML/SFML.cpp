#include "Console/Backend/SFML/SFML.hpp"

SFML::SFML(std::uint32_t width, std::uint32_t height) noexcept: IRenderer(width, height)
{
	const std::uint32_t widthWindow = getWidthCell() * SIZE_FONT_PIXELS;
	const std::uint32_t heightWindow = getHeightCell() * SIZE_FONT_PIXELS;

	window.create(sf::VideoMode(sf::Vector2u(widthWindow, heightWindow)), "Console");
	window.setFramerateLimit(30);

	if (!font.loadFromFile("Resources/Fonts/Square.ttf"))
	{
		// Show Error
	}

}

bool SFML::isRunning() const noexcept
{
	return window.isOpen();
}

void SFML::clear() noexcept
{
	window.clear();
}

void SFML::input() noexcept
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void SFML::draw() noexcept
{
	text.setFont(font);
	text.setString("Roguelike Console with several characters");
	text.setCharacterSize(SIZE_FONT_PIXELS);
	text.setFillColor(sf::Color(255, 94, 14));
	text.setStyle(sf::Text::Bold);

	window.draw(text);
	window.display();
}

void SFML::draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept
{

}
