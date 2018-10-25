#include "pcl_visualizer.h"
#include <QApplication>
#include<QDir>
#include<QDebug>
#include<QString>
#include<QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QDir mdir("/media/ttzhou/documents/pic");
//    //mdir.cd("/media/ttzhou/documents/pic");
//    QStringList filter;
//    filter<<"*.pcd";
//    QFileInfoList files = mdir.entryInfoList(filter,QDir::Files);
//    for(int i=0;i<files.count();i++)
//    {
//        qDebug()<<"filename"<<files.at(i).fileName();
//    }
    pcl_visualizer w;
    w.show();
//    qDebug()<<mdir.exists();
//    foreach(QFileInfo mItem,mdir.drives())
//    {
//        qDebug()<<mItem.absoluteFilePath();
//    }

    return a.exec();
}
