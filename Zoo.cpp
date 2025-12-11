#include <iostream>
#include <map>
#include "Zoo.hpp"
#include "Animal.cpp"

using namespace std;

Zoo::Zoo() : date_actuelle(0) {}

void Zoo::ajouter_visiteur(const Visiteur& nouveau_visiteur){ // ajoute des visiteurs dans le parc
    visiteurs.push_back(nouveau_visiteur);
};

void Zoo::simuler_sante_animaux(){ //Donne aux animaux un état de santé aléatoire (en bonne santé ou pas) (true/false)
    for (Enclos& e :enclos){
         for (Animal& a : e.getAnimaux()) {
            a.setSante(tirage_aleatoire());
        }
    }

};
    

void Zoo::passer_jour(){ //passe au jour suivant de la simulation si certaines conditions sont remplies
    for(const Enclos& e : enclos) {
        for (const Animal& a : e.getAnimaux()) {
            if (!a.getSante() || !a.getSatiete()) { // si les animaux sont nourris et en bonne santé
                cout << "Vous ne pouvez pas passer au jour suivant, occupez vous de tous les animaux avant ! " << endl; // sinon affiche ce message
            }
        }
    }

    simuler_sante_animaux(); 
    billets_par_jour[date_actuelle] = visiteurs; // prends ensuite en compte le nombre de billets vendus
    date_actuelle++; //augmente d'un jour la date
    visiteurs.clear(); //remet a 0 le nombre de visiteurs de la journée pour les stats
    for (Enclos& e : enclos) {
        for (Animal& a : e.getAnimaux()) {
            a.setSatiete(false); // donne faim aux animaux
        }
    }
};

int Zoo::nombre_billets_jour(int jour) const{ //calcule le nombre de billets vendus par jour
    int total = 0;
    auto it = billets_par_jour.find(jour);
    if (it == billets_par_jour.end()) return 0;

    for (const Visiteur& v : it->second) {
        total += v.getQuantiteBillets();
    }

    return total;

};

int Zoo::benefice_jour(int jour) const{ //calcule les bénéfices réalisés par le parc pour une journée
    int total = 0;
    auto it = billets_par_jour.find(jour);
    if (it == billets_par_jour.end()) return 0;

    for (const Visiteur& v : it->second) {
        total+= v.prix_total();

        return total;
    }
};

map<int, vector<Visiteur>> Zoo::getBilletsParJour() const{
    return billets_par_jour;
};


