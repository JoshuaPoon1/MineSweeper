#include "Tile.h"



Tile::Tile() {
    clickedMine = false;
    isMine = false;
    revealed = false;
    hasNum = false;
    flagged = false;
    bombcount = 0;
    x = 0;
    y = 0;

    mine.setTexture(TextureManager::getTexture("mine"));
    flag.setTexture(TextureManager::getTexture("flag"));
    tile_revealed.setTexture(TextureManager::getTexture("tile_revealed"));
    current.setTexture(TextureManager::getTexture("tile_hidden"));
    number.setTexture(TextureManager::getTexture("number_1"));




}
void Tile::setPos(float x, float y) {
    this->x = x;
    this->y = y;
    Texture texture;
   
    mine.setPosition(x, y);
    flag.setPosition(x, y);
    tile_revealed.setPosition(x, y);
    current.setPosition(x, y);
    number.setPosition(x, y);
}


Sprite& Tile::getCurrentTile() {
    
    if (flagged) {
        return flag; 
    }
    
    else {
        return current;
    }
}

Sprite& Tile::getMine() {

    return mine;
}
Sprite& Tile::getFlag() {

    return flag;
}
Sprite& Tile::getTile_revealed() {
    return tile_revealed;
}

Sprite& Tile::getNumber() {
    return number;
}


void Tile::setCurrent(string n) {

    current.setTexture(TextureManager::getTexture(n));
}

void Tile::setNum(string n) {

    number.setTexture(TextureManager::getTexture(n));

}

void Tile::makeMine() {
    isMine = true;
}

bool Tile::MineStatus() {
    return isMine; 
}

bool Tile::contains(float x, float y) {

    return current.getGlobalBounds().contains(x, y);

}

void Tile::clickedFlag() {

    flagged = !flagged;
  


}

bool Tile::isFlagTile() {

    return flagged; 
}