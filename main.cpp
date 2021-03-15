#include <SFML/Graphics.hpp>
#include <iostream>
#include "Node.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(600, 600), "AStar");

    //Node grid init
    const int GridWidth = 2;
    const int GridHeight = 2;

    Node nodes[GridWidth * GridHeight];

    while (window.isOpen())
    {

        //========== Events Start ==========
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was released" << std::endl;
                }
            }
        }

        //========== Events End ==========

        window.clear();

        //========== Main Loop Start ==========
        window.draw();

        //========== Main Loop End ==========

        window.display();
    }

    return 0;
}