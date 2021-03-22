#include "Node.h"
#include <SFML/Graphics.hpp>

Node::Node()
{
	NodeShape.setSize(sf::Vector2f(NodeSize, NodeSize));
	NodeShape.setFillColor(NodeColor);
	x = 0;
	y = 0;
}

sf::RectangleShape Node::getNodeShape()
{
	return NodeShape;
}

void Node::setNodePos(float x, float y)
{
	NodeShape.setPosition(sf::Vector2f(x, y));
}

void Node::setNodeColor(sf::Color NodeColor)
{
	this->NodeShape.setFillColor(NodeColor);
}
