#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <vector>
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
    Texture2D enemyText{};
    Vector3 worldPos{8.0f, 1.0f, 8.0f};
    Vector3 worldUp{0.0f, 1.0f, 0.0f};
    Rectangle source{0.0f,00.0f,48.0f,91.0f};
    player* playerPtr;
    void calculateAngle();
    float angle;
    float* anglePtr;
    Vector3 playerPos;
    std::vector<Texture2D> textureArray;
    int numberOfTextures{9};
    int assingTextureRot();

};

#endif