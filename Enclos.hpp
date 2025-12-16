#ifndef ENCLOS_HPP
#define ENCLOS_HPP

#include <string>
#include <vector>
#include "Animal.hpp"
using namespace std;

class Soigneur; 

class Enclos
{
private:
    int enclos_id;
    string race;
    string regime;
    string type_enclos;
    bool nourriture;
    vector<Animal> animaux;
    Soigneur* soigneur;

public:
    Enclos(int _id, const string& _race, const string& _regime, const string& _type_enclos);

    void ajout_animal(const Animal& nouvel_animal);
    void remplissage_nourriture(int date_actuelle);
    void afficher_informations() const;

    void setNourriture(bool etat);
    void setSoigneur(Soigneur* _soigneur);

    int getID() const;
    int getNombreAnimaux() const;
    bool getNourriture() const;
    vector<Animal>& getAnimaux(); //version modifiable
    const vector<Animal>& getAnimaux() const; //version lecture seule
    Soigneur* getSoigneur() const;
};

#endif
