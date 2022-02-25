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

//static vertices_t x_rotate(vertices_t point, int angle)
//{
//    vertices_t temp_vert;
//    angle = deg_to_rad(angle);

//    const double alpha_rotate[3][3] = {
//        {1,  0,                      0},
//        {0,  cos(angle),   -sin(angle)},
//        {0,  sin(angle),    cos(angle)}
//    };

//    temp_vert = matrix_mult_vector(point, alpha_rotate);

//    return temp_vert;
//}

//static vertices_t y_rotate(vertices_t point, int angle)
//{
//    vertices_t temp_vert;
//    angle = deg_to_rad(angle);

//    const double beta_rotate[3][3] = {
//        {cos(angle),    0, sin(angle)},
//        {0,             1,          0},
//        {-sin(angle),   0, cos(angle)}
//    };

//    temp_vert = matrix_mult_vector(point, beta_rotate);

//    return temp_vert;
//}

//static vertices_t z_rotate(vertices_t point, int angle)
//{
//    angle = deg_to_rad(angle);

//    const double gamma_rotate[3][3] = {
//        {cos(angle), -sin(angle),    0},
//        {sin(angle), cos(angle),     0},
//        {0,          0,              1}
//    };

//    return matrix_mult_vector(point, gamma_rotate);
//}

static void x_rotate(vertices_t& point, const double angle) {
    double radians = deg_to_rad(angle);

    double temp_y = point.y;

    point.y = point.y * cos(radians) + point.z * sin(radians);
    point.z = -temp_y * sin(radians) + point.z * cos(radians);
}

static void y_rotate(vertices_t& point, const double angle) {
    double radians = deg_to_rad(angle);

    double temp_x = point.x;

    point.x = point.x * cos(radians) + point.z * sin(radians);
    point.z = -temp_x * sin(radians) + point.z * cos(radians);
}

static void z_rotate(vertices_t& point, const double angle) {
    double radians = deg_to_rad(angle);

    double temp_x = point.x;

    point.x = point.x * cos(radians) - point.y * sin(radians);
    point.y = temp_x * sin(radians) + point.y * cos(radians);
}

void point_rotate(vertices_t &point, int angle_x, int angle_y, int angle_z)
{
//    point = x_rotate(point, angle_x);
//    point = y_rotate(point, angle_y);
//    point = z_rotate(point, angle_z);
    x_rotate(point, angle_x);
    y_rotate(point, angle_y);
    z_rotate(point, angle_z);
}

void point_scale(vertices_t &point, vertices_t coef, vertices_t center)
{
//    std::cout << "vert in p_s: " <<
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
