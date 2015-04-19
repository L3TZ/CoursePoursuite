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
    Jeu * jeu; /*!< instance du jeu*/

    /*!
        *  \brief Initialisation du jeu
        *
        *  Methode qui permet d'initialiser le jeu
        *
        */
    void initJeu();
    /*!
         * \brief afficheFenetreMenu
         * \param listFenetreJeu
         *
         *  Methode qui permet d'afficher la fenetre de menu
         */
    void afficheFenetreMenu(QList<QWidget * > listFenetreJeu);
    /*!
         * \brief creerListWidgetJeu
         * \return listWidgetJeu
         *
         *  Methode qui permet de creer la liste des widgets pour la fenetre de jeu
         */
    QList<QWidget * > creerListWidgetJeu();
    /*!
         * \brief creerListWidgetMenu
         * \return listWidgetMenu
         *
         *  Methode qui permet de creer la liste des widgets pour la fenetre de menu
         */
    QList<QWidget *> creerListWidgetMenu();

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
        *  \brief Re-initialise le jeu
        *
        *  Methode qui permet de re-initilaiser le jeu
        *
        */
    void reinitialisationJeu();
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
        *  \brief Affiche une ancienne position de F
        *
        *  Methode qui permet d'afficher une ancienne position de F lorsque
        * l'utilisateur click dessus
        */
    void clickOnHistoF();
    /*!
         * \brief afficheFenetreJeu
         *
         *  Methode qui permet d'afficher la fenetre de jeu lorsque
         * l'utilisateur click sur jouer
         */
    void afficheFenetreJeu();
};

#endif // MAINWINDOW_H
