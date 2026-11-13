#include "Components/Transform2D.h"

namespace bulb
{

Transform2D::Transform2D(Actor* pOwner, Vector2f position, Vector2f size, float rotation)
: Component(pOwner),
m_position(position),
m_size(size),
m_rotation(rotation)
{

}

Transform2D::~Transform2D()
{
}

void Transform2D::OnStart()
{
}

void Transform2D::Update()
{
}

void Transform2D::OnEnd()
{
}

void Transform2D::SetPosition(Vector2f position)
{
    m_position = position;
}

void Transform2D::SetSize(Vector2f size)
{
    m_size = size;
}

void Transform2D::SetRotation(float rotation)
{
    m_rotation = rotation;
}

Vector2f Transform2D::GetPosition() const
{
    return m_position;
}

Vector2f Transform2D::GetSize() const
{
    return m_size;
}

float Transform2D::GetRotation() const
{
    return m_rotation;
}

void Transform2D::AddPosition(Vector2f position)
{
    SetPosition(m_position + position);
}

void Transform2D::AddSize(Vector2f size)
{
    SetSize(m_size + size);
}

void Transform2D::AddRotation(float rotation)
{
    SetRotation(m_rotation + rotation);
}

void Transform2D::OnInput(SDL_Event event)
{
}

}
