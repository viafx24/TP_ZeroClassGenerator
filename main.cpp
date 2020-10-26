//rien de bien particulier à dire ici, code de base d'un main pour lancer un GUI. A noter
// seul la fenètre principale est généré dans le main.

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
