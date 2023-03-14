#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "player.hpp"

class enemy
{
    public:
    enemy(player* plPtr);
    Vector3 getWorldPos(){return worldPos;}
    void tick(float deltaTime, Camera3D cam);
    float getAngle(){return angle;}
    void setPlayerPos(Vector3 plPos){ playerPos = plPos;}

    private:
    float width{48.f};
    float height{90.f};
    Texture2D enemyText{LoadTexture("../texture/Imp.png")};
    Vector3 worldPos{8.0f, 1.0f, 8.0f};
    Vector3 worldUp{0.0f, 1.0f, 0.0f};
    Rectangle source{8.0f,40.0f,48.0f,90};
    player* playerPtr;
    void calculateAngle();
    float angle;
    float* anglePtr;
    Vector3 playerPos;
    

};

#endif