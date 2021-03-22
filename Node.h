#pragma once
#include <SFML/Graphics.hpp>

class Node
{
public:
	Node();

	sf::RectangleShape getNodeShape();

	void setNodePos(float x = 0, float y = 0);

	void setNodeColor(sf::Color NodeColor);

	//Position in 2D
	int x;
	int y;

	//Node size properties
	float NodeSize = 25.0f;
	float padding = 10.0f;

	sf::RectangleShape NodeShape;

	sf::Color NodeColor = sf::Color::Blue;
};