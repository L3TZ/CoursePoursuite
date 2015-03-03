/**
 * \file notaire.h
 * \brief classe Notaire
 * \author Thomas Zoratto
 *
 *
 */

#ifndef NOTAIRE_H
#define NOTAIRE_H

#include "position.h"
#include "Exception/notaireexceptionaucunedecision.h"

class Notaire
{
    /*! \class Notaire
       * \brief classe representant le Notaire
       *
       */
private:
    Position* fuyardDecision;   /*!< contient la décision du fuyard pour le tour courant*/
    Position* poursuivantDecision;   /*!< contient la décision du poursuivant pour le tour courant*/
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Notaire
         */
    Notaire();
    /*!
         *  \brief Constructeur
         *
         *  Constructeur copie de la classe Notaire
         */
    Notaire(const Notaire& notaire);
    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe Notaire
         */
    virtual ~Notaire();
    /*!
        *  \brief get la decision du fuyard
        *
        *
        * \return la Position décision du fuyard pour le tour en cours
        *
        */
    Position getFuyardDecision()const;
    /*!
        *  \brief get la decision du poursuivant
        *
        *
        * \return la Position décision du poursuivant pour le tour en cours
        *
        */
    Position getPoursuivantDecision()const;
    /*!
        *  \brief set la decision du fuyard
        *
        * Méthode qui permet de d'enregistrer la décision du fuyard pour le tour en cours
        *
        * \param p : la Position décision du fuyard pour le tour en cours
        *
        */
    void setFuyardDecision(const Position& p);
    /*!
        *  \brief set la decision du poursuivant
        *
        * Méthode qui permet de d'enregistrer la décision du poursuivant pour le tour en cours
        *
        * \param p : la Position décision du poursuivant pour le tour en cours
        *
        */
    void setPoursuivantDecision(const Position& p);
    /*!
        *  \brief Est-ce que le tour est valide ?
        *
        *
        * \return true si le tour est valide (les décisions sont renseignées),
        * false sinon
        *
        */
    bool tourValide()const;
    /*!
        *  \brief Remise à zéro
        *
        * Méthode qui permet d'effacer les décisions des joueurs avant le tour suivant.
        * On l'appelle à la fin de chaque tour
        *
        *
        */
    void raz();
    /*!
        *  \brief Opérateur d'affectation
        *
        *
        * \param notaire : le notaire que l'on veut affecter
        *
        */
    Notaire& operator=(const Notaire& notaire);
};

#endif // NOTAIRE_H
