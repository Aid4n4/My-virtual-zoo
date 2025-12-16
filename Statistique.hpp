#ifndef STATISTIQUE_HPP
#define STATISTIQUE_HPP

#include "Zoo.hpp"
using namespace std;

class Statistique
{
private:
    const Zoo& zoo;

public:
    Statistique(const Zoo& _zoo);

    int nombre_billets_totaux() const;
    int calculer_benefice_total() const;
};

#endif
