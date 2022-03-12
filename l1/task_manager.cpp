#include "task_manager.h"
#include "error_codes.h"

int task_manager(Task task_name, data_t data)
{
    int rc = OK;
    static model_t model;

    switch (task_name)
    {
    case DOWNLOAD:
        rc = download_model(model, data.filename);
        break;
    case DRAW:
        rc = draw_model(data.scene, model);
        break;
    case MOVE:
        rc = move_model(model, data.coef);
        break;
    case SCALE:
        rc = scale_model(model,data.coef);
        break;
    case ROTATE:
        rc = rotate_model(model, data.coef);
        break;
    case CLEAR:
        clear_model(model);
        break;
    default:
        rc = UNKNOWN_ERROR;
    }

    return rc;
}
