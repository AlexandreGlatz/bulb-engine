////////////////////////////////////////////////////
// CMake Generator by Alexandre Glatz
// https://github.com/AlexandreGlatz/cmake-generator
////////////////////////////////////////////////////
#include <Engine/GameManager.h>
#include "Scenes/TestScene.h"

int main(int argc, char *argv[])
{
    bulb::GameManager gm;

    gm.CreateWindow(800, 800, "LE JEU VIDEO GAMING");
    gm.CreateScene<TestScene>();

    gm.Init(); 
}
