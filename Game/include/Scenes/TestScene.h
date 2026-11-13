#ifndef TEST_SCENE__H_
#define TEST_SCENE__H_

#include <Core/Vector2.h>
#include <Engine/Scene.h>

class TestScene : public bulb::Scene
{
public:
    TestScene();
    ~TestScene();

    virtual void Start() override;
    virtual void Render() override;
    virtual void OnInput(SDL_Event event) override;
    virtual void Close() override;

protected:
    bulb::Vector2f m_position;
};

#endif
