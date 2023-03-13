#include "player.hpp"

player::player()
{
    //Initialize camera with provided parameters
    camera.position = worldPos;      //camera pos
    camera.target = Vector3{0.0f, 2.0f, 0.0f};      //camera look at point
    camera.up = worldUp;      //camera's up vector (rotation towards target)
    camera.fovy = 99.0f;                                 //Camera fov - y
    camera.projection = CAMERA_PERSPECTIVE;              //Camera projection type

    SetCameraMode(camera, CAMERA_FIRST_PERSON);
}

void player::tick(float deltaTime)
{
    worldPos = camera.position;
}