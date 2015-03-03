/**
 * \file joueur.h
 * \brief classe Joueur
 * \author Thomas Zoratto
 *
 *
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#include "position.h"
#include <vector>
#include "strategie.h"

class Joueur
{
    /*! \class Joueur
       * \brief classe representant le Joueur
       *
       */
protected:
    Position posActuelle; /*!< Position actuelle du joueur*/
    std::vector<Strategie*> tStrategiesFuyard; /*!< Tableau contenant les stratégies du joueur*/
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Joueur
         *initialise un Joueur à la position 0,0
         */
    Joueur();
    /*!
         *  \brief Constructeur
         *
         *  Constructeur paramétré de la classe Jeu
         *
         *  \param pos : la Position du Joueur
         */
    Joueur(Position pos);

    /*!
        *  \brief set le tableau des stratégies
        *
        *  Methode qui permet de définir le tableau des stratégies du joueur
        *
        * \param tStrategiesFuyard : le tableau des stratégies
        *
        */
    void setStrategiesFuyard(const std::vector<Strategie*>& tStrategiesFuyard);
    /*!
        *  \brief Avancer d'un coup
        *
        *  Methode qui permet de faire avancer le joueur d'un coup en avant
        *
        * \param decision : la position que va prendre le joueur
        *
        */
    void avancer(const Position& decision);
    /*!
        *  \brief get de la position actuelle
        *
        *  \return la position actuelle du joueur
        *
        */
    Position getPosActuelle()const;
};

#endif // JOUEUR_H
