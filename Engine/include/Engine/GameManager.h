#ifndef GAME_MANAGER__H_
#define GAME_MANAGER__H_

#include "Core/Define.h"

#include <string>
#include <vector>

namespace bulb
{
class Scene;
class Window;
class Renderer;
class GameManager 
{
public:
    GameManager();
    ~GameManager();
    
    bool Init();
    bool CreateWindow(uint16 windowWidth, uint16 windowHeight, std::string name);

    template<typename T>
    void CreateScene();

    void Loop();
    void Update();
    void Close();
    void CheckInputs();
    void Render();

private:
    uptr<Window> m_pWindow;
    sptr<Renderer> m_pRenderer;
    std::vector<sptr<Scene>> m_scenes;

    bool m_isRunning;
    uint16 m_currentScene;
};

}
#include "GameManager.inl"

#endif
