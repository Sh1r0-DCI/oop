#ifndef PROJECTION_H
#define PROJECTION_H

#include "model.h"
#include "error_codes.h"

vertices_t screen_projection(vertices_t point);
void point_rotate(vertices_t &point, int angle_x, int angle_y, int angle_z);
void point_scale(vertices_t &point, vertices_t coef, vertices_t center);
void point_move(vertices_t &point, vertices_t coef);

#endif // PROJECTION_H
