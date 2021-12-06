#include <iostream>
#include <cmath>

#include "projection.h"

static double deg_to_rad(double deg)
{
    const double pi = 3.14159265359;

    return deg * pi / 180;
}

static vertices_t matrix_mult(vertices_t point, const double rotate_matrix[3][3])
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
        1,  0,            0,
        0,  cos(angle),   -sin(angle),
        0,  sin(angle),   cos(angle)
    };

    temp_vert = matrix_mult(point, alpha_rotate);

    return temp_vert;
}

vertices_t y_rotate(vertices_t point, double angle)
{
    vertices_t temp_vert;
    angle = deg_to_rad(angle);

    const double beta_rotate[3][3] = {
        cos(angle),    0, sin(angle),
        0,                  1, 0,
        -sin(angle),   0, cos(angle)
    };

    temp_vert = matrix_mult(point, beta_rotate);

    return temp_vert;
}

vertices_t z_rotate(vertices_t point, double angle)
{
    vertices_t temp_vert;
    angle = deg_to_rad(angle);

    const double gamma_rotate[3][3] = {
        cos(angle), -sin(angle),    0,
        sin(angle), cos(angle),     0,
        0,          0,              1
    };

    temp_vert = matrix_mult(point, gamma_rotate);

    return temp_vert;
}

vertices_t screen_projection(vertices_t point)
{
    std::cout << "\n entered w/{" << point.x << ", " << point.y << ", " << point.z <<"}";

    double alpha_angle = 35/*asin(tan(deg_to_rad(40)))*/, beta_angle = 55; //alpha ->x; beta->y

//    double rotate_matrix[3][3];
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            rotate_matrix[i][j] = 0;
//            for (int t = 0; t < 3; t++)
//            {
//                rotate_matrix[i][j] += alpha_rotate[i][t] * beta_rotate[t][j];
//            }
//        }
//    }

//    const double rotate_matrix1[3][3] = {
//        1 / sqrt(2),  0,            -1 / sqrt(2),
//        1 / sqrt(6),  2 / sqrt(6),  1 / sqrt(6),
//        1 / sqrt(3),  -1 / sqrt(3),     1 / sqrt(3)
//    };

    vertices_t temp_vert;
//    temp_vert.x = rotate_matrix[0][0] * point.x +
//            rotate_matrix[0][1] * point.y +
//            rotate_matrix[0][2] * point.z;
//    std::cout << "\n got x = " << temp_vert.x << "; (rm = " << rotate_matrix[0][0];
//    temp_vert.y = rotate_matrix[1][0] * point.x +
//            rotate_matrix[1][1] * point.y +
//            rotate_matrix[1][2] * point.z;
//    std::cout << "\n got y = " << temp_vert.y;
//    temp_vert.z = rotate_matrix[2][0] * point.x +
//            rotate_matrix[2][1] * point.y +
//            rotate_matrix[2][2] * point.z;
//    temp_vert.z = 0;

//    std::cout << "\n {" << point.x << ", " << point.y << ", " << point.z <<
//                 "} transforms to --> {" << temp_vert.x << ", " << temp_vert.y << "}\n";
    temp_vert = x_rotate(point, alpha_angle);
    temp_vert = y_rotate(point, beta_angle);

    return temp_vert;
}
