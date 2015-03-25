#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "poursuivant.h"
#include "fuyard.h"
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
    Poursuivant P; /*!< Poursuivant du jeu*/
    Fuyard F; /*!< Fuyard du jeu*/
    Notaire N; /*!< Notaire du jeu*/
    Historique histo; /*!< Historique du jeu*/

private slots:
    void on_boutonTerminer_clicked();
    /*!
        *  \brief Passer au prochain tour
        *
        *  Methode qui permet de jouer un tour
        *
        */
    void tourSuivant();

};

#endif // MAINWINDOW_H
