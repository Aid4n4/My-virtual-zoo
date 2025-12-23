#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
using namespace std;

/**
 * @class Animal
 * @brief Représente un animal du zoo.
 *
 * La classe Animal modélise un animal présent dans un enclos du zoo.
 * Chaque animal possède une identité, un état de santé, un état de satiété
 * ainsi qu'une information sur la dernière date à laquelle il a été nourri.
 * 
 * Cette classe permet de consulter et modifier ces états au cours de la simulation
 */

class Animal
{
private:
    int numero; // Identifiant unique de l'animal dans l'enclos
    string nom; // Nom donné à l'animal
    bool sante; // État de santé (true = bonne santé, false = malade)
    bool satiete; // État de satiété (true = rassasié, false = affamé)
    int derniere_date_nourri; // Jour de la dernière alimentation de l'animal

public:
    /**
     * @brief Constructeur de la classe Animal.
     * @param _numero : Numéro d'identification de l'animal
     * @param _nom : Nom de l'animal
     *
     * À la création, l'animal est en bonne santé,
     * affamé et n'a encore jamais été nourri.
     */
    Animal(int _numero, const string& _nom);

    /**
     * @brief Affiche l'état actuel de l'animal (santé, satiété, dernière date nourri).
     */
    void verification_statut() const;

    /**
     * @brief Modifie l'état de santé de l'animal.
     * @param nouvel_etat : true si l'animal est en bonne santé, false sinon
     */
    void changement_statut_sante(bool nouvel_etat);

    /**
     * @brief Modifie l'état de satiété de l'animal.
     * @param nouvel_etat : true si l'animal est rassasié, false sinon
     */
    void changement_statut_satiete(bool nouvel_etat);

    /**
     * @brief Définit la dernière date à laquelle l'animal a été nourri.
     * @param date : Jour du nourrissage
     */
    void setDernierDateNourri(int date);

    // =======
    // Getters
    // =======

    /**
     * @return Numéro de l'animal
     */
    int getNumero() const;

    /**
     * @return Nom de l'animal
     */
    string getNom() const;

    /**
     * @return true si l'animal est en bonne santé, false sinon
     */
    bool getSante() const;

    /**
     * @return true si l'animal est rassasié, false sinon
     */
    bool getSatiete() const;
};

#endif
