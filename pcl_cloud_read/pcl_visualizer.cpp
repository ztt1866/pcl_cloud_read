#include "pcl_visualizer.h"
#include "ui_pcl_visualizer.h"

pcl_visualizer::pcl_visualizer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pcl_visualizer)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/lcas_logo.png"));
    this->setWindowTitle("L-CAS Cloud Annotation Tool");
    load_file_path = std::getenv("HOME");
    load_pic_path = std::getenv("HOME");
    initialVtkWidget();

    connect(ui->pushButton_pcl,SIGNAL(clicked()),this,SLOT(onOpenpcl()));
    connect(ui->pushButton_pic,SIGNAL(clicked()),this,SLOT(onOpenpic()));
    connect(ui->pushButton_dir,SIGNAL(clicked()),this,SLOT(onOpenPicDir()));
    connect(ui->previous,SIGNAL(clicked()),this,SLOT(onPushPrevious()));
    connect(ui->next,SIGNAL(clicked()),this,SLOT(onPushNext()));
    connect(ui->on_push_bin,SIGNAL(clicked()),this,SLOT(onOpenBin()));
    connect(ui->on_push_bin_dir,SIGNAL(clicked()),this,SLOT(onOpenPcdDir()));
}

void pcl_visualizer::initialVtkWidget(){
    cloud.reset(new pcl::PointCloud<PCLCloud_type>);
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

void pcl_visualizer::onOpenBin()
{
    QString binName = QFileDialog::getOpenFileName(this,tr("Open binName"),".",tr("Open Bin Files(*.bin)"));
    show_pcd(binName);

}

void pcl_visualizer::onOpenPcdDir()
{
    ui->listWidget->clear();
    QString filePcddir = QFileDialog::getExistingDirectory(this,tr("Open Directory"),load_file_path,QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    filePcdDir_str = filePcddir.toStdString();
   // std::cout<<filePcdDir_str<<std::endl;
    filter_pcd << "*.pcd"<<"*.bin";

    dir_pcd.setPath(filePcddir);

    dir_pcd.setNameFilters(filter_pcd);
    listpcd = dir_pcd.entryInfoList();
    QStringList pcd_list = dir_pcd.entryList();

    ui->listWidget->addItems(pcd_list);

    if(listpcd.length()!=0)
    {
        index = 0;
        pcdFile = listpcd.at(index).fileName();
        //std::cout<<pcdFile.toStdString()<<std::endl;
        show_pcd(pcdFile);

    }

    else{
        qDebug()<<"no file";
    }


}

void pcl_visualizer::onOpenPicDir(){
    ui->listWidget_pic->clear();
    QString filedir = QFileDialog::getExistingDirectory(this,tr("Open Directory"),load_pic_path,QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    filePicdir_str = filedir.toStdString();
    //std::cout<<filePicdir_str<<std::endl;
    filter_pic << "*.jpg"<<"*.jpeg"<<"*.png";

    dir_pic.setPath(filedir);
    dir_pic.setNameFilters(filter_pic);
    listpic = dir_pic.entryInfoList();
    QStringList pic_list = dir_pic.entryList();

    ui->listWidget_pic->addItems(pic_list);

    if(listpic.length()!=0)
    {
        index = 0;
        picFile = listpic.at(index).fileName();
        show_pic(picFile);
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
       // std::cout<<file_name<<"!!!!!!!!!!!!!!"<<std::endl;
        std::string file_abs_path = filePcdDir_str + '/' + file_name;
       // std::cout<< file_abs_path<<std::endl;
        if(file_name[file_name.length()-1]=='n')
        {
            std::fstream input(file_abs_path.c_str(),std::ios::in | std::ios::binary);

            if(!input.good()){
                std::cerr<<"Could not read file: "<<file_name<<std::endl;
                exit(EXIT_FAILURE);
            }
            input.seekg(0,std::ios::beg);

            int i;
            float intensity;
            for(i=0;input.good()&&!input.eof();i++)
            {
                PCLCloud_type point;
                input.read((char *)&point.x,3*sizeof(float));
                input.read((char *)&intensity,sizeof(float));
                point.r=intensity*255;
                cloud->push_back(point);
            }
            input.close();

        }
        else
        {
            pcl::PCLPointCloud2 cloud2;
            Eigen::Vector4f origin;
            Eigen::Quaternionf orientation;
            int pcd_version;
            int data_type;
            unsigned int data_idx;
            int offset = 0;
            pcl::PCDReader rd;
            //rd.readHeader(file_name,cloud2,origin,orientation,pcd_version,data_type,data_idx);
            rd.readHeader(file_abs_path,cloud2,origin,orientation,pcd_version,data_type,data_idx);


            //std::cout<<cloud2.fields.size()<<std::endl;

            if(data_type ==0)
            {
                 //pcl::io::loadPCDFile(filename_pcd.toStdString(),*cloud);
                 pcl::io::loadPCDFile(file_abs_path,*cloud);
            }
            else if(data_type==2)
            {
                 pcl::PCDReader reader;
                 //reader.read<pcl::PointXYZ>(filename_pcd.toStdString(),*cloud);
                 reader.read<PCLCloud_type>(file_abs_path,*cloud);
            }

        }


        viewer->updatePointCloud(cloud,"cloud");
        viewer->resetCamera();
        ui->qvtkWidget->update();

    }

}

void pcl_visualizer::show_pic(QString filename_pic){

    image = cv::imread(filePicdir_str + '/' + filename_pic.toLatin1().data());
    cv::cvtColor(image,image,CV_BGR2RGB);
    cv::resize(image,image,cv::Size(420,350),(0,0),(0,0),cv::INTER_NEAREST);
    QImage img = QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
    ui->labelimage->setPixmap(QPixmap::fromImage(img));
    ui->labelimage->resize(ui->labelimage->pixmap()->size());
}
