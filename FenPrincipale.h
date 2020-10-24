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

#include <FenCodeGenere.h>

class FenPrincipale : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT

    public:
    FenPrincipale();


public slots:
  void   Guillaume_slot();
//  void   Guillaume_slot();

    private:
    QLineEdit *nom;
    QLineEdit *classeMere;

    QLineEdit *auteur;
    QDateEdit *dateCreation= new QDateEdit;
    QTextEdit *comment = new QTextEdit;

};

#endif


