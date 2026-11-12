#ifndef RECTANGLE__H_ 
#define RECTANGLE__H_

#include <SDL2/SDL_rect.h>
#include "Define.h"
#include "Vector2.h"

struct Rectangle
{
   Vector2<float> position;
   Vector2<float> dimensions;

   SDL_Rect ToSdlRect() const
   {
       return SDL_Rect{
           static_cast<int16>(position.x),
           static_cast<int16>(position.y),
           static_cast<int16>(dimensions.width),
           static_cast<int16>(dimensions.height)};
   }
};

#endif
