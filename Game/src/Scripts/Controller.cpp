#include "Scripts/Controller.h"
#include <Engine/Components/Component.h>
#include <Engine/Actor.h>
#include <iostream>

Controller::Controller(bulb::Actor* pOwner)
: bulb::Component(pOwner),
m_direction({0.0f, 0.0f})
{
}

Controller::~Controller()
{
}

void Controller::OnStart()
{
}

void Controller::Update()
{
    m_pOwner->AddTransform(m_direction * 10.0f);
}

void Controller::OnEnd()
{
}

void Controller::OnCollision(bulb::Collider const* pCollider, bulb::Collider const* pOther)
{
    m_direction = m_direction * -1.0f;
    std::cout<<"AAAAAAAAAAAAAAAA"<<std::endl;
}

void Controller::OnInput(SDL_Event event)
{
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDL_KeyCode::SDLK_q)
        {
            m_direction = {-1.0f, 0.0f};
            m_inputAmount++;
        }

        else if(event.key.keysym.sym == SDL_KeyCode::SDLK_d)
        {
            m_direction = {1.0f, 0.0f};
            m_inputAmount++;
        }

        else if(event.key.keysym.sym == SDL_KeyCode::SDLK_z)
        {
            m_direction = {0.0f, -1.0f};
            m_inputAmount++;
        }

        else if(event.key.keysym.sym == SDL_KeyCode::SDLK_s)
        {
            m_direction = {0.0f, 1.0f};
            m_inputAmount++;
        }
    }   

    else if(event.type == SDL_KEYUP)
    {
       if(event.key.keysym.sym == SDL_KeyCode::SDLK_q)
        {
            m_inputAmount--;
        }

        else if(event.key.keysym.sym == SDL_KeyCode::SDLK_d)
        {
            m_inputAmount--;
        }

        else if(event.key.keysym.sym == SDL_KeyCode::SDLK_z)
        {
            m_inputAmount--;
        }

        else if(event.key.keysym.sym == SDL_KeyCode::SDLK_s)
        {
            m_inputAmount--;
        }
        if(m_inputAmount == 0)
            m_direction = {0.0f, 0.0f};
    }

}
