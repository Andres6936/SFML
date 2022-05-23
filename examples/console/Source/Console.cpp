#include <iostream>

#include "Console/Console.hpp"

void Console::setBackendRender()
{
	renderer = std::move(std::make_unique <SFML>());
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
		setBackendRender();

		consoleRootCreated = true;
	}
}

bool Console::isRunning() const noexcept
{
	return renderer->isRunning();
}

void Console::clear() noexcept
{

}

void Console::input() noexcept
{

}

void Console::draw() noexcept
{

}

void Console::write(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept
{
	renderer->draw(x, y, _char);
}

int main()
{
	Console console{ };
	while (console.isRunning())
	{
		console.clear();
		console.input();
		console.draw();
	}
}