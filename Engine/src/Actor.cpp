#include "Actor.h"
#include "Components/Component.h"
#include "Components/Transform2D.h"
#include <Core/Transform.h>

#include <Engine/Scene.h>

namespace bulb
{

Actor::Actor(int16 id, Transform const& transform)
    :m_id(id),
m_pTransformComponent(std::make_unique<Transform2D>(this, transform.position, transform.scale, transform.rotation))
{
}

Actor::~Actor()
{
    m_pScene = nullptr;
}

int16 Actor::GetId() const
{
    return m_id;
}

Transform2D const* Actor::GetTransform() const
{
    return m_pTransformComponent.get();
}

void Actor::AttachScene(Scene* pScene)
{
    m_pScene = pScene;
}

void Actor::AttachPhysicsManager(PhysicsManager* pPhysicsManager)
{
    m_pPhysicsManager = pPhysicsManager;
}

void Actor::Start()
{
    for(uptr<Component>& pComponent : m_components)
    {
        pComponent->OnStart();
    }
}

void Actor::Update()
{
    for(uptr<Component>& pComponent : m_components)
    {
        pComponent->Update();
    }
}

void Actor::OnInput(SDL_Event event)
{
    for(uptr<Component>& pComponent : m_components)
    {
        pComponent->OnInput(event);
    }
}

void Actor::SetActive(bool isActive)
{
    if(isActive == true)
    {
        m_state = ACTOR_STATE::ACTIVE;
        return;
    }

    m_state = ACTOR_STATE::PAUSED;
}

void Actor::SetTransform(Vector2f position, Vector2f size, float rotation)
{
    m_pTransformComponent->SetPosition(position);
    m_pTransformComponent->SetSize(size);
    m_pTransformComponent->SetRotation(rotation);
}

void Actor::AddTransform(Vector2f position, Vector2f size, float rotation)
{
    m_pTransformComponent->AddPosition(position);
    m_pTransformComponent->AddSize(size);
    m_pTransformComponent->AddRotation(rotation);
}

void Actor::Destroy()
{
    for(uptr<Component>& pComponent : m_components)
    {
        pComponent->OnEnd();
    }

    m_state = ACTOR_STATE::DEAD;
    m_pScene->DestroyActor(this);
}

void Actor::OnCollisionEnter(const Collider *pCollider, const Collider *pOther)
{
    for(uptr<Component>& pComponent : m_components)
    {
        pComponent->OnCollisionEnter(pCollider, pOther);
    }
}

void Actor::OnCollision(const Collider *pCollider, const Collider *pOther)
{
    for(uptr<Component>& pComponent : m_components)
    {
        pComponent->OnCollision(pCollider, pOther);
    }
}

void Actor::OnCollisionExit(const Collider *pCollider, const Collider *pOther)
{
    for(uptr<Component>& pComponent : m_components)
    {
        pComponent->OnCollisionExit(pCollider, pOther);
    }
}

}
