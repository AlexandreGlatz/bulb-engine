#ifndef TEST_SCENE__H_
#define TEST_SCENE__H_

#include <Core/Vector2.h>
#include <Engine/Scene.h>

class TestScene : public bulb::Scene
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
    bulb::Vector2f m_position;
};

#endif
