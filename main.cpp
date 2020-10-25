#include <QApplication>
#include <QtWidgets>
#include <FenPrincipale.h>
#include <FenCodeGenere.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale fenetrePrincipale;

    fenetrePrincipale.show();

    return app.exec();
}
