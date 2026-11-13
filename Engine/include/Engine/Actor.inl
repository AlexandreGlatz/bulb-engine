#include <memory>
#include <algorithm>
#include "Components/Component.h"

namespace bulb
{

template <typename T, typename ... Args>
void Actor::AddComponent(Args... args)
{
    m_components.push_back(std::make_unique<T>(this, args...));
    m_components[m_components.size() - 1]->AddToPhysicsManager(m_pPhysicsManager);
}

template <typename T>
void Actor::RemoveComponent()
{
    m_components.erase(std::remove_if(m_components.begin(), m_components.end(), 
        [](uptr<Component> pComponent) {return dynamic_cast<T*>(pComponent) != nullptr;}
    ));
}

}
