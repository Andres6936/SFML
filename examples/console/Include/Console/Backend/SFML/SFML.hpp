
#ifndef SFML_SFML_HPP
#define SFML_SFML_HPP

#include "Console/Backend/IRenderer.hpp"

class SFML : public IRenderer
{

public:

	void draw(std::uint32_t x, std::uint32_t y, std::uint32_t _char) noexcept override
	{

	}
};

#endif //SFML_SFML_HPP
