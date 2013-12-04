#include "stdafx.h"
//#include <SFML/System.hpp>
//#include <SFML/Graphics.hpp>

#include "MapManager.h"
#include "SpriteManager.h"
#include <iostream>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 
 
#include "SFML/Graphics.hpp" 
#include <map>
#include <Windows.h>


using namespace std;

// Sample program to demonstrate basic usage of SFML library. Can also be used as a starting
//  point for the spatial hashing assignment.


int main() {
	//
	// Make an instance of our sprite manager.
	CustomSprite::init("chromatic_circle.png");
	SpriteManager spriteManager;
	spriteManager = SpriteManager();
	map<int, string> mapTest;
	int updateCounter = 0;
	//system("PAUSE");
	//
	

	MapManager mapman;
	int numOfLineArrayVerts = 0;
	 
	sf::RenderWindow window(sf::VideoMode(DemoConstants::SCREEN_WIDTH, DemoConstants::SCREEN_HEIGHT), "SFML Window");

	// Define a single line.
	sf::Vertex line[DemoConstants::ROWS * 4];
	for(int i = DemoConstants::CELLSIZE; i < DemoConstants::SCREEN_WIDTH; i += DemoConstants::CELLSIZE){                                                              
		line[numOfLineArrayVerts] = sf::Vertex(sf::Vector2f(i, 0));
		numOfLineArrayVerts++;
		line[numOfLineArrayVerts] = sf::Vertex(sf::Vector2f(i, DemoConstants::SCREEN_HEIGHT));
		numOfLineArrayVerts++;
		line[numOfLineArrayVerts] = sf::Vertex(sf::Vector2f(0, i));
		numOfLineArrayVerts++;
		line[numOfLineArrayVerts] = sf::Vertex(sf::Vector2f(DemoConstants::SCREEN_WIDTH, i));
		numOfLineArrayVerts++;
	}
	
	
	// How to load an image
	sf::Image image;
    

	// How to create a sprite from that image.
	

	

	vector<CustomSprite> & allSprites = spriteManager.getAllSprites();
	
	CustomSprite s = allSprites[0];

	
	bool pressedOnce = false;
    // Start game loop
    while (window.isOpen())
    {
		updateCounter++;
		if(GetAsyncKeyState(0x01) != 0){//left button is pressed
			if(pressedOnce == false){
				POINT curPos;
				GetCursorPos(&curPos);
				HWND hWnd = window.getSystemHandle();
				ScreenToClient(hWnd, &curPos);//cur pos is now the position of the cursor inside the window
				cout << "x = " <<  curPos.x << "y = " <<  curPos.y << endl;
				sf::Vector2f cPos = sf::Vector2f(curPos.x, curPos.y);
				spriteManager.sellectSprite(cPos);
				pressedOnce = true;
			}
		}
		else
		{
			pressedOnce = false;
		}
		
		mapman.clearBucketLists();
		
		std::vector<CustomSprite> spriteVect = spriteManager.getAllSprites();
		std::list<CustomSprite> tempSpriteList;


		for(int i = 0; i < spriteVect.size(); i++ ){
			tempSpriteList.push_back(spriteVect[i]);
		}
        // Process events
        sf::Event event;
	
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

		
		for(int i = 0; i < allSprites.size(); i++){
			//mapman.addSpriteToBucket(,
		}
		window.clear(sf::Color::Black);
		
		spriteManager.updateSprites();
		mapman.initMap(&tempSpriteList);
		// How to draw a line.		
	    window.draw(line, DemoConstants::ROWS * 4, sf::Lines);	
			
		// How to draw a container of sprites.
		for ( int i = 0; i < allSprites.size(); ++i ) {		
			window.draw( allSprites.at(i) );
		}
		CustomSprite const & targSpr = *spriteManager.m_targetSprite;
		if(&targSpr != 0){
			//colour the nearby sprites green - access violation error
			//spriteManager.colourNearSprites(mapman.getNearbySprites(targSpr));
		}
        // Display window contents on screen
        window.display();
    }
	

    return EXIT_SUCCESS;
}

