#include "Console/Console.hpp"

int main()
{
	Console console{ 80, 50 };
	while (console.isRunning())
	{
		console.input();
		console.clear();

		console.write(0, 0, "Roguelike Console with several characters");

		console.draw();
	}
}