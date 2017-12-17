#ifndef CONTEXT_H
#define CONTEXT_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

/* Context struct holds references to the resource manager and various 'global' systems so that parameter lists are not bloated 
   as the context is passed around */

struct Context
{
	Context(sf::RenderWindow& pwindow, sf::Font& pfont)
	{
		window = &pwindow;
		font = &pfont;
	}

	sf::RenderWindow* window;
	sf::Font* font;
};

#endif