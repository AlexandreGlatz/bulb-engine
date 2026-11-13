#include <memory>

namespace bulb
{

template <typename T>
T* GameManager::CreateScene()
{
    m_scenes.push_back(std::make_unique<T>());
    return static_cast<T*>(m_scenes[m_scenes.size() - 1].get());
}

}
