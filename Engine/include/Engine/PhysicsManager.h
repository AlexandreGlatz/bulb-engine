#ifndef PHYSICS_MANAGER__H_
#define PHYSICS_MANAGER__H_

#include <vector>
namespace bulb
{

class Collider;
class PhysicsManager
{
public:
    PhysicsManager();
    ~PhysicsManager();

    void AddCollider(Collider const* pCollider);
    void ManageCollisions();

private:
    std::vector<Collider*> m_colliders;
};

}

#endif
