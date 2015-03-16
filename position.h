/**
 * \file position.h
 * \brief classe Position
 * \author Thomas Zoratto
 *
 *
 */

#ifndef POSITION_H
#define POSITION_H

#include <vector>

class Position
{
    /*! \class Position
       * \brief classe representant la Position d'un joueur
       *
       */
private:
    int x; /*!< coordonnée en X*/
    int y; /*!< coordonnée en Y*/
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Position
         * intialise une position à 0,0
         */
    Position();
    /*!
         *  \brief Constructeur
         *
         *  Constructeur paramétré de la classe Position
         *
         * \param x : la coordonnée en X
         * \param y : la coordonnée en Y
         */
    Position(int x,int y);
    /*!
        *  \brief get la coordonée en X
        *
        *
        * \return la coordonnée en X
        *
        */
    int getX()const;
    /*!
        *  \brief get la coordonnée en Y
        *
        *
        * \return la coordonnée en Y
        *
        */
    int getY()const;
    /*!
        *  \brief set la coordonnée en X
        *
        *
        * \param x : la coordonnée en X
        *
        */
    void setX(int x);
    /*!
        *  \brief set la coordonnée en Y
        *
        *
        * \param x : la coordonnée en Y
        *
        */
    void setY(int y);
    /*!
        *  \brief Affichage
        *
        *   affiche la Position sur la sortie standard
        *
        */
    void affiche()const;

    /*!
        *  \brief Méthode statique de calcul de distance
        *
        * calcule la distance entre 2 Position.
        * Cela correspond au nombre de déplacement (case par case) minimal nécessaire
        * pour rejoindre la position du fuyard depuis la position du poursuivant
        *
        * \param posPoursuivant : la position du poursuivant
        * \param posFuyard : la position du fuyard
        * \return la distance (en int)
        *
        */
    static int calculDistance(const Position& posPoursuivant,const Position& posFuyard);
    /*!
        *  \brief Méthode statique de calcul du cercle des positions possibles du fuyard
        *
        * calcule le cercle des positions possibles du fuyard en fonction de la position
        * du poursuivant et de la distance du fuyard
        *
        * \param posPoursuivant : la position du poursuivant
        * \param disanceFuyard : la distance du fuyard par rapport au poursuivant
        * \return vector de Position possibles pour le fuyard
        *
        */
    static std::vector<Position> cerclePosition(const Position& posPoursuivant,int distanceFuyard);
    /*!
        *  \brief Méthode statique de calcul de l'intersection de 2 cercles de Position
        *
        *   calcule un nouvel ensemble de Position possibles pour le fuyard en fonction
        * des 2 ensembles de Position possibles aux tours t et t-1 et du rayon d'action du fuyard
        *
        * \param cercle1 : l'ensemble des Position possibles au tour t-1
        * \param cercle2 : l'ensemble des Position possibles au tour t sans prendre en compte le tour t-1
        * \param rayonActionFuyard : le rayon d'action du fuyard
        * \return le nouvel ensemble des Position possibles du fuyard au tour t en prenant en compte le tour t-1
        *
        */
    static std::vector<Position> intersectionCercle(const std::vector<Position> cercle1, const std::vector<Position> cercle2,int rayonActionFuyard);
    /*!
        *  \brief Méthode statique de calcul d'une position en fonction du rayon d'action
        *
        *   calcule une position en fonction de la position actuelle, d'une position cible et du rayon d'action.
        * Utilisée dans le cas ou le poursuivant a un rayon d'action limité
        *
        * \param posActuelle : position actuelle du poursuivant
        * \param posCible : position que le poursuivant voudrait atteindre
        * \param rayonAction : le rayon d'action du poursuivant
        * \return la position que le poursuivant a le droit d'atteindre en direction de la position cible
        *
        */
    static Position reductionRayonAction(const Position& posActuelle,const Position& posCible,int rayonAction);
    /*!
        *  \brief opérateur d'égalité
        *
        * \param other : un objet Position à comparer
        * \return true si this équivaut à other, false sinon
        *
        */
    bool operator ==(const Position& other)const;
    /*!
        *  \brief opérateur d'inégalité
        *
        * \param other : un objet Position à comparer
        * \return false si this équivaut à other, true sinon
        *
        */
    bool operator !=(const Position& other)const;
};

#endif // POSITION_H
