#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct vec2 
{
    // member variable(s)
    float_t x, y;
    // member function(s)
    void (*print)(const struct vec2* self);
    struct vec2 (*normalize)(struct vec2* self);
    struct vec2 (*add)(const struct vec2* self, const struct vec2* other);
    struct vec2 (*dot)(const struct vec2* self, const struct vec2* other);
    float_t (*abs)(struct vec2* self);
} vec2;



void       vec2_print(const vec2* self);
vec2       vec2_normalize(vec2* self);
float_t    vec2_abs(vec2* self);
vec2*      vec2_init(float_t x, float_t y);
