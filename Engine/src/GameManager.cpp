#include "GameManager.h"
#include "Window.h"
#include "Renderer.h"
#include "Log.h"

GameManager::GameManager()
: m_isRunning(true)
{
}

GameManager::~GameManager()
{
}

bool GameManager::Init(uint16 windowWidth, uint16 windowHeight, std::string name)
{
       
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        Log::Error(LOG_TYPE::SYSTEM, "SDL initialization failed. SDL Error: ");
    }
    else
    {
        Log::Info("SDL initialization succeeded!");
    }

    m_pWindow = std::make_unique<Window>();
    m_pWindow->Init(windowWidth, windowHeight, name);
    if(m_pWindow->Open() == true)
    {
        m_pRenderer = std::make_unique<Renderer>();
        m_pRenderer->Initialize(*m_pWindow);

        Loop();
    }

    return true;
}


void GameManager::Loop()
{
    while(m_isRunning)
    {
        m_pWindow->Update();
        Render();
        CheckInputs();
    }

    Close();
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
                   break;
           }
       }
   }
}

void GameManager::Render()
{
    m_pRenderer->BeginDraw();
    m_pRenderer->EndDraw();
}

void GameManager::Close()
{
    m_pRenderer->Close();
    m_pWindow->Close();
}

