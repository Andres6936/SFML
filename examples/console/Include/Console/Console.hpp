#ifndef SFML_CONSOLE_HPP
#define SFML_CONSOLE_HPP

#include <memory>
#include <cstdint>

#include "Console/Backend/IRenderer.hpp"

class Console
{

private:

	bool consoleRoot = false;
	bool running = true;
	std::uint32_t width;
	std::uint32_t height;

	inline static std::unique_ptr <IRenderer> renderer{ nullptr };

	static void setBackendRender(std::uint32_t width, std::uint32_t height);

	void setConsoleModeMain();

public:

	Console() : Console(80, 24)
	{
	}

	Console(const std::uint32_t width, const std::uint32_t height);

	// Methods

	bool isRunning() const noexcept;

	void clear() noexcept;

	void input() noexcept;

	void draw() noexcept;

	void write(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept;
};

#endif //SFML_CONSOLE_HPP
