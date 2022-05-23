
#ifndef SFML_IRENDERER_HPP
#define SFML_IRENDERER_HPP

#include <cstdint>

class IRenderer
{

protected:

	std::uint32_t widthCell;
	std::uint32_t heightCell;

	inline static std::uint8_t SIZE_FONT_PIXELS = 16;

public:

	IRenderer(std::uint32_t width, std::uint32_t height) : widthCell(width), heightCell(height)
	{
	};

	virtual bool isRunning() const noexcept = 0;

	virtual void clear() noexcept = 0;

	virtual void input() noexcept = 0;

	virtual void draw() noexcept = 0;

	virtual void draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept = 0;

	// Getters

	const std::uint32_t getWidthCell() const noexcept;

	const std::uint32_t getHeightCell() const noexcept;

	// Setters

	void setWidthCell(const std::uint32_t width) noexcept;

	void setHeightCell(const std::uint32_t height) noexcept;
};

#endif //SFML_IRENDERER_HPP
