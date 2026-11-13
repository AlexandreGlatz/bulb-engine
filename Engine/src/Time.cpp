#include "Time.h"

#include <algorithm>
#include <SDL2/SDL_timer.h>

namespace bulb
{
unsigned int Time::m_frameStart = 0;
unsigned int Time::m_frameTime = 0;
unsigned int Time::m_lastFrame = 0;
float Time::deltaTime = 0;

unsigned int Time::ComputeDeltaTime()
{
   m_frameStart = SDL_GetTicks();
   unsigned int dt = m_frameStart - m_lastFrame;
   m_lastFrame = m_frameStart;
   dt = std::min(dt, MAX_DT);
   deltaTime = dt / 1000.0f;
   return dt;
}

void Time::DelayTime()
{
   m_frameTime = SDL_GetTicks() - m_frameStart;
   if(m_frameTime < FRAME_DELAY)
       SDL_Delay(FRAME_DELAY - m_frameTime);
}

}
