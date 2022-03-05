#include <iostream>
#include <cmath>

#include "projection.h"

static double deg_to_rad(double deg)
{
    const double pi = 3.14159265359;

    return deg * pi / 180;
}

static void x_rotate(vertices_t& point, const double angle)
{
    double radians = deg_to_rad(angle);

    double temp_y = point.y;

    point.y = point.y * cos(radians) + point.z * sin(radians);
    point.z = -temp_y * sin(radians) + point.z * cos(radians);
}

static void y_rotate(vertices_t& point, const double angle)
{
    double radians = deg_to_rad(angle);

    double temp_x = point.x;

    point.x = point.x * cos(radians) + point.z * sin(radians);
    point.z = -temp_x * sin(radians) + point.z * cos(radians);
}

static void z_rotate(vertices_t& point, const double angle)
{
    double radians = deg_to_rad(angle);

    double temp_x = point.x;

    point.x = point.x * cos(radians) - point.y * sin(radians);
    point.y = temp_x * sin(radians) + point.y * cos(radians);
}

void point_rotate(vertices_t &point, int angle_x, int angle_y, int angle_z)
{
    x_rotate(point, angle_x);
    y_rotate(point, angle_y);
    z_rotate(point, angle_z);
}

void point_scale(vertices_t &point, vertices_t coef, vertices_t center)
{
    point.x = center.x + (point.x - center.x) * coef.x;
    point.y = center.y + (point.y - center.y) * coef.y;
    point.z = center.z + (point.z - center.z) * coef.z;
}

void point_move(vertices_t &point, vertices_t coef)
{
    point.x += coef.x;
    point.y += coef.y;
    point.z += coef.z;
}
