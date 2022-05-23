
#ifndef SFML_IRENDERER_HPP
#define SFML_IRENDERER_HPP

class IRenderer
{

public:

	virtual bool isRunning() const noexcept = 0;

	virtual void input() noexcept = 0;

	virtual void draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept = 0;
};

#endif //SFML_IRENDERER_HPP
