/********************************************************************************
** Form generated from reading UI file 'MusicPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICPLAYER_H
#define UI_MUSICPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicPlayerClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MusicPlayerClass)
    {
        if (MusicPlayerClass->objectName().isEmpty())
            MusicPlayerClass->setObjectName(QString::fromUtf8("MusicPlayerClass"));
        MusicPlayerClass->resize(372, 544);
        MusicPlayerClass->setStyleSheet(QString::fromUtf8("*{\n"
"border:none\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	background-color: rgb(85, 255, 255);\n"
"}"));
        centralWidget = new QWidget(MusicPlayerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 64));
        widget->setMaximumSize(QSize(16777215, 64));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/C:/Users/Zu XiXin/Downloads/\347\264\240\346\235\220.svg);"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(32, 32));
        pushButton_2->setMaximumSize(QSize(32, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(32, 32));
        pushButton_5->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(32, 32));
        pushButton_3->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(32, 32));
        pushButton_4->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(32, 32));
        pushButton_6->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_6);


        verticalLayout->addWidget(widget);

        MusicPlayerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MusicPlayerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 372, 25));
        MusicPlayerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MusicPlayerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MusicPlayerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MusicPlayerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MusicPlayerClass->setStatusBar(statusBar);

        retranslateUi(MusicPlayerClass);

        QMetaObject::connectSlotsByName(MusicPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MusicPlayerClass)
    {
        MusicPlayerClass->setWindowTitle(QCoreApplication::translate("MusicPlayerClass", "MusicPlayer", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_5->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MusicPlayerClass: public Ui_MusicPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
