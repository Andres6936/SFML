#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Console/Backend/SFML/SFML.hpp"

sf::Color getRandomColor()
{
	const std::uint8_t red = rand() % 256;
	const std::uint8_t green = rand() % 256;
	const std::uint8_t blue = rand() % 256;

	return { red, green, blue };
}

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

	buffer.resize(getWidthCell() * getHeightCell());

	// Initialize the buffer
	for (int x = 0; x < getWidthCell(); ++x)
	{
		for (int y = 0; y < getHeightCell(); ++y)
		{
			sf::RectangleShape rect{ };
			rect.setSize({ 16, 16 });
			rect.setFillColor(getRandomColor());
			rect.setPosition({
					static_cast<float>(x * SIZE_FONT_PIXELS),
					static_cast<float>(y * SIZE_FONT_PIXELS)
			});

			buffer.at(y * getWidthCell() + x) = rect;
		}
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
	sf::Event event{ };

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

	const sf::Texture& texture = font.getTexture(16);
	sf::Glyph glyph = font.getGlyph('@', 16, true);
	sf::Sprite image;
	image.setTexture(texture);
	image.setPosition({ 16, 16 });
	image.setColor(sf::Color::Magenta);
	image.setTextureRect(glyph.textureRect);


	for (const sf::RectangleShape& rect: buffer)
	{
		window.draw(rect);
	}

	window.draw(text);
	window.draw(image);
	window.display();
}

void SFML::draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept
{

}
