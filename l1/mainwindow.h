#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void draw_on_scene();

    void on_load_button_clicked();

    void on_lineEdit_filename_returnPressed();

    void on_scale_button_clicked();

    void on_move_button_clicked();

    void on_rotate_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
