#include <iostream>
#include <map>
#include <cstdlib>
#include "Zoo.hpp"
#include "Utilitaires.hpp"
using namespace std;

Zoo::Zoo(const string& _nom) : nom(_nom), date_actuelle(1) {}

Zoo::~Zoo() {
    for (auto soigneur : soigneurs) {
        delete soigneur;
    }
};

void Zoo::ajouter_visiteur(const Visiteur& _visiteur){ // ajoute des visiteurs dans le parc
    for (const auto& v : visiteurs) {
        if (v.getNumeroClient() == _visiteur.getNumeroClient()) {
            cout << "\nErreur : un visiteur avec le numero client " << _visiteur.getNumeroClient() << " existe deja dans le zoo." << endl;
            return; 
        }
    }
    visiteurs.push_back(_visiteur);
};

bool Zoo::ajouter_soigneur(Soigneur* _soigneur, Enclos& _enclos) {
    for (const auto& s : soigneurs) {
        if (s->getNom() == _soigneur->getNom() && s->getPrenom() == _soigneur->getPrenom()) {
            cout << "\nErreur : le soigneur \"" << _soigneur->getNom() << " " << _soigneur->getPrenom() << "\" existe deja dans le zoo.\n" << endl;
            return false; 
        }
    }
    _soigneur->assigner_enclos(&_enclos);
    soigneurs.push_back(_soigneur);
    return true;
};

void Zoo::ajouter_enclos(const Enclos& _enclos) {
    for (const auto& e : enclos) {
        if (e.getID() == _enclos.getID()) {
            cout << "\nErreur : un enclos avec l'ID " << _enclos.getID() << " existe deja dans le zoo." << endl;
            return; 
        }

        if (e.getRace() == _enclos.getRace()) {
            cout << "Erreur : un enclos avec la race \"" << _enclos.getRace() << "\" existe deja dans le zoo." << endl;
            return;
        }
    }
    enclos.push_back(_enclos);
    cout << "\nEnclos #" << _enclos.getID() << " contenant des \"" << _enclos.getRace() << "\" ajouter avec succes au zoo \"" << nom << "\"." << endl;
};

void Zoo::simuler_sante_animaux(){ //Donne aux animaux un état de santé aléatoire (en bonne santé ou pas) (true/false)
    for (auto& e : enclos){
        for (auto& animal : e.getAnimaux()) {
            bool tirage = (rand() % 100) < 70;
            cout << tirage << endl;
            animal.changement_statut_sante(tirage);
        }
    }
};

void Zoo::generer_visiteurs_aleatoires(){ //génère des visiteurs aléatoires pour le zoo
    vector<string> noms = {"Dupont", "Martin", "Bernard", "Dubois", "Thomas", "Robert", "Richard", "Petit", "Durand", "Leroy"};
    vector<string> prenoms = {"Jean", "Marie", "Pierre", "Michel", "Sophie", "Nathalie", "Laurent", "Isabelle", "Philippe", "Christine"};
    int nb_visiteurs = rand() % 5 + 1;
    
    for (int i = 0; i < nb_visiteurs; i++) {
        string nom = noms[rand() % noms.size()];
        string prenom = prenoms[rand() % prenoms.size()];
        int numero_client = visiteurs.size() + 1;

        Visiteur visiteur(nom, prenom, numero_client);

        int nb_billets = rand() % 10 + 1;

        vector<string> types_billet;
        for (const auto& billet : Visiteur::getPrixBillet()) {
            types_billet.push_back(billet.first);
        }
        for (int j = 0; j < nb_billets; j++) {
            string type_aleatoire = types_billet[rand() % types_billet.size()];
            visiteur.acheter_billet(type_aleatoire, 1);
        }

        ajouter_visiteur(visiteur);
    }
};

void Zoo::passer_jour(){ //passe au jour suivant de la simulation si certaines conditions sont remplies
    // Vérification avant de passer au jour suivant
    for(const auto& e : enclos) {
        for (const auto& animal : e.getAnimaux()) {
            if (!animal.getSante() || !animal.getSatiete()) { // si les animaux sont nourris et en bonne santé
                cout << "\nVous ne pouvez pas passer au jour suivant, occupez-vous de tous les animaux avant ! " << endl; // sinon affiche ce message
                return; // Condition d'arrêt
            }
        }
    }
    
    // Sinon passe au jour suivant
    simuler_sante_animaux();
    generer_visiteurs_aleatoires();
    billets_par_jour[date_actuelle] = visiteurs; // prends ensuite en compte le nombre de billets vendus
    date_actuelle++; //augmente d'un jour la date
    visiteurs.clear(); //remet a 0 le nombre de visiteurs de la journée pour les stats

    // Réinitialise l'état de faim des animaux
    for (auto& e : enclos) {
        e.setNourriture(false);
        for (auto& animal : e.getAnimaux()) {
            animal.changement_statut_satiete(false); // donne faim aux animaux
        }
    }
};

int Zoo::nombre_billets_jour(int jour) const{ //calcule le nombre de billets vendus par jour
    int total = 0;
    auto it = billets_par_jour.find(jour);
    if (it == billets_par_jour.end()){
        return 0;
    }

    for (const auto& v : it->second) {
        for (const auto& b : v.getBillets()) {
            const string& type = b.first;
            int quantite = b.second;
            total += quantite;
        }
    }

    return total;
};

int Zoo::benefice_jour(int jour) const{ //calcule les bénéfices réalisés par le parc pour une journée
    int total = 0;
    auto it = billets_par_jour.find(jour);
    if (it == billets_par_jour.end()){
        return 0;
    }

    for (const auto& v : it->second) {
        total += v.prix_total();
    }

    return total;
};

void Zoo::afficher_informations() const {
    int total_animaux = 0;
    for (const auto& e : enclos) {
        total_animaux += e.getNombreAnimaux();
    }
    cout << "- Nom du zoo : " << nom << endl;
    pause(1);
    cout << "- Jour actuel : " << date_actuelle << endl;
    pause(1);
    cout << "- Nombre d'enclos : " << enclos.size() << endl;
    pause(1);
    cout << "- Nombre total d'animaux : " << total_animaux << endl;
};

string Zoo::getNom() const {
    return nom;
};

int Zoo::getDateActuelle() const {
    return date_actuelle;
};

int Zoo::getDernierJour() const {
    return date_actuelle - 1;
};

Enclos& Zoo::getEnclos(size_t index){
    return enclos.at(index);
};

const Enclos& Zoo::getEnclos(size_t index) const{
    return enclos.at(index);
};

vector<Soigneur*>& Zoo::getSoigneurs() {
    return soigneurs;
};

const vector<Soigneur*>& Zoo::getSoigneurs() const {
    return soigneurs;
};

map<int, vector<Visiteur>> Zoo::getBilletsParJour() const{
    return billets_par_jour;
};
