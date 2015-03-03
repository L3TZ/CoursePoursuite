/**
 * \file historique.h
 * \brief classe Historique
 * \author Thomas Zoratto
 *
 *
 */

#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <vector>
#include "position.h"

class Historique
{
    /*! \class Historique
       * \brief classe representant l'historique du jeu
       *
       */
private:
 std::vector<Position> histoFuyard; /*!< vector des Position du fuyard*/
 std::vector<Position> histoPoursuivant; /*!< vector des Position du poursuivant*/
 int nbTours; /*!< nombre de tours effectués*/
public:
 /*!
      *  \brief Constructeur
      *
      *  Constructeur de la classe Historique
      *initialise un historique vide
      */
    Historique();

    /*!
        *  \brief get nombre de tours
        *
        *
        *  \return le nombre de tours effectués
        */
    int getNbTours()const;
    /*!
        *  \brief Ajout d'une entrée
        *
        *  Methode qui permet d'ajouter une entrée (les informations d'un tour)
        * à l'historique
        *
        *  \param posFuyard : la position du fuyard pour le tour concerné
        * \param posPorsuivant : la position du poursuivant pour le tour concerné
        */
    void ajoutEntree(const Position& posFuyard,const Position& posPoursuivant);
    /*!
        *  \brief Lecture de l'historique du fuyard
        *
        *  Methode qui permet d'accéder à la position du fuyard à une certaine
        * profondeur de l'historique
        *
        *  \param ind : la profondeur à laquelle on s'interesse
        *  \return un objet Position contenant la position du fuyard à
        * la profondeur donnée
        */
    Position getPositionFuyard(int ind)const;
    /*!
        *  \brief Lecture de l'historique du poursuivant
        *
        *  Methode qui permet d'accéder à la position du poursuivant à une certaine
        * profondeur de l'historique
        *
        *  \param ind : la profondeur à laquelle on s'interesse
        *  \return un objet Position contenant la position du poursuivant à
        * la profondeur donnée
        */
    Position getPositionPoursuivant(int ind)const;
    /*!
        *  \brief Lecture de la dernière position du fuyard
        *
        *  Methode qui permet d'accéder à la dernière position du fuyard
        *
        *  \return un objet Position contenant la dernière position du fuyard
        */
    Position getDernierePositionFuyard()const;
    /*!
        *  \brief Lecture de la dernière position du poursuivant
        *
        *  Methode qui permet d'accéder à la dernière position du poursuivant
        *
        *  \return un objet Position contenant la dernière position du poursuivant
        */
    Position getDernierePositionPoursuivant()const;
};

#endif // HISTORIQUE_H
