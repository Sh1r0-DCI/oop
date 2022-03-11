#ifndef MODEL_H
#define MODEL_H


#include <QString>
#include <QGraphicsScene>


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

    vertices_t center;
} model_t;


void draw_model(QGraphicsScene *scene, model_t model);
int download_model(model_t &model, QString str);
int parameter_read(FILE *f, model_t &new_model);
int file_load(QString filename, FILE *& f);
int rotate_model(model_t &model, vertices_t coef_angle);
int scale_model(model_t &model, vertices_t coef_scale);
int move_model(model_t &model, vertices_t coef_move);
void clear_model(model_t &model);

#endif // MODEL_H
