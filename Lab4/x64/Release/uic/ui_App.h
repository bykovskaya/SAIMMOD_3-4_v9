/********************************************************************************
** Form generated from reading UI file 'App.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APP_H
#define UI_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditP_1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditP_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditP_3;
    QPushButton *button;
    QTextEdit *resultTextEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AppClass)
    {
        if (AppClass->objectName().isEmpty())
            AppClass->setObjectName(QString::fromUtf8("AppClass"));
        AppClass->resize(600, 400);
        centralWidget = new QWidget(AppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 10, 159, 112));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditP = new QLineEdit(layoutWidget);
        lineEditP->setObjectName(QString::fromUtf8("lineEditP"));

        horizontalLayout->addWidget(lineEditP);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditP_1 = new QLineEdit(layoutWidget);
        lineEditP_1->setObjectName(QString::fromUtf8("lineEditP_1"));

        horizontalLayout_2->addWidget(lineEditP_1);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditP_2 = new QLineEdit(layoutWidget);
        lineEditP_2->setObjectName(QString::fromUtf8("lineEditP_2"));

        horizontalLayout_3->addWidget(lineEditP_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditP_3 = new QLineEdit(layoutWidget);
        lineEditP_3->setObjectName(QString::fromUtf8("lineEditP_3"));

        horizontalLayout_4->addWidget(lineEditP_3);


        verticalLayout->addLayout(horizontalLayout_4);

        button = new QPushButton(centralWidget);
        button->setObjectName(QString::fromUtf8("button"));
        button->setGeometry(QRect(10, 140, 161, 24));
        resultTextEdit = new QTextEdit(centralWidget);
        resultTextEdit->setObjectName(QString::fromUtf8("resultTextEdit"));
        resultTextEdit->setGeometry(QRect(190, 10, 401, 371));
        AppClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AppClass->setStatusBar(statusBar);

        retranslateUi(AppClass);

        QMetaObject::connectSlotsByName(AppClass);
    } // setupUi

    void retranslateUi(QMainWindow *AppClass)
    {
        AppClass->setWindowTitle(QCoreApplication::translate("AppClass", "App", nullptr));
        label->setText(QCoreApplication::translate("AppClass", "p:  ", nullptr));
        label_2->setText(QCoreApplication::translate("AppClass", "p1:", nullptr));
        label_3->setText(QCoreApplication::translate("AppClass", "p2:", nullptr));
        label_4->setText(QCoreApplication::translate("AppClass", "p3:", nullptr));
        button->setText(QCoreApplication::translate("AppClass", "RUN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppClass: public Ui_AppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APP_H
