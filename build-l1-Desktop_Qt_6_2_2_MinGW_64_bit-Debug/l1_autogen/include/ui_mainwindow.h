/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit_filename;
    QLabel *label;
    QPushButton *load_button;
    QGroupBox *groupBox;
    QSpinBox *spinBox_rot_x;
    QSpinBox *spinBox_rot_y;
    QSpinBox *spinBox_rot_z;
    QPushButton *rotate_button;
    QDoubleSpinBox *spinBox_scale_x;
    QDoubleSpinBox *spinBox_scale_y;
    QDoubleSpinBox *spinBox_scale_z;
    QDoubleSpinBox *spinBox_move_x;
    QDoubleSpinBox *spinBox_move_y;
    QDoubleSpinBox *spinBox_move_z;
    QPushButton *move_button;
    QPushButton *scale_button;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1093, 491);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 740, 360));
        lineEdit_filename = new QLineEdit(centralwidget);
        lineEdit_filename->setObjectName(QString::fromUtf8("lineEdit_filename"));
        lineEdit_filename->setGeometry(QRect(10, 390, 210, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 370, 90, 16));
        QFont font;
        font.setPointSize(8);
        label->setFont(font);
        load_button = new QPushButton(centralwidget);
        load_button->setObjectName(QString::fromUtf8("load_button"));
        load_button->setGeometry(QRect(250, 370, 190, 50));
        load_button->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(780, 10, 291, 401));
        QFont font1;
        font1.setPointSize(10);
        groupBox->setFont(font1);
        spinBox_rot_x = new QSpinBox(groupBox);
        spinBox_rot_x->setObjectName(QString::fromUtf8("spinBox_rot_x"));
        spinBox_rot_x->setGeometry(QRect(20, 290, 61, 22));
        spinBox_rot_x->setMinimum(-359);
        spinBox_rot_x->setMaximum(359);
        spinBox_rot_x->setValue(0);
        spinBox_rot_y = new QSpinBox(groupBox);
        spinBox_rot_y->setObjectName(QString::fromUtf8("spinBox_rot_y"));
        spinBox_rot_y->setGeometry(QRect(110, 290, 61, 22));
        spinBox_rot_y->setMinimum(-359);
        spinBox_rot_y->setMaximum(359);
        spinBox_rot_z = new QSpinBox(groupBox);
        spinBox_rot_z->setObjectName(QString::fromUtf8("spinBox_rot_z"));
        spinBox_rot_z->setGeometry(QRect(200, 290, 61, 22));
        spinBox_rot_z->setMinimum(-359);
        spinBox_rot_z->setMaximum(359);
        rotate_button = new QPushButton(groupBox);
        rotate_button->setObjectName(QString::fromUtf8("rotate_button"));
        rotate_button->setGeometry(QRect(50, 330, 191, 28));
        spinBox_scale_x = new QDoubleSpinBox(groupBox);
        spinBox_scale_x->setObjectName(QString::fromUtf8("spinBox_scale_x"));
        spinBox_scale_x->setGeometry(QRect(20, 70, 62, 22));
        spinBox_scale_x->setFrame(true);
        spinBox_scale_x->setMinimum(-9999.000000000000000);
        spinBox_scale_x->setMaximum(9999.000000000000000);
        spinBox_scale_x->setSingleStep(0.100000000000000);
        spinBox_scale_x->setValue(1.000000000000000);
        spinBox_scale_y = new QDoubleSpinBox(groupBox);
        spinBox_scale_y->setObjectName(QString::fromUtf8("spinBox_scale_y"));
        spinBox_scale_y->setGeometry(QRect(110, 70, 62, 22));
        spinBox_scale_y->setMinimum(-9999.000000000000000);
        spinBox_scale_y->setMaximum(9999.000000000000000);
        spinBox_scale_y->setSingleStep(0.100000000000000);
        spinBox_scale_y->setValue(1.000000000000000);
        spinBox_scale_z = new QDoubleSpinBox(groupBox);
        spinBox_scale_z->setObjectName(QString::fromUtf8("spinBox_scale_z"));
        spinBox_scale_z->setGeometry(QRect(200, 70, 62, 22));
        spinBox_scale_z->setMinimum(-9999.000000000000000);
        spinBox_scale_z->setMaximum(9999.000000000000000);
        spinBox_scale_z->setSingleStep(0.100000000000000);
        spinBox_scale_z->setValue(1.000000000000000);
        spinBox_move_x = new QDoubleSpinBox(groupBox);
        spinBox_move_x->setObjectName(QString::fromUtf8("spinBox_move_x"));
        spinBox_move_x->setGeometry(QRect(20, 180, 62, 22));
        spinBox_move_x->setMinimum(-9999.000000000000000);
        spinBox_move_x->setMaximum(9999.989999999999782);
        spinBox_move_x->setSingleStep(0.100000000000000);
        spinBox_move_y = new QDoubleSpinBox(groupBox);
        spinBox_move_y->setObjectName(QString::fromUtf8("spinBox_move_y"));
        spinBox_move_y->setGeometry(QRect(110, 180, 62, 22));
        spinBox_move_y->setMinimum(-9999.000000000000000);
        spinBox_move_y->setMaximum(9999.000000000000000);
        spinBox_move_y->setSingleStep(0.100000000000000);
        spinBox_move_z = new QDoubleSpinBox(groupBox);
        spinBox_move_z->setObjectName(QString::fromUtf8("spinBox_move_z"));
        spinBox_move_z->setGeometry(QRect(200, 180, 62, 22));
        spinBox_move_z->setMinimum(-9999.000000000000000);
        spinBox_move_z->setMaximum(9999.000000000000000);
        spinBox_move_z->setSingleStep(0.100000000000000);
        move_button = new QPushButton(groupBox);
        move_button->setObjectName(QString::fromUtf8("move_button"));
        move_button->setGeometry(QRect(50, 220, 191, 28));
        scale_button = new QPushButton(groupBox);
        scale_button->setObjectName(QString::fromUtf8("scale_button"));
        scale_button->setGeometry(QRect(50, 110, 191, 28));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 40, 271, 111));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 150, 271, 111));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 260, 271, 111));
        groupBox_4->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        spinBox_rot_x->raise();
        spinBox_rot_y->raise();
        spinBox_rot_z->raise();
        rotate_button->raise();
        spinBox_scale_x->raise();
        spinBox_scale_y->raise();
        spinBox_scale_z->raise();
        spinBox_move_x->raise();
        spinBox_move_y->raise();
        spinBox_move_z->raise();
        move_button->raise();
        scale_button->raise();
        MainWindow->setCentralWidget(centralwidget);
        groupBox->raise();
        graphicsView->raise();
        lineEdit_filename->raise();
        label->raise();
        load_button->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1093, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_filename->setText(QCoreApplication::translate("MainWindow", "cubeModel.txt", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260", nullptr));
        load_button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        rotate_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        move_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        scale_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
