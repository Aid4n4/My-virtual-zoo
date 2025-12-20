#include "Utilitaires.hpp"
#include <ctime>
using namespace std;

void pause(int secondes) {
    time_t debut = time(nullptr);
    while (difftime(time(nullptr), debut) < secondes) {}
};