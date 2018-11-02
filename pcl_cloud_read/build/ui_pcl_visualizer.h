/********************************************************************************
** Form generated from reading UI file 'pcl_visualizer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCL_VISUALIZER_H
#define UI_PCL_VISUALIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_pcl_visualizer
{
public:
    QWidget *centralWidget;
    QLabel *labelimage;
    QVTKWidget *qvtkWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_dir;
    QPushButton *pushButton_pic;
    QPushButton *pushButton_pcl;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *on_push_bin;
    QPushButton *on_push_bin_dir;
    QListWidget *listWidget;
    QPushButton *next;
    QPushButton *previous;
    QListWidget *listWidget_pic;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pcl_visualizer)
    {
        if (pcl_visualizer->objectName().isEmpty())
            pcl_visualizer->setObjectName(QStringLiteral("pcl_visualizer"));
        pcl_visualizer->resize(1225, 680);
        centralWidget = new QWidget(pcl_visualizer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelimage = new QLabel(centralWidget);
        labelimage->setObjectName(QStringLiteral("labelimage"));
        labelimage->setGeometry(QRect(320, 50, 441, 371));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(760, 40, 461, 391));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 0, 282, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_dir = new QPushButton(layoutWidget);
        pushButton_dir->setObjectName(QStringLiteral("pushButton_dir"));

        horizontalLayout->addWidget(pushButton_dir);

        pushButton_pic = new QPushButton(layoutWidget);
        pushButton_pic->setObjectName(QStringLiteral("pushButton_pic"));

        horizontalLayout->addWidget(pushButton_pic);

        pushButton_pcl = new QPushButton(layoutWidget);
        pushButton_pcl->setObjectName(QStringLiteral("pushButton_pcl"));

        horizontalLayout->addWidget(pushButton_pcl);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(330, 470, 452, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        on_push_bin = new QPushButton(centralWidget);
        on_push_bin->setObjectName(QStringLiteral("on_push_bin"));
        on_push_bin->setGeometry(QRect(330, 0, 99, 27));
        on_push_bin_dir = new QPushButton(centralWidget);
        on_push_bin_dir->setObjectName(QStringLiteral("on_push_bin_dir"));
        on_push_bin_dir->setGeometry(QRect(440, 0, 99, 27));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 40, 291, 201));
        next = new QPushButton(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(700, 470, 85, 27));
        previous = new QPushButton(centralWidget);
        previous->setObjectName(QStringLiteral("previous"));
        previous->setGeometry(QRect(335, 470, 85, 27));
        listWidget_pic = new QListWidget(centralWidget);
        listWidget_pic->setObjectName(QStringLiteral("listWidget_pic"));
        listWidget_pic->setGeometry(QRect(20, 250, 291, 211));
        pcl_visualizer->setCentralWidget(centralWidget);
        labelimage->raise();
        qvtkWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        on_push_bin->raise();
        on_push_bin_dir->raise();
        listWidget->raise();
        next->raise();
        previous->raise();
        listWidget_pic->raise();
        menuBar = new QMenuBar(pcl_visualizer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1225, 31));
        pcl_visualizer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pcl_visualizer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        pcl_visualizer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(pcl_visualizer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        pcl_visualizer->setStatusBar(statusBar);

        retranslateUi(pcl_visualizer);

        QMetaObject::connectSlotsByName(pcl_visualizer);
    } // setupUi

    void retranslateUi(QMainWindow *pcl_visualizer)
    {
        pcl_visualizer->setWindowTitle(QApplication::translate("pcl_visualizer", "pcl_visualizer", 0));
        labelimage->setText(QString());
        pushButton_dir->setText(QApplication::translate("pcl_visualizer", "open pic dir", 0));
        pushButton_pic->setText(QApplication::translate("pcl_visualizer", "open_pic", 0));
        pushButton_pcl->setText(QApplication::translate("pcl_visualizer", "open_pcd", 0));
        on_push_bin->setText(QApplication::translate("pcl_visualizer", "open_bin_file", 0));
        on_push_bin_dir->setText(QApplication::translate("pcl_visualizer", "open_pcd_dir", 0));
        next->setText(QApplication::translate("pcl_visualizer", "next", 0));
        previous->setText(QApplication::translate("pcl_visualizer", "previous", 0));
    } // retranslateUi

};

namespace Ui {
    class pcl_visualizer: public Ui_pcl_visualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCL_VISUALIZER_H
