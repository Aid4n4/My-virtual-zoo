#include <iostream>
#include <ctime>
#include "Zoo.hpp"
#include "Soigneur.hpp"
#include "Visiteur.hpp"
using namespace std;

int main() {
    srand(time(nullptr));
    
    cout << "-- Creation du zoo --" << endl;
    Zoo zoo;

    cout << "-- Creation des enclos --" << endl;
    Enclos enclos1(1, "Girafe", "Herbivore", "Plaine");
    Enclos enclos2(2, "Lion", "Carnivore", "Savane");

    cout << "-- Creation des animaux --" << endl;
    Animal girafe1(1, "Sophie");
    Animal girafe2(2, "Cunegonde");

    enclos1.ajout_animal(girafe1);
    enclos1.ajout_animal(girafe2);
    
    girafe1.verification_statut();
    
    Animal lion1(1, "Simba");
    Animal lion2(2, "Nala");

    enclos2.ajout_animal(lion1);
    enclos2.ajout_animal(lion2);

    zoo.ajouter_enclos(enclos1);
    zoo.ajouter_enclos(enclos2);
    
    cout << "Identifiant enclos : " << enclos1.getID() << "\n Nombre d'animaux : " << enclos1.getNombreAnimaux() << "\n Nourriture  : " << enclos1.getNourriture() << endl;

    cout << "Identifiant enclos : " << enclos2.getID() << "\n Nombre d'animaux : " << enclos2.getNombreAnimaux() << "\n Nourriture  : " << enclos2.getNourriture() << endl;
    
    cout << "-- Creation des soigneurs --" << endl;
    Soigneur soigneur1("Broillet", "Virgile", &enclos1);
    Soigneur soigneur2("Quoi", "Feur", &enclos2);

    soigneur1.verification_statut_tous();
    soigneur1.remplir_nourriture_enclos(0);
    soigneur2.remplir_nourriture_enclos(0);
    soigneur1.soigner(girafe1);

    cout << "Identifiant enclos : " << enclos1.getID() << "\n Nombre d'animaux : " << enclos1.getNombreAnimaux() << "\n Nourriture  : " << enclos1.getNourriture() << endl;

    cout << "Identifiant enclos : " << enclos2.getID() << "\n Nombre d'animaux : " << enclos2.getNombreAnimaux() << "\n Nourriture  : " << enclos2.getNourriture() << endl;

    cout << "-- Creation des visiteurs --" << endl;
    Visiteur visiteur1("Feur", "Nugget", 1 );
    
    visiteur1.acheter_billet("jeune (- de 18 ans)", 10);
    visiteur1.acheter_billet("retraite (65 et +)", 1);
    visiteur1.prix_total();

    Visiteur visiteur2("Aubert", "Lily", 2);
    visiteur2.acheter_billet("etudiant (18-25 ans)", 2);
    visiteur2.prix_total();

    zoo.ajouter_visiteur(visiteur1);
    zoo.ajouter_visiteur(visiteur2);

    cout << "-- Passer un jour --" << endl;
    zoo.passer_jour();

    cout << "-- Statistique du jour 0  --" << endl;
    cout << "Nombre billets vendus jour 0 : " << zoo.nombre_billets_jour(0) << endl;
    cout << "Benefice jour 0 : " << zoo.benefice_jour(0) << endl;

    cout << "-- Jour 2 --" << endl;
    soigneur1.verification_statut_tous();
    soigneur2.verification_statut_tous();
    return 0;
}
