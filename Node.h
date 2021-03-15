#pragma once
#include <SFML/Graphics.hpp>

class Node
{
    public:
        Node();

        sf::RectangleShape getNodeShape();

        void setNodePos(float x = 0, float y = 0);


        //Position in 2D
        int x;
        int y;

        //Node size properties
        float NodeSize = 25.0f;
        float padding = 5.0f;

        sf::RectangleShape NodeShape;

        

        sf::Color NodeColor = sf::Color::Blue;
};