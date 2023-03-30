# include "enemy.hpp"

enemy::enemy(player* plPtr)
{
    playerPtr = playerPtr;

    for(int i = 0; i < numberOfTextures; i++)
    {
        std::string S{"../texture/Imp/1-"};
        S.append(std::to_string(i),0,1);
        S.append(".png",0,4);
        textureArray.emplace_back(LoadTexture(S.c_str()));
    }
}

void enemy::tick(float deltaTime, Camera3D cam)
{
    calculateAngle();
    anglePtr = &angle;
    Rectangle enemySource{0,0,textureArray.at(assingTextureRot()).width,textureArray.at(assingTextureRot()).height};
    //DrawBillboardPro(cam, enemyText, enemySource, worldPos, worldUp, Vector2{100.f,100.f},Vector2{0.0f,0.0f}, 0.0f, WHITE);
    DrawBillboardPro(cam, textureArray.at(assingTextureRot()), enemySource, worldPos, worldUp, Vector2{3.0f,3.0f}, Vector2{1.0f,1.0f}, 0.0f, WHITE );

}

void enemy::calculateAngle()
{
    Vector3 dist = Vector3Subtract(worldPos,playerPos);

    Vector3 forward = Vector3Add(worldPos, Vector3{1.f, 0.f, 0.f});
    angle = Vector2Angle(Vector2{dist.x, dist.z}, Vector2{forward.x, forward.z});
}

int enemy::assingTextureRot()
{
    if(angle <= 0.3926990817 && angle >= -0.3926990817)
    {
        return 1;
    }
    
    else if(angle >= 0.3926990817 && angle <=  1.1780972451 || ) 
    {
        return 2;
    }
    
    else if (angle >= 1.1780972451 && angle <= 1.9634954085)
    {
        return 3;
    }

    else if (angle >= 1.9634954085 && angle <= 2.7488935719)
    {
        return 4;
    }

    else if (angle >= 2.7488935719 && angle <= 3.5342917353) 
    {
        return 5;
    }
}