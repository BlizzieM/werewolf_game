#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "enemy.hpp"

const int wWidht{1600};
const int wHeight{900};
const int MAX_COLUMNS{20};



int main(void) {
    
    //Initialization
    InitWindow(wWidht, wHeight, "Werewolf Game");
    //Texture2D enemyText{LoadTexture("texture/Imp.png")};
    //Define the camera to look into 3D world (position, target, up vector)
    Camera camera = {0};
    camera.position = Vector3{4.0f, 2.0f, 4.0f};      //camera pos
    camera.target = Vector3{0.0f, 2.0f, 0.0f};      //camera look at point
    camera.up = Vector3{0.0f, 1.0f, 0.0f};      //camera's up vector (rotation towards target)
    camera.fovy = 99.0f;                                 //Camera fov - y
    camera.projection = CAMERA_PERSPECTIVE;              //Camera projection type

    int cameraMode = CAMERA_FIRST_PERSON;

    //generate some random columns

    float heights[MAX_COLUMNS] = {0};
    Vector3 positions[MAX_COLUMNS] = {0};
    Color colors[MAX_COLUMNS] = {0};

    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        
        heights[i] = (float)GetRandomValue(1, 12);
        positions[i] = Vector3{(float)GetRandomValue(-15,15), heights[i]/2.0f, (float)GetRandomValue(-15, 15)};
        colors[i] = Color{(unsigned char)GetRandomValue(20,255), (unsigned char)GetRandomValue(10,55), 30, 255};
    }

    enemy ene{};

    

    SetCameraMode(camera, CAMERA_FIRST_PERSON);

    SetTargetFPS(60);

    //main game loop
    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);

        BeginDrawing();
        

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawPlane(Vector3{0.0f, 0.0f, 0.0f}, Vector2{32.0f, 32.0f}, LIGHTGRAY);
                DrawCube(Vector3{-16.0f, 2.5f, 0.0f},1.0f, 5.0f, 32.0f, BLUE);
                DrawCube(Vector3{16.0f, 2.5, 0.0f}, 1.0f, 5.0f, 32.0f, LIME);
                DrawCube(Vector3{0.0f, 2.5f,16.0f}, 32.0f, 5.0f, 1.0f, GOLD);
                DrawCube(Vector3{0.0f, 2.5f,-16.0f}, 32.0f, 5.0f, 1.0f, MAGENTA);

            /*
              for (int i = 0; i < MAX_COLUMNS; i++)
                {
                    DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
                    DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, MAROON);
                }
              */
                ene.tick(GetFrameTime(), camera);  

                //DrawBillboard(camera, enemyText, Vector3{ 0.0f, 2.0f, 0.0f }, 1.0f, WHITE );
                //DrawBillboardPro(camera, enemyText, source, Vector3{ 0.0f, 2.0f, 0.0f }, Vector3{0.0f, 1.0f, 0.0f}, (Vector2) {1.0f, 1.0f}, Vector2{0.0f,0.0f}, 0.0f, WHITE);
                EndMode3D();

            DrawText("Text", wWidht/2 -20, wHeight/2 -20, 20, LIGHTGRAY);
           

            EndDrawing();
    }

    CloseWindow();

    return 0;
}
