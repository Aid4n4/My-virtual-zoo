/*Exercice 1, 2, 3
+--------------------------------------+
|               Zoo               |
+--------------------------------------+
| Attributs
date_actuelle : int
enclos : vector<Enclos>
visiteurs : vector<Visiteur>
billets_par_jour : map<int, vector<Visiteur>> → historique des visiteurs par jour => vérifie la structure de map + quelle librairie pour map
Méthodes
ajouter_visiteur : void → (Visiteur nouveau_visiteur)
Ajouter nouveau_visiteur dans visiteurs
simuler_sante_animaux : void → ()
Parcours tous les animaux de tous les enclos
Pour chaque animal : santé = tirage_aléatoire()
passer_jour : void → ()
Vérifier que tous les animaux dans tous les enclos ont : santé = true, satiété = true SINON ERREUR
simuler_sante_animaux()
billets_par_jour[date_actuelle, this] = visiteurs ; le this se réfère au visiteur pointé par l'instance de base, si ce n’est pas voulu, mettre a jour  
incrémente date_actuelle
visiteurs.clear()
pour tous les enclos : pour tous les animaux : changement_statut_satiété(false)
nombre_billets_jour : int → Visiteur : (int jour) 
Parcours billets_par_jour[jour, this]
Somme toutes les quantités de billets de chaque visiteur
bénéfice_jour : int → (int jour)
Parcours billets_par_jour[jour, this]
Somme de visiteurs.prix_total() pour chaque visiteur
Relations
Zoo contient plusieurs Visiteur → agrégation
Zoo contient plusieurs Enclos → agrégation         |
+--------------------------------------+
*/

#include <iostream>
#include "Zoo.hpp"
using namespace std;

Zoo::Zoo() : 
void Zoo::ajouter_visiteur(const Visiteur& nouveau_visiteur){
    Visiteur.push_back(nouveau_visiteur);
};

void Zoo::simuler_sante_animaux();{
    
}
void Zoo::passer_jour(){
    if animaux
};

int Zoo::nombre_billets_jour(int jour) const;
int Zoo::benefice_jour(int jour) const;

map<int, vector<Visiteur>> Zoo::getBilletsParJour() const{
    return billets_par_jour;
};


