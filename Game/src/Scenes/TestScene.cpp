#include "Scenes/TestScene.h"

#include <Render/Rectangle.h>
#include <Render/Renderer.h>

TestScene::TestScene()
: Scene(),
m_position({0.0f, 0.0f})
{
}

TestScene::~TestScene()
{
}

void TestScene::Start()
{
}

void TestScene::OnInput(SDL_Event event)
{
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDL_KeyCode::SDLK_q)
        {
            m_position.x+=10;
        }

        if(event.key.keysym.sym == SDL_KeyCode::SDLK_d)
        {
            m_position.x-=10;
        }
    }
}

void TestScene::Render()
{
    bulb::Rectangle rect {m_position, {100, 100}};
    m_pRenderer->DrawRect(rect);
}

void TestScene::Update()
{

}

void TestScene::Close()
{
}
