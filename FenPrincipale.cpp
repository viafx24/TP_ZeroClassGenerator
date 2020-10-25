#include "FenPrincipale.h"
#include "FenCodeGenere.h"

FenPrincipale::FenPrincipale() : QWidget()
{
    // première partie
    nom = new QLineEdit;
    classeMere = new QLineEdit;
//    QLineEdit *nom = new QLineEdit;
//    nom->setText("Entrez votre nom ici");
//    QString contenu = nom->text();

//    QLineEdit *classeMere= new QLineEdit;

    QFormLayout *layout_2 = new QFormLayout;
    layout_2->addRow("Nom", nom);
    layout_2->addRow("Classe mère", classeMere);

     QGroupBox *groupBox = new QGroupBox(tr("Définition de la classe"));
     groupBox->setLayout(layout_2);

     QVBoxLayout *layout = new QVBoxLayout;

     //seconde partie

     QCheckBox *qck1= new QCheckBox(tr("Protéger le header contre les inclusions multiples"));
     QCheckBox *qck2= new QCheckBox(tr("Générer un constructeur par défaut"));
     QCheckBox *qck3= new QCheckBox(tr("Générer un destructeur"));

     QVBoxLayout *layout_3 = new QVBoxLayout;
     layout_3->addWidget(qck1);
     layout_3->addWidget(qck2);
     layout_3->addWidget(qck3);

     QGroupBox *groupBox_2 = new QGroupBox(tr("Options"));
     groupBox_2->setLayout(layout_3);

     // troisième Partie

     auteur = new QLineEdit;
     dateCreation= new QDateEdit;
     dateCreation->setDate(QDate::currentDate());
     comment = new QTextEdit;

     QFormLayout *layout_4 = new QFormLayout;
     layout_4->addRow("Auteur", auteur);
     layout_4->addRow("Date de création:", dateCreation);
     layout_4->addRow("Rôle de la classe:", comment);

     groupBox_3 = new QGroupBox(tr("Ajouter des commentaires"));
     groupBox_3->setLayout(layout_4);
     groupBox_3->setCheckable(true);
     groupBox_3->setChecked(false);

     // quatrième partie

     QPushButton *bouton1 = new QPushButton("Générer !");
     QPushButton *bouton2 = new QPushButton("Quitter");

     QHBoxLayout *layout_5 = new QHBoxLayout;
     layout_5->addWidget(bouton1, Qt::AlignRight);
     layout_5->addWidget(bouton2, Qt::AlignRight);

     layout->addWidget(groupBox);
     layout->addWidget(groupBox_2);
     layout->addWidget(groupBox_3);
     layout->addLayout(layout_5);
     this->setLayout(layout);


    QObject::connect(bouton1, SIGNAL(clicked()), this, SLOT(Guillaume_slot()));
    QObject::connect(bouton2, SIGNAL(clicked()), this, SLOT(close()));
}

void FenPrincipale::Guillaume_slot()
{

    // On vérifie que le nom de la classe n'est pas vide, sinon on arrête
    if (nom->text().isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de classe");
        return; // Arrêt de la méthode
    }

    QString code;
    QString format="dd.MM.yyyy";

    if (groupBox_3->isChecked())
    {

        code="/*\n";
        code+= "Auteur : " + auteur->text() +"\n" ;
        code+= "Date de création : " + dateCreation->date().toString() + "\n";
        code+= comment->toPlainText() + "\n";
        code+="*/\n\n\n";

    }

    //QString code=nom->text();


 //   QString qString = nom->text();
    FenCodeGenere fenCodeGenere(code);
 //   fenCodeGenere.SetComment(test);

    fenCodeGenere.exec();
}


