#include <math.h>
#include <stdio.h>
typedef struct vec3 
{
    // member variable(s)
    float_t x, y, z;
    // member function(s)
    void (*print)(const struct vec3* self);
    struct vec3 (*normalize)(struct vec3* self);
    struct vec3 (*add)(const struct vec3* self, const struct vec3* other);
    struct vec3 (*dot)(const struct vec3* self, const struct vec3* other);
    float_t (*abs)(struct vec3* self);
} vec3;


void       vec3_print(const vec3* self);
vec3       vec3_normalize(vec3* self);
float_t    vec3_abs(vec3* self);
vec3*      vec3_init(float_t x, float_t y, float_t z);
