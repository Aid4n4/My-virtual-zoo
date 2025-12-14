#include <iostream>
#include "Zoo.hpp"
#include "Enclos.hpp"
#include "Animal.hpp"
#include "Soigneur.hpp"
#include "Visiteur.hpp"
using namespace std;

int main() {
    cout << "-- Création du zoo --";
    Zoo zoo;

    Enclos enclos1(1, "Girafe", "Herbivore", "Plaine");
    Enclos enclos2(2, "Lion", "Carnivore", "Savane");

    zoo.ajouter_enclos(enclos1);
    zoo.ajouter_enclos(enclos2);

    Animal lion1(1, "Simba");
    Animal lion2(2, "Nala");

    return 0;
}
