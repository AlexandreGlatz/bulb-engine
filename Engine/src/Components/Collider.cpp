#include "Components/Collider.h"
#include "Actor.h"
#include "PhysicsManager.h"

namespace bulb
{

Collider::Collider(Actor* pOwner, COLLIDER_TYPE type)
: Component(pOwner), 
m_type(type),
m_entered(false)
{
}

Collider::~Collider()
{
}

void Collider::AddToPhysicsManager(PhysicsManager* pPhysicsManager)
{
    pPhysicsManager->AddCollider(this);
    m_pPhysicsManager = pPhysicsManager;
}

COLLIDER_TYPE Collider::GetType() const
{
    return m_type;
}

void Collider::CollisionEnter(Collider const& other)
{
    if(m_entered == true)
        return;

    m_entered = true;
    m_pOwner->OnCollisionEnter(this, &other);
}

void Collider::Collision(Collider const& other)
{
    m_pOwner->OnCollision(this, &other);
}

void Collider::CollisionExit(Collider const& other)
{
    if(m_entered == false)
        return;

    m_entered = false;
    m_pOwner->OnCollisionExit(this, &other);
}

void Collider::OnEnd()
{
    m_pPhysicsManager->RemoveCollider(this);
}

}

