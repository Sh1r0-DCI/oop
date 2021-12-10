#include <iostream>
#include <cmath>

#include "projection.h"

static double deg_to_rad(double deg)
{
    const double pi = 3.14159265359;

    return deg * pi / 180;
}

static vertices_t matrix_mult_vector(vertices_t point, const double rotate_matrix[3][3])
{
    vertices_t temp_vert;
    temp_vert.x = rotate_matrix[0][0] * point.x +
            rotate_matrix[0][1] * point.y +
            rotate_matrix[0][2] * point.z;
    temp_vert.y = rotate_matrix[1][0] * point.x +
            rotate_matrix[1][1] * point.y +
            rotate_matrix[1][2] * point.z;
    temp_vert.z = rotate_matrix[2][0] * point.x +
            rotate_matrix[2][1] * point.y +
            rotate_matrix[2][2] * point.z;

    return temp_vert;
}

vertices_t x_rotate(vertices_t point, double angle)
{
    vertices_t temp_vert;
    angle = deg_to_rad(angle);

    const double alpha_rotate[3][3] = {
        {1,  0,                      0},
        {0,  cos(angle),   -sin(angle)},
        {0,  sin(angle),    cos(angle)}
    };

    temp_vert = matrix_mult_vector(point, alpha_rotate);

    return temp_vert;
}

vertices_t y_rotate(vertices_t point, double angle)
{
    vertices_t temp_vert;
    angle = deg_to_rad(angle);

    const double beta_rotate[3][3] = {
        {cos(angle),    0, sin(angle)},
        {0,             1,          0},
        {-sin(angle),   0, cos(angle)}
    };

    temp_vert = matrix_mult_vector(point, beta_rotate);

    return temp_vert;
}

vertices_t z_rotate(vertices_t point, double angle)
{
    vertices_t temp_vert;
    angle = deg_to_rad(angle);

    const double gamma_rotate[3][3] = {
        {cos(angle), -sin(angle),    0},
        {sin(angle), cos(angle),     0},
        {0,          0,              1}
    };

    temp_vert = matrix_mult_vector(point, gamma_rotate);

    return temp_vert;
}

vertices_t screen_projection(vertices_t point)
{
    double alpha_angle = 35, beta_angle = 55;

    vertices_t temp_vert = point;

    temp_vert = y_rotate(temp_vert, beta_angle);
    temp_vert = x_rotate(temp_vert, alpha_angle);

    return temp_vert;
}
