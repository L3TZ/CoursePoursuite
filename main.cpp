#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include "mainwindow.h"
//#include "jeu.h"
#include "strategiequart.h"
#include "strategiecycle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Poursuivant P(2,true,0,Position(5,25));
    Fuyard F(Position(10,10));

    //StrategieQuart st1(1,0,0,0,1); //P même X, même Y
    //StrategieQuart st2(1,0,1,0,-1);  //P même X, Y plus grand
    //StrategieQuart st3(1,0,-1,0,1);  //P même X, Y plus petit
    //StrategieQuart st4(1,1,0,-1,0);   //P X plus grand, même Y
    //StrategieQuart st5(1,1,1,-1,-1);   //P X plus grand, Y plus grand
    //StrategieQuart st6(1,1,-1,-1,1);  //P X plus grand, Y plus petit
    //StrategieQuart st7(1,-1,0,1,0);  //P X plus petit, même Y
    //StrategieQuart st8(1,-1,1,-1,-1);  //P X plus petit, Y plus grand
    //StrategieQuart st9(1,-1,-1,1,1); //P X plus petit, Y plus petit

    StrategieCycle st1(1,0,-1);
    StrategieCycle st2(1,1,0);
    StrategieCycle st3(1,0,1);
    StrategieCycle st4(1,-1,0);

    std::vector<Strategie*> tStrat;
    tStrat.push_back(&st1);
    tStrat.push_back(&st2);
    tStrat.push_back(&st3);
    tStrat.push_back(&st4);
    //tStrat.push_back(&st5);
    //tStrat.push_back(&st6);
    //tStrat.push_back(&st7);
    //tStrat.push_back(&st8);
    //tStrat.push_back(&st9);

    P.setStrategiesFuyard(tStrat);
    F.setStrategiesFuyard(tStrat);

    MainWindow w(P,F);
    QDesktopWidget bureau;
    QRect surface_bureau = bureau.screenGeometry();
    int x = surface_bureau.width()/2 - w.width()/2;
    int y = surface_bureau.height()/2 - w.height()/2;
    w.move(x/2.5,y/3.5);

    w.show();


    return a.exec();
}
