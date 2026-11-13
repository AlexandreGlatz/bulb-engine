#ifndef ACTOR__H_
#define ACTOR__H_

#include "PhysicsManager.h"
#include <SDL2/SDL_events.h>
#include <vector>
#include <Core/Define.h>
#include <Core/Vector2.h>

namespace bulb
{

enum class ACTOR_STATE
{
    ACTIVE,
    PAUSED,
    DEAD
};

struct Transform;
class Component;
class Transform2D;
class Scene;
class Collider;
class PhysicsManager;
class Actor
{
public:
    Actor(int16 id, Transform const& transform);
    ~Actor();

    void Start();
    void Update();
    void OnInput(SDL_Event event);
    void Destroy();
    void AttachScene(Scene* pScene);
    void AttachPhysicsManager(PhysicsManager* m_pPhysicsManager);

    template <typename T, typename ... Args>
    void AddComponent(Args... args);

    template <typename T>
    void RemoveComponent();

    void SetActive(bool isActive);
    void SetTransform(Vector2f position, Vector2f size, float rotation);
    void AddTransform(Vector2f position = {0.0f, 0.0f}, Vector2f size = {0.0f, 0.0f}, float rotation = 0.0f);

    void OnCollisionEnter(Collider const* pCollider, Collider const* pOther);
    void OnCollision(Collider const* pCollider, Collider const* pOther);
    void OnCollisionExit(Collider const* pCollider, Collider const* pOther);

    int16 GetId() const;
    Transform2D const* GetTransform() const;

private:
    int16 m_id;
    ACTOR_STATE m_state;

    Scene* m_pScene;
    PhysicsManager* m_pPhysicsManager;
    uptr<Transform2D> m_pTransformComponent;
    std::vector<uptr<Component>> m_components;
};

}
#include "Actor.inl"

#endif
