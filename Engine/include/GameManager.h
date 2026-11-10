#ifndef GAME_MANAGER__H_
#define GAME_MANAGER__H_

#include "Define.h"

#include <string>

class Window;
class Renderer;
class GameManager 
{
public:
    GameManager();
    ~GameManager();
    
    bool Init(uint16 windowWidth, uint16 windowHeight, std::string name);
    void Loop();
    void Close();
    void CheckInputs();
    void Render();

private:
    uptr<Window> m_pWindow;
    uptr<Renderer> m_pRenderer;
    bool m_isRunning;
};

#endif
