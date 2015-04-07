#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jeu.h"
#include "notaire.h"
#include "historique.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Poursuivant& p, Fuyard& f,QWidget *parent = 0);
    ~MainWindow();

    /*!
        *  \brief Démarrer le jeu
        *
        *  Methode qui permet de lancer l'exécution du jeu
        *
        */
    void lancerJeu();

private:
    Ui::MainWindow *ui; /*!< Interface graphique*/
    Jeu * jeu; /*!< Jeu en cours */
    Poursuivant poursuivant;
    Fuyard fuyard;

private slots:
    /*!
        *  \brief Passer au prochain tour
        *
        *  Methode qui permet de jouer un tour
        *
        */
    void tourSuivant();
    /*!
        *  \brief Terminer la partie
        *
        *  Methode qui permet de dérouler toute la partie
        *
        */
    void terminerPartie();
    /*!
        *  \brief Initialiser le jeu
        *
        *  Methode qui permet d'initialiser le jeu
        *
        */
    void initJeu();
    /*!
        *  \brief Mettre à jour la grille
        *
        *  Methode qui permet de mettre à jour la grille avec les positions
        * des joueurs et le numéro du tour en cours
        *
        */
    void majPositionGrille();
    /*!
        *  \brief Mettre à jour l'affichage de l'historique
        *
        *  Methode qui permet de mettre à jour l'affichage de l'historique
        * au fur et à mesure que le jeu se déroule
        */
    void majHisto();
    /*!
        *  \brief Affiche une ancienne position de P
        *
        *  Methode qui permet d'afficher une ancienne position de P lorsque
        * l'utilisateur click dessus.
        */
    void clickOnHistoP();
    /*!
        *  \brief Intialise les paramètres pour l'affichage d'une ancienne position de F
        *
        *  Methode qui permet d'afficher une ancienne position de F lorsque
        * l'utilisateur click dessus
        */
    void clickOnHistoF();
};

#endif // MAINWINDOW_H
