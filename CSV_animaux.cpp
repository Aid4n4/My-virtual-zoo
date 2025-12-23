#include "CSV_animaux.hpp"
#include <fstream>
#include <sstream>
using namespace std;

/**
 * Charge les animaux depuis un fichier CSV et les stocke dans un vecteur.
 * La première ligne du fichier (en-tête) est ignorée.
 */
vector<Animal_modele> charger_animaux_csv(const string& fichier) {
    vector<Animal_modele> animaux;
    ifstream file(fichier);

    // Vérification de l'ouverture du fichier
    if (!file) return animaux;

    string ligne;

    // Ignorer la ligne d'en-tête du CSV
    getline(file, ligne);

    // Lecture de chaque ligne du fichier
    while (getline(file, ligne)) {
        stringstream ss(ligne);
        Animal_modele a;

        // Extraction des champs séparés par des virgules
        getline(ss, a.race, ',');
        getline(ss, a.regime, ',');
        getline(ss, a.type_enclos, ',');

        animaux.push_back(a);
    }

    return animaux;
};

/**
 * Ajoute un animal à la fin du fichier CSV.
 * Les informations sont écrites sur une nouvelle ligne.
 */
void ajouter_animal_csv(const string& fichier, const Animal_modele& animal) {
    ofstream file(fichier, ios::app);

    // Écriture des informations de l'animal dans le fichier CSV
    file << animal.race << "," << animal.regime << "," << animal.type_enclos << "\n";
};
