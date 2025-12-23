#include <iostream>
#include <map>
#include "Visiteur.hpp"
using namespace std;

// Initialisation des prix des billets (statique, commun à tous les visiteurs)
map<string, int> Visiteur::prix_billet = {
    {"enfant (- de 5 ans)", 0},
    {"jeune (- de 18 ans)", 8},
    {"etudiant (18-25 ans)", 10},
    {"adulte", 15},
    {"retraite (65 et +)", 12},
    {"handicape", 0},
};

// Initialisation du visiteur avec son nom, prénom et numéro client
Visiteur::Visiteur(const string& _nom, const string& _prenom, int _numero_client) : Personne(_nom, _prenom), numero_client(_numero_client) {};

// Ajout de billets achetés au visiteur
void Visiteur::acheter_billet(const string& type_billet, int quantite) {
    billets[type_billet] += quantite; // Ajoute la quantité au type de billet existant
};

// Calcul du prix total des billets achetés par le visiteur
int Visiteur::prix_total() const {
    int total = 0;
    for (const auto& b : billets) {
        const string& type = b.first;
        int quantite = b.second;
        total += quantite * prix_billet[type]; // Prix unitaire multiplié par la quantité
    }
    return total;
};

// Affichage des informations du visiteur
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

const map<string, int>& Visiteur::getPrixBillet() {
    return prix_billet;
};
