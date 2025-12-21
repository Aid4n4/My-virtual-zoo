#ifndef VISITEUR_HPP
#define VISITEUR_HPP

#include "Personne.hpp"
#include <map>
using namespace std;

class Visiteur : public Personne
{
private:
    int numero_client;
    map<string, int> billets;
    static map<string, int> prix_billet;

public:
    Visiteur(const string& _nom, const string& _prenom, int _numero_client);

    void acheter_billet(const string& type_billet, int quantite);
    int prix_total() const;
    
    void afficher_informations() const override;

    int getNumeroClient() const;
    const map<string, int>& getBillets() const;
    static const map<string, int>& getPrixBillet();
};

#endif
