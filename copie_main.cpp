#include <iostream>
#include <ctime>
#include "Zoo.hpp"
#include "Soigneur.hpp"
#include "Visiteur.hpp"
#include "Statistique.hpp"
using namespace std;

int main() {
    /*srand(time(nullptr));

    cout << "-- Creation du zoo --" << endl;
    Zoo zoo("Chat");

    cout << "-- Creation des enclos --" << endl;
    zoo.ajouter_enclos(Enclos(1, "Girafe", "Herbivore", "Plaine"));
    zoo.ajouter_enclos(Enclos (2, "Lion", "Carnivore", "Savane"));
    
    cout << "-- Creation des animaux --" << endl;
    
    zoo.getEnclos(0).ajout_animal(Animal (1, "Sophie"));
    zoo.getEnclos(0).ajout_animal(Animal (2, "Cunegonde"));

    Animal& girafe1 = zoo.getEnclos(0).getAnimaux()[0];
    Animal& girafe2 = zoo.getEnclos(0).getAnimaux()[1];

    girafe1.verification_statut();

    zoo.getEnclos(1).ajout_animal(Animal (1, "Simba"));
    zoo.getEnclos(1).ajout_animal(Animal (2, "Nala"));

    Animal& lion1 = zoo.getEnclos(1).getAnimaux()[0];
    Animal& lion2 = zoo.getEnclos(1).getAnimaux()[1];

    cout << "Identifiant enclos : " << zoo.getEnclos(0).getID() << "\n Nombre d'animaux : " << zoo.getEnclos(0).getNombreAnimaux() << "\n Nourriture  : " << zoo.getEnclos(0).getNourriture() << endl;

    cout << "Identifiant enclos : " << zoo.getEnclos(1).getID() << "\n Nombre d'animaux : " << zoo.getEnclos(1).getNombreAnimaux() << "\n Nourriture  : " << zoo.getEnclos(1).getNourriture() << endl;
    
    cout << "-- Creation des soigneurs --" << endl;
    Soigneur soigneur1("Broillet", "Virgile");
    Soigneur soigneur2("Quoi", "Feur");

    soigneur1.assigner_enclos(&zoo.getEnclos(0));
    soigneur2.assigner_enclos(&zoo.getEnclos(1));

    soigneur1.afficher_informations();
    soigneur2.afficher_informations();

    soigneur1.verification_statut_tous();
    soigneur1.remplir_nourriture_enclos(zoo.getDateActuelle());
    soigneur2.remplir_nourriture_enclos(zoo.getDateActuelle());

    cout << "Identifiant enclos : " << zoo.getEnclos(0).getID() << "\n Nombre d'animaux : " << zoo.getEnclos(0).getNombreAnimaux() << "\n Nourriture  : " << zoo.getEnclos(0).getNourriture() << endl;
    
    cout << "Identifiant enclos : " << zoo.getEnclos(1).getID() << "\n Nombre d'animaux : " << zoo.getEnclos(1).getNombreAnimaux() << "\n Nourriture  : " << zoo.getEnclos(1).getNourriture() << endl;

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

    cout << "-- Statistique du jour 1  --" << endl;
    cout << "Nombre billets vendus jour 1 : " << zoo.nombre_billets_jour(zoo.getDernierJour()) << endl;
    cout << "Benefice jour 1 : " << zoo.benefice_jour(zoo.getDernierJour()) << endl;

    cout << "-- Jour 2 --" << endl;
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

    cout << "-- Creation des visiteurs --" << endl;
    Visiteur visiteur3("fghtj", "ghytj", 3);

    visiteur3.acheter_billet("jeune (- de 18 ans)", 10);
    visiteur3.acheter_billet("retraite (65 et +)", 1);
    
    zoo.ajouter_visiteur(visiteur3);

    cout << "-- Passer un jour --" << endl;
    zoo.passer_jour();

    Statistique stats(&zoo);
    cout << "Nombre billets vendus jour ALL : " << stats.nombre_billets_totaux() << endl;
    cout << "Benefice jour ALL : " << stats.calculer_benefice_total() << endl;

    return 0;*/

    srand(time(nullptr));
    string nom;
    cout << "-- Bienvenue dans My Virtual Zoo --" << endl;
    cout << "Veuillez donner un nom a votre zoo : " << endl;
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
    cout << "- Choisis quel animal tu veux mettre à l'intérieur"<< endl;
    cout << "- Tu as le choix entre tout ces animaux : \n" << "Girafe, Lion, Pingouin, Loup, Guepard, Koala, Tigre, Rhinoceros, Dauphin, Tortue terrestre, Tortue aquatique, Ouistiti, Gorille, Perroquet, Gazelle, Crocodile, Lynx, Cobra, Panda Roux, Flamant Rose. " << endl;

    /* zoo.ajouter_enclos(Enclos(1, "Girafe", "Herbivore", "Plaine"));
    zoo.ajouter_enclos(Enclos (2, "Lion", "Carnivore", "Savane"));
    
    cout << "- Super ! Maintenant que nous avons leurs habitats il faudrait ajouter des animaux." << endl;
    
    zoo.getEnclos(0).ajout_animal(Animal (1, "Sophie"));
    zoo.getEnclos(0).ajout_animal(Animal (2, "Cunegonde"));

    Animal& girafe1 = zoo.getEnclos(0).getAnimaux()[0];
    Animal& girafe2 = zoo.getEnclos(0).getAnimaux()[1];

    girafe1.verification_statut();

    zoo.getEnclos(1).ajout_animal(Animal (1, "Simba"));
    zoo.getEnclos(1).ajout_animal(Animal (2, "Nala"));

    Animal& lion1 = zoo.getEnclos(1).getAnimaux()[0];
    Animal& lion2 = zoo.getEnclos(1).getAnimaux()[1];

    cout << "Identifiant enclos : " << zoo.getEnclos(0).getID() << "\n Nombre d'animaux : " << zoo.getEnclos(0).getNombreAnimaux() << "\n Nourriture  : " << zoo.getEnclos(0).getNourriture() << endl;

    cout << "Identifiant enclos : " << zoo.getEnclos(1).getID() << "\n Nombre d'animaux : " << zoo.getEnclos(1).getNombreAnimaux() << "\n Nourriture  : " << zoo.getEnclos(1).getNourriture() << endl;
    
    cout << "-- Creation des soigneurs --" << endl;
    Soigneur soigneur1("Broillet", "Virgile", &zoo.getEnclos(0));
    Soigneur soigneur2("Quoi", "Feur", &zoo.getEnclos(1));

    soigneur1.verification_statut_tous();
    soigneur1.remplir_nourriture_enclos(zoo.getDateActuelle());
    soigneur2.remplir_nourriture_enclos(zoo.getDateActuelle());

    cout << "Identifiant enclos : " << zoo.getEnclos(0).getID() << "\n Nombre d'animaux : " << zoo.getEnclos(0).getNombreAnimaux() << "\n Nourriture  : " << zoo.getEnclos(0).getNourriture() << endl;

   cout << "Identifiant enclos : " << zoo.getEnclos(1).getID() << "\n Nombre d'animaux : " << zoo.getEnclos(1).getNombreAnimaux() << "\n Nourriture  : " << zoo.getEnclos(1).getNourriture() << endl;

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

    cout << "-- Statistique du jour 1  --" << endl;
    cout << "Nombre billets vendus jour 1 : " << zoo.nombre_billets_jour(zoo.getDernierJour()) << endl;
    cout << "Benefice jour 1 : " << zoo.benefice_jour(zoo.getDernierJour()) << endl;

    cout << "-- Jour 2 --" << endl;
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

    cout << "-- Creation des visiteurs --" << endl;
    Visiteur visiteur3("fghtj", "ghytj", 3);

    visiteur3.acheter_billet("jeune (- de 18 ans)", 10);
    visiteur3.acheter_billet("retraite (65 et +)", 1);
    
    zoo.ajouter_visiteur(visiteur3);

    cout << "-- Passer un jour --" << endl;
    zoo.passer_jour();

    Statistique stats(&zoo);
    cout << "Nombre billets vendus jour ALL : " << stats.nombre_billets_totaux() << endl;
    cout << "Benefice jour ALL : " << stats.calculer_benefice_total() << endl; */

    return 0;
}
