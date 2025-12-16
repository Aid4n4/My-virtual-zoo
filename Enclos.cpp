#include <iostream>
#include "Enclos.hpp"
#include "Soigneur.hpp"
using namespace std;

Enclos::Enclos(int _id, const string& _race, const string& _regime, const string& _type_enclos) : enclos_id(_id), race(_race), regime(_regime), type_enclos(_type_enclos), nourriture(false), soigneur(nullptr) {}

void Enclos::ajout_animal(const Animal& nouvel_animal){
    animaux.push_back(nouvel_animal);
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
    << "    Nombre d'animaux : " << animaux.size() << "\n";
    if (soigneur) {
        cout << "   Soigneur assigné : " << soigneur->getNom() << " " << soigneur->getPrenom() << endl;
    }
    else {
        cout << "   Soigneur assigné : Aucun" << endl;
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
