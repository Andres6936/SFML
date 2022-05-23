
#ifndef SFML_SFML_HPP
#define SFML_SFML_HPP

#include <cstdint>

#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Console/Backend/IRenderer.hpp"

class SFML : public IRenderer
{

private:

	bool running = true;

	sf::Text text;
	sf::Font font;
	sf::RenderWindow window;

public:

	SFML();

	bool isRunning() const noexcept override;

	void clear() noexcept override;

	void input() noexcept override;

	void draw() noexcept override;

	void draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept override;
};

#endif //SFML_SFML_HPP
