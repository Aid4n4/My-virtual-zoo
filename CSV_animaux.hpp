#ifndef CSV_ANIMAUX_HPP
#define CSV_ANIMAUX_HPP

#include <vector>
#include <string>
#include "Animal_modele.hpp"
using namespace std;

vector<Animal_modele> charger_animaux_csv(const string& fichier);
void ajouter_animal_csv(const string& fichier, const Animal_modele& animal);

#endif
