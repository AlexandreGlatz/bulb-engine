#include "PhysicsManager.h"
#include "Components/Collider.h"

#include <algorithm>
#include <Core/Define.h>

namespace bulb
{

PhysicsManager::PhysicsManager()
{
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::AddCollider(Collider* pCollider)
{
    m_colliders.push_back(pCollider);
}

void PhysicsManager::RemoveCollider(Collider* pCollider)
{
    m_colliders.erase(std::remove(m_colliders.begin(), m_colliders.end(), pCollider));
}


void PhysicsManager::ManageCollisions()
{
    int16 size;
    for(uint16 i = 0; i < m_colliders.size(); ++i)
    {
        if(i + 1 >= m_colliders.size())
            return;

        for(uint16 j = i + 1; j < size; ++j)
        {
            Collider const* pCurrent = m_colliders[j];
            if(m_colliders[i]->IsColliding(*pCurrent))
            {
                m_colliders[i]->CollisionEnter(*pCurrent);
                m_colliders[i]->Collision(*pCurrent);
                continue;
            }
            m_colliders[i]->CollisionExit(*pCurrent);

        }
        size--;
    }
}
}
