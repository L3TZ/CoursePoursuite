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
    Jeu jeu;

private slots:
    void on_boutonQuitter_clicked();
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
        *  \brief Mettre à jour la grille
        *
        *  Methode qui permet de mettre à jour la grille avec les positions
        * des joueurs et le numéro du tour en cours
        *
        */
    void majPositionGrille();
};

#endif // MAINWINDOW_H
