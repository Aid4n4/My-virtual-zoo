#include <iostream>
#include <ctime>
#include "Zoo.hpp"
#include "Soigneur.hpp"
#include "Visiteur.hpp"
#include "Statistique.hpp"
using namespace std;

int main() {
    srand(time(nullptr));
    string nom;
    cout << "-- Bienvenue dans My Virtual Zoo --" << endl;
    cout << " - Veuillez donner un nom a votre zoo : " << endl;
    cin >> nom;
    Zoo zoo(nom);

    cout << "- Pour commencer, il faudrait creer des enclos pour pouvoir y mettre nos futurs animaux." << endl;
    
    map<string, vector<string>> animaux = {
        {"Girafe", {"Herbivore", "Plaine"}},
        {"Lion", {"Carnivore", "Savane"}},
        {"Pingouin", {"Carnivore", "Banquise"}},
        {"Loup", {"Carnivore", "Forêt"}},
        {"Guepard", {"Carnivore", "Savane"}},
        {"Koala", {"Herbivore", "Foret"}},
        {"Tigre", {"Carnivore", "Foret"}},
        {"Rhinoceros", {"herbivore", "Savane"}},
        {"Dauphin", {"Carnivore", "Océan"}},
        {"Tortue terrestre", {"Herbivore", "Plaine"}},
        {"Tortue aquatique", {"Herbivore", "Lac"}},
        {"Ouistiti", {"Omnivore", "Foret"}},
        {"Gorille", {"Herbivore", "Foret"}},
        {"Perroquet", {"Herbivore", "Voliere"}},
        {"Gazelle", {"herbivore", "Savane"}},
        {"Crocodile", {"Carnivore", "Lac"}},
        {"Lynx", {"Carnivore", "Foret"}},
        {"Cobra", {"Carnivore", "Vivarium"}},
        {"Panda Roux", {"Omnivore", "Foret"}},
        {"Flamant Rose", {"Carnivore", "Lac"}},   
    };
        
    vector<string> noms_animaux;
    for (const auto& a : animaux) {
        noms_animaux.push_back(a.first);
    }

    int nb_enclos = 0;

    char continuer = 'o';
    int id_enclos = 1;

    while (continuer == 'o' || continuer == 'O') {
        cout << "\n--- Creation d'un enclos ---\n";
        cout << "- Choisis un animal :\n";

        for (size_t i = 0; i < noms_animaux.size(); i++) {
            cout << i + 1 << " - " << noms_animaux[i] << endl;
        }
        int choix;
        cin >> choix;
        if (choix < 1 || choix > noms_animaux.size()) {
            cout << "- Choix invalide.\n";
            continue;
        }

        string nom_animal = noms_animaux[choix - 1];
        string regime = animaux[nom_animal][0];
        string habitat = animaux[nom_animal][1];

        zoo.ajouter_enclos(Enclos(id_enclos++, nom_animal, regime, habitat));
        nb_enclos++;
        cout << "- Enclos pour " << nom_animal << " cree avec succes !\n";

        cout << "- Souhaites-tu creer un autre enclos ? (o/n) : " << endl;
        cin >> continuer;
    }
    
    cout << "- Maintenant que nous avons les enclos il faudrait les remplir" << endl;

    cout << "\n--- Ajout des animaux dans les enclos ---\n";

    for (int i = 0; i < nb_enclos; i++) {

        Enclos& enclos = zoo.getEnclos(i);

        cout << "\nEnclos numéro : " << enclos.getID() << endl;

        int nb_animaux;
        cout << "- Combien d'animaux veux-tu ajouter dans cet enclos ? ";
        cin >> nb_animaux;

        if (!cin || nb_animaux <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "- Nombre invalide, passons a l'enclos suivant.\n";
            continue;
    }

    for (int j = 0; j < nb_animaux; j++) {

        string nom_animal;
        cout << "Nom de l'animal numéro" << j + 1 << " de ton enclos : ";
        cin >> nom_animal;

        int id_animal = j + 1;

        enclos.ajout_animal(Animal(id_animal, nom_animal));
    }
}

}
/*
    cout << "\n-- Creation des soigneurs --" << endl;
    Soigneur soigneur1("Broillet", "Virgile");
    Soigneur soigneur2("Quoi", "Feur");

    soigneur1.assigner_enclos(&zoo.getEnclos(0));
    soigneur2.assigner_enclos(&zoo.getEnclos(1));

    zoo.ajouter_soigneur(soigneur1);
    zoo.ajouter_soigneur(soigneur2);

    soigneur1.afficher_informations();
    soigneur2.afficher_informations();

    zoo.getEnclos(0).afficher_informations();
    zoo.getEnclos(1).afficher_informations();

    soigneur1.remplir_nourriture_enclos(zoo.getDateActuelle());
    soigneur2.remplir_nourriture_enclos(zoo.getDateActuelle());

    cout << "\n-- Creation des visiteurs --" << endl;
    Visiteur visiteur1("Feur", "Nugget", 1 );
    
    visiteur1.acheter_billet("jeune (- de 18 ans)", 10);
    visiteur1.acheter_billet("retraite (65 et +)", 1);

    Visiteur visiteur2("Aubert", "Lily", 2);
    visiteur2.acheter_billet("etudiant (18-25 ans)", 2);

    zoo.ajouter_visiteur(visiteur1);
    zoo.ajouter_visiteur(visiteur2);

    cout << "\n-- Passer un jour --" << endl;
    zoo.passer_jour();

    cout << "\n-- Statistique du jour 1  --" << endl;
    cout << "Nombre billets vendus jour 1 : " << zoo.nombre_billets_jour(zoo.getDernierJour()) << endl;
    cout << "Benefice jour 1 : " << zoo.benefice_jour(zoo.getDernierJour()) << endl;

    cout << "\n-- Jour 2 --" << endl;
    soigneur1.verification_statut_tous();
    soigneur2.verification_statut_tous();

    soigneur1.soigner(girafe1);
    soigneur1.soigner(girafe2);
    soigneur2.soigner(lion1);
    soigneur2.soigner(lion2);

    soigneur1.remplir_nourriture_enclos(zoo.getDateActuelle());
    soigneur2.remplir_nourriture_enclos(zoo.getDateActuelle());

    soigneur1.verification_statut_tous();
    soigneur2.verification_statut_tous();

    cout << "\n-- Creation des visiteurs --" << endl;
    Visiteur visiteur3("fghtj", "ghytj", 3);

    visiteur3.acheter_billet("jeune (- de 18 ans)", 10);
    visiteur3.acheter_billet("retraite (65 et +)", 1);
    
    zoo.ajouter_visiteur(visiteur3);

    cout << "\n-- Passer un jour --" << endl;
    zoo.passer_jour();

    Statistique stats(zoo);
    cout << "Nombre billets vendus jour ALL : " << stats.nombre_billets_totaux() << endl;
    cout << "Benefice jour ALL : " << stats.calculer_benefice_total() << endl;
    return 0;*/

