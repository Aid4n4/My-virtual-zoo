#include <iostream>
#include "Animal.hpp"
using namespace std;

Animal::Animal(int _numero, const string& _nom) : numero(_numero), nom(_nom), sante(true), satiete(false), derniere_date_nourri(0) {};

void Animal::verification_statut() const{
    cout << "Animal #" << numero << " (" << nom << ")\n" 
    << "    Sante : " << (sante ? "Bonne" : "Mauvaise") << "\n" 
    << "    Satiete : " << (satiete ? "Rassasie" : "Affame") << "\n" 
    << "    Derniere date nourri : Jour n°" << derniere_date_nourri << endl;
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

bool Animal::getSante() const{
    return sante;
};

bool Animal::getSatiete() const{
    return satiete;
};
