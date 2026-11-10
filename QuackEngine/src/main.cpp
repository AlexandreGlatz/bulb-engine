////////////////////////////////////////////////////
// CMake Generator by Alexandre Glatz
// https://github.com/AlexandreGlatz/cmake-generator
////////////////////////////////////////////////////
#include "Window.h"
#include "GameManager.h"

int main(int argc, char *argv[])
{
    GameManager gm;
    gm.Init(800, 800, "GMAINGE");
}
