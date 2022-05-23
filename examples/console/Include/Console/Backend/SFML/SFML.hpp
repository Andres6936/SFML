
#ifndef SFML_SFML_HPP
#define SFML_SFML_HPP

#include <cstdint>

#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Console/Backend/IRenderer.hpp"

/**
 * This clear/draw/display cycle is the only good way to draw things. Don't try
 * other strategies, such as keeping pixels from the previous frame, "erasing"
 * pixels, or drawing once and calling display multiple times. You'll get
 * strange results due to double-buffering.
 *
 * Modern graphics hardware and APIs are really made for repeated
 * clear/draw/display cycles where everything is completely refreshed at each
 * iteration of the main loop. Don't be scared to draw 1000 sprites 60 times
 * per second, you're far below the millions of triangles that your computer
 * can handle.
 */
class SFML : public IRenderer
{

private:

	bool running = true;

	sf::Text text;
	sf::Font font;

	/**
	 * To draw the entities provided by the graphics module, you must use a
	 * specialized window class: sf::RenderWindow. This class is derived from
	 * sf::Window, and inherits all its functions. Everything that you've
	 * learnt about sf::Window (creation, event handling, controlling the
	 * framerate, mixing with OpenGL, etc.) is applicable to sf::RenderWindow
	 * as well.
	 */
	sf::RenderWindow window;

public:

	SFML(std::uint32_t width, std::uint32_t height) noexcept;

	bool isRunning() const noexcept override;

	/**
	 * Calling clear before drawing anything is mandatory, otherwise the
	 * contents from previous frames will be present behind anything you
	 * draw. The only exception is when you cover the entire window with
	 * what you draw, so that no pixel is not drawn to. In this case you
	 * can avoid calling clear (although it won't have a noticeable impact
	 * on performance).
	 */
	void clear() noexcept override;

	void input() noexcept override;

	/**
	 * Calling display is also mandatory, it takes what was drawn since
	 * the last call to display and displays it on the window. Indeed,
	 * things are not drawn directly to the window, but to a hidden buffer.
	 * This buffer is then copied to the window when you call display
	 * -- this is called double-buffering.
	 */
	void draw() noexcept override;

	void draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept override;
};

#endif //SFML_SFML_HPP
