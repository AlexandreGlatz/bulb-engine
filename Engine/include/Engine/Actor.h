#ifndef ACTOR__H_
#define ACTOR__H_

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
class Actor
{
public:
    Actor(int16 id, Transform const& transform);
    ~Actor();

    void Start();
    void Update();
    void Destroy();
    void AttachScene(Scene* pScene);

    template <typename T, typename ... Args>
    void AddComponent(Args... args);

    template <typename T>
    void RemoveComponent();

    void SetActive(bool isActive);
    void SetTransform(Vector2f position, Vector2f size, float rotation);

    int16 GetId() const;
    Transform2D const* GetTransform() const;

private:
    int16 m_id;
    ACTOR_STATE m_state;

    Scene* m_pScene;
    uptr<Transform2D> m_pTransformComponent;
    std::vector<uptr<Component>> m_components;
};

}
#include "Actor.inl"

#endif
