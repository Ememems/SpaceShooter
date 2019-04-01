#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>

using namespace std;

class Ship{

public:
    int positionX, positionY, lives, points;

public:
	Ship(int=900, int=500, int=3, int=0);
	~Ship();
    void printImage();
    void resetImage();
    void animation();
};
