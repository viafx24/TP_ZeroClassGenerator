// je n'ai pas bien nommé les widgets et layout et je ne commente pas trop le code
// mais se rappeler que le fonctionnement des layout est trés userfriendly.
// idem (relativement) pour le fonctionnement slot/signal.


#include "FenPrincipale.h"
#include "FenCodeGenere.h"

FenPrincipale::FenPrincipale() : QWidget()
{
    // première partie
    nom = new QLineEdit;
    classeMere = new QLineEdit;

// ca c'est les lignes que j'avais écrit au debut et qui faisait bugger le code;
// je ne sais pas exactement pourquoi
//    QLineEdit *nom = new QLineEdit;
//    QLineEdit *classeMere= new QLineEdit;

// si on ajoute pas le truc dans les attributs alors on peut (doit?) écrire comme cela:
    QFormLayout *layout_2 = new QFormLayout;
    layout_2->addRow("Nom", nom);
    layout_2->addRow("Classe mère", classeMere);

     QGroupBox *groupBox = new QGroupBox(tr("Définition de la classe"));
     groupBox->setLayout(layout_2);

     QVBoxLayout *layout = new QVBoxLayout;

     //seconde partie

     qck1= new QCheckBox(tr("Protéger le header contre les inclusions multiples"));
     qck2= new QCheckBox(tr("Générer un constructeur par défaut"));
     qck3= new QCheckBox(tr("Générer un destructeur"));

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

     // gestion du titre et ajout de l'icone. l'icone n'apparait que quand on lance l'executable.

     setWindowTitle("Zero Class Generator ");
     setWindowIcon(QIcon("icone.png"));
     resize(400, 450);

// si il n'y a pas de type passé dans Signal, on ne peut pas en mettre dans slot.

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

    if (groupBox_3->isChecked())
    {


        // pour trouver le date().toString(), j'ai du regarder la correction
        // sinon on passe des heures dans la doc a cherché la bonne méthode: l'aide
        // à cause de l'héritage et du manque d'exemple reste trés lourde.
        // trouver le bon attribut ou la bonne méthode est chronophage et souvent
        // peu intuitif.

        code="/*\n";
        code+= "Auteur : " + auteur->text() +"\n" ;
        code+= "Date de création : " + dateCreation->date().toString() + "\n";
        code+= comment->toPlainText() + "\n";
        code+="*/\n\n\n";

    }
    if (qck1->isChecked())
    {
        code+="#ifndef HEADER_" + nom->text().toUpper() + "\n";
        code+="#define HEADER_" + nom->text().toUpper() + "\n\n";
    }


    if (!classeMere->text().isEmpty())
    {
        code+= "class " + nom->text();
        code+= " : public " + classeMere->text() +"\n\n";

    }
    else
    {
        code+= "class " + nom->text() + "\n\n";

    }
    code+="{\n";
    code+="     public:\n\n";
    if (qck2->isChecked())
    {
        code+="          "+ nom->text() + "();\n\n";

    }
    if (qck3->isChecked())
    {
        code+="         ~" + nom->text() + "();\n\n";
    }

    code+="     protected:\n\n";
    code+="     private:\n\n";
    code+="};";


    FenCodeGenere fenCodeGenere(code,this);
    fenCodeGenere.exec();

// une variante pour faire la même chose consiste à faire:
//    FenCodeGenere *fenetreCode = new FenCodeGenere(code, this);
//    fenetreCode->exec();
// mais les nuances ne sont pas encore bien claires en particulier dans quel cas
// il vaut mieux passer par le pointeur et dans quel cas , il vaut mieux eviter.
}


