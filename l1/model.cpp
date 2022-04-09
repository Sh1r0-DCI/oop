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

    if (model.edges == NULL || model.vertices == NULL)
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

int read_vertex(vertices_t &vertex, FILE *f)
{
    int rc = OK;

    if ((fscanf(f, "%lf %lf %lf", &vertex.x, &vertex.y, &vertex.z)) != 3)
    {
        rc = PARAM_ERROR;
    }

    return rc;
}

int read_vertices(vertices_t *const array, const int size, FILE *f)
{
    int rc = OK;

    for (int i = 0; rc == OK && i < size; i++)
    {
        rc = read_vertex(array[i], f);
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

int read_edge(edges_t &edge, FILE *f)
{
    int rc = OK;

    if ((fscanf(f, "%d %d", &edge.start_vert, &edge.end_vert)) != 2)
    {
        rc = PARAM_ERROR;
    }

    return rc;
}

int read_edges(edges_t *const array, const int &size, FILE *f)
{
    int rc = OK;

    for (int i = 0; rc == OK && i < size; i++)
    {
        rc = read_edge(array[i], f);
    }

    return rc;
}

int read_center(vertices_t &center, FILE *f)
{
    return fscanf(f, "%lf%lf%lf", &center.x,
                   &center.y, &center.z) != 3;
}

int vertices_allocation(vertices_t *&vertices, int num_of_vertices)
{
    int rc = OK;

    vertices = new vertices_t[num_of_vertices];

    if (vertices == NULL)
    {
        rc = ALLOC_ERROR;
    }

    return rc;
}

int handle_vertices(vertices_t *&vertices, int &num_of_vertices, FILE *f)
{
    int error_code = OK;

    if (!(error_code = read_num_of_verts(num_of_vertices, f)))
    {
        if (!(error_code = vertices_allocation(vertices, num_of_vertices)))
        {
            if ((error_code = read_vertices(vertices, num_of_vertices, f)))
            {
                clear_vertices(vertices);
            }
        }
    }

    return error_code;
}

int edges_allocation(edges_t *&edges, int num_of_edges)
{
    int rc = OK;

    edges = new edges_t[num_of_edges];

    if (edges == NULL)
    {
        rc = ALLOC_ERROR;
    }

    return rc;
}

int handle_edges(edges_t *&edges, int &num_of_edges, FILE *f)
{
     int error_code = OK;

     if (!(error_code = read_num_of_edges(num_of_edges, f)))
     {
         if (!(error_code = edges_allocation(edges, num_of_edges)))
         {
             if ((error_code = read_edges(edges, num_of_edges, f)))
             {
                 clear_edges(edges);
             }
         }
     }

     return error_code;
}

int load_temp_model(model_t &temp_model, FILE *f)
{
    int rc = OK;

    rc = handle_vertices(temp_model.vertices, temp_model.num_of_vertices, f);

    if (!rc)
    {
        rc = handle_edges(temp_model.edges, temp_model.num_of_edges, f);

        if (rc)
        {
            clear_vertices(temp_model.vertices);
        }
        else
        {
            rc = read_center(temp_model.center, f);

            if (rc)
            {
                clear_vertices(temp_model.vertices);
                clear_edges(temp_model.edges);
            }
        }
    }

    return rc;
}

int download_model(model_t &model, std::string str)
{
    FILE *f = NULL;
    int rc = OK;

    if (!(rc = file_open(str, f)))
    {
        model_t temp_model = init_model();
        rc = load_temp_model(temp_model, f);
        fclose(f);

        if (!rc)
        {
            clear_model(model);
            model = temp_model;
        }
    }

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
