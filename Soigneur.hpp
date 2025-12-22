#ifndef SOIGNEUR_HPP
#define SOIGNEUR_HPP

#include "Personne.hpp"
#include "Enclos.hpp"
using namespace std;

class Soigneur : public Personne
{
private:
    Enclos* enclos_assigne;

public:
    Soigneur(const string& _nom, const string& _prenom);
    
    void assigner_enclos(Enclos* _enclos_assigne);
    void verification_statut_tous() const;
    void remplir_nourriture_enclos(int date_actuelle);
    void soigner(Animal& animal);

    void afficher_informations() const override;

    Enclos* getEnclos() const;
};

#endif
