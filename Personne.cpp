#include <iostream>
#include "Personne.hpp"
using namespace std;

// Initialise le nom et le prénom de la personne
Personne::Personne(const string& _nom, const string& _prenom) : nom(_nom), prenom(_prenom) {};

// Affiche les informations de base de la personne
void Personne::afficher_informations() const {
    cout << "- Nom : " << nom << endl;
    cout << "- Prenom : " << prenom << endl;
};

string Personne::getNom() const {
    return nom;
};

string Personne::getPrenom() const {
    return prenom;
};
