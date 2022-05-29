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
	bufferChar.resize(getWidthCell() * getHeightCell());

	// Initialize the buffer
	for (int x = 0; x < getWidthCell(); ++x)
	{
		for (int y = 0; y < getHeightCell(); ++y)
		{
			sf::RectangleShape rect{ };
			rect.setSize({ static_cast<float>(SIZE_FONT_PIXELS), static_cast<float>(SIZE_FONT_PIXELS) });
			rect.setFillColor(getRandomColor());
			rect.setPosition({
					static_cast<float>(x * SIZE_FONT_PIXELS),
					static_cast<float>(y * SIZE_FONT_PIXELS)
			});

			buffer.at(y * getWidthCell() + x) = rect;
			bufferChar.at(y * getWidthCell() + x) = ' ';
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
	for (const sf::RectangleShape& rect: buffer)
	{
		window.draw(rect);
	}

	const sf::Texture& texture = font.getTexture(SIZE_FONT_PIXELS);
	for (int index = 0; index < bufferChar.size(); ++index)
	{
		sf::Glyph glyph = font.getGlyph(bufferChar.at(index), SIZE_FONT_PIXELS, true);
		sf::Sprite image{ texture };
		image.setTextureRect(glyph.textureRect);

		sf::Vector2f relativePosition = getRelativeVectorByIndex(index);
		// These calculations are exclusively to improve the positioning of
		// the characters in the console, with this we center the character
		// both vertically and horizontally.

		// The offset in the x-axis in pixels.
		const std::uint32_t offsetX = (SIZE_FONT_PIXELS - glyph.textureRect.width) / 2;
		// The offset in the y-axis in pixels.
		const std::uint32_t offsetY = (SIZE_FONT_PIXELS - glyph.textureRect.height) / 2;
		// Center the character  in its respective cell, It is to visually
		// improve the layout of the character
		relativePosition.x += static_cast<float>(offsetX);
		relativePosition.y += static_cast<float>(offsetY);

		image.setPosition(relativePosition);
		window.draw(image);
	}

	window.display();
}

void SFML::draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept
{
	bufferChar.at(y * getWidthCell() + x) = _char;
}

// Private Methods

sf::Vector2f SFML::getRelativeVectorByIndex(const std::uint32_t index) const noexcept
{
	const std::uint32_t x = (index % getWidthCell());
	const std::uint32_t y = (index / getWidthCell());

	return { static_cast<float>(x * SIZE_FONT_PIXELS), static_cast<float>(y * SIZE_FONT_PIXELS) };
}