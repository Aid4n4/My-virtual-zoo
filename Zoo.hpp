#ifndef ZOO_HPP
#define ZOO_HPP

#include <vector>
#include <map>
#include "Enclos.hpp"
#include "Visiteur.hpp"
using namespace std;

class Zoo
{
private:
    int date_actuelle;
    vector<Enclos> enclos;
    vector<Visiteur> visiteurs;
    map<int, vector<Visiteur>> billets_par_jour;

public:
    Zoo();
    
    void ajouter_visiteur(const Visiteur& nouveau_visiteur);
    void ajouter_enclos(const Enclos& e);
    void simuler_sante_animaux();
    void passer_jour();
    int nombre_billets_jour(int jour) const;
    int benefice_jour(int jour) const;
};

#endif
