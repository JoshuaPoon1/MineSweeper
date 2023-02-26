#include "Grid.h"

Grid::Grid() {

    
   
    face.setTexture(TextureManager::getTexture("face_happy"));
    face.setPosition(368, 512);

    debug.setTexture(TextureManager::getTexture("debug"));
    debug.setPosition(500, 512);

   
    test_1.setTexture(TextureManager::getTexture("test_1"));
    test_1.setPosition(564, 512);

    test_2.setTexture(TextureManager::getTexture("test_2"));
    test_2.setPosition(628, 512);

  
    test_3.setTexture(TextureManager::getTexture("test_3"));
    test_3.setPosition(692, 512);

    /*
    int temp[3];

    ifstream file;
    file.open("boards/config.cfg");
    string line;
    int i = 0;
    while (getline(file, line)) {
           temp[i] = stoi(line);
           i++;
    }

    file.close();*/


    debugSwitch = false; 
    
    resetBoard();
    setCounterDigits(); 
    


}

Sprite& Grid::getFace() {
    return face; 
}
Sprite& Grid::getDebug() {
    return debug;
}
Sprite& Grid::getTest_1() {
    return test_1; 
}
Sprite& Grid::getTest_2() {
    return test_2;

}
Sprite& Grid::getTest_3() {
    return test_3; 
}

void Grid::resetBoard() {

    notMine = 0; 

    debugSwitch = false; 

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            tiles[i][j] = Tile();
        }
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            tiles[i][j].setPos(i * 32, j * 32);
        }

    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            check[i][j] = false;
            checkFlag[i][j] = false; 
        }
    }


     minecount = 0;

    while (minecount < 50) {
        int i = rand() % 25;
        int j = rand() % 16;
        if (tiles[i][j].MineStatus() == false) {
            tiles[i][j].makeMine(); 
            minecount++; 
             
        }
        
    }

    flagcount = minecount; 

    cout << minecount << endl;

    setCounterDigits(); 

}

void Grid::makeBoardTest1() {


    minecount = 0; 

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            tiles[i][j] = Tile();
        }
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            tiles[i][j].setPos(i * 32, j * 32);
        }

    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            check[i][j] = false;
            checkFlag[i][j] = false; 
        }
    }


    
    char digit[25][16];

    ifstream file;
    file.open("boards/testboard1.brd");
    string line;
    int j = 0; 
    while (getline(file, line)) {

        for (int i = 0; i < 25; i++) {
            digit[i][j] = line[i];
        }
        j++;

    }

    file.close(); 

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            if (digit[i][j] == '1') {
                tiles[i][j].makeMine(); 
                minecount++; 

            }
        }
    }

    flagcount = minecount; 
    
    setCounterDigits(); 
}

void Grid::makeBoardTest2() {

    minecount = 0; 

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            tiles[i][j] = Tile();
        }
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            tiles[i][j].setPos(i * 32, j * 32);
        }

    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            check[i][j] = false;
            checkFlag[i][j] = false; 
        }
    }


    
    char digit[25][16];

    ifstream file;
    file.open("boards/testboard2.brd");
    string line;
    int j = 0;
    while (getline(file, line)) {

        for (int i = 0; i < 25; i++) {
            digit[i][j] = line[i];
        }
        j++;

    }

    file.close(); 

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            if (digit[i][j] == '1') {
                tiles[i][j].makeMine();
                minecount++; 
            }
        }
    }

    flagcount = minecount; 

    cout << minecount << endl; 

    setCounterDigits(); 
}

void Grid::makeBoardTest3() {
    
    minecount = 0; 

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            tiles[i][j] = Tile();
        }
    }

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            tiles[i][j].setPos(i * 32, j * 32);
        }

    }


    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            check[i][j] = false;
            checkFlag[i][j] = false; 
        }
    }

   
    char digit[25][16];

    ifstream file;
    file.open("boards/testboard3.brd");
    string line;
    int j = 0;
    while (getline(file, line)) {

        for (int i = 0; i < 25; i++) {
            digit[i][j] = line[i];
        }
        j++;

    }

    file.close(); 

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 16; j++) {
            if (digit[i][j] == '1') {
                tiles[i][j].makeMine();
                minecount++;
            }
        }
    }

    flagcount = minecount; 
    setCounterDigits(); 

}

void Grid::debugNow() {
    debugSwitch = !debugSwitch;

    if (debugSwitch) {
        for (int i = 0; i < 25; i++) {

            for (int j = 0; j < 16; j++) {

                if (tiles[i][j].MineStatus() == true && !tiles[i][j].isFlagTile()) {
                    tiles[i][j].getCurrentTile().setTexture(TextureManager::getTexture("mine"));
                }
            }
        }
    }
    else {

        for (int i = 0; i < 25; i++) {

            for (int j = 0; j < 16; j++) {

                if (tiles[i][j].MineStatus() == true) {
                    tiles[i][j].getCurrentTile().setTexture(TextureManager::getTexture("tile_hidden"));
                }
            }
        }
    }
 }

void Grid::click(int i, int j) {
    //lets get a number yay
    bool iEdg = false;
    bool jEdg = false;
    bool iEdg2 = false;
    bool jEdg2 = false; 

    int number = 0; 

    if (tiles[i][j].MineStatus() == false) {

        //prevent out of bounds exception
        if (i == 24) {
            iEdg = true; 
            }
        if (j == 15) {
            jEdg = true; 
        }

        if (i == 0) {
            iEdg2 = true; 
        }

        if (j == 0) {

            jEdg2 = false; 
        }
        

        //---------------------These are exceptions------------

        if (jEdg != true) {

           
            if (tiles[i][j + 1].MineStatus() == true) {
                number++;
            }
            

        }

        if (iEdg != true) {

            if (tiles[i + 1][j].MineStatus() == true) {
                number++;
            }


        }

        if (iEdg != true && jEdg != true) {

            if (tiles[i + 1][j + 1].MineStatus() == true) {
                number++;
            }
        }



            if (jEdg2 != true) {

 

                if (tiles[i][j - 1].MineStatus() == true) {
                    number++;
                }
            }

            if (jEdg2 != true && iEdg != true) {

                if (tiles[i + 1][j - 1].MineStatus() == true) {
                    number++;
                }
            }

            if (iEdg2 != true) {
                if (tiles[i - 1][j].MineStatus() == true) {
                    number++;
                }

            }
            if (jEdg != true && iEdg2 != true) {
                if (tiles[i - 1][j + 1].MineStatus() == true) {
                    number++;
                }

            }
            if (jEdg2 != true && iEdg2 != true) {
                if (tiles[i - 1][j - 1].MineStatus() == true) {
                    number++;
                }


            }


            

        
            

        if (number == 0) {
            tiles[i][j].getCurrentTile().setTexture(TextureManager::getTexture("tile_revealed"));
            ++notMine;
            cout << notMine << endl; 
        }
       
        if (number > 0) {
            string input = "number_" + to_string(number); 

            tiles[i][j].getCurrentTile().setTexture(TextureManager::getTexture(input));
            ++notMine; 
            cout << notMine << endl; 
        }

    }
    

}

void Grid::revealAllMines() {

    for (int i = 0; i < 25; i++) {

        for (int j = 0; j < 16; j++) {

            if (tiles[i][j].MineStatus() == true) {
                tiles[i][j].getCurrentTile().setTexture(TextureManager::getTexture("mine"));
            }
        }
    }

}


bool Grid :: checkWin(){

    int finish = 400 - minecount;

    if (notMine == finish){
        revealAllMines(); 
        face.setTexture(TextureManager::getTexture("face_win")); 

        return true; 
    }

    else {
        return false; 
    }
}

bool Grid::checkOriginality(int i, int j) {

    if (check[i][j] == false) {
        check[i][j] = true; 
        return true; 
    }
    else {
        return false; 
    }

    
}

bool Grid::checkOriginality2(int i, int j) {

    checkFlag[i][j] = !checkFlag[i][j]; 

    return checkFlag[i][j]; 


}


Sprite& Grid:: getDigit1(){

    return digit1;
}


Sprite& Grid::getDigit2() {

    return digit2;
}


Sprite& Grid::getDigit3() {

    return digit3;
}

void Grid::setCounterDigits() {

    bool isNeg = false; 

    if (flagcount < 0) {
        isNeg = true; 
    }

    int map[10] = { 0,21,42,63,84,105,126,147,168,189 };

    int length = to_string(flagcount).length();

    if (length == 1) {

        //set 0

        digit1.setTexture(TextureManager::getTexture("digits"));
        digit1.setTextureRect(IntRect(0, 0, 21, 32));
        digit1.setPosition(20, 512);
        

        //set 0 
        digit2.setTexture(TextureManager::getTexture("digits"));
        digit2.setTextureRect(IntRect(0, 0, 21, 32));
        digit2.setPosition(50, 512);

        
        digit3.setTexture(TextureManager::getTexture("digits"));
        digit3.setTextureRect(IntRect(map[flagcount], 0, 21, 32));
        digit3.setPosition(80, 512);

    }

    // we only assume mines 1-99
    else if (length == 2) {


        digit1.setTexture(TextureManager::getTexture("digits"));
        digit1.setTextureRect(IntRect(0, 0, 21, 32));
        digit1.setPosition(20, 512);

        digit2.setTexture(TextureManager::getTexture("digits"));
        digit2.setTextureRect(IntRect(map[flagcount/10], 0, 21, 32));
        digit2.setPosition(50, 512);

        digit3.setTexture(TextureManager::getTexture("digits"));
        digit3.setTextureRect(IntRect(map[flagcount % 10], 0, 21, 32));
        digit3.setPosition(80, 512);


    }

    else if (length == 3) {
        digit1.setTexture(TextureManager::getTexture("digits"));
        digit1.setTextureRect(IntRect(map[(flagcount/10)/10], 0, 21, 32));
        digit1.setPosition(20, 512);

        digit2.setTexture(TextureManager::getTexture("digits"));
        digit2.setTextureRect(IntRect(map[(flagcount / 10) % 10], 0, 21, 32));
        digit2.setPosition(50, 512);

        digit3.setTexture(TextureManager::getTexture("digits"));
        digit3.setTextureRect(IntRect(map[flagcount % 10], 0, 21, 32));
        digit3.setPosition(80, 512);


    }
    

    //0 = 0 
    //21 = 1
    //42 = 2
    //63 = 3
    //84 = 4
    //105 = 5
    //126 = 6
    //147 = 7
    //168 = 8
    //189 = 9
    //210 = -


}

void Grid::decreaseCounter() {

    flagcount -= 1;
    setCounterDigits(); 
}

void Grid::increaseCounter() {

    flagcount += 1;
    setCounterDigits(); 

}