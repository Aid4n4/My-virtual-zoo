#include <iostream>
#include <map>
#include <cstdlib>
#include "Zoo.hpp"
#include "Utilitaires.hpp"
using namespace std;

// Initialise le zoo avec un nom et une date de départ
Zoo::Zoo(const string& _nom) : nom(_nom), date_actuelle(1) {}

// Destructeur du zoo, libère la mémoire des soigneurs
Zoo::~Zoo() {
    for (auto soigneur : soigneurs) {
        delete soigneur;
    }
};

// Ajoute un visiteur au zoo
void Zoo::ajouter_visiteur(const Visiteur& _visiteur){ // ajoute des visiteurs dans le parc
    for (const auto& v : visiteurs) {
        if (v.getNumeroClient() == _visiteur.getNumeroClient()) {
            cout << "\nErreur : un visiteur avec le numero client " << _visiteur.getNumeroClient() << " existe deja dans le zoo." << endl;
            return; 
        }
    }
    visiteurs.push_back(_visiteur);
};

// Ajoute un soigneur au zoo et l'assigne à un enclos
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

// Ajoute un enclos au zoo
void Zoo::ajouter_enclos(const Enclos& _enclos) {
    for (const auto& e : enclos) {
        if (e.getID() == _enclos.getID()) {
            cout << "\nErreur : un enclos avec l'ID " << _enclos.getID() << " existe deja dans le zoo." << endl;
            return; 
        }

        if (e.getRace() == _enclos.getRace()) {
            cout << "\nErreur : un enclos avec la race \"" << _enclos.getRace() << "\" existe deja dans le zoo." << endl;
            return;
        }
    }
    enclos.push_back(_enclos);
    cout << "\nEnclos #" << _enclos.getID() << " contenant des \"" << _enclos.getRace() << "\" ajouter avec succes au zoo \"" << nom << "\"." << endl;
};

// Vérifie que tous les enclos ont de la nourriture
bool Zoo::tous_les_enclos_sont_remplis() const {
    for (const auto& e : enclos) {
        if (!e.getNourriture()) {
            return false;
        }
    }
    return true;
};

// Vérifie que tous les animaux sont en bonne santé
bool Zoo::tous_les_animaux_sont_soignes() const {
    for (const auto& e : enclos) {
        for (const auto& animal : e.getAnimaux()) {
            if (!animal.getSante()) {
                return false;
            }
        }
    }
    return true;
};

// Simule la santé des animaux du zoo (aléatoire)
void Zoo::simuler_sante_animaux(){
    for (auto& e : enclos){
        for (auto& animal : e.getAnimaux()) {
            bool tirage = (rand() % 100) < 50; // 50% de chances que l'animal soit en bonne santé
            animal.changement_statut_sante(tirage);
        }
    }
};

// Génère des visiteurs aléatoires pour le zoo
void Zoo::generer_visiteurs_aleatoires(){
    // Listes de noms et prénoms pour la génération aléatoire
    vector<string> noms = {"Dupont", "Martin", "Bernard", "Dubois", "Thomas", "Robert", "Richard", "Petit", "Durand", "Leroy"};
    vector<string> prenoms = {"Jean", "Marie", "Pierre", "Michel", "Sophie", "Nathalie", "Laurent", "Isabelle", "Philippe", "Christine"};

    int nb_visiteurs = rand() % 5 + 1; // Génère entre 1 et 5 visiteurs aléatoires
    
    // Boucle de création des visiteurs
    for (int i = 0; i < nb_visiteurs; i++) {
        // Génération aléatoire du nom, prénom et numéro client
        string nom = noms[rand() % noms.size()];
        string prenom = prenoms[rand() % prenoms.size()];
        int numero_client = visiteurs.size() + 1;

        // Création du visiteur
        Visiteur visiteur(nom, prenom, numero_client);

        int nb_billets = rand() % 10 + 1; // Chaque visiteur achète entre 1 et 10 billets

        // Achat aléatoire de billets
        vector<string> types_billet;
        for (const auto& billet : Visiteur::getPrixBillet()) {
            types_billet.push_back(billet.first);
        }
        for (int j = 0; j < nb_billets; j++) {
            string type_aleatoire = types_billet[rand() % types_billet.size()];
            visiteur.acheter_billet(type_aleatoire, 1);
        }

        // Ajout du visiteur au zoo
        ajouter_visiteur(visiteur);
    }
};

// Passe au jour suivant et met à jour les états du zoo
void Zoo::passer_jour(){
    // Vérifie que tous les enclos ont de la nourriture
    if (!tous_les_enclos_sont_remplis()) {
        cout << "\nVous ne pouvez pas passer au jour suivant, tous les mangeoirs doivent etre remplis de nourriture ! " << endl;
        return; // Condition d'arrêt
    }

    // Vérifie que tous les animaux sont en bonne santé
    if (!tous_les_animaux_sont_soignes()) {
        cout << "\nVous ne pouvez pas passer au jour suivant, tous les animaux doivent etre en bonne sante ! " << endl;
        return; // Condition d'arrêt
    }
    
    // Met à jour la santé des animaux et génère de nouveaux visiteurs
    simuler_sante_animaux();
    generer_visiteurs_aleatoires();

    // Enregistre les visiteurs du jour et réinitialise la liste
    billets_par_jour[date_actuelle] = visiteurs;
    date_actuelle++;
    visiteurs.clear();

    // Réinitialise la nourriture des enclos et la satiété des animaux
    for (auto& e : enclos) {
        e.setNourriture(false);
        for (auto& animal : e.getAnimaux()) {
            animal.changement_statut_satiete(false);
        }
    }
    
    // Annonce la fin du jour
    cout << "\nJour " << getDernierJour() << " terminer." << endl;
    pause(1);

    // Affiche les statistiques du jour précédent
    cout << "\n--- Statistiques du jour " << getDernierJour() << " ---" << endl;
    pause(1);
    cout << "- Nombre de billets vendus : " << nombre_billets_jour(getDernierJour()) << endl;
    pause(1);
    cout << "- Benefice realise : " << benefice_jour(getDernierJour()) << " euros" << endl;
    pause(2);

    // Accueille le jour suivant
    cout << "\nBienvenue au jour " << date_actuelle << " !" << endl;
};

// Calcule le nombre de billets vendus pour un jour donné
int Zoo::nombre_billets_jour(int jour) const{
    int total = 0;

    // Recherche le jour dans l'historique
    auto it = billets_par_jour.find(jour);
    if (it == billets_par_jour.end()){
        return 0;
    }

    // Compte les billets vendus ce jour-là
    for (const auto& v : it->second) {
        for (const auto& b : v.getBillets()) {
            const string& type = b.first;
            int quantite = b.second;
            total += quantite;
        }
    }

    return total;
};

// Calcule le bénéfice réalisé pour un jour donné
int Zoo::benefice_jour(int jour) const{
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

// Calcule le nombre total de billets vendus depuis l'ouverture du zoo
int Zoo::nombre_billets_total() const {
    int total = 0;

    for (auto& paire : getBilletsParJour()) {
        int jour = paire.first;
        total += nombre_billets_jour(jour);
    }

    return total;
};

// Calcule le bénéfice total réalisé par le zoo depuis son ouverture
int Zoo::benefice_total() const {
    int total = 0;

    for (auto& paire : getBilletsParJour()) {
        int jour = paire.first;
        total += benefice_jour(jour);
    }

    return total;
};

// Affiche les informations générales du zoo
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
