#include "Components/Component.h"
#include "Actor.h"

namespace bulb
{

Component::Component(Actor* pOwner)
{
    m_pOwner = pOwner;
}

Component::~Component()
{
    m_pOwner = nullptr;
}

void Component::OnCollisionEnter(const Collider *pCollider, const Collider *pOther)
{
}

void Component::OnCollision(const Collider *pCollider, const Collider *pOther)
{
}

void Component::OnCollisionExit(const Collider *pCollider, const Collider *pOther)
{
}

}
