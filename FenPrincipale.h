#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QApplication>
#include <QWidget>
#include <QDateEdit>
#include <QTextEdit>

#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QCheckBox>

#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QDate>
#include <QFont>

#include <FenCodeGenere.h>

class FenPrincipale : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT

    public:
    FenPrincipale();


    private slots:
        void   Guillaume_slot();


    private:
    QLineEdit *nom;
    QLineEdit *classeMere;

    QLineEdit *auteur;
    QDateEdit *dateCreation= new QDateEdit;
    QTextEdit *comment = new QTextEdit;

    QCheckBox *qck1;
    QCheckBox *qck2;
    QCheckBox *qck3;

    QGroupBox *groupBox_3;

};

#endif


