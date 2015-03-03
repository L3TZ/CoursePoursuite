/**
 * \file strategie.h
 * \brief classe Strategie
 * \author Thomas Zoratto
 *
 *
 */

#ifndef STRATEGIE_H
#define STRATEGIE_H

#include <vector>
#include "position.h"

class Strategie
{
    /*! \class Strategie
       * \brief classe representant les stratégies du fuyard
       *
       */
private:
    const int rayonActionFuyard; /*!< rayon d'action du fuyard*/
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Strategie
         *
         * \param rayonActionFuyard : le rayon d'action du fuyard
         */
    Strategie(int rayonActionFuyard);
    /*!
        *  \brief get du rayon d'action du fuyard
        *
        *  \return le rayon d'action du fuyard
        */
    int getRayonActionFuyard()const;

    /*!
        *  \brief Calcul de la décision du fuyard
        *
        *  Methode qui permet de calculer le prochain coup du fuyard en fonction de ses stratégies
        * et des positions des 2 joueurs
        *
        *  \param tStrategies : l'ensemble des stratégies du fuyard
        * \param posFuyard : la position du fuyard
        * \param posPoursuivant : la position du poursuivant
        *  \return un objet Position contenant la décision du fuyard
        */
    virtual Position decisionFuyard(const std::vector<Strategie*>& tStrategies,const Position& posFuyard,const Position& posPoursuivant)const=0;
    /*!
        *  \brief Calcul de la décision du poursuivant
        *
        *  Methode qui permet de calculer le déplacement du poursuivant en fonction
        *  des stratégies qu'il a découvert et des positions des 2 joueurs.
        * Cette méthode est utilisée si le poursuivant connait la position exacte du fuyard
        *
        *  \param tStrategiesDecouvertes : l'ensemble des stratégies du fuyard découvertes par le poursuivant
        * \param posFuyard : la position du fuyard
        * \param posPoursuivant : la position du poursuivant
        * \param rayonActionPoursuivant : le rayon d'action du poursuivant
        *  \return un objet Position contenant la décision du poursuivant
        */
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const Position& posFuyard,const Position& posPoursuivant,int rayonActionPoursuivant)const=0;
    /*!
        *  \brief Calcul de la décision du poursuivant
        *
        *  Methode qui permet de calculer le déplacement du poursuivant en fonction
        *  des stratégies qu'il a découvert, de sa position et de la distance du fuyard.
        * Cette méthode est utilisée si le poursuivant connait uniquement la distance du fuyard
        *
        *  \param tStrategiesDecouvertes : l'ensemble des stratégies du fuyard découvertes par le poursuivant
        * \param posFuyardPossibles : l'ensemble des positions possibles du fuyard
        * \param posPoursuivant : la position du poursuivant
        * \param rayonActionPoursuivant : le rayon d'action du poursuivant
        *  \return un objet Position contenant la décision du poursuivant
        */
    virtual Position decisionPoursuivant(const std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Position>& posFuyardPossibles,const Position& posPoursuivant,int rayonActionPoursuivant)const=0;
    /*!
        *  \brief Apprentissage des stratégies du fuyard par le poursuivant
        *
        *  Methode qui permet de d'ajouter une stratégie du fuyard aux stratégies découvertes
        * par le poursuivant en fonction du dernier coup du fuyard. Cette méthode est utilisée si le poursuivant connait la position exacte du fuyard
        *
        *  \param tStrategiesDecouvertes : l'ensemble des stratégies du fuyard découvertes par le poursuivant
        * \param tStrategiesFuyard : l'ensemble des stratégies du fuyard
        * \param dernierePosPoursuivant : position du poursuivant au tour t-1
        * \param dernierePosFuyard : la position du fuyard au tour t-1
        * \param nouvellePosFuyard : la position du fuyard au tour t
        */
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const Position& dernierePosFuyard,const Position& nouvellePosFuyard)const=0;
    /*!
        *  \brief Apprentissage des stratégies du fuyard par le poursuivant
        *
        *  Methode qui permet de d'ajouter une stratégie du fuyard aux stratégies découvertes
        * par le poursuivant en fonction du dernier coup du fuyard. Cette méthode est utilisée si le poursuivant connait uniquement la distance du fuyard
        *
        *  \param tStrategiesDecouvertes : l'ensemble des stratégies du fuyard découvertes par le poursuivant
        * \param tStrategiesFuyard : l'ensemble des stratégies du fuyard
        * \param dernierePosPoursuivant : position du poursuivant au tour t-1
        * \param dernieresPosPossiblesFuyard : l'ensemble des positions possibles du fuyard au tour t-1
        * \param nouvellesPosPossiblesfuyard : l'ensemble des positions possibles du fuyard au tour t
        */
    virtual void apprentissagePoursuivant(std::vector<Strategie*>& tStrategiesDecouvertes,const std::vector<Strategie*>& tStrategiesFuyard,const Position& dernierePosPoursuivant,const std::vector<Position>& dernieresPosPossiblesFuyard,const std::vector<Position>& nouvellesPosPossiblesfuyard)const=0;    //met à jour les stratégies découvertes par P en fonction du dernier déplacement de F ne sachant pas sa position exacte
};

#endif // STRATEGIE_H
