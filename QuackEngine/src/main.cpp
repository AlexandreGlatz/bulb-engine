////////////////////////////////////////////////////
// CMake Generator by Alexandre Glatz
// https://github.com/AlexandreGlatz/cmake-generator
////////////////////////////////////////////////////
#include "Log.h"
#include "Vector2.h"

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout<<"hello"<<std::endl;
    Log::Info("Informations");
    Vector2f vec(0.0f, 0.0f);
    vec += 1.0f;

    Log::Info(vec.ToString());

}
