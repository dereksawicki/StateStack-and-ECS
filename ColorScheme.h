#ifndef COLOR_SCHEME_H
#define COLOR_SCHEME_H

#include <SFML/Graphics/Color.hpp>

#include <map>

class ColorScheme
{
public:
	enum COLOR {
		Primary
	  , Secondary
	  , Detail
	  , Background
	};

	enum SCHEME {
		Light
	  , Dark
	};

public:
	ColorScheme();

	const sf::Color& Color(COLOR color);

	void setScheme(SCHEME scheme);
	SCHEME getScheme() { return mScheme; };

private:
	std::map<COLOR, sf::Color> mColorScheme;
	SCHEME mScheme;
};


#endif