#ifndef RECTANGLE__H_
#define RECTANGLE__H_

#include <SDL2/SDL_rect.h>
#include "Define.h"
#include "Vector2.h"

struct Rectangle
{
   Vector2<uint16> position;
   Vector2<uint16> dimensions;

   SDL_Rect ToSdlRect() const
   {
       return SDL_Rect{
           static_cast<int>(position.x),
           static_cast<int>(position.y),
           static_cast<int>(dimensions.width),
           static_cast<int>(dimensions.height)};
   }
};

#endif
