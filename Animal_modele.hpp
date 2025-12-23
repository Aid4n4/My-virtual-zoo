#ifndef ANIMAL_MODELE_HPP
#define ANIMAL_MODELE_HPP

#include <string>
using namespace std;

/**
 * @struct Animal_modele
 * @brief Structure représentant un modèle d'animal issu du fichier CSV.
 *
 * Cette structure sert à stocker les informations génériques d'un animal
 * disponibles dans le fichier CSV : sa race, son régime alimentaire
 * et le type d'enclos auquel il est associé.
 * Elle est utilisée lors du chargement et de l'ajout d'animaux dans le zoo.
 */
struct Animal_modele {
    string race; // Nom de la race de l'animal
    string regime; // Régime alimentaire (Herbivore, Carnivore, Omnivore)
    string type_enclos; // Type d'enclos adapté à l'animal
};

#endif
