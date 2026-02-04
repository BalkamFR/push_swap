*This project has been created as part of the 42 curriculum by papilaz, ajeloyan.*

# Push_swap

## Description

Le projet **Push_swap** est un projet d'algorithmie simple et efficace : il s'agit de trier des données à l'aide d'un ensemble d'instructions limité.

Nous disposons :
- d'un ensemble d'entiers,
- de deux piles (**a** et **b**),
- d'un jeu d'instructions imposé.

L'objectif est d'écrire un programme en **C** qui calcule et affiche sur la sortie standard la **suite d'instructions la plus courte possible** permettant de trier les entiers passés en arguments.

Ce projet nous a permis d'aborder :
- la complexité algorithmique,
- différents algorithmes de tri,
- la sélection dynamique d'une stratégie selon le niveau de désordre des données ("disorder").

---

## Instructions

### Compilation

Le projet contient un `Makefile` conforme au sujet, sans relink inutile.

Pour compiler :

```bash
make
```

Cela génère l'exécutable `push_swap`.

---

### Exécution

Le programme prend en argument une liste d'entiers à trier :

```bash
./push_swap 2 1 3 6 5 8
```

---

## Options et Flags

Le programme supporte plusieurs flags permettant de forcer une stratégie ou d'activer un mode benchmark :

- `--simple` : Force l'algorithme en **O(n²)**
- `--medium` : Force l'algorithme en **O(n√n)**
- `--complex` : Force l'algorithme en **O(n log n)**
- `--adaptive` : *(par défaut)* Choisit automatiquement la meilleure stratégie
- `--bench` : Affiche les métriques de performance et le désordre sur la sortie d'erreurs.

### Exemple avec benchmark

```bash
ARG="4 67 3 87 23"; ./push_swap --bench $ARG
```

---

## Algorithmes implémentés

Conformément au sujet, quatre stratégies distinctes ont été développées.

### 1. Simple Algorithm — **O(n²)** (Selection Sort)

- **Implémentation** : `algos/simple_select.c`
- **Principe** :
  - Recherche du minimum dans la pile A
  - Placement en haut via `ra` ou `rra`
  - Envoi dans la pile B (`pb`)
  - Répétition jusqu'à vider A
  - Rapatriement de B vers A

- **Justification** :
  Très efficace pour les listes avec un faible disorder, et une petite quantite de nombres a trier. Il minimise le nombre d'instructions.
---

### 2. Medium Algorithm — **O(n√n)** (Chunk Sort)

- **Implémentation** : `algos/medium_chunk.c`
- **Principe** :
  - Division des valeurs triées théoriquement en √n groupes (*chunks*)
  - Envoi progressif des éléments de A vers B par chunk
  - Reconstruction de A en récupérant les maximums depuis B

- **Justification** :
  Très bon compromis entre performance et simplicité pour des listes moyennement triées (entre 20% et 50%).

---

### 3. Complex Algorithm — **O(n log n)** (Radix Sort binaire)

- **Implémentation** : `algos/complex_radix.c`
- **Principe** :
  - Indexation des valeurs pour gérer les négatifs
  - Tri bit par bit (LSB → MSB)
  - Les valeurs avec bit = 0 vont dans B, celles avec bit = 1 restent dans A

- **Justification** :
  Extrêmement stable et performant pour les grands ensembles (500+ nombres). La complexité dépend du nombre de bits (`k × n`).

---

### 4. Stratégie Adaptive (Custom)

- **Implémentation** : `main.c`, `disorder.c`
- **Principe** :
  - Calcul du **disorder** (pourcentage de paires mal ordonnées)
  - Sélection automatique de la stratégie :

| Disorder | Algorithme utilisé |
|--------|-------------------|
| < 0.2 | Simple Sort — O(n²) |
| 0.2 à < 0.5 | Chunk Sort — O(n√n) |
| ≥ 0.5 | Radix Sort — O(n log n) |

- **Raisonnement** :
  Un algorithme complexe est inefficace sur une liste presque triée, tandis qu'un algorithme simple devient trop lent sur une liste très désordonnée. Cette approche garantit le meilleur score possible quel que soit l'input.

---

## Resources

- Documentation sur le **Chunk Sort** et le **Radix Sort**
- Sujet officiel 42 — *Push_swap*

---

## Utilisation de l'IA

- Génération de listes aleatoires pour tester notre fonction de disorder.
- Vulgarisation des concepts liés à la complexité.

## Contribution de chacun

- La plupart du travail a été réalisé à deux :
  - Segmentation et planification du travail à réaliser.
  - base (opérations, liste chainées...)
  - Algos simples et medium.
- Papilaz : finalisation et amélioration du parsing et des gestions d'erreurs.
- Ajeloyan : Implémentation du système de tri complexe (Radix).

