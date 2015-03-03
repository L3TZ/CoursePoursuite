/**
 * \file fuyard.h
 * \brief classe Fuyard
 * \author Thomas Zoratto
 *
 *
 */

#ifndef FUYARD_H
#define FUYARD_H

#include "joueur.h"
#include "historique.h"

class Fuyard : public Joueur
{
    /*! \class Fuyard
       * \brief classe representant le fuyard
       *
       *  Elle hérite de la classe Joueur
       */
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Fuyard
         *
         *  \param pos : position initiale du fuyard
         */
    Fuyard(Position pos);

    /*!
        *  \brief Donner la décision de déplacement
        *
        *  Methode qui permet au fuyard de rendre sa décision
        * concernant son prochain déplacement
        *
        *  \param historiqueJeu : l'historique du jeu
        *  \return un objet Position contenant la prochaine position
        * du fuyard
        */
    Position donnerDecision(const Historique& historiqueJeu)const;
};

#endif // FUYARD_H
