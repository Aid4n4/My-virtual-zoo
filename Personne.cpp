#include <iostream>
#include "Personne.hpp"
using namespace std;

Personne::Personne(const string& nom, const string& prenom) : nom(nom), prenom(prenom) {};

void Personne::afficher_informations() const {
    cout << "Nom : " << nom << "    Prénom : " << prenom << endl;
};
