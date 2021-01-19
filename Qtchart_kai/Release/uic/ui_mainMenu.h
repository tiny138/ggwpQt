/********************************************************************************
** Form generated from reading UI file 'mainMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainMenu
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_11;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *mainMenu)
    {
        if (mainMenu->objectName().isEmpty())
            mainMenu->setObjectName(QStringLiteral("mainMenu"));
        mainMenu->resize(1038, 692);
        verticalLayout_2 = new QVBoxLayout(mainMenu);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(mainMenu);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_4 = new QLabel(mainMenu);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_8 = new QLabel(mainMenu);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 4, 2, 1, 1);

        label_10 = new QLabel(mainMenu);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        label_6 = new QLabel(mainMenu);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        label_3 = new QLabel(mainMenu);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_7 = new QLabel(mainMenu);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_12 = new QLabel(mainMenu);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout->addWidget(label_12);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(mainMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(19);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_11 = new QLabel(mainMenu);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout->addWidget(label_11);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(mainMenu);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font1.setPointSize(27);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        verticalSpacer_4 = new QSpacerItem(5, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        label_2 = new QLabel(mainMenu);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(23);
        label_2->setFont(font2);
        label_2->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(label_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        retranslateUi(mainMenu);
        QObject::connect(pushButton, SIGNAL(clicked()), mainMenu, SLOT(start()));

        QMetaObject::connectSlotsByName(mainMenu);
    } // setupUi

    void retranslateUi(QWidget *mainMenu)
    {
        mainMenu->setWindowTitle(QApplication::translate("mainMenu", "\345\274\271\345\244\264\345\206\215\345\205\245\351\243\236\350\241\214\346\200\247\350\203\275\346\217\220\345\215\207\346\234\272\345\212\250\345\274\271\351\201\223\350\256\241\347\256\227\350\275\257\344\273\266", nullptr));
        label_5->setText(QString());
        label_4->setText(QString());
        label_8->setText(QString());
        label_10->setText(QString());
        label_6->setText(QString());
        label_3->setText(QString());
        label_7->setText(QString());
        label_12->setText(QString());
        pushButton->setText(QApplication::translate("mainMenu", "\350\277\233\345\205\245", nullptr));
        label_11->setText(QString());
        label->setText(QApplication::translate("mainMenu", "<html><head/><body><p align=\"center\">\345\274\271\345\244\264\345\206\215\345\205\245\351\243\236\350\241\214\346\200\247\350\203\275\346\217\220\345\215\207\346\234\272\345\212\250\345\274\271\351\201\223\350\256\241\347\256\227\350\275\257\344\273\266</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("mainMenu", "<html><head/><body><p align=\"center\">\345\214\227\344\272\254\350\210\252\345\244\251\351\225\277\345\276\201\351\243\236\350\241\214\345\231\250\347\240\224\347\251\266\346\211\200</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainMenu: public Ui_mainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
