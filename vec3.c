#include "vec3.h"
#include <stdlib.h>

void    vec3_print(const vec3* self)    { printf("Vector3(%f, %f, %f)", self->x, self->y, self->z);                                       }
vec3    normalize(vec3* self       )    { return (vec3) { self->x / vec3_abs(self), self->y / vec3_abs(self), self->z / vec3_abs(self) }; }
float_t vec3_abs (vec3* self       )    { return sqrt(pow(self->x, 2) + pow(self->y, 2) + pow(self->z, 2));                               }

vec3 vec3_add(const vec3* self, const vec3* other)
{
    return (vec3)
    {
        self->x + other->x,
        self->y + other->y,
        self->z + other->z,
    };
}

vec3* vec3_init(float_t x, float_t y, float_t z)
{
    vec3* self = (vec3*) malloc(sizeof(vec3));
    self->x = x; self->y = y; self->z = z;

    // binding implementation to definition
    self->print = vec3_print;
    self->abs = vec3_abs;
    self->normalize = vec3_normalize;
    self->add = vec3_add;

    return self;
}
