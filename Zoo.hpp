#ifndef ZOO_HPP
#define ZOO_HPP

#include <vector>
#include <map>
#include "Enclos.hpp"
#include "Soigneur.hpp"
#include "Visiteur.hpp"
using namespace std;

class Zoo
{
private:
    string nom;
    int date_actuelle;
    vector<Enclos> enclos;
    vector<Soigneur> soigneurs;
    vector<Visiteur> visiteurs;
    map<int, vector<Visiteur>> billets_par_jour;
public:
    Zoo(const string& _nom);
    
    void ajouter_visiteur(const Visiteur& _visiteur);
    bool ajouter_soigneur(Soigneur& _soigneur, Enclos& _enclos);
    void ajouter_enclos(const Enclos& _enclos);
    void simuler_sante_animaux();
    void generer_visiteurs_aleatoires();
    void passer_jour();
    int nombre_billets_jour(int jour) const;
    int benefice_jour(int jour) const;
    void afficher_informations() const;

    string getNom() const;
    int getDateActuelle() const;
    int getDernierJour() const;
    Enclos& getEnclos(size_t index); // version modifiable
    const Enclos& getEnclos(size_t index) const; // version lecture
    vector<Soigneur>& getSoigneurs(); // version modifiable
    const vector<Soigneur>& getSoigneurs() const; // version lecture
    map<int, vector<Visiteur>> getBilletsParJour() const;
};

#endif
