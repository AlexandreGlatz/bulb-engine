#ifndef TEST_SCENE__H_
#define TEST_SCENE__H_

#include "Scene.h"
#include "Vector2.h"

class TestScene : public Scene
{
public:
    TestScene();
    ~TestScene();

    virtual void Start();
    virtual void Update();
    virtual void Render();
    virtual void OnInput(SDL_Event event);
    virtual void Close();

protected:
    Vector2f m_position;
};

#endif
