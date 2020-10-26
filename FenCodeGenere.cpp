#include "FenCodeGenere.h"

FenCodeGenere::FenCodeGenere(QString &code, QWidget *parent = 0) : QDialog(parent)
{
    this->setModal(1);
    QTextEdit *comment = new QTextEdit;
    QFont font = QFont("Courier");
    comment->setCurrentFont(font);

    comment->setText(code);
    comment->setReadOnly(1);

    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton *bouton1 = new QPushButton("Fermer");

    layout->addWidget(comment);
    layout->addWidget(bouton1);
    this->setLayout(layout);

    resize(450, 650);
    QObject::connect(bouton1, SIGNAL(clicked()), this, SLOT(close()));
}
