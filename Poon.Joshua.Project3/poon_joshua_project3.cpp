#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Tile.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Grid.h";

using namespace std;
using namespace sf; 




int main()
{
    RenderWindow window(VideoMode(800, 600), "Minesweeper");

    Grid grid;
  
    bool loss = false; 
    bool win = false; 

    

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            else if (event.type == Event::MouseButtonPressed) {

                if (event.mouseButton.button == Mouse::Right && loss == false && grid.checkWin() == false){


                    auto mousePos = Mouse::getPosition(window);



                    for (int i = 0; i < 25; i++) {  
                        for (int j = 0; j < 16; j++) {

                            if (grid.tiles[i][j].contains(mousePos.x, mousePos.y)) {
                                grid.tiles[i][j].clickedFlag();
                                
                                
                                
                                
                                if (grid.checkOriginality2(i, j) == true) {
                                    grid.decreaseCounter(); 

                                }

                                else {
                                    grid.increaseCounter(); 

                                }




                            }
                        }
                    }

                }

                else if (event.mouseButton.button == Mouse::Left) {
                 auto mousePos = Mouse::getPosition(window);

                 if (grid.getFace().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                     grid.resetBoard();
                     grid.getFace().setTexture(TextureManager::getTexture("face_happy"));
                     loss = false; 
                     
                

                 }

                 

                 else if (grid.getDebug().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                     grid.debugNow();
                    
                 }
                 else if (grid.getTest_1().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                     grid.makeBoardTest1(); 
                   
                 }
                 else if (grid.getTest_2().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                     grid.makeBoardTest2(); 
                   
                 }
                 else if (grid.getTest_3().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                     grid.makeBoardTest3();
                   
                 }
                 else {

                     for (int i = 0; i < 25; i++) {
                         for (int j = 0; j < 16; j++) {

                             if (grid.tiles[i][j].contains(mousePos.x, mousePos.y) && grid.tiles[i][j].MineStatus() && grid.checkWin() == false){
                                
                                 grid.getFace().setTexture(TextureManager::getTexture("face_lose"));
                                 grid.revealAllMines(); 
                                 loss = true; 
                                 
                            


                             }
                             if (grid.tiles[i][j].contains(mousePos.x, mousePos.y) && !grid.tiles[i][j].MineStatus() && loss == false && grid.checkWin() == false){
                                 if (grid.checkOriginality(i, j) == true){
                                     grid.click(i, j);
                                 }
                          

                             }

                         }
                     }


                 }
             }
            
            }



            for (int i = 0; i < 25; i++) {
                for (int j = 0; j < 16; j++) {

                    window.draw(grid.tiles[i][j].getCurrentTile());
                   
                }
            }

            window.draw(grid.getFace());
            window.draw(grid.getDigit1()); 
            window.draw(grid.getDigit2());
            window.draw(grid.getDigit3()); 
            window.draw(grid.getDebug());
            window.draw(grid.getTest_1()); 
            window.draw(grid.getTest_2());
            window.draw(grid.getTest_3()); 



            window.display(); 
        }
    }

        

        TextureManager::Clear();
        return 0;
    
}