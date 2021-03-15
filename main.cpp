#include <SFML/Graphics.hpp>
#include <iostream>
#include "Node.h"

void drawNodes(sf::RenderWindow window, Node nodes[], int GridWidth, int GridHeight)
{
    for (int x = 0; x < GridWidth; x++)
    {
        for (int y = 0; y < GridHeight; y++)
        {
            int NodeIndex = y * GridWidth + x;
            nodes[NodeIndex].setNodePos((float)x, (float)y);
            window.draw(nodes[NodeIndex].getNodeShape());
        }
    }
}

int main()
{
    unsigned int WindowWidth = 600;
    unsigned int WindowHeight = 600;
    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "AStar");

    //Node grid init
    const int GridWidth = 20;
    const int GridHeight = 20;

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
        
        //drawNodes(window, nodes, GridWidth, GridHeight);

        int NodeIndex = 0;

        for (int x = 0; x < GridWidth; x++)
        {
            for (int y = 0; y < GridHeight; y++)
            {
                NodeIndex = y * GridWidth + x;
                nodes[NodeIndex].setNodePos((float)x * nodes[NodeIndex].NodeSize + (x+1)*nodes[NodeIndex].padding,
                    (float)y * nodes[NodeIndex].NodeSize + (y+1)*nodes[NodeIndex].padding);
                window.draw(nodes[NodeIndex].getNodeShape());
            }
        }

        //========== Main Loop End ==========

        window.display();
    }

    return 0;
}