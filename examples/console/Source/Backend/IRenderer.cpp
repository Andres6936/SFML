#include "Console/Backend/IRenderer.hpp"

// Getters

std::uint32_t IRenderer::getWidthCell() const noexcept
{
	return width;
}

std::uint32_t IRenderer::getHeightCell() const noexcept
{
	return height;
}

// Setters

void IRenderer::setWidthCell(const std::uint32_t width) noexcept
{
	widthCell = width;
}

void IRenderer::setHeightCell(const std::uint32_t height) noexcept
{
	heightCell = height;
}
