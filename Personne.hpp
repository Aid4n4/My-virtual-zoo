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
    Personne(const string& nom, const string& prenom);

    virtual ~Personne() = default;
    
    virtual void afficher_informations() const;

};

#endif
