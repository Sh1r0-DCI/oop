#include "task_manager.h"
#include "error_codes.h"

int task_manager(Task task_name, data_t data)
{
    static model_t model;

    switch (task_name)
    {
    case DOWNLOAD:
        return download_model(model, data.filename);
        break;
    case DRAW:
        draw_model(data.scene, model);
        break;
    case MOVE:
        move_model(model, data.coef);
        break;
    case SCALE:
        scale_model(model,data.coef);
        break;
    case ROTATE:
        rotate_model(model, data.coef);
        break;
    case CLEAR:
        clear_model(model);
        break;
    default:
        return UNKNOWN_ERROR;
    }

    return OK;
}
