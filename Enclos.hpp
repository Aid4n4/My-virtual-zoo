#ifndef ENCLOS_HPP
#define ENCLOS_HPP

#include <string>
#include <vector>
#include "Animal.hpp"
using namespace std;

class Soigneur; // Déclaration anticipée pour éviter une dépendance circulaire

/**
 * @class Enclos
 * @brief Représente un enclos du zoo.
 *
 * Un enclos contient un ensemble d'animaux d'une même race,
 * possède un type et un régime alimentaire associés,
 * et peut être pris en charge par un soigneur.
 * Il gère également la nourriture des animaux qu'il contient.
 */
class Enclos
{
private:
    int enclos_id; // Identifiant unique de l'enclos
    string race; // Race des animaux présents dans l'enclos
    string regime; // Régime alimentaire des animaux de l'enclos
    string type_enclos; // Type d'enclos (savane, forêt, etc.)
    bool nourriture; // Indique si la nourriture est présente dans l'enclos
    vector<Animal> animaux; // Liste des animaux présents dans l'enclos
    Soigneur* soigneur; // Soigneur assigné à l'enclos

public:
    /**
     * @brief Constructeur de la classe Enclos.
     *
     * @param _id : Identifiant de l'enclos
     * @param _race : Race des animaux hébergés
     * @param _regime : Régime alimentaire associé
     * @param _type_enclos : Type d'enclos
     */
    Enclos(int _id, const string& _race, const string& _regime, const string& _type_enclos);

    /**
     * @brief Ajoute un animal à l'enclos.
     *
     * Vérifie l'unicité du numéro et du nom de l'animal
     * avant de l'ajouter à la liste.
     *
     * @param nouvel_animal : Animal à ajouter
     * @return true si l'ajout a réussi, false sinon
     */
    bool ajout_animal(const Animal& nouvel_animal);

    /**
     * @brief Remplit la nourriture de l'enclos.
     *
     * Met à jour l'état de satiété de tous les animaux
     * et enregistre la date du dernier repas.
     *
     * @param date_actuelle Jour actuel du zoo
     * @return true si le remplissage a été effectué, false si déjà rempli
     */
    bool remplissage_nourriture(int date_actuelle);

    /**
     * @brief Affiche les informations de l'enclos.
     */
    void afficher_informations() const;

    // =======
    // Setters
    // =======

    /**
     * @brief Définit l'état de la nourriture dans l'enclos.
     *
     * @param etat : true si la nourriture est présente, false sinon
     */
    void setNourriture(bool etat);

    /**
     * @brief Assigne un soigneur à l'enclos.
     *
     * @param _soigneur : Pointeur vers le soigneur responsable de l'enclos
     */
    void setSoigneur(Soigneur* _soigneur);

    // =======
    // Getters
    // =======

    /**
     * @return Identifiant unique de l'enclos
     */
    int getID() const;

    /**
     * @return Race des animaux
     */
    string getRace() const;

    /**
     * @return Nombre d'animaux
     */
    int getNombreAnimaux() const;

    /**
     * @return true si la nourriture est présente, false sinon
     */
    bool getNourriture() const;

    /**
     * @brief Donne accès à la liste des animaux de l'enclos.
     *
     * Version modifiable permettant d'altérer l'état des animaux
     * (soins, alimentation, etc.).
     *
     * @return Référence vers le vecteur d'animaux
     */
    vector<Animal>& getAnimaux();
    
    /**
     * @brief Donne un accès en lecture seule à la liste des animaux.
     *
     * Empêche toute modification directe des animaux.
     *
     * @return Référence constante vers le vecteur d'animaux
     */
    const vector<Animal>& getAnimaux() const;
    
    /**
     * @return Pointeur vers le soigneur ou nullptr si aucun n'est assigné
     */
    Soigneur* getSoigneur() const;
};

#endif
