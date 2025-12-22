#include <iostream>
#include "Animal.hpp"
#include "Utilitaires.hpp"
using namespace std;

Animal::Animal(int _numero, const string& _nom) : numero(_numero), nom(_nom), sante(true), satiete(false), derniere_date_nourri(0) {};

void Animal::verification_statut() const{
    cout << "Animal #" << numero << " (" << nom << ")" << endl;
    pause(1);
    cout << "- Sante : " << (sante ? "Bonne" : "Mauvaise") << endl;
    cout << "- Satiete : " << (satiete ? "Rassasie" : "Affame") << endl;
    cout << "- Derniere date nourri : Jour " << derniere_date_nourri << endl;
};

void Animal::changement_statut_sante(bool nouvel_etat){
    sante = nouvel_etat;
};

void Animal::changement_statut_satiete(bool nouvel_etat){
    satiete = nouvel_etat;
};

void Animal::setDernierDateNourri(int date){
    derniere_date_nourri = date;
};

int Animal::getNumero() const {
    return numero;
};

string Animal::getNom() const {
    return nom;
};

bool Animal::getSante() const{
    return sante;
};

bool Animal::getSatiete() const{
    return satiete;
};
