#include <QStringBuilder>
#include <iostream>
#include <stdio.h>
#include <dir.h>

#include "model_load.h"
#include "error_codes.h"


void output_model_array(model_t model)
{
    std::cout << "\n____\\/model array output\\/____\n";

    std::cout << "num of verticies = " << model.num_of_vertices;
    for (int i = 0; i < model.num_of_vertices; i++)
        std::cout << "\n(" << (model.vertices[i].x)
                  << ";" << (model.vertices[i].y)
                  << ";" << (model.vertices[i].z);

    std::cout << "\n_________________\n";

    std::cout << "num of edges = " << model.num_of_edges;
    for (int i = 0; i < model.num_of_edges; i++)
        std::cout << "\n(" << (model.edges[i].first_edge)
                  << ";" << (model.edges[i].second_edge) << ")";

    std::cout << "\n____/\\model array output/\\____\n";
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
                  &new_model.vertices[i].y, &new_model.vertices[i].z) != 3)
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
        if(fscanf(f, "%d%d", &new_model.edges[i].first_edge,
                  &new_model.edges[i].second_edge) != 2)
        {
            return PARAM_ERROR;
        }
    }


    return OK;
}

int file_load(QString filename, FILE *& f)
{
    filename = "C:\\msys64\\home\\Sh1r0\\oop\\1st_try_l1\\l1\\data\\" + filename;
//    char full_filename[] = "C:\\msys64\\home\\Sh1r0\\oop\\1st_try_l1\\l1\\data\\cubeModel.txt";
//    std::cout << filename.toUtf8().data() << "\n";
//    std::cout << strcmp(filename.toUtf8().data(), full_filename) << "\n";
    f = fopen(filename.toUtf8().data(), "r"); // cubeModel.txt"

    if (f == NULL)
    {
        std::cout << "File error\n";
        return FILE_ERROR;
    }

    return OK;
}
