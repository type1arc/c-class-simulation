// simulating classes in C

#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>

// define class using struct with forward declaration 
typedef struct Vector3 
{
    // member variable(s)
    float_t x, y, z;
    // member function(s)
    void (*print)(const struct Vector3* self);
    struct Vector3 (*normalize)(const struct Vector3* self);
    struct Vector3 (*add)(const struct Vector3* self, const struct Vector3* other);
    struct Vector3 (*dot)(const struct Vector3* self, const struct Vector3* other);
} Vector3; 

// implementation of member function(s) 
void Vector3_print(const Vector3* self) { printf("Vector3(%f, %f, %f)", self->x, self->y, self->z); }

Vector3 Vector3_normalize(const struct Vector3* self)
{
#define denominator sqrt(pow(self->x, 2) + pow(self->y, 2) + pow(self->z, 2))  
    return (Vector3) 
    {
        self->x / denominator,
        self->y / denominator,
        self->z / denominator,
    };
}

Vector3 Vector3_add(const Vector3* self, const Vector3* other) { return (Vector3) { self->x + other->x, self->y + other->y, self->z + other->z }; }
Vector3 Vector3_dot(const Vector3* self, const Vector3* other) { return (Vector3) { self->x * other->x, self->y * other->y, self->z * other->z }; }

// constructor
void* Vector3_init(float _x, float _y, float _z)
{
    Vector3* self = (Vector3*) malloc(sizeof(Vector3));
    self->x = _x; self->y = _y; self->z = _z;

    // binding implementation to definition
    self->print = Vector3_print;
}

// destructor
void Vector3_destroy(Vector3* self) { free(self); }

typedef struct rgba_array { uint8_t r; uint8_t g; uint8_t b; uint8_t a; } rgba_array;

uint32_t encode_rgba(uint8_t r, uint8_t g, uint8_t b, uint32_t a)
{
    return (uint32_t) 
    {  
        ((uint32_t)r << 24) | 
        ((uint32_t)g << 16) | 
        ((uint32_t)b << 8)  | 
        (uint32_t)a
    };
}

rgba_array extract_rgba(uint32_t color)
{
    return (rgba_array) { 
        (color >> 24) & 0xff, 
        (color >> 16) & 0xff, 
        (color >> 8)  & 0xff, 
        (color)       & 0xff 
    };

}

int main(int argc, char *argv[])
{
    Vector3* vector = Vector3_init(1.0f, -1.0f, 3.0f);
    vector->print(vector);
}
