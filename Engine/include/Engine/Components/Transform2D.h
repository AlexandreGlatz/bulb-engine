#ifndef TRANSFORM_2D__H_
#define TRANSFORM_2D__H_

#include "Component.h"

#include <Core/Vector2.h>

namespace bulb
{

class Transform2D : public Component
{
public:
    Transform2D(Actor* pOwner, Vector2f position, Vector2f size, float rotation);
    ~Transform2D() override;

    void OnStart() override;
    void Update() override;
    void OnEnd() override;
    void OnInput(SDL_Event event) override;

    void SetPosition(Vector2f position);
    void SetSize(Vector2f size);
    void SetRotation(float rotation);

    void AddPosition(Vector2f position);
    void AddSize(Vector2f size);
    void AddRotation(float rotation);

    Vector2f GetPosition() const;
    Vector2f GetSize() const;
    float GetRotation() const;

private:
    Vector2f m_position;
    Vector2f m_size;
    float m_rotation;

};

}
#endif
