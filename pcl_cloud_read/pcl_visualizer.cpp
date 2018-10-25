#include "pcl_visualizer.h"
#include "ui_pcl_visualizer.h"

pcl_visualizer::pcl_visualizer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pcl_visualizer)
{
    ui->setupUi(this);
    initialVtkWidget();

    connect(ui->pushButton_pcl,SIGNAL(clicked()),this,SLOT(onOpenpcl()));
    connect(ui->pushButton_pic,SIGNAL(clicked()),this,SLOT(onOpenpic()));
    connect(ui->pushButton_dir,SIGNAL(clicked()),this,SLOT(onOpendir()));
    connect(ui->previous,SIGNAL(clicked()),this,SLOT(onPushPrevious()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(onPushNext()));
}

void pcl_visualizer::initialVtkWidget(){
    cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer",false));
    viewer->addPointCloud(cloud,"cloud");

    ui->qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setupInteractor(ui->qvtkWidget->GetInteractor(),ui->qvtkWidget->GetRenderWindow());
    ui->qvtkWidget->update();
}


pcl_visualizer::~pcl_visualizer()
{
    delete ui;
}

void pcl_visualizer::onOpenpcl()
{
    QString pcdName = QFileDialog::getOpenFileName(this,tr("Open PointCloud"),".",tr("Open PCD files(*.pcd)"));
    show_pcd(pcdName);
}

void pcl_visualizer::onOpenpic()
{
    QString picName = QFileDialog::getOpenFileName(this,tr("Open photo"),".",tr("Open photo files(*.pic *.png *.jpg *.jpeg *.bmp)"));
    show_pic(picName);

}

void pcl_visualizer::onOpendir(){
    QString filedir = QFileDialog::getExistingDirectory(this,tr("Open Directory"),"/media",QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    filedir_str = filedir.toStdString();
    std::cout<<filedir_str<<std::endl;
    //QDir dir(filedir);
    filter_pic << "*.jpg"<<"*.jpeg"<<"*.png";
    filter_pcd << "*.pcd";

    dir_pic.setPath(filedir);
    dir_pcd.setPath(filedir);

    dir_pic.setNameFilters(filter_pic);
    dir_pcd.setNameFilters(filter_pcd);
    listpcd = dir_pcd.entryInfoList();
    listpic = dir_pic.entryInfoList();
    if(listpcd.length()!=0)
    {
        //std::cout<<listpcd.length();
        index = 0;
        pcdFile = listpcd.at(index).fileName();
        picFile = listpic.at(index).fileName();
        show_pic(picFile);

//        int a=10000;
//        while(a--){}

        show_pcd(pcdFile);

    }

    else{
        qDebug()<<"no file";
    }

}

void pcl_visualizer::onPushNext(){
    if(index<listpcd.length()-1)
    {
        index++;
        pcdFile = listpcd.at(index).fileName();
        picFile = listpic.at(index).fileName();
        show_pic(picFile);
        show_pcd(pcdFile);
    }
    else {
        std::cout<<"You have looked all the files!"<<std::endl;
    }


}

void pcl_visualizer::onPushPrevious(){
    if(index>0)
    {
        index--;
        pcdFile = listpcd.at(index).fileName();
        picFile = listpic.at(index).fileName();
        show_pic(picFile);
        show_pcd(pcdFile);
    }
    else {
        std::cout<<"You are looking at the first file!"<<std::endl;
    }


}

void pcl_visualizer::show_pcd(QString filename_pcd){

    if(!filename_pcd.isEmpty())
    {
        std::string file_name = filename_pcd.toStdString();
        pcl::PCLPointCloud2 cloud2;
        Eigen::Vector4f origin;
        Eigen::Quaternionf orientation;
        int pcd_version;
        int data_type;
        unsigned int data_idx;
        int offset = 0;
        pcl::PCDReader rd;
        std::string file_abs_path = filedir_str + '/' + file_name;
        //rd.readHeader(file_name,cloud2,origin,orientation,pcd_version,data_type,data_idx);
        rd.readHeader(file_abs_path,cloud2,origin,orientation,pcd_version,data_type,data_idx);

        if(data_type ==0)
        {
            //pcl::io::loadPCDFile(filename_pcd.toStdString(),*cloud);
            pcl::io::loadPCDFile(file_abs_path,*cloud);
        }
        else if(data_type==2)
        {
            pcl::PCDReader reader;
            //reader.read<pcl::PointXYZ>(filename_pcd.toStdString(),*cloud);
            reader.read<pcl::PointXYZ>(file_abs_path,*cloud);
        }

        viewer->updatePointCloud(cloud,"cloud");
        viewer->resetCamera();
        ui->qvtkWidget->update();
    }

}

void pcl_visualizer::show_pic(QString filename_pic){

    image = cv::imread(filedir_str + '/' + filename_pic.toLatin1().data());
    cv::cvtColor(image,image,CV_BGR2RGB);
    cv::resize(image,image,cv::Size(420,350),(0,0),(0,0),cv::INTER_NEAREST);
    QImage img = QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
    ui->labelimage->setPixmap(QPixmap::fromImage(img));
    //ui->labelimage->resize(ui->labelimage->pixmap()->size());
}
