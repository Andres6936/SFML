#include "Console/Backend/IRenderer.hpp"

// Getters

const std::uint32_t IRenderer::getWidthCell() const noexcept
{
	return widthCell;
}

const std::uint32_t IRenderer::getHeightCell() const noexcept
{
	return heightCell;
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
