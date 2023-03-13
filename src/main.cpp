#include <iostream>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "enemy.hpp"
#include "player.hpp"

const int wWidht{1600};
const int wHeight{900};
const int MAX_COLUMNS{20};



int main(void) {
    
    //Initialization
    InitWindow(wWidht, wHeight, "Werewolf Game");
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


    player  plaja{};
    enemy ene{&plaja};
    Camera3D* playerCameraPtr = plaja.GetCameraPtr();

    

    

    SetTargetFPS(60);

    //main game loop
    while (!WindowShouldClose())
    {
        UpdateCamera(playerCameraPtr);

        BeginDrawing();
        

            ClearBackground(RAYWHITE);

            BeginMode3D(*playerCameraPtr);

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
                plaja.tick(GetFrameTime());
                ene.tick(GetFrameTime(), *playerCameraPtr);  

                //DrawBillboard(camera, enemyText, Vector3{ 0.0f, 2.0f, 0.0f }, 1.0f, WHITE );
                //DrawBillboardPro(camera, enemyText, source, Vector3{ 0.0f, 2.0f, 0.0f }, Vector3{0.0f, 1.0f, 0.0f}, (Vector2) {1.0f, 1.0f}, Vector2{0.0f,0.0f}, 0.0f, WHITE);
                EndMode3D();
            

            std::string Angle = "Angle: ";
            Angle.append(std::to_string(ene.getAngle()), 0, 5);
            DrawText(Angle.c_str(), 40, 40, 20, RED);

            EndDrawing();
    }

    CloseWindow();

    return 0;
}
