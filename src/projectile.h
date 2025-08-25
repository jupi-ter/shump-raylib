#pragma once
#include "GameObject.h"

class Projectile : public GameObject
{
public:
    Projectile(Vector2 startPosition, float angle, float force);   // sets up defaults inside itself
    void Update() override;

protected:
    bool isActive = false;
};
