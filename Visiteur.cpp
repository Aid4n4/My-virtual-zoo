#include <iostream>
#include <map>
#include "Visiteur.hpp"
using namespace std;

map<string, int> Visiteur::prix_billet = {
    {"enfant (- de 5 ans)", 0},
    {"jeune (- de 18 ans)", 8},
    {"etudiant (18-25 ans)", 10},
    {"adulte", 15},
    {"retraite (65 et +)", 12},
    {"handicape", 0},
};

Visiteur::Visiteur(const string& _nom, const string& _prenom, int _numero_client) : Personne(_nom, _prenom), numero_client(_numero_client) {};

void Visiteur::acheter_billet(const string& type_billet, int quantite) {
    billets[type_billet] += quantite;
};

int Visiteur::prix_total() const {
    int total = 0;
    for (const auto& b : billets) {
        const string& type = b.first;
        int quantite = b.second;
        total += quantite * prix_billet[type];
    }
    return total;
};
    
void Visiteur::afficher_informations() const {
    cout << "Client #" << numero_client << endl;
    Personne::afficher_informations();
};

int Visiteur::getNumeroClient() const {
    return numero_client;
};

const map<string, int>& Visiteur::getBillets() const{
    return billets;
};
