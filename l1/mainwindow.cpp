#include <QMessageBox>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "task_manager.h"

#include <string>
#include <iostream>
#include <cstdio>

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

int MainWindow::draw_on_scene()
{
    static QGraphicsScene *scene = ui->graphicsView->scene();
    scene->clear();

    data_t only_scene;
    only_scene.scene = scene;

    task_manager(DRAW, only_scene);

    return 0;
}

void MainWindow::on_load_button_clicked()
{
    QString str = (ui->lineEdit_filename->text());
    data_t only_filename;
    only_filename.filename = str;

    task_manager(DOWNLOAD, only_filename);

    draw_on_scene();
}

void MainWindow::on_lineEdit_filename_returnPressed()
{
    MainWindow::on_load_button_clicked();
}

void MainWindow::on_scale_button_clicked()          //need debug here
{
    vertices_t scale_coef;
    sscanf(ui->spinBox_scale_x->text().toUtf8().constData(), "%lf", &scale_coef.x);
    sscanf(ui->spinBox_scale_y->text().toUtf8().constData(), "%lf", &scale_coef.y);
    sscanf(ui->spinBox_scale_z->text().toUtf8().constData(), "%lf", &scale_coef.z);


    data_t only_coef;
    only_coef.coef = scale_coef;

    task_manager(SCALE, only_coef);

    draw_on_scene();
}

void MainWindow::on_move_button_clicked()
{
    vertices_t move_coef;
    sscanf(ui->spinBox_move_x->text().toUtf8().constData(), "%lf", &move_coef.x);
    sscanf(ui->spinBox_move_y->text().toUtf8().constData(), "%lf", &move_coef.y);
    sscanf(ui->spinBox_move_z->text().toUtf8().constData(), "%lf", &move_coef.z);


    QMessageBox::information(this, "move_cf", ui->spinBox_move_y->text());
    QMessageBox::information(this, "real move_cf", QString::number(move_coef.y));

    data_t only_coef;
    only_coef.coef = move_coef;

    task_manager(MOVE, only_coef);

    draw_on_scene();
}

void MainWindow::on_rotate_button_clicked()
{
    vertices_t rotate_coef;
    sscanf(ui->spinBox_rot_x->text().toUtf8().constData(), "%lf", &rotate_coef.x);
    sscanf(ui->spinBox_rot_y->text().toUtf8().constData(), "%lf", &rotate_coef.y);
    sscanf(ui->spinBox_rot_z->text().toUtf8().constData(), "%lf", &rotate_coef.z);

    data_t only_coef;
    only_coef.coef = rotate_coef;

    task_manager(ROTATE, only_coef);

    draw_on_scene();
}
