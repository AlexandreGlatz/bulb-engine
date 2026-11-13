#include "Components/AABBBoxCollider.h"
#include "Components/Collider.h"
#include "Components/Transform2D.h"
#include "Actor.h"

namespace bulb
{
AABBBoxCollider::AABBBoxCollider(Actor* pOwner, Transform const& transform)
: Collider(pOwner, COLLIDER_TYPE::AABB),
m_transform(transform)
{
}

AABBBoxCollider::~AABBBoxCollider()
{
}

void AABBBoxCollider::OnStart()
{
}

void AABBBoxCollider::Update()
{
    m_transform.position = m_pOwner->GetTransform()->GetPosition();
}

void AABBBoxCollider::OnEnd()
{
}

bool AABBBoxCollider::IsColliding(Collider const& other) const
{
    switch(other.GetType())
    {
    case COLLIDER_TYPE::AABB:
        return IsColliding(static_cast<AABBBoxCollider const&>(other));
        break;
    case COLLIDER_TYPE::CIRCLE:
        return false;
        break;
    }

    return false;
}

bool AABBBoxCollider::IsColliding(const AABBBoxCollider &other) const
{
    return !(m_transform.position.x > other.m_transform.position.x + other.m_transform.scale.width ||
        m_transform.position.x + m_transform.scale.width < other.m_transform.position.x ||
        m_transform.position.y + m_transform.scale.height < other.m_transform.position.y ||
        m_transform.position.y > other.m_transform.position.y + other.m_transform.scale.height);
}

void AABBBoxCollider::OnCollisionEnter(Collider const* pCollider, Collider const* pOther) 
{
}

void AABBBoxCollider::OnCollision(Collider const* pCollider, Collider const* pOther)
{
}

void AABBBoxCollider::OnCollisionExit(Collider const* pCollider, Collider const* pOther)
{
}

void AABBBoxCollider::OnInput(SDL_Event)
{
}

}

