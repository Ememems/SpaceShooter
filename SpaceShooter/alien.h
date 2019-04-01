#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>

using namespace std;


class Alien{
public:
	Alien(float=90,float=120,bool=true);
	~Alien();
    float positionX,positionY;
    int hit;
    void printImage();
    void resetImage();
    void animation();
};
