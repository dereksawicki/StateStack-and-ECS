#ifndef CONTEXT_H
#define CONTEXT_H

#include "Input.h"
#include "ControlScheme.h"
#include "ColorScheme.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

/* Context struct holds references to the resource manager and various 'global' systems so that parameter lists are not bloated 
   as the context is passed around */

struct Context
{
	Context(sf::RenderWindow& pwindow, sf::Font& pfont, Input& inp, ControlScheme& ctrlScheme, ColorScheme& clrScheme)
	{
		window = &pwindow;
		font = &pfont;
		input = &inp;
		controlScheme = &ctrlScheme;
		colorScheme = &clrScheme;
	}

	sf::RenderWindow* window;
	sf::Font* font;
	Input* input;
	ControlScheme* controlScheme;
	ColorScheme* colorScheme;

};

#endif