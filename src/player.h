#pragma once
#include "GameObject.h"
#include "projectile.h"
#include <raylib.h>
#include <vector>
using namespace std;

class Player : public GameObject
{
public:
    Player();   // sets up defaults inside itself
    void Draw() const override;
    void Update() override;

protected:
    void HandleInput();
    void HandleShooting();
    void CheckShootCooldown();
    int health = 3;
    bool canShoot = true;
    float shootTimerInSeconds = 0.0f;

    vector<Projectile> projectiles; // Buffer to hold active projectiles
};
