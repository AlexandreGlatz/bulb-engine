#ifndef COMPONENT__H_
#define COMPONENT__H_

#include <Core/Define.h>

namespace bulb
{

class Actor;
class Component
{
public:
    Component(Actor* pOwner);
    virtual ~Component();

    virtual void OnStart() = 0;
    virtual void Update() = 0;
    virtual void OnEnd() = 0;

protected:
    bool m_isActive;
    int m_updateOrder;
    Actor* m_pOwner;
};

}

#endif
