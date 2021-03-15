#pragma once
#include <SFML/Graphics.hpp>

class Node
{
    public:
        Node();

        sf::RectangleShape getNodeShape();
        //Position in 2D
        int x;
        int y;

        //Node size
        int NodeSize = 50;

        sf::Color NodeColor = sf::Color::Blue;
};