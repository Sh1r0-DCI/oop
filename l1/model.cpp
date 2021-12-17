#include "model.h"

#include "error_codes.h"
#include "projection.h"

#define SCENE_HEIGHT 360

void draw_model(QGraphicsScene *scene, model_t model)
{
    for (int i = 0; i < model.num_of_edges; i++)
    {
        vertices_t first_point, second_point;

        first_point = model.vertices[model.edges[i].first_edge];
        second_point = model.vertices[model.edges[i].second_edge];

//        first_point = screen_projection(first_point);
        first_point.y = SCENE_HEIGHT - first_point.y;

//        second_point = screen_projection(second_point);
        second_point.y = SCENE_HEIGHT - second_point.y;

        scene->addLine(first_point.x, first_point.y,
                       second_point.x, second_point.y);
    }
}

int download_model(model_t &model, QString str)
{
    FILE *f = NULL;

    QMessageBox::information(NULL, "Открытие файла", "Открытие файла " + str);

    if (file_load(str, f))
    {
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при открытии файла");
        return FILE_ERROR;
    }

    if (parameter_read(f, model))
    {
        QMessageBox::critical(NULL, "Ошибка", "Ошибка при чтении файла");
        fclose(f);
        return PARAM_ERROR;
    }

    fclose(f);
}

int parameter_read(FILE *f, model_t &new_model)
{
    if (fscanf(f, "%d", &new_model.num_of_vertices) != 1)
    {
        return PARAM_ERROR;
    }

    new_model.vertices = new vertices_t[new_model.num_of_vertices];
    for (int i = 0; i < new_model.num_of_vertices; i++)
    {
        if(fscanf(f, "%lf%lf%lf", &new_model.vertices[i].x,
                  &new_model.vertices[i].y,
                  &new_model.vertices[i].z) != 3)
        {
            return PARAM_ERROR;
        }
    }

    if (fscanf(f, "%d", &new_model.num_of_edges) != 1)
    {
        return PARAM_ERROR;
    }

    new_model.edges = new  edges_t[new_model.num_of_edges];
    for (int i = 0; i < new_model.num_of_edges; i++)
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

int file_load(QString filename, FILE *& f)
{
    filename = "C:\\msys64\\home\\Sh1r0\\oop\\1st_try_l1\\l1\\data\\" + filename;
    f = fopen(filename.toUtf8().data(), "r");

    if (f == NULL)
    {
        std::cout << "File error\n";
        return FILE_ERROR;
    }

    return OK;
}

void scale_model(model_t &model, vertices_t coef_scale)
{
    for (int i = 0; i < model.num_of_vertices; i++)
    {
        point_scale(model.vertices[i], coef_scale, model.center);
    }
}

void move_model(model_t &model, vertices_t coef_move)
{
    for (int i = 0; i < model.num_of_vertices; i++)
    {
        point_move(model.vertices[i], coef_move);
    }
}

void rotate_model(model_t &model, vertices_t coef_angle)
{
    for (int i = 0; i < model.num_of_vertices; i++)
    {
        point_rotate(model.vertices[i],
                     coef_angle.x, coef_angle.y, coef_angle.z);
    }
}
