#include "Statistique.hpp"

using namespace std;

Statistique::Statistique(const Zoo& _zoo) : zoo(_zoo) {};

int Statistique::nombre_billets_totaux() const {
    int total = 0;

    for (auto& paire : zoo.getBilletsParJour()) {
        int jour = paire.first;
        total += zoo.nombre_billets_jour(jour);
    }

    return total;
};

int Statistique::calculer_benefice_total() const {
    int total = 0;

    for (auto& paire : zoo.getBilletsParJour()) {
        int jour = paire.first;
        total += zoo.benefice_jour(jour);
    }

    return total;
}


