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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_dir;
    QPushButton *pushButton_pic;
    QPushButton *pushButton_pcl;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *previous;
    QSpacerItem *horizontalSpacer;
    QPushButton *next;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pcl_visualizer)
    {
        if (pcl_visualizer->objectName().isEmpty())
            pcl_visualizer->setObjectName(QStringLiteral("pcl_visualizer"));
        pcl_visualizer->resize(945, 543);
        centralWidget = new QWidget(pcl_visualizer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelimage = new QLabel(centralWidget);
        labelimage->setObjectName(QStringLiteral("labelimage"));
        labelimage->setGeometry(QRect(-4, 36, 441, 371));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(440, 30, 461, 381));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 0, 269, 29));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_dir = new QPushButton(widget);
        pushButton_dir->setObjectName(QStringLiteral("pushButton_dir"));

        horizontalLayout->addWidget(pushButton_dir);

        pushButton_pic = new QPushButton(widget);
        pushButton_pic->setObjectName(QStringLiteral("pushButton_pic"));

        horizontalLayout->addWidget(pushButton_pic);

        pushButton_pcl = new QPushButton(widget);
        pushButton_pcl->setObjectName(QStringLiteral("pushButton_pcl"));

        horizontalLayout->addWidget(pushButton_pcl);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(130, 440, 452, 29));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        previous = new QPushButton(widget1);
        previous->setObjectName(QStringLiteral("previous"));

        horizontalLayout_2->addWidget(previous);

        horizontalSpacer = new QSpacerItem(268, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        next = new QPushButton(widget1);
        next->setObjectName(QStringLiteral("next"));

        horizontalLayout_2->addWidget(next);

        pcl_visualizer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(pcl_visualizer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 945, 31));
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
        pushButton_dir->setText(QApplication::translate("pcl_visualizer", "open dir", 0));
        pushButton_pic->setText(QApplication::translate("pcl_visualizer", "open_pic", 0));
        pushButton_pcl->setText(QApplication::translate("pcl_visualizer", "open_pcd", 0));
        previous->setText(QApplication::translate("pcl_visualizer", "previous", 0));
        next->setText(QApplication::translate("pcl_visualizer", "next", 0));
    } // retranslateUi

};

namespace Ui {
    class pcl_visualizer: public Ui_pcl_visualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCL_VISUALIZER_H
