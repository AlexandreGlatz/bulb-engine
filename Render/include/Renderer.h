#ifndef RENDERER__H_
#define RENDERER__H_

#include "Window.h"

class Rectangle;
class Renderer
{
private:
   SDL_Renderer* mSdlRenderer;
public:
   Renderer();
   Renderer(const Renderer&) = delete;
   Renderer& operator=(const Renderer&) = delete;

   bool Initialize(Window& rWindow);
   void BeginDraw();
   void EndDraw();
   void Close();

   void DrawRect(Rectangle& rRect);
};

#endif
