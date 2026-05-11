# My Virtual Zoo — Jeu de gestion de zoo en C++

Projet réalisé en binôme dans le cadre du cours d'Algorithmique et Programmation Orientée Objet — Licence Informatique (L3), Université Lyon 2.  
Application de gestion d'un zoo virtuel en mode textuel, développée en C++ avec les principes fondamentaux de la POO.

---

## Concept

Le joueur incarne le gérant d'un zoo et doit gérer au quotidien ses enclos, ses animaux et son personnel. Chaque journée de simulation suit des règles précises : tous les animaux doivent être nourris et en bonne santé pour passer au jour suivant. Des visiteurs sont générés aléatoirement et achètent des billets, permettant de calculer les bénéfices journaliers.

---

## Technologies utilisées

- **C++** — programmation orientée objet (héritage, polymorphisme, composition)
- **Fichiers CSV** — persistance des données entre les sessions
- **Terminal** — interface entièrement textuelle

---

## Fonctionnalités

- Ajouter et supprimer des animaux dans les enclos
- Gérer plusieurs enclos par type d'animal et régime alimentaire
- Affecter des soigneurs aux enclos pour nourrir et soigner les animaux
- Générer des visiteurs aléatoires qui achètent des billets
- Calculer les statistiques financières (billets vendus, bénéfices journaliers et totaux)
- Lire et écrire des espèces animales depuis/vers un fichier CSV
- Simuler le passage du temps jour par jour

---

## Architecture des classes

```
Personne (classe de base)
├── Soigneur   — affecté à un enclos, nourrit et soigne les animaux
└── Visiteur   — achète des billets, génère des revenus

Zoo            — classe principale, orchestre toute la simulation
└── Enclos     — zone dédiée à un type d'animal (composition)
    └── Animal — animal individuel avec santé et satiété (composition)
```

**Relations :**
- **Composition** : Zoo → Enclos → Animal (cycle de vie lié)
- **Association** : Soigneur ↔ Enclos, Zoo ↔ Visiteur (objets indépendants)
- **Héritage** : Soigneur et Visiteur héritent de Personne
- **Polymorphisme** : méthodes virtuelles pour l'affichage selon le type de personne

---

## Gestion des fichiers

- `animaux.csv` — base de données des espèces animales, chargée au démarrage
- Possibilité d'ajouter de nouvelles espèces depuis le jeu, sauvegardées automatiquement dans le CSV

---

## Auteurs

- **Serena** — [@Aid4n4](https://github.com/Aid4n4)
- **Maély Thomas** — binôme
- Université Lyon 2, décembre 2025
