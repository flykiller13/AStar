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

	// Node grid init
	const int GridWidth = 16;
	const int GridHeight = 16;

	// Node indexing variables init
	int NodeIndex = 0;
	int nSelectedNodeX = 0;
	int nSelectedNodeY = 0;
	Node* StartNode = nullptr;
	Node* EndNode = nullptr;

	// Nodes array init
	Node nodes[GridWidth * GridHeight];

	bool bShift = false;
	bool bControl = false;

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
					sf::Vector2f ClickLocation;
					ClickLocation.x = (float)event.mouseButton.x;
					ClickLocation.y = (float)event.mouseButton.y;
					nSelectedNodeX = ClickLocation.x / (nodes[0].NodeSize + nodes[0].padding);
					nSelectedNodeY = ClickLocation.y / (nodes[0].NodeSize + nodes[0].padding);

					std::cout << nSelectedNodeX << " , " << nSelectedNodeY << std::endl;
				}
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was released" << std::endl;
				}
			}

			// Control or Shift pressed. If Control is held, Shift can't be pressed
			if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
			{
				bControl = event.key.control;
				std::cout << "control:" << bControl << std::endl;
				bShift = event.key.shift && !bControl;
				std::cout << "shift:" << bShift << std::endl;
			}
			
		}

		//========== Events End ==========

		window.clear();

		//========== Main Loop Start ==========

		// Draw nodes
		for (int x = 0; x < GridWidth; x++)
		{
			for (int y = 0; y < GridHeight; y++)
			{
				NodeIndex = y * GridWidth + x;
				nodes[NodeIndex].setNodePos((float)x * nodes[NodeIndex].NodeSize + (x + 1) * nodes[NodeIndex].padding,
					(float)y * nodes[NodeIndex].NodeSize + (y + 1) * nodes[NodeIndex].padding);

				// Sets the start node
				if (nSelectedNodeX == x && nSelectedNodeY == y && bControl)
				{
					if (StartNode != nullptr)
						StartNode->setNodeColor(sf::Color::Blue);
					StartNode = &nodes[NodeIndex];
					StartNode->setNodeColor(sf::Color::Yellow);
				}

				// Sets the end node
				if (nSelectedNodeX == x && nSelectedNodeY == y && bShift)
				{
					if (EndNode != nullptr)
						EndNode->setNodeColor(sf::Color::Blue);
					EndNode = &nodes[NodeIndex];
					EndNode->setNodeColor(sf::Color::Green);
				}

				
				window.draw(nodes[NodeIndex].getNodeShape());
			}
		}

		
		//========== Main Loop End ==========

		window.display();
	}

	return 0;
}