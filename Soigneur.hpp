#ifndef SOIGNEUR_HPP
#define SOIGNEUR_HPP

#include "Personne.hpp"
#include "Enclos.hpp"
using namespace std;

/**
 * @class Soigneur
 * @brief Représente un soigneur du zoo.
 *
 * La classe Soigneur hérite de la classe Personne.
 * Un soigneur est responsable d'un enclos et peut :
 * - vérifier l'état des animaux,
 * - remplir les mangeoires,
 * - soigner les animaux malades.
 *
 * Cette classe illustre l'héritage, l'association avec Enclos
 * et le polymorphisme via la redéfinition d'une méthode virtuelle.
 */
class Soigneur : public Personne
{
private:
    /**
     * @brief Pointeur vers l'enclos assigné au soigneur.
     *
     * Un soigneur est associé à un unique enclos.
     * L'utilisation d'un pointeur permet une relation d'association
     * et évite la duplication d'objets.
     */
    Enclos* enclos_assigne;

public:
    /**
     * @brief Constructeur de la classe Soigneur.
     *
     * @param _nom : Nom du soigneur
     * @param _prenom : Prénom du soigneur
     */
    Soigneur(const string& _nom, const string& _prenom);
    
    /**
     * @brief Assigne un enclos au soigneur.
     *
     * Vérifie que :
     * - l'enclos est valide,
     * - le soigneur n'est pas déjà assigné,
     * - l'enclos n'a pas déjà un soigneur.
     *
     * @param _enclos_assigne : Enclos à assigner
     */
    void assigner_enclos(Enclos* _enclos_assigne);

    /**
     * @brief Vérifie et affiche l'état de tous les animaux de l'enclos assigné.
     */
    void verification_statut_tous() const;

    /**
     * @brief Remplit le mangeoir de l'enclos assigné.
     *
     * Met à jour la satiété des animaux et la date de dernier nourrissage.
     *
     * @param date_actuelle : Jour actuel de la simulation
     */
    void remplir_nourriture_enclos(int date_actuelle);

    /**
     * @brief Soigne un animal donné.
     *
     * Change l'état de santé de l'animal s'il est malade.
     *
     * @param animal : Animal à soigner
     */
    void soigner(Animal& animal);

    /**
     * @brief Affiche les informations du soigneur.
     *
     * Redéfinition de la méthode virtuelle de la classe Personne.
     */
    void afficher_informations() const override;

    // =======
    // Getters
    // =======
    
    /**
     * @return Pointeur vers l'enclos assigné
     */
    Enclos* getEnclos() const;
};

#endif
