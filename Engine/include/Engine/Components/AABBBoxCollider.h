#ifndef AABB_BOX_COOLIDER__H__
#define AABB_BOX_COOLIDER__H__

#include "Collider.h"

namespace bulb
{

class AABBBoxCollider : public Collider
{
public :
    AABBBoxCollider(Actor* pOwner, Transform const& transform);
    ~AABBBoxCollider() override;
    
    virtual void OnStart() override;
    virtual void Update() override;
    virtual void OnEnd() override;
    virtual void OnInput(SDL_Event) override;
    
    virtual void OnCollisionEnter(Collider const* pCollider, Collider const* pOther) override;
    virtual void OnCollision(Collider const* pCollider, Collider const* pOther) override;
    virtual void OnCollisionExit(Collider const* pCollider, Collider const* pOther) override;

    bool IsColliding(Collider const& other) const override;

private:
    bool IsColliding(AABBBoxCollider const& other) const;

private:
    Transform m_transform; 
};

}
#endif
