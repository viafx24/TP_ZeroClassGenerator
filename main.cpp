#include <QApplication>
#include <QtWidgets>
#include <FenPrincipale.h>
#include <FenCodeGenere.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale fenetrePrincipale;

//    FenCodeGenere* fenCodeGenere = new FenCodeGenere;

//  FenCodeGenere fenCodeGenere;

    fenetrePrincipale.show();

// fenCodeGenere.exec();

    return app.exec();
}
