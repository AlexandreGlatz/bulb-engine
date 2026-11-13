#include "Scenes/TestScene.h"
#include "Engine/Actor.h"

#include <Engine/Components/Transform2D.h>
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
    for(uptr<bulb::Actor>& pActor : m_actors)
    {
        bulb::Transform2D const* pTransform = pActor->GetTransform();
        bulb::Rectangle rect {pTransform->GetPosition(), pTransform->GetSize()};
        m_pRenderer->DrawRect(rect);
    }
}

void TestScene::Close()
{
}
