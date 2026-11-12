#ifndef LOG_H__
#define LOG_H__

#include <SDL2/SDL_log.h>
#include <string>

namespace bulb 
{
enum class LOG_TYPE
{
   APPLICATION = SDL_LOG_CATEGORY_APPLICATION,
   ASSERT = SDL_LOG_CATEGORY_ASSERT,
   AUDIO = SDL_LOG_CATEGORY_AUDIO,
   ERROR = SDL_LOG_CATEGORY_ERROR,
   INPUT = SDL_LOG_CATEGORY_INPUT,
   RENDER = SDL_LOG_CATEGORY_RENDER,
   SYSTEM = SDL_LOG_CATEGORY_SYSTEM,
   TEST = SDL_LOG_CATEGORY_TEST,
   VIDEO = SDL_LOG_CATEGORY_VIDEO
};

class Log
{
public:
   Log()=delete;
   Log(const Log&) = delete;
   Log& operator=(const Log&) = delete;

   static void Info(const std::string& message);
   static void Error(LOG_TYPE category, const std::string& message);
};
}
#endif
