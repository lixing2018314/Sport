#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Sport.h"

class Sport : public QMainWindow
{
    Q_OBJECT

public:
    Sport(QWidget *parent = nullptr);
    ~Sport();
protected slots:
    void pageChanged();  //采集槽函数
    void pageChanged2(); //播放槽函数
    void pageChanged3(); //分析槽函数
    void pageChanged4(); //叠加对比槽函数
    void pageChanged5(); //动作全景槽函数
    void pageChanged6(); //二维解析槽函数

private:
    Ui::SportClass ui;
};
