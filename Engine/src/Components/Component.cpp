#include "Components/Component.h"
#include "Actor.h"

namespace bulb
{

Component::Component(Actor* pOwner)
{
    m_pOwner = pOwner;
}

Component::~Component()
{
    m_pOwner = nullptr;
}

}
