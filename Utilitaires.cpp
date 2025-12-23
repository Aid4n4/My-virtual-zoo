#include "Utilitaires.hpp"
#include <ctime>
using namespace std;

// Bloque l'exécution du programme pendant un nombre donné de secondes
void pause(int secondes) {
    time_t debut = time(nullptr);

    // Attente active jusqu'à ce que le temps écoulé atteigne la durée demandée
    while (difftime(time(nullptr), debut) < secondes) {}
};
