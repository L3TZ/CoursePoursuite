/**
 * \file jeu.h
 * \brief classe Jeu
 * \author Thomas Zoratto
 *
 *
 */

#ifndef JEU_H
#define JEU_H

#include "poursuivant.h"
#include "fuyard.h"
#include "notaire.h"
#include "historique.h"


class Jeu
{
    /*! \class Jeu
       * \brief classe representant le Jeu
       *
       */
private:
    Poursuivant P; /*!< Poursuivant du jeu*/
    Fuyard F; /*!< Fuyard du jeu*/
    Notaire N; /*!< Notaire du jeu*/
    Historique histo; /*!< Historique du jeu*/

public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Jeu
         *
         *  \param p : un poursuivant
         * \param f : un fuyard
         * \param w : la fenêtre principale
         */
    Jeu(Poursuivant& p, Fuyard& f);

    /*!
        *  \brief Démarrer le jeu
        *
        *  Methode qui permet de lancer l'exécution du jeu
        *
        */
    void lancerJeu();

    /*!
        *  \brief Passer au prochain tour
        *
        *  Methode qui permet de jouer un tour
        *
        */
    void tourSuivant();

    Position getPositionF();
    Position getPositionP();

};
#endif // JEU_H
