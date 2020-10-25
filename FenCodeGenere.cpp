#include "FenCodeGenere.h"

FenCodeGenere::FenCodeGenere(QString &code) : QDialog()
{

    this->setModal(1);
    QTextEdit *comment = new QTextEdit;
    //comment->toPlainText(code);
    comment->setText(code);


    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton *bouton1 = new QPushButton("Fermer");


    layout->addWidget(comment);
    layout->addWidget(bouton1);
    this->setLayout(layout);

    QObject::connect(bouton1, SIGNAL(clicked()), this, SLOT(close()));
}


//void FenCodeGenere::SetComment(QString *qString)
//{
//   comment->setText(*qString);

//}
