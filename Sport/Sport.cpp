#include "Sport.h"
//#include <QDirModel>
#include <QFileSystemModel>
#include <QStandardItemModel>
//ceshiceshi，更新测试
Sport::Sport(QWidget *parent)
    : QMainWindow(parent)
{

  

  //  ui.test->setRootIndex(model->index("C:/Users/Administrator"));
   
    ui.setupUi(this);
   
    /*QWidget* lTitleBar = ui.dockWidget_2->titleBarWidget();
    QWidget* lEmptyWidget = new QWidget();
    ui.dockWidget_2->setTitleBarWidget(lEmptyWidget);
    delete  lTitleBar;*/
    //设置dockwidget只能缩放，不可移动
    ui.dockWidget_2->setFeatures(QDockWidget::NoDockWidgetFeatures);
    ui.dockWidget_3->setFeatures(QDockWidget::NoDockWidgetFeatures);
    //设置dockwidget颜色
    QPalette pal;
    pal.setColor(QPalette::Window,QColor(45,45,45));
    ui.dockWidget_2->setAutoFillBackground(true);
    ui.dockWidget_2->setPalette(pal);
    ui.dockWidget_3->setAutoFillBackground(true);
    ui.dockWidget_3->setPalette(pal);
    ui.dockWidget_2->setStyleSheet("font-size:20px;color:white;");
    ui.dockWidget_3->setStyleSheet("font-size:20px;color:white;");
    ui.statusBar->setStyleSheet("font-size:20px;color:white;");
	this->setStyleSheet("QMainWindow {"
		" color: rgb(160,127, 19);"
		"background-color :rgb(45, 45, 45); }"

	);
    ui.toolBar->setStyleSheet("color:rgb(160,127,19);font-size:22px;min-width:150px;border-color:rgb(45,45,45);");
    ui.menuBar->setStyleSheet("font-size:20px;background-color :rgb(45, 45, 45);color:white;min-width:100px;");
    ui.treeView_2->setStyleSheet("background-color:rgb(45,45,45);font-size:15px;");
    ui.treeView_2->setHeaderHidden(true);
    ui.tableView->setStyleSheet("background-color:rgb(45,45,45);font-size:15px;");
    QString str = "D:/test";
    QFileSystemModel* model = new QFileSystemModel(this);
    //ui.test->setModel(model);
  //  model.set;
    model->setRootPath(str);
    ui.treeView_2->setModel(model);
    ui.treeView_2->setRootIndex(model->index(str));
    connect(ui.action,SIGNAL(triggered()),this,SLOT(pageChanged()));
    connect(ui.action_2, SIGNAL(triggered()), this, SLOT(pageChanged2()));
    connect(ui.analy, SIGNAL(triggered()), this, SLOT(pageChanged3()));
    connect(ui.contrast, SIGNAL(triggered()), this, SLOT(pageChanged4()));
    connect(ui.all, SIGNAL(triggered()), this, SLOT(pageChanged5()));
    connect(ui.dimension, SIGNAL(triggered()), this, SLOT(pageChanged6()));
    ui.statusBar->showMessage("StateBar");
      /* this->setStyleSheet("QMenu::item:selected{background-color:rgb(45,45,45);}\
                         QMenuBar{background-color:rgb(45,45,45);}");*/
     
	
 /*   ui.toolBar->setStyleSheet(
        "padding-left:80px;padding-top:5px;padding-bottom:5px;");
      this->setStyleSheet("QAction:item:selected{color:rgb(255,0, 0);background-color:rgb(160,127, 19);}\
                           QToolBar{color:rgb(160,127, 19);background-color:rgb(45,45,45);}");*/
	
  /*  QStandardItemModel* model1 = new QStandardItemModel();

    model1->setColumnCount(2);

    model1->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("卡号"));

    model1->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("姓名"));
    ui.tableView->setModel(model1);*/
     //  ui.menuBar->
      // ui.dockWidget_2->setBaseSize(370,457);
      // this->resizeDocks(ui.dockWidget_2,370);
     
      /* ui.toolBar->setStyleSheet
       (
           "QAction#action { background:red }"
       );*/
       //隐藏标题栏
       /*QWidget* titleBarWidget = ui.dockWidget_2->titleBarWidget();
       ui.dockWidget_2->setTitleBarWidget(NULL);
       delete  titleBarWidget;*/
      

      


  
 
 
}

void Sport::pageChanged()
{
    ui.stackedWidget->setCurrentIndex(0);
}

void Sport::pageChanged2()
{
    ui.stackedWidget->setCurrentIndex(5);
}
void Sport::pageChanged3()
{
    ui.stackedWidget->setCurrentIndex(4);
}
void Sport::pageChanged4()
{
    ui.stackedWidget->setCurrentIndex(1);
}
void Sport::pageChanged5()
{
    ui.stackedWidget->setCurrentIndex(2);
}

void Sport::pageChanged6()
{
    ui.stackedWidget->setCurrentIndex(3);
}

Sport::~Sport()
{}
