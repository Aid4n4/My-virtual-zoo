#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
using namespace std;

class Animal
{
private:
    int numero;
    string nom;
    bool sante;
    bool satiete;
    int derniere_date_nourri;

public:
    Animal(int _numero, const string& _nom);

    void verification_statut() const;
    void changement_statut_sante(bool nouvel_etat);
    void changement_statut_satiete(bool nouvel_etat);

    void setDernierDateNourri(int date);

    int getNumero() const;
    string getNom() const;
    bool getSante() const;
    bool getSatiete() const;
};

#endif
