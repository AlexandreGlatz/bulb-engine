#ifndef TRANSFORM__H_
#define TRANSFORM__H_

#include "Vector2.h"

namespace bulb
{

struct Transform
{
    Vector2f position;
    Vector2f scale;
    float rotation;
};

}
#endif

