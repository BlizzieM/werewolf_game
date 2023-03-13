#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "raylib.h"
#include "raymath.h"

class player
{
    public:
    player();
    Camera3D* GetCameraPtr(){return &camera;}
    void tick(float deltaTime);
    Vector3 getWorldPosition(){return worldPos;}
    
    private:
    Camera camera = {0};
    int cameraMode = CAMERA_FIRST_PERSON;
    Vector3 worldPos{4.0f, 2.0f, 4.0f};
    Vector3 worldUp{0.0f, 1.0f, 0.0f};

};

#endif