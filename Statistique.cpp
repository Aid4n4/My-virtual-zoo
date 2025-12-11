/*Exercice 1, 2, 3
+--------------------------------------+
|               Etudiant               |
+--------------------------------------+
| - nom : string                       |
| - amendes : double                   |
| - fraisScolarite : double            |
+--------------------------------------+
| + Etudiant(nom : string)             |
| + Etudiant(nom : string,             |
|            amendes : double)         |
| + Etudiant(nom : string,             |
|            amendes : double,         |
|            frais : double)           |
| + const totalDu() : double           |
+--------------------------------------+
*/

#include <iostream>
#include "Etudiant.hpp"
using namespace std;

Etudiant::Etudiant(const string& _nom) : nom(_nom), amendes(0.0), fraisScolarite(0.0) {}

Etudiant::Etudiant(const string& _nom, double _amendes) : nom(_nom), amendes(_amendes), fraisScolarite(0.0) {}

Etudiant::Etudiant(const string& _nom, double _amendes, double _fraisScolarite) : nom(_nom), amendes(_amendes), fraisScolarite(_fraisScolarite) {}

Etudiant::Etudiant(const string& _nom, double _amendes, double _fraisScolarite, const Date& naissance) : nom(_nom), amendes(_amendes), fraisScolarite(_fraisScolarite), date_naissance(naissance) {}

double Etudiant::totalDu() const {
    return amendes + fraisScolarite;
}

string Etudiant::getNom() const {
    return nom;
}

double Etudiant::getAmendes() const {
    return amendes;
}

double Etudiant::getFraisScolarite() const {
    return fraisScolarite;
}

int Etudiant::getAge(const Date& date_actuelle) const {
    return date_naissance.calculerAge(date_actuelle);
};

void Etudiant::setNom(const std::string& _nom){
    nom = _nom;
}

void Etudiant::setAmendes(double _amendes) {
    if (_amendes >= 0.0) {
        amendes = _amendes;
    } else {
        cout << "Erreur : les amendes ne peuvent pas être négatives !" << endl;
    }
}

void Etudiant::setFraisScolarite(double _fraisScolarite) {
    fraisScolarite = _fraisScolarite;
}

void Etudiant::afficher() const{
    cout << "Etudiant : " << nom << endl;
    cout << "Date de naissance : " << date_naissance.getJour() << "/" << date_naissance.getMois() << "/" << date_naissance.getAnnee() << endl;
    cout << "Amendes de bibliotheque : " << amendes << " euros" << endl;
    cout << "Frais de scolarite : " << fraisScolarite << " euros" << endl;
    cout << "Total du : " << totalDu() << " euros" << endl;
}

