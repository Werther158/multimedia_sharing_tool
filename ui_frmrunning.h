/********************************************************************************
** Form generated from reading UI file 'frmrunning.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMRUNNING_H
#define UI_FRMRUNNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmRunning
{
public:

    void setupUi(QWidget *FrmRunning)
    {
        if (FrmRunning->objectName().isEmpty())
            FrmRunning->setObjectName(QString::fromUtf8("FrmRunning"));
        FrmRunning->resize(400, 300);

        retranslateUi(FrmRunning);

        QMetaObject::connectSlotsByName(FrmRunning);
    } // setupUi

    void retranslateUi(QWidget *FrmRunning)
    {
        FrmRunning->setWindowTitle(QCoreApplication::translate("FrmRunning", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmRunning: public Ui_FrmRunning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMRUNNING_H
