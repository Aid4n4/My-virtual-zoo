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
    cin >> nom; //personalisation du nom du zoo
    Zoo zoo(nom);

    cout << "- Pour commencer, il faudrait creer des enclos pour pouvoir y mettre nos futurs animaux." << endl;
    
    map<string, vector<string>> animaux = { //tableau des animaux disponible pour le moment
        {"Girafe", {"Herbivore", "Plaine"}},
        {"Lion", {"Carnivore", "Savane"}},
        {"Pingouin", {"Carnivore", "Banquise"}},
        {"Loup", {"Carnivore", "Forêt"}},
        {"Guepard", {"Carnivore", "Savane"}},
        {"Koala", {"Herbivore", "Foret"}},
        {"Tigre", {"Carnivore", "Foret"}},
        {"Rhinoceros", {"herbivore", "Savane"}},
        {"Dauphin", {"Carnivore", "Ocean"}},
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

    int nb_enclos = 0; //stockage nombre d'enclos

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
            cout << "Ton choix est invalide, cet animal n'existe pas. Choisis-en un dans la liste cette fois ! \n";
            continue;
        }

        string nom_animal = noms_animaux[choix - 1];
        string regime = animaux[nom_animal][0];
        string habitat = animaux[nom_animal][1];

        zoo.ajouter_enclos(Enclos(id_enclos++, nom_animal, regime, habitat));
        nb_enclos++; //augmente le nombre d'enclos a chaque nouvelle création
        cout << "- Voici ton enclos pour :  " << nom_animal << " il a ete cree avec succes !\n";

        cout << "- Souhaites-tu creer un autre enclos ? (o/n) : " << endl; //donne le choix de créer plusieurs enclos
        cin >> continuer;
    }
    
    cout << "\n - Maintenant que nous avons les enclos il faudrait les remplir" << endl;
    cout << "\n--- Ajout des animaux dans les enclos ---\n";

    int nb_animaux; //variable pour stocker le nombre d'animaux créés
    for (int i = 0; i < nb_enclos; i++) {

        Enclos& enclos = zoo.getEnclos(i);

        cout << "\nEnclos numero : " << enclos.getID() << endl;


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
            cout << "Nom de l'animal numero : " << j + 1 << " de ton enclos : \n";
            cin >> nom_animal;

            int id_animal = j + 1;

            enclos.ajout_animal(Animal(id_animal, nom_animal));
        }
    }

    cout << "\n- Recapitulons, on a des enclos et des animaux, mais qui va s'en occuper maintenant ? Creeons des soigneurs pour prendre soin d'eux !" << endl;
    vector<bool> enclos_occupe(nb_enclos, false);
    vector<Soigneur> soigneurs;

    cout << "\n--- Creation des soigneurs ---\n";

    for (int i = 0; i < nb_enclos; i++) {

        string nom, prenom;

        cout << "\nSoigneur pour l'enclos #" << zoo.getEnclos(i).getID() << endl;

        cout << "Nom du soigneur : ";
        cin >> nom;

        cout << "Prenom du soigneur : ";
        cin >> prenom;

        Soigneur s(nom, prenom);

        s.assigner_enclos(&zoo.getEnclos(i));

        soigneurs.push_back(s);
    }   


    cout << "\n - Super, tu as cree ton zoo ! Maintenant passons aux choses serieuse, il faut que tu t'en occupes." << endl;
   int choix_menu = -1;

    while (choix_menu != 0) {

        cout << "\n===== MENU =====\n";
        cout << "1 - Afficher les informations des enclos\n";
        cout << "2 - Afficher les informations des soigneurs\n";
        cout << "3 - Verifier l'etat des animaux (par soigneur)\n";
        cout << "4 - Nourrir les animaux (choisir un soigneur)\n";
        cout << "5 - Nourrir les animaux (tous les soigneurs)\n";
        cout << "6 - Soigner les animaux malades (par soigneur)\n";
        cout << "7 - Passer au jour suivant\n";
        cout << "0 - Quitter\n";
        cout << "Votre choix : ";

        cin >> choix_menu;

        if (!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entree invalide.\n";
            continue;
        }

        switch (choix_menu) {

            case 1: {
                cout << "\n--- Informations des enclos ---\n";
                for (int i = 0; i < nb_enclos; i++) {
                    zoo.getEnclos(i).afficher_informations();
                }
                break;
            }

            case 2: {
                cout << "\n--- Informations des soigneurs ---\n";
                for (Soigneur& s : soigneurs) {
                    s.afficher_informations();
                }
                break;
            }

            case 3: {
                cout << "\n--- Verification de l'etat des animaux ---\n";

                // Afficher la liste des soigneurs
                for (size_t i = 0; i < soigneurs.size(); i++) {
                    cout << i + 1 << " - ";
                    soigneurs[i].afficher_informations();
                }

                int choix_soigneur;
                cout << "Choisis un soigneur : ";
                cin >> choix_soigneur;

                if (!cin || choix_soigneur < 1 || choix_soigneur > soigneurs.size()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Choix invalide.\n";
                break;
                }

                // Appel DIRECT de ta méthode existante
                soigneurs[choix_soigneur - 1].verification_statut_tous();

                break;
            }

            case 4: {
                cout << "\n--- Choisir un soigneur ---\n";
                for (size_t i = 0; i < soigneurs.size(); i++) {
                    cout << i + 1 << " - ";
                    soigneurs[i].afficher_informations();
                }

                int choix_soigneur;
                cout << "Numero du soigneur : ";
                cin >> choix_soigneur;

                if (!cin || choix_soigneur < 1 || choix_soigneur > soigneurs.size()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Choix invalide.\n";
                    break;
                }

                soigneurs[choix_soigneur - 1]
                    .remplir_nourriture_enclos(zoo.getDateActuelle());

                break;
            }
            
            case 5: {
                cout << "\n--- Tous les soigneurs nourrissent ---\n";
                for (Soigneur& s : soigneurs) {
                    s.remplir_nourriture_enclos(zoo.getDateActuelle());
                }
                break; 
            }

            case 6 : {
                // Règle : pas de soins le premier jour
                if (zoo.getDateActuelle() <= 1) {
                    cout << "Les animaux ne peuvent pas etre malades le premier jour.\n";
                    break;
                }

                cout << "\n--- Soigner les animaux malades ---\n";

                // Afficher les soigneurs
                for (size_t i = 0; i < soigneurs.size(); i++) {
                    cout << i + 1 << " - ";
                    soigneurs[i].afficher_informations();
                }

                int choix_soigneur;
                cout << "Choisis un soigneur : ";
                cin >> choix_soigneur;

                if (!cin || choix_soigneur < 1 || choix_soigneur > soigneurs.size()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Choix invalide.\n";
                    break;
                }

                Soigneur& soigneur = soigneurs[choix_soigneur - 1];

                // Récupération de l'enclos du soigneur
                Enclos* enclos = soigneur.getEnclos();   // getter simple

                if (!enclos) {
                    cout << "Ce soigneur n'a pas d'enclos assigne.\n";
                    break;
                }

                bool au_moins_un_soigne = false;

                // Parcours des animaux de l'enclos
                for (Animal& animal : enclos->getAnimaux()) {

                    if (!animal.getSante()) {   // animal malade
                        soigneur.soigner(animal);
                        au_moins_un_soigne = true;
                    }
                }

                if (!au_moins_un_soigne) {
                    cout << "Aucun animal malade dans cet enclos.\n";
                }

                break;
            }

            case 7: {
                cout << "\n--- Passage au jour suivant ---\n";
                    zoo.passer_jour();
                    break;
            }
                

            case 0: {
                cout << "Fermeture du menu du gerant.\n";
                break;
            }

            default: {
                cout << "Choix invalide.\n";
            }
    }
    }

}




    /*cout << "\n-- Creation des visiteurs --" << endl;
    Visiteur visiteur1("Feur", "Nugget", 1 );
    
    visiteur1.acheter_billet("jeune (- de 18 ans)", 10);
    visiteur1.acheter_billet("retraite (65 et +)", 1);

    Visiteur visiteur2("Aubert", "Lily", 2);
    visiteur2.acheter_billet("etudiant (18-25 ans)", 2);

    zoo.ajouter_visiteur(visiteur1);
    zoo.ajouter_visiteur(visiteur2);

    

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

