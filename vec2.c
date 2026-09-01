#include "vec2.h"

static vec2 vec2_add(const vec2* self, const vec2* other) {
    vec2 result = { self->x + other->x, self->y + other->y };
    return result;
}

static vec2 vec2_dot(const vec2* self, const vec2* other) {
    vec2 result = { self->x * other->x + self->y * other->y, 0 };
    return result;
}

void vec2_print(const vec2* self) {
    printf("(%.2f, %.2f)\n", self->x, self->y);
}

vec2 vec2_normalize(vec2* self) {
    float_t len = sqrtf(self->x * self->x + self->y * self->y);
    vec2 result = { self->x / len, self->y / len };
    return result;
}

float_t vec2_abs(vec2* self) {
    return sqrtf(self->x * self->x + self->y * self->y);
}

vec2* vec2_init(float_t x, float_t y) {
    vec2* v = malloc(sizeof(vec2));
    v->x = x;
    v->y = y;
    v->print = vec2_print;
    v->normalize = vec2_normalize;
    v->add = vec2_add;
    v->dot = vec2_dot;
    v->abs = vec2_abs;
    return v;
}
