#ifndef SFML_CONSOLE_HPP
#define SFML_CONSOLE_HPP

#include <memory>
#include <cstdint>

#include "Console/Backend/IRenderer.hpp"
#include "Console/Backend/SFML/SFML.hpp"

class Console
{

private:

	bool root = false;
	bool running = true;
	std::uint32_t width;
	std::uint32_t height;

	inline static std::unique_ptr <IRenderer> renderer{ nullptr };

	static void setBackendRender();

public:

	Console() : Console(80, 24)
	{
	}

	Console(const std::uint32_t width, const std::uint32_t height);

	// Methods

	void write(std::uint32_t x, std::uint32_t y, std::uint32_t _char);

	bool isRunning() const noexcept
	{
		return running;
	}
};

#endif //SFML_CONSOLE_HPP
