#include <iostream>
#include <cmath>

#include "projection.h"

static double deg_to_rad(double deg)
{
    const double pi = 3.14159265359;

    return deg * pi / 180;
}

vertices_t screen_projection(vertices_t point)
{
    std::cout << "\n entered w/{" << point.x << ", " << point.y << ", " << point.z <<"}";

    double alpha_angle = deg_to_rad(35)/*asin(tan(deg_to_rad(40)))*/, beta_angle = deg_to_rad(55); //alpha ->x; beta->y

    const double alpha_rotate[3][3] = {
        1,  0,                   0,
        0,  cos(alpha_angle),    sin(alpha_angle),
        0,  -sin(alpha_angle),   cos(alpha_angle)
    };

    const double beta_rotate[3][3] = {
        cos(beta_angle),    0, -sin(beta_angle),
        0,                  1, 0,
        sin(beta_angle),    0, cos(beta_angle)
    };

    double rotate_matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            rotate_matrix[i][j] = 0;
            for (int t = 0; t < 3; t++)
            {
                rotate_matrix[i][j] += alpha_rotate[i][t] * beta_rotate[t][j];
            }
        }
    }

    const double rotate_matrix1[3][3] = {
        1 / sqrt(2),  0,            -1 / sqrt(2),
        1 / sqrt(6),  2 / sqrt(6),  1 / sqrt(6),
        1 / sqrt(3),  -1 / sqrt(3),     1 / sqrt(3)
    };

    vertices_t temp_vert;
    temp_vert.x = rotate_matrix[0][0] * point.x +
            rotate_matrix[0][1] * point.y +
            rotate_matrix[0][2] * point.z;
    std::cout << "\n got x = " << temp_vert.x << "; (rm = " << rotate_matrix[0][0];
    temp_vert.y = rotate_matrix[1][0] * point.x +
            rotate_matrix[1][1] * point.y +
            rotate_matrix[1][2] * point.z;
    std::cout << "\n got y = " << temp_vert.y;
//    temp_vert.z = rotate_matrix[2][0] * point.x +
//            rotate_matrix[2][1] * point.y +
//            rotate_matrix[2][2] * point.z;
    temp_vert.z = 0;

    std::cout << "\n {" << point.x << ", " << point.y << ", " << point.z <<
                 "} transforms to --> {" << temp_vert.x << ", " << temp_vert.y << "}\n";

    return temp_vert;
}
