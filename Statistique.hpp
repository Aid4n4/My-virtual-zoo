#ifndef STATISTIQUE_HPP
#define STATISTIQUE_HPP

#include "Zoo.hpp"
using namespace std;

class Statistique
{
private:
    Zoo* zoo;

public:
    Statistique(Zoo* z);

    int nombre_billets_totaux() const;
    int calculer_benefice_total() const;

};

#endif
