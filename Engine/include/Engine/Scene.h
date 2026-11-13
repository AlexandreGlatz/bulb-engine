#ifndef SCENE__H_
#define SCENE__H_

#include <vector>
#include <queue>
#include <SDL2/SDL.h>
#include "Core/Define.h"

namespace bulb
{

struct Transform;
class Actor;
class Renderer;
class Collider;
class Scene
{
public:
    Scene();
    ~Scene();

    void SetRenderer(sptr<Renderer> pRenderer);

    Actor* SpawnActor(Transform const& transform);
    void DestroyActor(Actor* pActor);

    void AddCollider(Collider* pCollider);
    void CheckCollisions();

    virtual void Start();
    virtual void Update();
    virtual void PhysicStep();
    virtual void Render();
    virtual void OnInput(SDL_Event event);
    virtual void Close();

protected:
    void CreateActors();
    void DestroyActors();

protected:
    int m_actorId;
    sptr<Renderer> m_pRenderer;

    std::vector<uptr<Actor>> m_actors;

    std::queue<uptr<Actor>> m_toDestroy;
    std::queue<uptr<Actor>> m_toCreate;
    std::vector<Collider*> m_colliders;
};

}

#endif
