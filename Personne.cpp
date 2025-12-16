#include <iostream>
#include "Personne.hpp"
using namespace std;

Personne::Personne(const string& _nom, const string& _prenom) : nom(_nom), prenom(_prenom) {};

void Personne::afficher_informations() const {
    cout << "Nom : " << nom << "    Prénom : " << prenom << endl;
};

string Personne::getNom() const {
    return nom;
};

string Personne::getPrenom() const {
    return prenom;
};
