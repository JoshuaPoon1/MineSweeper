#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <vector>
#include <iostream>
using namespace sf;
using namespace std; 




class Tile {
    int x;
    int y;
    bool clickedMine;
    bool isMine;
    bool revealed;
    bool hasNum;
    bool flagged;

    int bombcount;

    Sprite mine;
    Sprite flag;
    Sprite tile_revealed;
    Sprite current;
    Sprite number;

public:
    vector <Tile> surroundings; 
    Tile();
    void setPos(float x, float y);

    //getters
    Sprite& getMine();
    Sprite& getFlag();
    Sprite& getTile_revealed();
    Sprite& getCurrentTile();
    Sprite& getNumber(); 
    //-----
    /*
    void mAffirmative();
    bool isMineClicked();
    */
    void setCurrent(string n); 
    void setNum(string n); 
    void makeMine();
    bool MineStatus();
    bool contains(float x, float y);
    void clickedFlag();
    bool isFlagTile();
        

    

    


    //destructor
   // ~Tile(); 


};
