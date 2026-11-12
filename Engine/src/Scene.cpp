#include "Scene.h"
#include "Renderer.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::SetRenderer(sptr<Renderer> pRenderer)
{
    m_pRenderer = pRenderer;
}

void Scene::Start()
{
}

void Scene::Update()
{
}

void Scene::OnInput(SDL_Event event)
{
}

void Scene::Render()
{
}


void Scene::Close()
{
}
