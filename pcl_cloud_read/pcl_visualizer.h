#ifndef PCL_VISUALIZER_H
#define PCL_VISUALIZER_H

#include <QMainWindow>
#include<QFileDialog>
#include<QString>
#include<QLabel>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<iostream>
#include<QDebug>
#include<QDir>
#include<QListWidgetItem>
#include<QProcess>
#include<QDirIterator>

#include<pcl/point_cloud.h>
#include<pcl/point_types.h>
#include <pcl/impl/point_types.hpp>
#include<pcl/visualization/pcl_visualizer.h>
#include<pcl/io/pcd_io.h>
#include<opencv2/opencv.hpp>


#include<vtkRenderWindow.h>


//using namespace cv;


typedef pcl::PointXYZRGBA PCLCloud_type;
//typedef pcl::PointXYZI pclBinType;


namespace Ui {
class pcl_visualizer;
}

class pcl_visualizer : public QMainWindow
{
    Q_OBJECT

public:
    explicit pcl_visualizer(QWidget *parent = 0);

    ~pcl_visualizer();


private slots:
    void onOpenpcl();
    void onOpenpic();
    void onOpenPicDir();
    void onPushPrevious();
    void onPushNext();
    void onOpenBin();
    void onOpenPcdDir();


private:
    Ui::pcl_visualizer *ui;
    pcl::PointCloud<PCLCloud_type>::Ptr cloud;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer; //初始化vtk部件
    void initialVtkWidget();
    cv::Mat image;
    int index;
    std::string filePicdir_str,filePcdDir_str;
    QStringList filter_pic,filter_pcd;
    QString load_file_path,load_pic_path;
    QDir dir_pic,dir_pcd;
    QFileInfoList listpcd,listpic;
    QString pcdFile,picFile;
    void show_pcd(QString filename_pcd);
    void show_pic(QString filename_pic);


};

#endif // PCL_VISUALIZER_H
