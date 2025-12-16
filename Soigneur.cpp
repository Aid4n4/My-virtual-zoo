#include <iostream>
#include "Soigneur.hpp"
using namespace std;

Soigneur::Soigneur(const string& _nom, const string& _prenom) : Personne(_nom, _prenom), enclos_assigne(nullptr) {};

void Soigneur::assigner_enclos(Enclos* _enclos_assigne) {
    enclos_assigne = _enclos_assigne;
    if (_enclos_assigne) {
        _enclos_assigne->setSoigneur(this);
    }
};

void Soigneur::verification_statut_tous() const {
    if (!enclos_assigne) {
        cout << "Aucun enclos n'est assigne au soigneur." << endl;
        return;
    }

    for (const auto& animal : enclos_assigne->getAnimaux()) {
        animal.verification_statut();
    }
};

void Soigneur::remplir_nourriture_enclos(int date_actuelle) {
    enclos_assigne->remplissage_nourriture(date_actuelle);
};

void Soigneur::soigner(Animal& animal) {
    if (animal.getSante() == false) {
        animal.changement_statut_sante(true);
    }
    else {
        cout << "Vous ne pouvez pas soigner cet animal, il est deja en bonne sante." << endl;
    }
};

void Soigneur::afficher_informations() const {
    cout << "Rôle : Soigneur" << endl;
    Personne::afficher_informations();

    if (enclos_assigne) {
        cout << "Enclos assigne : #" << enclos_assigne->getID() << endl;
    }
    else {
        cout << "Aucun enclos assigne" << endl;
    }
};
