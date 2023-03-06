#include <iostream>
#include "raylib.h"


#define MAX_COLUMNS 20

const int wWidht{800};
const int wHeight{600};



int main(void) {
    
    //Initialization
    InitWindow(wWidht, wHeight, "Werewolf Game");

    //Define the camera to look into 3D world (position, target, up vector)
    Camera camera = {0};
    camera.position = (Vector3){0.0f, 2.0f, 4.0f};       //camera pos
    camera.target = (Vector3){0.0f, 2.0f, 0.0f};         //camera look at point
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};             //camera's up vector (rotation towards target)
    camera.fovy = 99.0f;                                 //Camera fov - y
    camera.projection = CAMERA_PERSPECTIVE;              //Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    //generate some random columns

    float heights[MAX_COLUMNS] = {0};
    Vector3 positions[MAX_COLUMNS] = {0};
    Color colors[MAX_COLUMNS] = {0};

    SetTargetFPS(60);

    //main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        

            ClearBackground(RAYWHITE);

            DrawText("Text", wWidht/2 -20, wHeight/2 -20, 20, LIGHTGRAY);

            EndDrawing();
    }

    CloseWindow();

    return 0;
}
