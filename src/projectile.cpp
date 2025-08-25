#include "gameobject.h"
#include "projectile.h"
#include <raylib.h>
#include <raymath.h>

Projectile::Projectile()
{
    position = { 0.0f, 0.0f };
    speed = 0.0f;
    direction = 0.0f; // default direction
    rotation = 0.0f;
    mainSprite = LoadTexture("resources/sprites/projectiles/bullet_2.png");
}

void Projectile::Launch(Vector2 startPosition, float angle, float force)
{
    position = startPosition;
    speed = force;
    direction = angle;
    rotation = direction;
    isActive = true;
}

void Projectile::Update()
{
    if (isActive)
    {
        // Convert angle to radians for calculation
        float rad = DEG2RAD * direction;
        // Update position based on speed and direction
        position.x += cosf(rad) * speed;
        position.y += sinf(rad) * speed;

        /*/ deactivate if outside screen bounds
        if (position.x < 0 || position.x > GetScreenWidth() ||
            position.y < 0 || position.y > GetScreenHeight())
        {
            isActive = false;
            delete this;
        }*/
    }
}