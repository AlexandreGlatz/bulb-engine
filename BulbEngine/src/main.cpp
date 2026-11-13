////////////////////////////////////////////////////
// CMake Generator by Alexandre Glatz
// https://github.com/AlexandreGlatz/cmake-generator
////////////////////////////////////////////////////

#include <Core/Transform.h>
#include <Engine/GameManager.h>
#include <Engine/Actor.h>
#include <Engine/Components/Transform2D.h>
#include <Engine/Components/AABBBoxCollider.h>

#include "Scenes/TestScene.h"
#include "Scripts/Controller.h"

int main(int argc, char *argv[])
{
    bulb::GameManager gm;

    gm.CreateWindow(800, 800, "LE JEU VIDEO GAMING");
    TestScene* pScene = gm.CreateScene<TestScene>();

    bulb::Transform playerTransform {{0.0f, 0.0f}, {100.0f, 100.0f}, 0.0f};
    bulb::Actor* pPlayer = pScene->SpawnActor(playerTransform);
    pPlayer->AddComponent<Controller>();
    pPlayer->AddComponent<bulb::AABBBoxCollider>(playerTransform);

    bulb::Transform obstacleTransform {{300.0f, 300.0f}, {30.0f, 30.0f}, 0.0f};
    bulb::Actor* pObstacle = pScene->SpawnActor(obstacleTransform);
    pObstacle->AddComponent<bulb::AABBBoxCollider>(obstacleTransform);

    gm.Init(); 
}
