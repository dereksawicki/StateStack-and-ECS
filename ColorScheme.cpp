#include "ColorScheme.h"

ColorScheme::ColorScheme()
{
	setScheme(ColorScheme::SCHEME::Light);
}

const sf::Color& ColorScheme::Color(ColorScheme::COLOR color)
{
	return mColorScheme[color];
}

void ColorScheme::setScheme(ColorScheme::SCHEME scheme)
{
	switch (scheme) {
	case ColorScheme::SCHEME::Light:
		mColorScheme[ColorScheme::COLOR::Primary] = sf::Color::Black;
		mColorScheme[ColorScheme::COLOR::Background] = sf::Color::White;
		mColorScheme[ColorScheme::COLOR::Secondary] = sf::Color::Green;
		mScheme = ColorScheme::SCHEME::Light;
		break;
	case ColorScheme::SCHEME::Dark:
		mColorScheme[ColorScheme::COLOR::Primary] = sf::Color::White;
		mColorScheme[ColorScheme::COLOR::Background] = sf::Color::Black;
		mColorScheme[ColorScheme::COLOR::Secondary] = sf::Color::Red;
		mScheme = ColorScheme::SCHEME::Dark;
		break;
	}
}