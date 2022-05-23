#include "Console/Console.hpp"
#include "Console/Backend/SFML/SFML.hpp"

void Console::setBackendRender(std::uint32_t width, std::uint32_t height)
{
	renderer = std::move(std::make_unique <SFML>(width, height));
}

void Console::setConsoleModeMain()
{
	consoleRoot = true;
}

Console::Console(const std::uint32_t _width, const std::uint32_t _height) : width(_width), height(_height)
{
	static bool consoleRootCreated = false;

	if (not consoleRootCreated)
	{
		setBackendRender(width, height);
		consoleRootCreated = true;
	}
}

bool Console::isRunning() const noexcept
{
	return renderer->isRunning();
}

void Console::clear() noexcept
{
	renderer->clear();
}

void Console::input() noexcept
{
	renderer->input();
}

void Console::draw() noexcept
{
	renderer->draw();
}

void Console::write(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept
{
	renderer->draw(x, y, _char);
}

void Console::write(std::uint32_t x, std::uint32_t y, const std::string& _char) noexcept
{
	for (const char& glyph: _char)
	{
		renderer->draw(x, y, glyph);
	}

}