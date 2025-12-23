#ifndef CSV_ANIMAUX_HPP
#define CSV_ANIMAUX_HPP

#include <vector>
#include <string>
#include "Animal_modele.hpp"
using namespace std;

/**
 * @brief Charge la liste des animaux disponibles depuis un fichier CSV.
 *
 * Cette fonction lit un fichier CSV contenant les informations des animaux
 * (race, régime, type d'enclos) et les stocke dans un vecteur de structures
 * 'Animal_modele'.
 *
 * @param fichier : Chemin du fichier CSV à lire
 * @return Vecteur contenant les modèles d'animaux chargés
 */
vector<Animal_modele> charger_animaux_csv(const string& fichier);

/**
 * @brief Ajoute un nouvel animal dans le fichier CSV.
 *
 * Cette fonction écrit les informations d'un animal à la fin du fichier CSV,
 * permettant d'enrichir dynamiquement la base de données des animaux.
 *
 * @param fichier : Chemin du fichier CSV
 * @param animal : Modèle d'animal à ajouter
 */
void ajouter_animal_csv(const string& fichier, const Animal_modele& animal);

#endif
