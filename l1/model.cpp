#include "model.h"

#include "projection.h"

#define SCENE_HEIGHT 360

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

        first_point = model.vertices[model.edges[i].first_edge];
        second_point = model.vertices[model.edges[i].second_edge];

        first_point.y = SCENE_HEIGHT - first_point.y;
        second_point.y = SCENE_HEIGHT - second_point.y;

        scene->addLine(first_point.x, first_point.y,
                       second_point.x, second_point.y);
    }

    return OK;
}

int download_model(model_t &model, QString str) // Qstring - ?
{
    FILE *f = NULL;
    int rc = OK;

    rc = file_load(str, f);

    if (!rc)
    {
        rc = parameter_read(f, model);
    }

    fclose(f);
    return rc;
}

int parameter_read(FILE *f, model_t &new_model) // уровни абстракции, выход из цикла, модель - вар параметр, утечка при ошибке
{
    int rc = 0;

    rc = fscanf(f, "%d", &new_model.num_of_vertices);

    if (rc != 1)
    {
        return PARAM_ERROR;
    }

    new_model.vertices = new vertices_t[new_model.num_of_vertices];

    for (int i = 0; i < new_model.num_of_vertices; i++) // вынести на уровень ниже?
    {
        rc = fscanf(f, "%lf%lf%lf", &new_model.vertices[i].x,
                    &new_model.vertices[i].y,
                    &new_model.vertices[i].z);
        if(rc != 3)
        {
            return PARAM_ERROR;
        }
    }

    if (fscanf(f, "%d", &new_model.num_of_edges) != 1)
    {
        return PARAM_ERROR;
    }

    new_model.edges = new  edges_t[new_model.num_of_edges];
    for (int i = 0; i < new_model.num_of_edges; i++) // вынос
    {
        if (fscanf(f, "%d%d", &new_model.edges[i].first_edge,
                  &new_model.edges[i].second_edge) != 2)
        {
            return PARAM_ERROR;
        }
    }

    if (fscanf(f, "%d%d%d", &new_model.center.x,
               &new_model.center.y, &new_model.center.z) != 3)
    {
        return PARAM_ERROR;
    }

    return OK;
}

int file_load(QString filename, FILE *& f) // Qstring - ?
{
    filename = "C:\\Users\\ASUS\\Documents\\GitHub\\oop\\l1\\data\\" + filename;
    f = fopen(filename.toUtf8().data(), "r");

    if (f == NULL)
    {
        return FILE_ERROR;
    }

    return OK;
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

void clear_model(model_t &model)
{
    delete [] model.vertices;
    delete [] model.edges;

    model.vertices = NULL;
    model.edges = NULL;
}
