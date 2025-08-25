#pragma once
#include <raylib.h>

const int SPRITE_SCALE = 4;

class GameObject
{
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    virtual void Update() = 0;   // force subclasses to implement
    virtual void Draw() const {
        if (mainSprite.id != 0) {
            DrawTextureEx(mainSprite, position, rotationInDegrees, SPRITE_SCALE, WHITE);
        }
    }
    virtual Texture2D GetSprite() const { return mainSprite; }

protected:
    Vector2 position = {0.0f, 0.0f};
    float xScale = 1.0f;
    float yScale = 1.0f;
    float speed = 0.0f;
    float rotationInDegrees = 0.0f;
    float direction = 0.0f;
    Texture2D mainSprite {0};
};