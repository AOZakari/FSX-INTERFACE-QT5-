/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication7.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION7_H
#define UI_QTGUIAPPLICATION7_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication7Class
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QSlider *verticalSlider;
    QLabel *label_5;
    QLabel *label_6;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpinBox *spinBox;
    QDial *dial;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBox_2;
    QDial *dial_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QSpinBox *spinBox_3;
    QDial *dial_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_4;
    QSpinBox *spinBox_4;
    QDial *dial_4;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_7;
    QCheckBox *checkBox_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication7Class)
    {
        if (QtGuiApplication7Class->objectName().isEmpty())
            QtGuiApplication7Class->setObjectName(QStringLiteral("QtGuiApplication7Class"));
        QtGuiApplication7Class->resize(875, 800);
        actionExit = new QAction(QtGuiApplication7Class);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(QtGuiApplication7Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(270, 40, 19, 160));
        verticalSlider->setMaximum(1);
        verticalSlider->setPageStep(1);
        verticalSlider->setValue(1);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedAppearance(true);
        verticalSlider->setInvertedControls(false);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 40, 47, 13));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 180, 61, 20));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(60, 70, 70, 17));
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 130, 70, 17));
        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(100, 130, 70, 17));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(320, 280, 47, 13));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(310, 240, 47, 13));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(370, 270, 428, 202));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(0);
        spinBox->setMaximum(100);

        verticalLayout->addWidget(spinBox);

        dial = new QDial(layoutWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setMinimum(0);
        dial->setMaximum(100);

        verticalLayout->addWidget(dial);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(50000);
        spinBox_2->setSingleStep(100);

        verticalLayout_2->addWidget(spinBox_2);

        dial_2 = new QDial(layoutWidget);
        dial_2->setObjectName(QStringLiteral("dial_2"));
        dial_2->setMaximum(50000);
        dial_2->setSingleStep(100);

        verticalLayout_2->addWidget(dial_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        spinBox_3 = new QSpinBox(layoutWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMaximum(360);

        verticalLayout_3->addWidget(spinBox_3);

        dial_3 = new QDial(layoutWidget);
        dial_3->setObjectName(QStringLiteral("dial_3"));
        dial_3->setMaximum(360);
        dial_3->setPageStep(1);

        verticalLayout_3->addWidget(dial_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        spinBox_4 = new QSpinBox(layoutWidget);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMinimum(-3800);
        spinBox_4->setMaximum(3800);

        verticalLayout_4->addWidget(spinBox_4);

        dial_4 = new QDial(layoutWidget);
        dial_4->setObjectName(QStringLiteral("dial_4"));
        dial_4->setMinimum(-3800);
        dial_4->setMaximum(3800);

        verticalLayout_4->addWidget(dial_4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_4);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(370, 230, 321, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox_5 = new QSpinBox(layoutWidget1);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setMaximum(1000);

        horizontalLayout_2->addWidget(spinBox_5);

        spinBox_6 = new QSpinBox(layoutWidget1);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setMaximum(50000);

        horizontalLayout_2->addWidget(spinBox_6);

        spinBox_7 = new QSpinBox(layoutWidget1);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setMaximum(360);

        horizontalLayout_2->addWidget(spinBox_7);

        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(140, 270, 70, 17));
        QtGuiApplication7Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplication7Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 875, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        QtGuiApplication7Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication7Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplication7Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication7Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApplication7Class->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(QtGuiApplication7Class);
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), dial_2, SLOT(setValue(int)));
        QObject::connect(spinBox_4, SIGNAL(valueChanged(int)), dial_4, SLOT(setValue(int)));
        QObject::connect(dial_2, SIGNAL(valueChanged(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(dial_3, SIGNAL(valueChanged(int)), spinBox_3, SLOT(setValue(int)));
        QObject::connect(dial_4, SIGNAL(valueChanged(int)), spinBox_4, SLOT(setValue(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), QtGuiApplication7Class, SLOT(Alt(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), QtGuiApplication7Class, SLOT(Hdg(int)));
        QObject::connect(spinBox_4, SIGNAL(valueChanged(int)), QtGuiApplication7Class, SLOT(VS(int)));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), QtGuiApplication7Class, SLOT(Gear(int)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_alt(int)), dial_2, SLOT(setValue(int)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_spd(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_hdg(int)), dial_3, SLOT(setValue(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), dial_3, SLOT(setValue(int)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_rt_spd(int)), spinBox_5, SLOT(setValue(int)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_rt_alt(int)), spinBox_6, SLOT(setValue(int)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_rt_hdg(int)), spinBox_7, SLOT(setValue(int)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_left_gear(bool)), checkBox_2, SLOT(setChecked(bool)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_nose_gear(bool)), checkBox, SLOT(setChecked(bool)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_right_gear(bool)), checkBox_3, SLOT(setChecked(bool)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_ap(bool)), checkBox_4, SLOT(setChecked(bool)));
        QObject::connect(checkBox_4, SIGNAL(stateChanged(int)), QtGuiApplication7Class, SLOT(AP(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), QtGuiApplication7Class, SLOT(Spd(int)));
        QObject::connect(QtGuiApplication7Class, SIGNAL(refresh_vs(int)), spinBox_4, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(QtGuiApplication7Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication7Class)
    {
        QtGuiApplication7Class->setWindowTitle(QApplication::translate("QtGuiApplication7Class", "QtGuiApplication7", Q_NULLPTR));
        actionExit->setText(QApplication::translate("QtGuiApplication7Class", "Exit", Q_NULLPTR));
        label_5->setText(QApplication::translate("QtGuiApplication7Class", "Gear up", Q_NULLPTR));
        label_6->setText(QApplication::translate("QtGuiApplication7Class", "Gear Down", Q_NULLPTR));
        checkBox->setText(QApplication::translate("QtGuiApplication7Class", "Nose", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("QtGuiApplication7Class", "Left", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("QtGuiApplication7Class", "Right", Q_NULLPTR));
        label_7->setText(QApplication::translate("QtGuiApplication7Class", "AP", Q_NULLPTR));
        label_8->setText(QApplication::translate("QtGuiApplication7Class", "Real-Time", Q_NULLPTR));
        label->setText(QApplication::translate("QtGuiApplication7Class", "Spd", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtGuiApplication7Class", "Alt", Q_NULLPTR));
        label_4->setText(QApplication::translate("QtGuiApplication7Class", "Hdg", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtGuiApplication7Class", "VS", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("QtGuiApplication7Class", "Autopilot", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("QtGuiApplication7Class", "File", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("QtGuiApplication7Class", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication7Class: public Ui_QtGuiApplication7Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION7_H
