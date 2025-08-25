#include "gameobject.h"
#include "projectile.h"
#include <raylib.h>
#include <raymath.h>
#include <iostream>

Projectile::Projectile(Vector2 startPosition, float angle, float force)
{
    position = startPosition;
    speed = force;
    direction = angle; // default direction
    rotationInDegrees = direction;
    mainSprite = LoadTexture("resources/sprites/projectiles/bullet_2.png");
    isActive = true;
}

void Projectile::Update()
{
    if (isActive) {
        //angle

        float deltaTime = GetFrameTime();

        Vector2 movement = {
            cosf(DEG2RAD * rotationInDegrees) * speed * deltaTime,
            sinf(DEG2RAD * rotationInDegrees) * speed * deltaTime * -1.0f
        };
        
        position.x += movement.x;
        position.y += movement.y;

        //delete if off screen
        //TODO : create a game manager since we need to delete this projectile from the player buffer
        // but we cant do it from here, also thats bad practice and stupid
        if (position.y < -mainSprite.height * SPRITE_SCALE) {
            isActive = false;
        }
        
        Draw();
    }
}