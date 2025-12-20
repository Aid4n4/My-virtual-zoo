#include "CSV_animaux.hpp"
#include <fstream>
#include <sstream>
using namespace std;

vector<Animal_modele> charger_animaux_csv(const string& fichier) {
    vector<Animal_modele> animaux;
    ifstream file(fichier);

    if (!file) return animaux;

    string ligne;
    getline(file, ligne);

    while (getline(file, ligne)) {
        stringstream ss(ligne);
        Animal_modele a;

        getline(ss, a.race, ',');
        getline(ss, a.regime, ',');
        getline(ss, a.type_enclos, ',');

        animaux.push_back(a);
    }

    return animaux;
};

void ajouter_animal_csv(const string& fichier, const Animal_modele& animal) {
    ofstream file(fichier, ios::app);
    file << animal.race << "," << animal.regime << "," << animal.type_enclos << "\n";
};