#include "player.h"
#include "gameobject.h"
#include "projectile.h"
#include <raylib.h>
#include <raymath.h>
#include <iostream>
using namespace std;

Player::Player()
{
    position = { 64.0f, 64.0f };
    speed = 4;
    rotationInDegrees = 0.0f;
    mainSprite = LoadTexture("resources/sprites/ship/ship.png");
}

void Player::Update()
{
    HandleInput();
    HandleShooting();
    CheckShootCooldown();

    for (auto& projectile : projectiles) {
        projectile.Update();
    }
}

void Player::HandleInput()
{
    if (IsKeyDown(KEY_W)) position.y -= speed;
    if (IsKeyDown(KEY_S)) position.y += speed;
    if (IsKeyDown(KEY_A)) position.x -= speed;
    if (IsKeyDown(KEY_D)) position.x += speed;
}

void Player::CheckShootCooldown()
{
    shootTimerInSeconds -= GetFrameTime();
    if (shootTimerInSeconds <= 0.0f)
    {
        canShoot = true;
    }

}

void Player::HandleShooting()
{
    if (canShoot && IsKeyPressed(KEY_SPACE)) {
        //std::cout<<"shoot!";
        canShoot = false;
        shootTimerInSeconds = 0.25f;

        // todo: change this later.
        int magicNumber = 8 * SPRITE_SCALE; 
        Projectile projectile(Vector2{position.x + magicNumber, position.y - magicNumber}, 90.0f, 500.0f);
        //we need to add them to a buffer so they keep existing after this function ends
        projectiles.push_back(projectile);
    }
}


void Player::Draw() const
{
    GameObject::Draw();

    // Draw all active projectiles
    for (const auto& projectile : projectiles) {
        projectile.Draw();
    }
}   