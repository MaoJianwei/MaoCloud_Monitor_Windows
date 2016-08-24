/********************************************************************************
** Form generated from reading UI file 'maocloud.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAOCLOUD_H
#define UI_MAOCLOUD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaoCloudClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QTableWidget *NodeBrocastTable;
    QPushButton *StartUDP;

    void setupUi(QMainWindow *MaoCloudClass)
    {
        if (MaoCloudClass->objectName().isEmpty())
            MaoCloudClass->setObjectName(QStringLiteral("MaoCloudClass"));
        MaoCloudClass->resize(731, 510);
        centralWidget = new QWidget(MaoCloudClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        NodeBrocastTable = new QTableWidget(centralWidget);
        NodeBrocastTable->setObjectName(QStringLiteral("NodeBrocastTable"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NodeBrocastTable->sizePolicy().hasHeightForWidth());
        NodeBrocastTable->setSizePolicy(sizePolicy);

        gridLayout->addWidget(NodeBrocastTable, 0, 0, 1, 1);

        StartUDP = new QPushButton(centralWidget);
        StartUDP->setObjectName(QStringLiteral("StartUDP"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(StartUDP->sizePolicy().hasHeightForWidth());
        StartUDP->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        StartUDP->setFont(font);

        gridLayout->addWidget(StartUDP, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MaoCloudClass->setCentralWidget(centralWidget);

        retranslateUi(MaoCloudClass);

        QMetaObject::connectSlotsByName(MaoCloudClass);
    } // setupUi

    void retranslateUi(QMainWindow *MaoCloudClass)
    {
        MaoCloudClass->setWindowTitle(QApplication::translate("MaoCloudClass", "MaoCloud", 0));
        StartUDP->setText(QApplication::translate("MaoCloudClass", "StartUDP", 0));
    } // retranslateUi

};

namespace Ui {
    class MaoCloudClass: public Ui_MaoCloudClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAOCLOUD_H
