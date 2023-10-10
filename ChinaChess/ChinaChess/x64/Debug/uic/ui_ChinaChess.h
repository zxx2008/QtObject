/********************************************************************************
** Form generated from reading UI file 'ChinaChess.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHINACHESS_H
#define UI_CHINACHESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChinaChessClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChinaChessClass)
    {
        if (ChinaChessClass->objectName().isEmpty())
            ChinaChessClass->setObjectName(QString::fromUtf8("ChinaChessClass"));
        ChinaChessClass->resize(600, 400);
        menuBar = new QMenuBar(ChinaChessClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ChinaChessClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChinaChessClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ChinaChessClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ChinaChessClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ChinaChessClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ChinaChessClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ChinaChessClass->setStatusBar(statusBar);

        retranslateUi(ChinaChessClass);

        QMetaObject::connectSlotsByName(ChinaChessClass);
    } // setupUi

    void retranslateUi(QMainWindow *ChinaChessClass)
    {
        ChinaChessClass->setWindowTitle(QCoreApplication::translate("ChinaChessClass", "ChinaChess", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChinaChessClass: public Ui_ChinaChessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHINACHESS_H
