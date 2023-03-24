# include "enemy.hpp"

enemy::enemy(player* plPtr)
{
    playerPtr = playerPtr;

for(int i = 0; i < numberOfTextures; i++)
{
    textureArray.emplace_back(LoadTexture("../texture/Imp/1-{i+1}.png"));
}
}

void enemy::tick(float deltaTime, Camera3D cam)
{
    calculateAngle();
    anglePtr = &angle;
    Rectangle enemySource{width,height,width,height};
    //DrawBillboardPro(cam, enemyText, enemySource, worldPos, worldUp, Vector2{100.f,100.f},Vector2{0.0f,0.0f}, 0.0f, WHITE);
    DrawBillboardPro(cam, enemyText, source, worldPos, worldUp, Vector2{3.0f,3.0f}, Vector2{1.0f,1.0f}, 0.0f, WHITE );

}

void enemy::calculateAngle()
{
    Vector3 dist = Vector3Subtract(worldPos,playerPos);

    Vector3 forward = Vector3Add(worldPos, Vector3{1.f, 0.f, 0.f});
    angle = Vector2Angle(Vector2{dist.x, dist.z}, Vector2{forward.x, forward.z});
}