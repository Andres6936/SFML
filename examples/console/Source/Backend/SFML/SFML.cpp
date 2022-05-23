#include "Console/Backend/SFML/SFML.hpp"

SFML::SFML() : IRenderer()
{
	window.create(sf::VideoMode(sf::Vector2u(800, 600)), "Console");
	window.setFramerateLimit(30);
}

bool SFML::isRunning() const noexcept
{
	return window.isOpen();
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

void SFML::draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept
{

}
