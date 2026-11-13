#include <memory>
#include <algorithm>

namespace bulb
{

template <typename T, typename ... Args>
void Actor::AddComponent(Args... args)
{
    m_components.push_back(std::make_unique<T>(this, args...));
}

template <typename T>
void Actor::RemoveComponent()
{
    m_components.erase(std::remove_if(m_components.begin(), m_components.end(), 
        [](uptr<Component> pComponent) {return dynamic_cast<T*>(pComponent) != nullptr;}
    ));
}

}
