#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jeu.h"
#include "notaire.h"
#include "historique.h"
#include "dialog.h"

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
    Dialog *dlg;

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
         * \brief Creer la liste de widget menu
         * \return Une liste de widget
         *
         *  Methode qui permet de creer la liste des widgets pour la fenetre de jeu
         */
    QList<QWidget * > creerListWidgetJeu();
    /*!
         * \brief Creer la liste de widget jeu
         * \return Une liste de widget
         *
         *  Methode qui permet de creer la liste des widgets pour la fenetre de menu
         */
    QList<QWidget *> creerListWidgetMenu();
    /*!
          * \brief Affiche la fenetre de jeu
          *
          *  Methode qui permet d'afficher la fenetre de jeu
          */
     void afficheFenetreJeu();

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
  /*  void reinitialisationJeu();*/
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
         * \brief Initialise un nouveau jeu avec les positions données par l'utilisateur
         *
         *  Methode qui permet d'initialiser le nouveau jeu lorsque l'utilisateur
         * click sur jouer.
         */
    void nouveauJeu(int yF,int xF, int yP, int xP);
    /*!
     * \brief showDialogModal permet d'afficher le menu
     *
     *  Methode qui affiche le menu
     */
    void showDialogModal();
    /*!
     * \brief recevoirValeur permet de recuperer les valeurs du menu
     * \param position position du poursuivant et du fuyard sous forme de QString
     *
     *  Methode qui permet de recuperer les valeurs du menu
     */
    void recevoirValeur(QString position);
    /*!
     * \brief quit quitter
     *
     *  Methode qui permet de quitter l'application (menu et jeu)
     */
    void quit();
};

#endif // MAINWINDOW_H
