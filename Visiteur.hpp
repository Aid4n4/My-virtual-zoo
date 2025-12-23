#ifndef VISITEUR_HPP
#define VISITEUR_HPP

#include "Personne.hpp"
#include <map>
using namespace std;

/**
 * @brief Classe représentant un visiteur du zoo.
 *
 * Hérite de la classe Personne et gère les billets achetés par le visiteur.
 * Chaque visiteur possède un numéro unique et un historique de billets achetés.
 */
class Visiteur : public Personne
{
private:
    int numero_client; // Numéro unique du visiteur
    map<string, int> billets; // Historique des billets achetés (type -> quantité)
    static map<string, int> prix_billet; // Prix fixe des différents types de billets (commun à tous les visiteurs) (type -> prix)

public:
    /**
     * @brief Constructeur du visiteur
     * @param _nom : Nom du visiteur
     * @param _prenom : Prénom du visiteur
     * @param _numero_client : Numéro unique du visiteur
     */
    Visiteur(const string& _nom, const string& _prenom, int _numero_client);

    /**
     * @brief Acheter un billet pour le visiteur
     * @param type_billet : Type de billet (clé dans prix_billet)
     * @param quantite : Nombre de billets à acheter
     */
    void acheter_billet(const string& type_billet, int quantite);
    
    /**
     * @brief Calcul du prix total des billets achetés
     * @return Total à payer pour le visiteur
     */
    int prix_total() const;
    
    /**
     * @brief Affiche les informations du visiteur
     */
    void afficher_informations() const override;

    // =======
    // Getters
    // =======

    /**
     * @return Numéro du client
     */
    int getNumeroClient() const;

    /**
     * @return const map<string,int>& : clés = type de billet, valeurs = quantités achetées
     */
    const map<string, int>& getBillets() const;

    /**
     * @return const map<string,int>& : clés = type de billet, valeurs = prix correspondant
     */
    static const map<string, int>& getPrixBillet();
};

#endif
