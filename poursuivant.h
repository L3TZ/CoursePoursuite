/**
 * \file poursuivant.h
 * \brief classe Poursuivant
 * \author Thomas Zoratto
 *
 *
 */

#ifndef POURSUIVANT_H
#define POURSUIVANT_H

#include "joueur.h"
#include <vector>
#include "strategie.h"
#include "historique.h"

class Poursuivant : public Joueur
{
    /*! \class Poursuivant
       * \brief classe representant le Poursuivant
       *
       */
private:
    const int rayonAction; /*!< rayon d'action du poursuivant*/
    std::vector<Strategie*> tStrategiesDecouvertes; /*!<  ensemble des stratégies du fuyard découvertes par le poursuivant*/
    const bool visibiliteFuyard; /*!< true si on connait la position du fuyard, false si on a seulement sa distance*/
    const int profondeurHistorique;  /*!< taille de la mémoire des coups joués, 0 pour infini*/
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Poursuivant
         *
         * \param rayonAction : le rayon d'action du poursuivant
         * \param visibiliteFuyard : true si le poursuivant connait la position exacte du fuyard, false sinon
         * \param pos : la position de départ du poursuivant
         */
    Poursuivant(int rayonAction,bool visibiliteFuyard,int profondeurHistorique,Position pos);

    /*!
        *  \brief Donner la décision de déplacement
        *
        *  Methode qui permet au poursuivant de rendre sa décision
        * concernant son prochain déplacement
        *
        *  \param historiqueJeu : l'historique du jeu
        *  \return un objet Position contenant la prochaine position
        * du poursuivant
        */
    Position donnerDecision(const Historique& historiqueJeu)const;
    /*!
        *  \brief Etape d'apprentissage du poursuivant
        *
        *  Methode qui permet au poursuivant d'apprendre les stratégies du fuyard
        * en fonction des coups joués (donc de l'historique)
        *
        *  \param historiqueJeu : l'historique du jeu
        */
    void apprentissage(const Historique& historiqueJeu);
};

#endif // POURSUIVANT_H
