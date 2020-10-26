#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H


// tous ces includes s'avèrent necessaire pour éviter d'avoir des erreurs detectés mais il est
// possible que cela fonctionne avec le QWidget seul (ralentit la compile mais évite tous les includes

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

    // commande necessaire si  on ajoute des slots
    Q_OBJECT

    public:
    FenPrincipale();


    private slots:
        void   Guillaume_slot();


    private:

    // attributs necessaire si on veut les utiliser ensuite dans les méthodes.
    // attention ne pas les définir tel quel dans le constructeur sinon ca bug.
    // dans le constructeur on fait : nom = new QLineEdit; mais je ne sais pas
    // exactement pourquoi.

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


