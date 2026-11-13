#include "Scene.h"
#include "Actor.h"

#include <memory>
#include <algorithm>
#include <Render/Renderer.h>
#include <Core/Transform.h>

namespace bulb 
{

Scene::Scene()
{
    m_pPhysicsManager = std::make_unique<PhysicsManager>();
}

Scene::~Scene()
{
}

void Scene::SetRenderer(sptr<Renderer> pRenderer)
{
    m_pRenderer = pRenderer;
}

void Scene::Start()
{
}

Actor* Scene::SpawnActor(Transform const& transform)
{
    m_toCreate.push(std::make_unique<Actor>(m_actorId, transform));
    m_actorId++;

    m_toCreate.back()->AttachScene(this);
    m_toCreate.back()->AttachPhysicsManager(m_pPhysicsManager.get());
    m_toCreate.back()->Start();
    return m_toCreate.back().get();
}

void Scene::CreateActors()
{
    while(m_toCreate.empty() == false)
    {
        m_actors.push_back(std::move(m_toCreate.front()));

        m_toCreate.pop();
    }
}

void Scene::PhysicsStep()
{
    m_pPhysicsManager->ManageCollisions();
}

void Scene::Update()
{
    CreateActors();

    for(uptr<Actor>& pActor : m_actors)
    {
        pActor->Update();
    }

    DestroyActors();
}

void Scene::DestroyActor(Actor* pActor)
{
    std::vector<uptr<Actor>>::iterator it = std::find_if(m_actors.begin(), m_actors.end(), 
            [&](uptr<Actor>& pCurrentActor) {return pActor->GetId() == pCurrentActor->GetId();}
    );

    if(it != m_actors.end())
    {
        m_toDestroy.push(std::move(m_actors[it - m_actors.begin()]));
        m_actors.erase(it);
    }

}

void Scene::DestroyActors()
{
    while(m_toDestroy.empty() == false)
    {
        m_toDestroy.pop();
    }
}

void Scene::OnInput(SDL_Event event)
{
    for(uptr<Actor>& pActor : m_actors)
    {
        pActor->OnInput(event);
    }
}

void Scene::Render()
{
}


void Scene::Close()
{
}

}
