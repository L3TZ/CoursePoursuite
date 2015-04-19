    #include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include "mainwindow.h"
//#include "jeu.h"
#include "strategiequart.h"
#include "strategiecycle.h"
#include "strategiecyclerandom.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Poursuivant P(2,true,0,Position(5,25));
    Fuyard F(Position(30,30));

    std::vector<Strategie*> tStrat;

/*
    // STRATEGIE QUART

    StrategieQuart st1(1,0,0,0,1); //P même X, même Y
    StrategieQuart st2(1,0,1,0,-1);  //P même X, Y plus grand
    StrategieQuart st3(1,0,-1,0,1);  //P même X, Y plus petit
    StrategieQuart st4(1,1,0,-1,0);   //P X plus grand, même Y
    StrategieQuart st5(1,1,1,-1,-1);   //P X plus grand, Y plus grand
    StrategieQuart st6(1,1,-1,-1,1);  //P X plus grand, Y plus petit
    StrategieQuart st7(1,-1,0,1,0);  //P X plus petit, même Y
    StrategieQuart st8(1,-1,1,-1,-1);  //P X plus petit, Y plus grand
    StrategieQuart st9(1,-1,-1,1,1); //P X plus petit, Y plus petit

    tStrat.push_back(&st5);
    tStrat.push_back(&st6);
    tStrat.push_back(&st7);
    tStrat.push_back(&st8);
    tStrat.push_back(&st9);
    //Fin Quart
*/

    //STRATEGIE CYCLE RANDOM

    const int RAYON_ACTION_FUYARD = 1;

    StrategieCycleRandom st1(RAYON_ACTION_FUYARD,0,-1,0);
    StrategieCycleRandom st2(RAYON_ACTION_FUYARD,1,0,1);
    StrategieCycleRandom st3(RAYON_ACTION_FUYARD,0,1,2);
    StrategieCycleRandom st4(RAYON_ACTION_FUYARD,-1,0,3);

    tStrat.push_back(&st1);
    tStrat.push_back(&st2);
    tStrat.push_back(&st3);
    tStrat.push_back(&st4);
    //Fin cycle random


    P.setStrategiesFuyard(tStrat);
    F.setStrategiesFuyard(tStrat);

    MainWindow w(P,F);
    w.showMaximized();


    return a.exec();
}
