# include "enemy.hpp"

enemy::enemy()
{

}

void enemy::tick(float deltaTime, Camera3D cam)
{
    Rectangle enemySource{width,height,width,height};
    //DrawBillboardPro(cam, enemyText, enemySource, worldPos, worldUp, Vector2{100.f,100.f},Vector2{0.0f,0.0f}, 0.0f, WHITE);
    DrawBillboardPro(cam, enemyText, source, worldPos, worldUp, Vector2{3.0f,3.0f}, Vector2{1.0f,1.0f}, 0.0f, WHITE );
}