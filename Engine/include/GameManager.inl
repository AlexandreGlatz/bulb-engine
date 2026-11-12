#include <memory>

template <typename T>
void GameManager::CreateScene()
{
    m_scenes.push_back(std::make_shared<T>());
}
