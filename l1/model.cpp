#include "model.h"

#include "projection.h"

#define SCENE_HEIGHT 360


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

int download_model(model_t &model, std::string str)
{
    FILE *f = NULL;
    int rc = OK;

    rc = file_load(str, f);

    if (!rc)
    {
        rc = parameter_read(model, f);
    }

    fclose(f);
    return rc;
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

int vertices_read(vertices_t *&vertices, int &num_of_vertices, FILE *f)
{
    int rc = 3;

    if (!read_num_of_verts(num_of_vertices, f))
    {
        clear_vertices(vertices);
        vertices = new vertices_t[num_of_vertices];

        for (int i = 0; i < num_of_vertices && rc == 3; i++)
        {
            rc = fscanf(f, "%lf%lf%lf", &vertices[i].x,
                        &vertices[i].y,
                        &vertices[i].z);
        }
    }
    else
    {
        rc = 0;
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

int edges_read(edges_t *&edges, int &num_of_edges, FILE *f)
{
    int rc = 2;

    if (read_num_of_edges(num_of_edges, f))
    {
        clear_edges(edges);
        edges = new edges_t[num_of_edges];

        for (int i = 0; i < num_of_edges && rc == 2; i++)
        {
            rc = fscanf(f, "%d%d", &edges[i].start_vert,
                        &edges[i].end_vert);
        }
    }
    else
    {
        rc = 0;
    }

    return rc;
}

int center_read(vertices_t &center, FILE *f)
{
    return fscanf(f, "%lf%lf%lf", &center.x,
                   &center.y, &center.z);
}

int parameter_read(model_t &new_model, FILE *f)
{
    int rc = PARAM_ERROR;

    if(vertices_read(new_model.vertices, new_model.num_of_vertices, f) == 3)
    {
        if(edges_read(new_model.edges, new_model.num_of_edges, f) == 2)
        {
            if(center_read(new_model.center, f) == 3)
            {
                rc = OK;
            }
            else
            {
                clear_edges(new_model.edges);
                clear_vertices(new_model.vertices);     // no need in clearing???
            }
        }
        else
        {
            clear_edges(new_model.edges);
            clear_vertices(new_model.vertices);
        }
    }
    else
    {
        clear_vertices(new_model.vertices);             // else's too far from if
    }

    return rc;
}

int file_load(std::string filename, FILE *& f)
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
