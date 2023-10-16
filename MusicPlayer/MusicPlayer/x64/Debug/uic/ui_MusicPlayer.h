/********************************************************************************
** Form generated from reading UI file 'MusicPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICPLAYER_H
#define UI_MUSICPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicPlayerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MusicPlayerClass)
    {
        if (MusicPlayerClass->objectName().isEmpty())
            MusicPlayerClass->setObjectName(QStringLiteral("MusicPlayerClass"));
        MusicPlayerClass->resize(600, 400);
        menuBar = new QMenuBar(MusicPlayerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MusicPlayerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MusicPlayerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MusicPlayerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MusicPlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MusicPlayerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MusicPlayerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MusicPlayerClass->setStatusBar(statusBar);

        retranslateUi(MusicPlayerClass);

        QMetaObject::connectSlotsByName(MusicPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MusicPlayerClass)
    {
        MusicPlayerClass->setWindowTitle(QApplication::translate("MusicPlayerClass", "MusicPlayer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MusicPlayerClass: public Ui_MusicPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
