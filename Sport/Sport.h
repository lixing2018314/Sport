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
    void pageChanged();  //�ɼ��ۺ���
    void pageChanged2(); //���Ųۺ���
    void pageChanged3(); //�����ۺ���
    void pageChanged4(); //���ӶԱȲۺ���
    void pageChanged5(); //����ȫ���ۺ���
    void pageChanged6(); //��ά�����ۺ���

private:
    Ui::SportClass ui;
};
