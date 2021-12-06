#include <QMessageBox>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "projection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::draw_model(model_t model)
{
    QGraphicsScene *scene = ui->graphicsView->scene();
    scene->clear();

    for (int i = 0; i < model.num_of_edges; i++)
    {
        vertices_t first_point, second_point;

        first_point = model.vertices[model.edges[i].first_edge];
        second_point = model.vertices[model.edges[i].second_edge];

        first_point = screen_projection(first_point);
        first_point.y = ui->centralwidget->height() - first_point.y;

        second_point = screen_projection(second_point);
        second_point.y = ui->centralwidget->height() - second_point.y;

        scene->addLine(first_point.x, first_point.y,
                       second_point.x, second_point.y);
    }

    return 0;
}

void MainWindow::on_pushButton_clicked()//load_button
{
    FILE *f = NULL;
    model_t model;

    QString str = (ui->lineEdit->text());
    QMessageBox::information(this, "Открытие файла", str);
    if (file_load(str, f))
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка при открытии файла");
        return;
    }

    if (parameter_read(f, model))
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка при чтении файла");
        fclose(f);
        return;
    }

    draw_model(model);

    output_model_array(model);

    fclose(f);
}

void MainWindow::on_lineEdit_returnPressed()
{
    MainWindow::on_pushButton_clicked();
}
