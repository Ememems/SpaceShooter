#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>

using namespace std;


class Weapon{
public:
    int positionX,positionY,lastYposition,randomLocation;
    float shipWeaponSpeed,alienWeaponSpeed;

    Weapon(int=900, int=500+3,int=246,int=0, float=2,float=1);
	~Weapon();

    void printImage();
    void resetImage();
    void randomize();
};
