#include <iostream>
#include <ctime>
#include "Zoo.hpp"
#include "Soigneur.hpp"
#include "Visiteur.hpp"
#include "Statistique.hpp"
#include "CSV_animaux.hpp"
#include "Utilitaires.hpp"
using namespace std;

int main() {
    srand(time(nullptr));

    // Initialisation du zoo
    string nom_zoo;
    cout << "--- Bienvenue dans My Virtual Zoo ---" << endl;
    pause(1);
    cout << "-- Quel nom souhaitez-vous donner a votre zoo ? ";
    cin >> nom_zoo;
    Zoo zoo(nom_zoo);
    cout << "\nVous avez cree avec succes le zoo \"" << nom_zoo << "\" :" << endl;
    pause(1);

    zoo.afficher_informations();
    pause(2);

    // Initialisation des enclos
    vector<Animal_modele> animaux_disponibles = charger_animaux_csv("animaux.csv");
    cout << "\n-- Pour commencer, vous allez devoir creer des enclos pour pouvoir y mettre vos futurs animaux." << endl;
    pause(2);

    char continuer = 'O';
    int id_enclos = 1;
    int nb_enclos = 0;
    
    while (continuer == 'O' || continuer == 'o') {
        cout << "\n--- Creation de l'enclos #" << id_enclos << " ---\n";
        pause(1);

        int index_debut = 0;
        int choix;
        Animal_modele animal_choisi;

        while (true) {
            cout << "-- Veuillez choisir un animal :\n";
            pause(1);

            int index_fin = min(index_debut + 10, static_cast<int>(animaux_disponibles.size()));

            for (int i = index_debut; i < index_fin; i++) {
                cout << i + 1 << " - " << animaux_disponibles[i].race << endl;
                pause(1);
            }

            if (index_fin < animaux_disponibles.size()) {
                cout << index_fin + 1 << " - Afficher les 10 animaux suivants\n";
                pause(1);
            }
            
            cout << "0 - Creer une nouvelle espece\n";
            pause(1);
            cout << "\n-- Votre choix : ";
            cin >> choix;
            while (!cin >> choix) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\nChoix invalide. Veuillez saisir un nombre valide : ";
                cin >> choix;
            }
            if (choix == index_fin + 1 && index_fin < animaux_disponibles.size()) {
                index_debut += 10;
                continue;
            }
            else if (choix >= 1 && choix <= animaux_disponibles.size()) {
                animal_choisi = animaux_disponibles[choix - 1];
                break;
            }
            else if (choix == 0) {
                cout << "\n--- Creation d'une nouvelle espece ---\n";
                while (true) {
                    cout << "- Race : ";
                    cin >> animal_choisi.race;

                    bool existe_deja = false;
                    for (const auto& a : animaux_disponibles) {
                        if (a.race == animal_choisi.race) {
                            existe_deja = true;
                            break;
                        }
                    }

                    if (existe_deja) {
                        cout << "\nCette espece existe deja dans la base. Veuillez en choisir une autre.\n";
                    }
                    else {
                        break;
                    }
                }
                
                while (true) {
                    cout << "- Regime (Omnivore / Carnivore / Herbivore) : ";
                    cin >> animal_choisi.regime;
                    if (animal_choisi.regime == "Omnivore" || animal_choisi.regime == "Carnivore" || animal_choisi.regime == "Herbivore") {
                        break;
                    }   
                    else {
                        cout << "\nRegime invalide. Veuillez saisir Omnivore, Carnivore ou Herbivore.\n";
                    }
                }
                cout << "- Type d'enclos : ";
                cin >> animal_choisi.type_enclos;

                animaux_disponibles.push_back(animal_choisi);
                ajouter_animal_csv("animaux.csv", animal_choisi);
                cout << "\nNouvelle espece ajoutee avec succes a la base.\n";
                pause(1);
                break;
            }
            else {
                cout << "\nChoix invalide. Recommencez.\n";
                pause(1);
            }
        }

        zoo.ajouter_enclos(Enclos(id_enclos++, animal_choisi.race, animal_choisi.regime, animal_choisi.type_enclos));
        nb_enclos++; //augmente le nombre d'enclos a chaque nouvelle création

        for (auto it = animaux_disponibles.begin(); it != animaux_disponibles.end(); ++it) {
            if (it->race == animal_choisi.race) {
                animaux_disponibles.erase(it);
                break;
            }
        }

        pause(2);
        cout << "\n-- Souhaitez-vous creer un autre enclos ? (O/N) : "; //donne le choix de créer plusieurs enclos
        cin >> continuer;

        while (continuer != 'O' && continuer != 'o' && continuer != 'N' && continuer != 'n') {
            cout << "\nChoix invalide. Veuillez repondre par O (oui) ou N (non) : ";
            cin >> continuer;
        }
    }

    // Initialisation des animaux dans les enclos
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
