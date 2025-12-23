#include <iostream>
#include <ctime>
#include "Zoo.hpp"
#include "Soigneur.hpp"
#include "Visiteur.hpp"
#include "CSV_animaux.hpp"
#include "Utilitaires.hpp"
using namespace std;

int main() {
    // Initialisation du générateur de nombres aléatoires
    // (utilisé notamment pour les visiteurs et la simulation de santé des animaux)
    srand(time(nullptr));

    // =================================
    // CREATION ET INITIALISATION DU ZOO
    // =================================
    string nom_zoo;
    cout << "--- Bienvenue dans My Virtual Zoo ---" << endl;
    pause(1);
    cout << "-- Quel nom souhaitez-vous donner a votre zoo ? ";
    cin >> nom_zoo;

    // Création de l'objet Zoo avec le nom choisi par l'utilisateur
    Zoo zoo(nom_zoo);

    cout << "\nVous avez cree avec succes le zoo \"" << nom_zoo << "\" :" << endl;
    pause(1);

    // Affichage des informations initiales du zoo
    zoo.afficher_informations();
    pause(2);

    // =========================
    // CREATION DES ENCLOS DU ZOO
    // ==========================

    // Chargement des animaux disponibles depuis le fichier CSV
    vector<Animal_modele> animaux_disponibles = charger_animaux_csv("animaux.csv");
    
    cout << "\n-- Pour commencer, vous allez devoir creer des enclos pour pouvoir y mettre vos futurs animaux." << endl;
    pause(2);

    // Variables de contrôle de la création des enclos
    char continuer = 'O';
    int id_enclos = 1;
    int nb_enclos = 0;
    int nb_enclos_max = 10; // Nombre maximum d'enclos autorisés

    // Boucle de création des enclos (limitée à 10 enclos maximum)
    while ((continuer == 'O' || continuer == 'o') && nb_enclos < nb_enclos_max + 1) {

        // Vérification de la limite maximale d'enclos
        if (nb_enclos >= nb_enclos_max) {
            cout << "\nVous avez atteint le nombre maximum d'enclos (" << nb_enclos_max << ")." << endl;
            break;
        }

        cout << "\n--- Creation de l'enclos #" << id_enclos << " ---" << endl;
        pause(1);
        
        // Variables utilisées pour l'affichage par pages des animaux
        int index_debut = 0;
        int choix;
        Animal_modele animal_choisi;

        // Boucle de sélection ou de création d'une espèce
        while (true) {
            cout << "-- Veuillez choisir un animal :" << endl;
            pause(1);

            // Affichage de 10 animaux à la fois
            int index_fin = min(index_debut + 10, static_cast<int>(animaux_disponibles.size()));

            for (int i = index_debut; i < index_fin; i++) {
                cout << i + 1 << " - " << animaux_disponibles[i].race << endl;
            }
            
            // Option pour afficher les animaux suivants
            if (index_fin < animaux_disponibles.size()) {
                cout << index_fin + 1 << " - Afficher les 10 animaux suivants" << endl;
            }
            
            // Option pour créer une nouvelle espèce
            cout << "0 - Creer une nouvelle espece" << endl;
            pause(1);
            cout << "\n-- Votre choix : ";
            cin >> choix;

            // Sécurisation de la saisie utilisateur
            while (cin.fail() || choix < 0 || choix > animaux_disponibles.size() + 1) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\nChoix invalide. Veuillez saisir un nombre valide : ";
                cin >> choix;
            }

            // Affichage de la page suivante
            if (choix == index_fin + 1 && index_fin < animaux_disponibles.size()) {
                index_debut += 10;
                continue;
            }
            // Sélection d'une espèce existante
            else if (choix >= 1 && choix <= animaux_disponibles.size()) {
                animal_choisi = animaux_disponibles[choix - 1];
                break;
            }
            // Création d'une nouvelle espèce
            else if (choix == 0) {
                cout << "\n--- Creation d'une nouvelle espece ---" << endl;
                
                // Saisie et vérification de l'unicité de la race
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
                        cout << "\nCette espece existe deja dans la base. Veuillez en choisir une autre." << endl;
                    }
                    else {
                        break;
                    }
                }

                // Saisie contrôlée du régime alimentaire
                while (true) {
                    cout << "- Regime (Omnivore / Carnivore / Herbivore) : ";
                    cin >> animal_choisi.regime;

                    if (animal_choisi.regime == "Omnivore" || animal_choisi.regime == "Carnivore" || animal_choisi.regime == "Herbivore") {
                        break;
                    }   
                    else {
                        cout << "\nRegime invalide. Veuillez saisir Omnivore, Carnivore ou Herbivore." << endl;
                    }
                }

                // Saisie du type d'enclos
                cout << "- Type d'enclos : ";
                cin >> animal_choisi.type_enclos;

                // Ajout de la nouvelle espèce à la base et au CSV
                animaux_disponibles.push_back(animal_choisi);
                ajouter_animal_csv("animaux.csv", animal_choisi);
                
                cout << "\nNouvelle espece ajoutee avec succes a la base." << endl;
                pause(1);
                break;
            }
            else {
                cout << "\nChoix invalide. Recommencez." << endl;
                pause(1);
            }
        }

        // Création de l'enclos associé à l'espèce choisie
        zoo.ajouter_enclos(Enclos(id_enclos++, animal_choisi.race, animal_choisi.regime, animal_choisi.type_enclos));
        
        nb_enclos++; // Incrémentation du nombre d'enclos créés

        // Suppression de l'espèce utilisée pour éviter les doublons d'enclos
        for (auto it = animaux_disponibles.begin(); it != animaux_disponibles.end(); ++it) {
            if (it->race == animal_choisi.race) {
                animaux_disponibles.erase(it);
                break;
            }
        }

        pause(2);
        cout << "\n-- Souhaitez-vous creer un autre enclos ? (O/N) : "; //donne le choix de créer plusieurs enclos
        cin >> continuer;

        // Validation de la réponse utilisateur
        while (continuer != 'O' && continuer != 'o' && continuer != 'N' && continuer != 'n') {
            cout << "\nChoix invalide. Veuillez repondre par O (oui) ou N (non) : ";
            cin >> continuer;
        }
    }

    // Initialisation des animaux dans les enclos
    pause(2);
    cout << "\n-- Ensuite, vous allez devoir ajouter des animaux dans vos enclos." << endl;
    pause(2);

    for (int i = 0; i < nb_enclos; i++) {
        int nb_animaux = 0; //variable pour stocker le nombre d'animaux créés
        int nb_animaux_max = 10; //limite le nombre d'animaux pouvant être créés par enclos
        cout << "\n--- Creation des animaux dans l'enclos #" << zoo.getEnclos(i).getID() << " ---" << endl;
        pause(1);
        cout << "-- Combien d'animaux voulez-vous ajouter dans l'enclos #" << zoo.getEnclos(i).getID() << " ? ";
        cin >> nb_animaux;

        while (cin.fail() || nb_animaux <= 0 || nb_animaux > nb_animaux_max) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nChoix invalide. Veuillez saisir un entier strictement positif superieur a 0 et inferieur ou egal a " << nb_animaux_max << " : ";
            cin >> nb_animaux;
        }

        for (int j = 0; j < nb_animaux; j++) {
            bool ajoute = false;
            while (!ajoute) {
                string nom_animal;
                cout << "\n-- Quel nom souhaitez-vous donner a l'animal #" << j + 1 << " de l'enclos #" << zoo.getEnclos(i).getID() << " ? ";
                cin >> nom_animal;

                int id_animal = j + 1;
                Animal animal_temp(id_animal, nom_animal);

                ajoute = zoo.getEnclos(i).ajout_animal(animal_temp);
                pause(1);
            }
        }
    }

    pause(1);
    cout << "\n-- Maintenant que vous avez vos animaux, il ne vous reste plus qu'a creer des soigneurs pour s'en occuper." << endl;
    
    // Initialisation des soigneurs pour chaque enclos
    for (int i = 0; i < nb_enclos; i++) {
        bool ajoute = false;
        pause(2);
        cout << "\n--- Creation du soigneur pour l'enclos #" << zoo.getEnclos(i).getID() << " ---" << endl;
        pause(1);
        while (!ajoute) {
            string nom, prenom;

            cout << "-- Quel nom souhaitez-vous donner a votre soigneur ? ";
            cin >> nom;

            cout << "-- Quel prenom souhaitez-vous donner a votre soigneur ? ";
            cin >> prenom;

            Soigneur* soigneur = new Soigneur(nom, prenom);
            ajoute = zoo.ajouter_soigneur(soigneur, zoo.getEnclos(i));

            if (!ajoute) {
                delete soigneur; // Libérer la mémoire si l'ajout a échoué
            }
        }
    }   

    pause(2);
    cout << "\n-- Tous les elements du zoo sont crees. Vous pouvez maintenant gerer votre zoo." << endl;
    pause(1);

   // Boucle principale
   // Menu du gérant
    int choix_menu = -1;
    while (choix_menu != 0) {
        pause(1);
        cout << "\n================= MENU =================" << endl;
        pause(1);
        cout << "1 - Afficher les informations des enclos" << endl;
        cout << "2 - Verifier l'etat des animaux" << endl;
        cout << "3 - Nourrir les animaux" << endl;
        cout << "4 - Soigner les animaux malades" << endl;
        cout << "5 - Passer au jour suivant" << endl;
        cout << "0 - Quitter" << endl;
        pause(1);
        cout << "\nVotre choix : ";
        cin >> choix_menu;

        while (cin.fail() || choix_menu < 0 || choix_menu > 5) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\nChoix invalide. Veuillez saisir un nombre valide : ";
                cin >> choix_menu;
            }

        switch (choix_menu) {
    
            case 1: {
                cout << "\n--- Informations des enclos ---" << endl;
                for (int i = 0; i < nb_enclos; i++) {
                    pause(1);
                    zoo.getEnclos(i).afficher_informations();
                    pause(1);
                    cout << "\n--------------------------" << endl;
                }
                break;
            }

            case 2: {
                cout << "\n--- Verification de l'etat des animaux ---" << endl;
                pause(1);
                cout << "-- Veuillez choisir un soigneur :" << endl;
                pause(1);

                // Afficher la liste des soigneurs
                for (size_t i = 0; i < zoo.getSoigneurs().size(); i++) {
                    cout << i + 1 << " - " << zoo.getSoigneurs()[i]->getNom() << " " << zoo.getSoigneurs()[i]->getPrenom() << endl;
                }
                
                int choix_soigneur;
                pause(1);
                cout << "\n-- Votre choix : ";
                cin >> choix_soigneur;

                while (cin.fail() || choix_soigneur < 1 || choix_soigneur > zoo.getSoigneurs().size()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nChoix invalide. Veuillez saisir un nombre valide : ";
                    cin >> choix_soigneur;
                }

                pause(1);
                cout << "\n--- Enclos #" << zoo.getSoigneurs()[choix_soigneur - 1]->getEnclos()->getID() << " ---" << endl;
                zoo.getSoigneurs()[choix_soigneur - 1]
                ->verification_statut_tous();
                break;
            }

            case 3: {
                if (zoo.tous_les_enclos_sont_remplis()) {
                    pause(1);
                    cout << "\nTous les enclos ont deja de la nourriture dans leur mangeoir." << endl;
                    break;
                }
                cout << "\n--- Remplir la nourriture des enclos ---" << endl;
                pause(1);
                cout << "-- Veuillez choisir un soigneur :" << endl;
                pause(1);

                // Afficher la liste des soigneurs
                for (size_t i = 0; i < zoo.getSoigneurs().size(); i++) {
                    cout << i + 1 << " - " << zoo.getSoigneurs()[i]->getNom() << " " << zoo.getSoigneurs()[i]->getPrenom() << endl;
                }
                
                int choix_soigneur;
                pause(1);
                cout << "\n-- Votre choix : ";
                cin >> choix_soigneur;

                while (cin.fail() || choix_soigneur < 1 || choix_soigneur > zoo.getSoigneurs().size()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nChoix invalide. Veuillez saisir un nombre valide : ";
                    cin >> choix_soigneur;
                }

                pause(1);
                zoo.getSoigneurs()[choix_soigneur - 1]->remplir_nourriture_enclos(zoo.getDateActuelle());
                if (zoo.tous_les_enclos_sont_remplis()) {
                    pause(1);
                    cout << "\nTous les enclos ont de la nourriture dans leur mangeoir." << endl;
                }
                break;
            }

            case 4: {
                // Règle : pas de soins le premier jour
                if (zoo.getDateActuelle() == 1) {
                    pause(1);
                    cout << "\nLes animaux ne peuvent pas etre malades le premier jour." << endl;
                    break;
                }

                if (zoo.tous_les_animaux_sont_soignes()) {
                    pause(1);
                    cout << "\nTous les animaux du zoo sont deja en bonne sante." << endl;
                    break;
                }

                cout << "\n--- Soigner les animaux malades ---" << endl;
                pause(1);
                cout << "-- Veuillez choisir un soigneur :" << endl;
                pause(1);

                // Afficher la liste des soigneurs
                for (size_t i = 0; i < zoo.getSoigneurs().size(); i++) {
                    cout << i + 1 << " - " << zoo.getSoigneurs()[i]->getNom() << " " << zoo.getSoigneurs()[i]->getPrenom() << endl;
                }
                
                int choix_soigneur;
                pause(1);
                cout << "\n-- Votre choix : ";
                cin >> choix_soigneur;

                while (cin.fail() || choix_soigneur < 1 || choix_soigneur > zoo.getSoigneurs().size()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nChoix invalide. Veuillez saisir un nombre valide : ";
                    cin >> choix_soigneur;
                }

                pause(1);
                Soigneur& soigneur = *zoo.getSoigneurs()[choix_soigneur - 1];

                // Récupération de l'enclos du soigneur
                Enclos* enclos = soigneur.getEnclos();   // getter simple
                
                cout << "\n-- Veuillez choisir un animal malade :" << endl;
                pause(1);

                for (size_t i = 0; i < enclos->getAnimaux().size(); i++) {
                    cout << i + 1 << " - " << enclos->getAnimaux()[i].getNom() << " | Sante : " << (enclos->getAnimaux()[i].getSante() ? "Bonne" : "Mauvaise") << endl;
                }

                int choix_animal;
                pause(1);
                cout << "\n-- Votre choix : ";
                cin >> choix_animal;

                while (cin.fail() || choix_animal < 1 || choix_animal > enclos->getAnimaux().size()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\nChoix invalide. Veuillez saisir un nombre valide : ";
                    cin >> choix_animal;
                }

                pause(1);
                Animal& animal = enclos->getAnimaux()[choix_animal - 1];

                if (animal.getSante() == true) {
                    cout << "\nCet animal est deja en bonne sante. Vous ne pouvez pas le soigner." << endl;
                    break;
                }
                else {
                    soigneur.soigner(animal);
                    cout << "\nL'animal \"" << animal.getNom() << "\" a ete soigne avec succes." << endl;
                }

                bool tous_soignes = true;

                for (const auto& a : enclos->getAnimaux()) {
                    if (!a.getSante()) {
                        tous_soignes = false;
                        break;
                    }
                }

                if (tous_soignes) {
                    pause(1);
                    cout << "\nTous les animaux de l'enclos #" << enclos->getID() << " sont en bonne sante." << endl;
                }

                if (zoo.tous_les_animaux_sont_soignes()) {
                    pause(1);
                    cout << "\nTous les animaux du zoo sont en bonne sante." << endl;
                }

                break;
            }

            case 5: {
                cout << "\n--- Passage au jour suivant ---" << endl;
                pause(1);
                zoo.passer_jour();
                break;
            }
                
            case 0: {
                pause(1);
                cout << "\n--- Fermeture du jeu ---\n" << endl;
                pause(1);
                zoo.afficher_informations();
                pause(1);
                cout << "\n--- Statistiques finales du zoo ---" << endl;
                pause(1);
                cout << "- Nombre total de billets vendus : " << zoo.nombre_billets_total() << endl;
                pause(1);
                cout << "- Benefice total realise : " << zoo.benefice_total() << " euros" << endl;
                pause(1);
                cout << "\nMerci d'avoir jouer !" << endl;
                break;
            }
        }
    }

    return 0;
}
