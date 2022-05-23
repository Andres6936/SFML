#include <iostream>
#include "Console/Console.hpp"

Console::Console(const std::uint32_t _width, const std::uint32_t _height) : width(_width), height(_height)
{
	static bool consoleRootCreated = false;

	if (not consoleRootCreated)
	{
		setBackendRender();

		consoleRootCreated = true;
	}
}

void Console::setBackendRender()
{
	renderer = std::move(std::make_unique <SFML>());
}

void Console::write(std::uint32_t x, std::uint32_t y, std::uint32_t _char)
{
	renderer->draw(x, y, _char);
}

int main()
{
	Console console{ };
	std::cout << "Hi";
}