#ifndef SCENE__H_
#define SCENE__H_

#include "Core/Define.h"
#include <SDL2/SDL.h>

namespace bulb
{
class Renderer;
class Scene
{
public:
    Scene();
    ~Scene();

    void SetRenderer(sptr<Renderer> pRenderer);
    virtual void Start();
    virtual void Update();
    virtual void Render();
    virtual void OnInput(SDL_Event event);
    virtual void Close();

protected:
    sptr<Renderer> m_pRenderer;
};
}
#endif
