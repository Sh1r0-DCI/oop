#include "model.h"

#include "projection.h"

#define SCENE_HEIGHT 360


#include <iostream>

model_t init_model()
{
    model_t model;

    model.num_of_vertices = 0;
    model.num_of_edges = 0;

    model.vertices = NULL;
    model.edges = NULL;

    model.center.x = 0;
    model.center.y = 0;
    model.center.z = 0;

    return model;
}

void clear_vertices(vertices_t *&vertices)
{
    delete [] vertices;

    vertices = NULL;
}

void clear_edges(edges_t *&edges)
{
    delete [] edges;

    edges = NULL;
}

void clear_model(model_t &model)
{
    clear_vertices(model.vertices);
    clear_edges(model.edges);
}

int draw_model(QGraphicsScene *scene, model_t model)
{
    if (!scene)
    {
        return UNKNOWN_ERROR;
    }

    if (model.edges == 0 || model.vertices == 0)
    {
        return MODEL_ERROR;
    }

    for (int i = 0; i < model.num_of_edges; i++)
    {
        vertices_t first_point, second_point;

        first_point = model.vertices[model.edges[i].start_vert];
        second_point = model.vertices[model.edges[i].end_vert];

        first_point.y = SCENE_HEIGHT - first_point.y;
        second_point.y = SCENE_HEIGHT - second_point.y;

        scene->addLine(first_point.x, first_point.y,
                       second_point.x, second_point.y);
    }

    return OK;
}

int read_num_of_verts(int &num_of_vertices, FILE *f)
{
    int rc = OK;

    if (fscanf(f, "%d", &num_of_vertices) != 1)
    {
        rc = PARAM_ERROR;
    }

    return rc;
}

int read_vertices(vertices_t *const array, const int size, FILE *f)
{
    int rc = OK;
    int num_of_read_values = 3;

    for (int i = 0; i < size && num_of_read_values == 3; i++)
    {
        if ((fscanf(f, "%lf %lf %lf", &array[i].x, &array[i].y, &array[i].z)) != 3)
        {
            rc = PARAM_ERROR;
        }
    }

    return rc;
}

int read_num_of_edges(int &num_of_edges, FILE *f)
{
    int rc = OK;

    if (fscanf(f, "%d", &num_of_edges) != 1)
    {
        rc = PARAM_ERROR;
    }

    return rc;
}

//int read_edges(edges_t *&edges, int &num_of_edges, FILE *f)
//{
//    int rc = 2;

//    if (read_num_of_edges(num_of_edges, f))
//    {
//        clear_edges(edges);
//        edges = new edges_t[num_of_edges];

//        for (int i = 0; i < num_of_edges && rc == 2; i++)
//        {
//            rc = fscanf(f, "%d%d", &edges[i].start_vert,
//                        &edges[i].end_vert);
//        }
//    }
//    else
//    {
//        rc = 0;
//    }

//    return rc;
//}

int read_edges(edges_t *const array, const int &size, FILE *f)
{
    int rc = OK;
    int num_of_read_values = 2;

    for (int i = 0; i < size && num_of_read_values == 2; i++)
    {
        if ((fscanf(f, "%d %d", &array[i].start_vert, &array[i].end_vert)) != 2)
        {
            rc = PARAM_ERROR;
        }
    }

    return rc;
}

int read_center(vertices_t &center, FILE *f)
{
    return fscanf(f, "%lf%lf%lf", &center.x,
                   &center.y, &center.z) != 3;
}

int handle_vertices(vertices_t *&vertices, int &num_of_vertices, FILE *f)
{
    int error_code = OK;

    if ((error_code = read_num_of_verts(num_of_vertices, f)))
    {
        return error_code;
    }

    vertices = new vertices_t[num_of_vertices];

    if ((error_code = read_vertices(vertices, num_of_vertices, f)))
    {
        clear_vertices(vertices);
    }

    return error_code;
}

int handle_edges(edges_t *&edges, int &num_of_edges, FILE *f)
{
     int error_code = OK;

     if ((error_code = read_num_of_edges(num_of_edges, f)))
     {
         return error_code;
     }

     edges = new edges_t[num_of_edges];

     if ((error_code = read_edges(edges, num_of_edges, f)))
     {
         clear_edges(edges);
     }

     return error_code;
}

int load_temp_model(model_t &temp_model, FILE *f)
{
    int rc = OK;

    if ((rc = handle_vertices(temp_model.vertices, temp_model.num_of_vertices, f)))
    {
        return rc;
    }

    if ((rc = handle_edges(temp_model.edges, temp_model.num_of_edges, f)))
    {
        clear_vertices(temp_model.vertices);
        return rc;
    }

    if ((rc = read_center(temp_model.center, f)))
    {
        clear_vertices(temp_model.vertices);
        clear_edges(temp_model.edges);
    }

    return rc;
}

int download_model(model_t &model, std::string str)
{
    FILE *f = NULL;
    int rc = OK;

    if ((rc = file_open(str, f)))
    {
        return rc;
    }

    model_t temp_model = init_model();

    if (!(rc = load_temp_model(temp_model, f)))
    {
        clear_model(model);
        model = temp_model;
    }

    fclose(f);
    std::cout << rc << std::endl;
    return rc;
}

int file_open(std::string filename, FILE *& f)
{
    int rc = OK;

    filename = "C:\\Users\\ASUS\\Documents\\GitHub\\oop\\l1\\data\\" + filename;
    f = fopen(filename.c_str(), "r");

    if (f == NULL)
    {
        rc = FILE_ERROR;
    }

    return rc;
}

int scale_model(model_t &model, vertices_t coef_scale)
{
    if (model.edges == 0 || model.vertices == 0)
    {
        return MODEL_ERROR;
    }

    for (int i = 0; i < model.num_of_vertices; i++)
    {
        point_scale(model.vertices[i], coef_scale, model.center);
    }

    return OK;
}

int move_model(model_t &model, vertices_t coef_move)
{
    if (model.edges == 0 || model.vertices == 0)
    {
        return MODEL_ERROR;
    }

    for (int i = 0; i < model.num_of_vertices; i++)
    {
        point_move(model.vertices[i], coef_move);
    }

    return OK;
}

int rotate_model(model_t &model, vertices_t coef_angle)
{
    if (model.edges == 0 || model.vertices == 0)
    {
        return MODEL_ERROR;
    }

    for (int i = 0; i < model.num_of_vertices; i++)
    {
        point_rotate(model.vertices[i],
                     coef_angle.x, coef_angle.y, coef_angle.z);
    }

    return OK;
}
