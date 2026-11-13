#ifndef COLLIDER__H_
#define COLLIDER__H_

#include "Component.h"

#include <Core/Transform.h>
namespace bulb
{


enum class COLLIDER_TYPE
{
    AABB,
    CIRCLE
};

class PhysicsManager;
class Actor;
class Collider : public Component
{
public:
    Collider(Actor* pOwner, COLLIDER_TYPE type);
    virtual ~Collider() override;

    virtual void AddToPhysicsManager(PhysicsManager* pPhysicsManager) override;
    virtual void OnStart() override = 0;
    virtual void Update() override = 0;
    virtual void OnEnd() override;
    virtual void OnInput(SDL_Event event) override = 0;
    
    virtual void CollisionEnter(Collider const& other);
    virtual void Collision(Collider const& other);
    virtual void CollisionExit(Collider const& other);

    virtual bool IsColliding(Collider const& other) const = 0;
    COLLIDER_TYPE GetType() const;

protected:
    COLLIDER_TYPE m_type;
    bool m_entered;
    PhysicsManager* m_pPhysicsManager;
};

}
#endif
