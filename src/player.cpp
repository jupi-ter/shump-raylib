#include "player.h"
#include "gameobject.h"
#include "projectile.h"
#include <raylib.h>
#include <raymath.h>
#include <iostream>

Player::Player()
{
    position = { 64.0f, 64.0f };
    speed = 4;
    rotation = 0.0f;
    mainSprite = LoadTexture("resources/sprites/ship/ship.png");
}

void Player::Update()
{
    HandleInput();
    HandleShooting();
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
    shootTimer -= GetFrameTime();
    if (shootTimer <= 0.0f)
    {
        canShoot = true;
    }

}

void Player::HandleShooting()
{
    if (canShoot && IsKeyPressed(KEY_SPACE)) {
        canShoot = false;
        shootTimer = 0.5f; // half a second cooldown

        Projectile* b = new Projectile();
        std::cout<<"shooting";
        b->Launch(position, 90, 10.0f);
    }
}
