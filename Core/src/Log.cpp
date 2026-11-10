#include "Log.h"
#include <SDL2/SDL_error.h>

void Log::Info(const std::string& message)
{
   SDL_Log("%s", message.c_str());
}

void Log::Error(LOG_TYPE category, const std::string& message)
{
   SDL_LogError(static_cast<int>(category), "%s | SDL : %s", message.c_str(), SDL_GetError());
}
