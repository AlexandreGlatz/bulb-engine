#ifndef COMPONENT__H_
#define COMPONENT__H_

#include "../PhysicsManager.h"
#include <Core/Define.h>
#include <SDL2/SDL_events.h>

namespace bulb
{

class Collider;
class PhysicsManager;
class Actor;
class Component
{
public:
    Component(Actor* pOwner);
    virtual ~Component();

    virtual void AddToPhysicsManager(PhysicsManager* pPhysicsManager);

    virtual void OnStart() = 0;
    virtual void Update() = 0;
    virtual void OnEnd() = 0;
    virtual void OnInput(SDL_Event event) = 0;
    virtual void OnCollisionEnter(Collider const* pCollider, Collider const* pOther);
    virtual void OnCollision(Collider const* pCollider, Collider const* pOther);
    virtual void OnCollisionExit(Collider const* pCollider, Collider const* pOther);

protected:
    bool m_isActive;
    int m_updateOrder;
    Actor* m_pOwner;
};

}

#endif
