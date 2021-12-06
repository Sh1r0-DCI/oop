#ifndef MODEL_LOAD_H
#define MODEL_LOAD_H

#include <QString>

typedef struct vertices
{
    double x = 0;
    double y = 0;
    double z = 0;
}vertices_t;

typedef struct edges
{
    int first_edge = 0;
    int second_edge = 0;
}edges_t;

typedef struct model
{
    int num_of_vertices = 0;
    int num_of_edges = 0;

    vertices_t *vertices = 0;
    edges_t *edges = 0;
} model_t;

void output_model_array(model_t model);
int parameter_read(FILE *f, model_t &new_model);
int file_load(QString filename, FILE *& f);

#endif // MODEL_LOAD_H
