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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *curLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *totalLabel;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QSlider *verticalSlider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MusicPlayerClass)
    {
        if (MusicPlayerClass->objectName().isEmpty())
            MusicPlayerClass->setObjectName(QStringLiteral("MusicPlayerClass"));
        MusicPlayerClass->resize(811, 544);
        MusicPlayerClass->setStyleSheet(QLatin1String("*{\n"
"border:none\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	background-color: rgb(85, 255, 255);\n"
"}"));
        centralWidget = new QWidget(MusicPlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        listWidget = new QListWidget(widget_4);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_4->addWidget(listWidget);

        listWidget_2 = new QListWidget(widget_4);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        horizontalLayout_4->addWidget(listWidget_2);


        verticalLayout->addWidget(widget_4);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 25));
        widget_2->setMaximumSize(QSize(16777215, 25));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        curLabel = new QLabel(widget_2);
        curLabel->setObjectName(QStringLiteral("curLabel"));
        curLabel->setMinimumSize(QSize(0, 20));
        curLabel->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(curLabel);

        horizontalSpacer = new QSpacerItem(261, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        totalLabel = new QLabel(widget_2);
        totalLabel->setObjectName(QStringLiteral("totalLabel"));
        totalLabel->setMinimumSize(QSize(0, 20));
        totalLabel->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(totalLabel);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 20));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSlider = new QSlider(widget_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 10));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);


        verticalLayout->addWidget(widget_3);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 64));
        widget->setMaximumSize(QSize(16777215, 64));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/\347\264\240\346\235\220.svg);"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(32, 32));
        pushButton_2->setMaximumSize(QSize(32, 32));
        pushButton_2->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(32, 32));
        pushButton_5->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(32, 32));
        pushButton_3->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(32, 32));
        pushButton_4->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(32, 32));
        pushButton_6->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_6);

        verticalSlider = new QSlider(widget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider);


        verticalLayout->addWidget(widget);

        MusicPlayerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MusicPlayerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 811, 23));
        MusicPlayerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MusicPlayerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MusicPlayerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MusicPlayerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MusicPlayerClass->setStatusBar(statusBar);

        retranslateUi(MusicPlayerClass);

        QMetaObject::connectSlotsByName(MusicPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MusicPlayerClass)
    {
        MusicPlayerClass->setWindowTitle(QApplication::translate("MusicPlayerClass", "MusicPlayer", Q_NULLPTR));
        curLabel->setText(QApplication::translate("MusicPlayerClass", "00:00", Q_NULLPTR));
        totalLabel->setText(QApplication::translate("MusicPlayerClass", "00:00", Q_NULLPTR));
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
