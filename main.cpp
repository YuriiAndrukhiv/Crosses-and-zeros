#include "crossesandzeros.h"
#include <QApplication>


int main (int lArgc, char *lArgv[])
{
    QApplication lApplication(lArgc, lArgv);

    CrossesAndZeros lCrossesAndZeros;
    lCrossesAndZeros.show();

    return lApplication.exec();
}
