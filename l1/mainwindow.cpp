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
//    scale_coef.y = ui->spinBox_scale_y->text().toDouble();
    sscanf(ui->spinBox_scale_y->text().toUtf8().constData(), "%lf", &scale_coef.y);
//    scale_coef.z = ui->spinBox_scale_z->text().toDouble();
    sscanf(ui->spinBox_scale_z->text().toUtf8().constData(), "%lf", &scale_coef.z);

   //output of things above
    QMessageBox::information(this, "scale_coef", ui->spinBox_scale_x->text());
    QMessageBox::information(this, "scale_coef real", QString::number(scale_coef.x)); //check for wrong convertation

    data_t only_coef;
    only_coef.coef = scale_coef;

    task_manager(SCALE, only_coef);

    draw_on_scene();
}

void MainWindow::on_move_button_clicked()
{
    vertices_t move_coef;
    move_coef.x = ui->spinBox_move_x->text().toDouble();
    move_coef.y = ui->spinBox_move_y->text().toDouble();
    move_coef.z = ui->spinBox_move_z->text().toDouble();

    data_t only_coef;
    only_coef.coef = move_coef;

    task_manager(SCALE, only_coef);

    draw_on_scene();
}

void MainWindow::on_rotate_button_clicked()
{
    vertices_t rotate_coef;
    rotate_coef.x = ui->spinBox_rot_x->text().toDouble();
    rotate_coef.y = ui->spinBox_rot_y->text().toDouble();
    rotate_coef.z = ui->spinBox_rot_z->text().toDouble();

    data_t only_coef;
    only_coef.coef = rotate_coef;

    task_manager(SCALE, only_coef);

    draw_on_scene();
}
