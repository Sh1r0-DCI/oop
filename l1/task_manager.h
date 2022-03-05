#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "model.h"

enum Task
{
    DOWNLOAD,
    DRAW,
    MOVE,
    SCALE,
    ROTATE,
    CLEAR
};

typedef struct data
{
    QString filename;
    vertices_t coef;
    QGraphicsScene *scene;
}data_t;

int task_manager(Task task_name, data_t data);

#endif // TASK_MANAGER_H
