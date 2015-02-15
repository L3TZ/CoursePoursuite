#include "mainwindow.h"
#include <QApplication>

#include "jeu.h"
#include "strategietest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Poursuivant P(0,true,0,Position(0,0));
    Fuyard F(Position(10,10));

    StrategieTest st(2);
    std::vector<Strategie*> tStrat;
    tStrat.push_back(&st);

    P.setStrategiesFuyard(tStrat);
    F.setStrategiesFuyard(tStrat);


    Jeu jeu(P,F);
    jeu.lancerJeu();

    return a.exec();
}
