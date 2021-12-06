#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "model_load.h"

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
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    int draw_model(model_t model);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
