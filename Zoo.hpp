#ifndef ZOO_HPP
#define ZOO_HPP

#include <vector>
#include <map>
#include "Enclos.hpp"
#include "Soigneur.hpp"
#include "Visiteur.hpp"
using namespace std;

/**
 * @class Zoo
 * @brief Représente un zoo virtuel avec ses enclos, soigneurs et visiteurs.
 * 
 * La classe gère la création d'enclos, l'assignation de soigneurs,
 * la gestion des visiteurs et la simulation quotidienne du zoo.
 */
class Zoo
{
private:
    string nom; // Nom du zoo
    int date_actuelle; // Jour actuel de la simulation
    vector<Enclos> enclos; // Liste des enclos du zoo
    vector<Soigneur*> soigneurs; // Liste des soigneurs (pointeurs)
    vector<Visiteur> visiteurs; // Liste des visiteurs
    map<int, vector<Visiteur>> billets_par_jour; // Historique des billets vendus par jour
public:
    /**
     * @brief Constructeur du zoo
     * @param _nom : Nom du zoo
     */
    Zoo(const string& _nom);

    /**
     * @brief Destructeur du zoo, libère la mémoire des soigneurs
     */
    ~Zoo();
    
    /**
     * @brief Ajoute un visiteur au zoo
     * @param _visiteur : Visiteur à ajouter
     */
    void ajouter_visiteur(const Visiteur& _visiteur);

    /**
     * @brief Ajoute un soigneur au zoo et l'assigne à un enclos
     * @param _soigneur : Pointeur vers le soigneur à ajouter
     * @param _enclos : Référence vers l'enclos à assigner
     * @return true si l'ajout a réussi, false sinon
     */
    bool ajouter_soigneur(Soigneur* _soigneur, Enclos& _enclos);
    
    /**
     * @brief Ajoute un enclos au zoo
     * @param _enclos : Enclos à ajouter
     */
    void ajouter_enclos(const Enclos& _enclos);

    /**
     * @brief Vérifie que tous les enclos ont de la nourriture
     * @return true si tous les enclos sont remplis, false sinon
     */
    bool tous_les_enclos_sont_remplis() const;

    /**
     * @brief Vérifie que tous les animaux sont en bonne santé
     * @return true si tous les animaux sont soignés, false sinon
     */
    bool tous_les_animaux_sont_soignes() const;

    /**
     * @brief Simule la santé des animaux du zoo (aléatoire)
     */
    void simuler_sante_animaux();

    /**
     * @brief Génère des visiteurs aléatoires pour le zoo
     */
    void generer_visiteurs_aleatoires();

    /**
     * @brief Passe au jour suivant et met à jour les états du zoo
     */
    void passer_jour();

    /**
     * @brief Calcule le nombre de billets vendus pour un jour donné
     * @param jour : Jour à analyser
     * @return Nombre de billets vendus ce jour-là
     */
    int nombre_billets_jour(int jour) const;

    /**
     * @brief Calcule le bénéfice réalisé pour un jour donné
     * @param jour : Jour à analyser
     * @return Bénéfice réalisé ce jour-là
     */
    int benefice_jour(int jour) const;

    /**
     * @brief Calcule le nombre total de billets vendus depuis l'ouverture du zoo
     * @return Nombre total de billets vendus
     */
    int nombre_billets_total() const;

    /**
     * @brief Calcule le bénéfice total réalisé par le zoo depuis son ouverture
     * @return Bénéfice total réalisé en euros
     */
    int benefice_total() const;

    /**
     * @brief Affiche les informations générales du zoo
     */
    void afficher_informations() const;

    // =======
    // Getters
    // =======

    /**
     * @return Nom du zoo
     */
    string getNom() const;

    /**
     * @return Jour actuel de la simulation
     */
    int getDateActuelle() const;

    /**
     * @return Dernier jour enregistré dans billets_par_jour
     */
    int getDernierJour() const;

    /**
     * @brief Retourne une référence modifiable vers un enclos
     * @param index : Index de l'enclos
     * @return Enclos& Référence vers l'enclos
     */
    Enclos& getEnclos(size_t index);

    /**
     * @brief Retourne une référence constante vers un enclos
     * @param index : Index de l'enclos
     * @return const Enclos& Référence constante vers l'enclos
     */
    const Enclos& getEnclos(size_t index) const;

    /**
     * @brief Retourne le vecteur de soigneurs (modifiable)
     * @return vector<Soigneur*>& Référence vers le vecteur de soigneurs
     */
    vector<Soigneur*>& getSoigneurs();

    /**
     * @brief Retourne le vecteur de soigneurs (lecture seule)
     * @return const vector<Soigneur*>& Référence constante vers le vecteur de soigneurs
     */
    const vector<Soigneur*>& getSoigneurs() const;

    /**
     * @brief Retourne le vecteur de visiteurs (modifiable)
     * @return vector<Visiteur>& Référence vers le vecteur de visiteurs
     */
    map<int, vector<Visiteur>> getBilletsParJour() const;
};

#endif
