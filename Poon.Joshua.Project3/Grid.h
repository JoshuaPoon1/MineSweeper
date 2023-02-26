#pragma once
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace sf;
using namespace std;


class Grid
{

	Sprite face;
	Sprite debug;
	Sprite test_1;
	Sprite test_2;
	Sprite test_3;
	Sprite digit1;
	Sprite digit2;
	Sprite digit3;
	bool debugSwitch;
	int notMine; 
	int minecount;
	int flagcount; 
	


	
public:
	Tile tiles[25][16];
	bool check[25][16];
	bool checkFlag[25][16];
	Grid();
	Sprite& getFace();
	Sprite& getDebug();
	Sprite& getTest_1();
	Sprite& getTest_2();
	Sprite& getTest_3(); 
	Sprite& getDigit1(); 
	Sprite& getDigit2();
	Sprite& getDigit3();
	void resetBoard(); 
	void makeBoardTest1(); 
	void makeBoardTest2();
	void makeBoardTest3(); 
	void debugNow(); 
	void click(int i, int j); 
	void revealAllMines(); 
	bool checkWin(); 
	bool checkOriginality(int i, int j); 
	bool checkOriginality2(int i, int j);
	void setCounterDigits(); 
	void decreaseCounter(); 
	void increaseCounter(); 
	
	

};

