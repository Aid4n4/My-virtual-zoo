#ifndef PERSONNE_HPP
#define PERSONNE_HPP

#include <string>
using namespace std;

class Personne
{
protected:
   string nom;
   string prenom;

public:
    Personne(const string& _nom, const string& _prenom);

    virtual ~Personne() = default;
    
    virtual void afficher_informations() const;

};

#endif
