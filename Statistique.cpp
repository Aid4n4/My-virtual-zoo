#include "Statistique.hpp"
#include "Zoo.hpp"
#include <map>

using namespace std;

Statistique::Statistique(Zoo* _zoo)
    : zoo(_zoo)
{}

int Statistique::nombre_billets_totaux() const
{
    int total = 0;

    const map<int, vector<Visiteur>>& historique = zoo->getBilletsParJour();

    for (const auto& element : historique) {
        int jour = element.first;
        total += zoo->nombre_billets_jour(jour);
    }

    return total;
}

int Statistique::calculer_benefice_total() const
{
    int total = 0;

    const map<int, vector<Visiteur>>& historique = zoo->getBilletsParJour();

    for (const auto& element : historique) {
        int jour = element.first;
        total += zoo->benefice_jour(jour);
    }

    return total;
}



