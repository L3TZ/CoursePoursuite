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
         */
    Jeu(Poursuivant& p, Fuyard& f);

    /*!
        *  \brief Test si la valeur est négative (hors grille)
        *
        *  \param valeur : X ou Y d'un joueur
        *
        *  \return vrai si la valeur est inférieure à 0, faux sinon
        *
        */
    bool testValTropPetite(int valeur);

    /*!
        *  \brief Test si la valeur est trop grande (hors grille)
        *
        *  \param valeur : X ou Y d'un joueur
        *
        *  \return vrai si la valeur est supérieure ou égale à 200, faux sinon
        *
        */
    bool testValTropGrande(int valeur);
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
    /*!
        *  \brief Getter du poursuivant
        *
        *  \return le poursuivant du jeu
        *
        */
    Poursuivant getPoursuivant() const;
    /*!
        *  \brief Getter du fuyard
        *
        *  \return le fuyard du jeu
        *
        */
    Fuyard getFuyard() const;
    /*!
        *  \brief Getter de l'historique
        *
        *  \return l'historique du jeu
        *
        */
    Historique getHistorique() const;

};
#endif // JEU_H
