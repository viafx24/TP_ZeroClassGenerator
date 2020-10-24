#include "FenCodeGenere.h"

FenCodeGenere::FenCodeGenere() : QDialog()
{

    this->setModal(1);
    QTextEdit *comment = new QTextEdit;
    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton *bouton1 = new QPushButton("Fermer");


    layout->addWidget(comment);
    layout->addWidget(bouton1);
    this->setLayout(layout);
}


