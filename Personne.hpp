#ifndef PERSONNE_HPP
#define PERSONNE_HPP

#include <string>
using namespace std;

/**
 * @class Personne
 * @brief Classe de base représentant une personne du zoo.
 *
 * Cette classe abstrait les informations communes aux différentes
 * personnes du système (soigneurs, visiteurs, etc.).
 * Elle est destinée à être héritée.
 */
class Personne
{
protected:
    /**
     * Attribut protégé afin d'être accessible directement
     * par les classes dérivées.
     */
   string nom; // Nom de la personne
   string prenom; // Prénom de la personne

public:
    /**
     * @brief Constructeur de la classe Personne.
     *
     * @param _nom : Nom de la personne
     * @param _prenom : Prénom de la personne
     */
    Personne(const string& _nom, const string& _prenom);

    /**
     * @brief Destructeur virtuel.
     *
     * Garantit la destruction correcte des objets dérivés
     * via un pointeur de type Personne.
     */
    virtual ~Personne() = default;
    
    /**
     * @brief Affiche les informations de la personne.
     *
     * Méthode virtuelle permettant aux classes dérivées
     * de redéfinir l'affichage si nécessaire.
     */
    virtual void afficher_informations() const;

    /**
     * @return Nom de la personne
     */
    string getNom() const;

    /**
     * @return Prénom de la personne
     */
    string getPrenom() const;
};

#endif
