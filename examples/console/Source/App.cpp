#include "Console/Console.hpp"

int main()
{
	Console console{ 80, 50 };
	while (console.isRunning())
	{
		console.input();
		console.clear();
		console.draw();
	}
}