
#ifndef SFML_SFML_HPP
#define SFML_SFML_HPP

#include <cstdint>

#include <SFML/Window.hpp>
#include "Console/Backend/IRenderer.hpp"

class SFML : public IRenderer
{

private:

	bool running = true;

	sf::Window window;

public:

	SFML();

	bool isRunning() const noexcept override;

	void input() noexcept override;

	void draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept override;
};

#endif //SFML_SFML_HPP
