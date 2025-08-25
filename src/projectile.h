#pragma once
#include "GameObject.h"

class Projectile : public GameObject
{
public:
    Projectile();   // sets up defaults inside itself
    void Launch(Vector2 startPosition, float angle, float force);
    void Update() override;

protected:
    bool isActive = false;
};
