#include "Console/Backend/SFML/SFML.hpp"

SFML::SFML() : IRenderer()
{
	window.create(sf::VideoMode(sf::Vector2u(800, 600)), "Console");
}

bool SFML::isRunning() const noexcept
{
	return running;
}

void SFML::input() noexcept
{

}

void SFML::draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept
{

}
