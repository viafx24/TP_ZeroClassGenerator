#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>


class FenCodeGenere : public QDialog // On hérite de QWidget (IMPORTANT)
{

    public:
    FenCodeGenere(QString &code, QWidget *parent);

    private:
    QTextEdit *comment;

};


#endif // FENCODEGENERE_H
