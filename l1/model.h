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
    int start_vert = 0;
    int end_vert = 0;
}edges_t;

typedef struct model
{
    int num_of_vertices = 0;
    int num_of_edges = 0;

    vertices_t *vertices = NULL;
    edges_t *edges = NULL;

    vertices_t center;
} model_t;


model_t init_model();
void clear_model(model_t &model);
int draw_model(QGraphicsScene *scene, model_t model);
int download_model(model_t &model, std::string str);
int parameter_read(FILE *f, model_t &new_model);
int file_load(std::string filename, FILE *& f);
int rotate_model(model_t &model, vertices_t coef_angle);
int scale_model(model_t &model, vertices_t coef_scale);
int move_model(model_t &model, vertices_t coef_move);

#endif // MODEL_H
