#include "Node.h"
#include <SFML/Graphics.hpp>

Node::Node()
{
	x = 0;
	y = 0;
}

sf::RectangleShape Node::getNodeShape()
{
	sf::RectangleShape rectangle(sf::Vector2f(x + NodeSize, y + NodeSize));
	rectangle.setFillColor(NodeColor);
	return rectangle;
}
