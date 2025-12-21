#include <iostream>
#include "Enclos.hpp"
#include "Soigneur.hpp"
using namespace std;

Enclos::Enclos(int _id, const string& _race, const string& _regime, const string& _type_enclos) : enclos_id(_id), race(_race), regime(_regime), type_enclos(_type_enclos), nourriture(false), soigneur(nullptr) {}

void Enclos::ajout_animal(const Animal& nouvel_animal){
    for (const auto& animal : animaux) {
        if (animal.getNumero() == nouvel_animal.getNumero()) {
            cout << "Erreur : un animal avec le numero " << nouvel_animal.getNumero() << " existe deja dans cet enclos." << endl;
            return; 
        }

        if (animal.getNom() == nouvel_animal.getNom()) {
            cout << "\nErreur : un animal avec le nom \"" << nouvel_animal.getNom() << "\" existe deja dans cet enclos." << endl;
            return; 
        }
    }
    animaux.push_back(nouvel_animal);
    cout << "\n" << race << " \"" << nouvel_animal.getNom() << "\" ajouter avec succes dans l'enclos #" << enclos_id << "." << endl;
};

void Enclos::remplissage_nourriture(int date_actuelle){
    if (nourriture == true){
        return;
    }
    
    nourriture = true;
    for (auto& animal : animaux) {
        animal.changement_statut_satiete(true);
        animal.setDernierDateNourri(date_actuelle);
    }
};

void Enclos::afficher_informations() const {
    cout << "Enclos #" << enclos_id << "\n" 
    << "    Race : " << race << "\n" 
    << "    Regime : " << regime << "\n" 
    << "    Type : " << type_enclos << "\n"
    << "    Nombre d'animaux : " << animaux.size() << endl;
    if (soigneur) {
        cout << "    Soigneur assigne : " << soigneur->getNom() << " " << soigneur->getPrenom() << endl;
    }
    else {
        cout << "    Soigneur assigne : Aucun" << endl;
    }
};

void Enclos::setNourriture(bool etat) {
    nourriture = etat;
};

void Enclos::setSoigneur(Soigneur* _soigneur) {
    soigneur = _soigneur;
};

int Enclos::getID() const{
    return enclos_id;
};

string Enclos::getRace() const{
    return race;
};

int Enclos::getNombreAnimaux() const{
    return animaux.size();
};

bool Enclos::getNourriture() const{
    return nourriture;
};

vector<Animal>& Enclos::getAnimaux() {
    return animaux;
};

const vector<Animal>& Enclos::getAnimaux() const{
    return animaux;
};

Soigneur* Enclos::getSoigneur() const {
    return soigneur;
};
