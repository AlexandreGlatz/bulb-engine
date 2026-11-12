#include "Window.h"
#include "Log.h"

namespace bulb
{

Window::Window()
: m_name("Base Window"),
m_dimensions({0, 0}),
m_pSDLWindow(nullptr)
{
}

Window::~Window()
{
    if(m_pSDLWindow != nullptr)
        Close();
}

bool Window::Init(uint16 width, uint16 height, std::string name)
{
    m_dimensions = {width, height};
    m_name = name;
    return true;
}

bool Window::Open()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        Log::Error(LOG_TYPE::VIDEO, "Unable to initialize video");
        return false;
    }

    m_pSDLWindow = SDL_CreateWindow(m_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, static_cast<int>(m_dimensions.width),static_cast<int>(m_dimensions.height), SDL_WINDOW_OPENGL);

    if(m_pSDLWindow == nullptr)
    {
        Log::Error(LOG_TYPE::SYSTEM, "Failed to create window");
        return false;
    }

    return true;
}

void Window::Update()
{

}

SDL_Window* Window::GetSDLWindow()
{
    return m_pSDLWindow;
}

bool Window::Close()
{
    SDL_Quit();
    SDL_DestroyWindow(m_pSDLWindow);
    return true;
}

}
