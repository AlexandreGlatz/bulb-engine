#ifndef CONTROLLER__H_
#define CONTROLLER__H_

#include <Engine/Components/Component.h>
#include <Core/Vector2.h>

class Controller : public bulb::Component
{
public:
    Controller(bulb::Actor* pOwner);
    ~Controller() override;

    void OnStart() override;
    void Update() override;
    void OnEnd() override;
    void OnInput(SDL_Event event) override;

    void OnCollisionEnter(bulb::Collider const* pCollider, bulb::Collider const* pOther) override;

private:
    bulb::Vector2f m_direction;
    int16 m_inputAmount;
};

#endif
