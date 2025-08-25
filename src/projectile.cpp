#include "gameobject.h"
#include "projectile.h"
#include <raylib.h>
#include <raymath.h>

Projectile::Projectile(Vector2 startPosition, float angle, float force)
{
    position = startPosition;
    speed = force;
    direction = angle; // default direction
    rotation = direction;
    mainSprite = LoadTexture("resources/sprites/projectiles/bullet_2.png");
    isActive = true;
}

void Projectile::Update()
{
    if (isActive) {
        //movement
        if (speed > 0.0f) {
            position.y -= speed;
        }

        //delete if off screen
        //TODO : create a game manager since we need to delete this projectile from the player buffer
        // but we cant do it from here, also thats bad practice and stupid
        if (position.y < -mainSprite.height * SPRITE_SCALE) {
            isActive = false;
        }
        
        Draw();
    }
}