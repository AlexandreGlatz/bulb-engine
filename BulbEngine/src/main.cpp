////////////////////////////////////////////////////
// CMake Generator by Alexandre Glatz
// https://github.com/AlexandreGlatz/cmake-generator
////////////////////////////////////////////////////

#include <Core/Transform.h>
#include <Engine/GameManager.h>
#include <Engine/Actor.h>
#include <Engine/Components/Transform2D.h>

#include "Scenes/TestScene.h"

int main(int argc, char *argv[])
{
    bulb::GameManager gm;

    gm.CreateWindow(800, 800, "LE JEU VIDEO GAMING");
    TestScene* pScene = gm.CreateScene<TestScene>();

    bulb::Transform transform {{0.0f, 0.0f}, {100.0f, 100.0f}, 0.0f};
    bulb::Actor* pActor1 = pScene->SpawnActor(transform);

    gm.Init(); 
}
