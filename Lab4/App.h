#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_App.h"
#include "Model.h"


class App : public QMainWindow
{
    Q_OBJECT

public:
    App(QWidget *parent = Q_NULLPTR);

public slots:
  void RunImitation();

private:
    Ui::AppClass ui;
    CModel model;
};
