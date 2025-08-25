#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
    Player();   // sets up defaults inside itself

    void Update() override;

protected:
    void HandleInput();
    void HandleShooting();
    void CheckShootCooldown();
    int health = 3;
    bool canShoot = true;
    float shootTimer = 0.0f;
};
