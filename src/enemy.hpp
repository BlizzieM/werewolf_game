#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "raylib.h"
#include "raymath.h"

class enemy
{
    public:
    enemy();
    Vector3 getWorldPos(){return worldPos;}
    void tick(float deltaTime, Camera3D cam);

    private:
    float width{10.f};
    float height{10.f};
    Texture2D enemyText{LoadTexture("../Textures/Imp.png")};
    Vector3 worldPos{16.0f, 16.0f, 0.0f};
    Vector3 worldUp{0.0f, 1.0f, 0.0f};
    

};

#endif