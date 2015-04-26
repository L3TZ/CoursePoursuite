#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "jeu.h"
#include "notaire.h"
#include "historique.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

public slots:
    /*!
     * \brief recupValeur recupere les valeurs saisies par l'utilisateur
     *
     *  Methode qui permet de recuperer les valeurs saisies par l'utilisateur
     */
    void recupValeur();
    /*!
     * \brief quitterApplication quitter l'application
     *
     *  Methode qui permet de quitter l'application
     */
    void quitterApplication();

signals:
    /*!
     * \brief envoyerValeur envoie un signal pour recuperer les valeurs
     * \param position
     *
     *  Methode qui permet d'envoyer un signal pour recuperer les valeurs dans le jeu
     */
    void envoyerValeur(QString position);
    /*!
     * \brief quitter envoie un signal pour quitter l'application
     *
     *  Methode qui permet de quitter l'application
     */
    void quitter();
};

#endif // DIALOG_H
