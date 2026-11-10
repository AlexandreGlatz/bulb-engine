#ifndef WINDOW_H__
#define WINDOW_H__

#include "Define.h"
#include "Vector2.h"

#include <string>
#include <SDL2/SDL.h>

class Window
{
public:
    Window();
    ~Window();
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    bool Init(uint16 width, uint16 height, std::string name);
    bool Open();
    bool Close();
    void Update();

    Vector2<uint16> GetDimensions() const;
    SDL_Window* GetSDLWindow();

private:
    std::string m_name;
    Vector2<uint16> m_dimensions;
    SDL_Window* m_pSDLWindow;
};

#endif
