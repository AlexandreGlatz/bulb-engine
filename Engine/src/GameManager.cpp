#include "GameManager.h"
#include "Scene.h"

#include <Core/Log.h>
#include <Render/Window.h>
#include <Render/Renderer.h>

namespace bulb
{

GameManager::GameManager()
: m_isRunning(true),
m_currentScene(0),
m_pRenderer(nullptr)
{
}

GameManager::~GameManager()
{
}

bool GameManager::Init()
{
       
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        Log::Error(LOG_TYPE::SYSTEM, "SDL initialization failed. SDL Error: ");
    }
    else
    {
        Log::Info("SDL initialization succeeded!");
    }

    if(m_pWindow->Open() == true)
    { 
        m_pRenderer = std::make_unique<Renderer>();
        m_pRenderer->Initialize(*m_pWindow);

        for(sptr<Scene> pScene : m_scenes)
        {
            pScene->SetRenderer(m_pRenderer);
        }
        Loop();
    }

    return true;
}

bool GameManager::CreateWindow(uint16 windowWidth, uint16 windowHeight, std::string name)
{
    m_pWindow = std::make_unique<Window>();
    return m_pWindow->Init(windowWidth, windowHeight, name);
}

void GameManager::Loop()
{
    while(m_isRunning)
    {
        Update();
        Render();
        CheckInputs();
    }

    Close();
}

void GameManager::Update()
{
    m_pWindow->Update();
    m_scenes[m_currentScene]->Update();
}
void GameManager::CheckInputs()
{
   if (m_isRunning)
   {
       SDL_Event event;
       while(SDL_PollEvent(&event))
       {
           switch(event.type)
           {
               case SDL_QUIT:
                   m_isRunning = false;
                   break;
               default:
                   //Send input to scene
                   m_scenes[m_currentScene]->OnInput(event);
                   break;
           }
       }
   }
}

void GameManager::Render()
{
    m_pRenderer->BeginDraw();
    m_scenes[m_currentScene]->Render();
    m_pRenderer->EndDraw();
}

void GameManager::Close()
{
    m_pRenderer->Close();
    m_pWindow->Close();

    for(sptr<Scene> pScene : m_scenes)
    {
        pScene->Close();
    }
}

}
