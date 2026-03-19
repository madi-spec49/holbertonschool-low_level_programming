# 📘 Structures et typedef en C

## 🧩 Introduction

En langage C, les **structures (`struct`)** permettent de regrouper plusieurs variables de types différents sous une seule entité.

Le mot-clé **`typedef`** permet quant à lui de créer un alias (un nouveau nom) pour un type existant, afin de rendre le code plus lisible.

---

## 🏗️ Définition d'une structure

Une structure se définit avec le mot-clé `struct` :

```c
struct Personne {
    char nom[50];
    int age;
    float taille;
};
```

👉 Ici, `Personne` est une structure contenant :

* un nom (`char`)
* un âge (`int`)
* une taille (`float`)

---

## 📦 Déclaration et utilisation

```c
struct Personne p1;

p1.age = 25;
```

---

## ✨ Utilisation de typedef

Sans `typedef`, il faut toujours écrire `struct` :

```c
struct Personne p2;
```

Avec `typedef`, on simplifie :

```c
typedef struct {
    char nom[50];
    int age;
    float taille;
} Personne;
```

👉 Ensuite :

```c
Personne p2;
```

---

## 🎯 Exemple complet

```c
#include <stdio.h>

typedef struct {
    char nom[50];
    int age;
} Personne;

int main() {
    Personne p;

    p.age = 30;

    printf("Age: %d\n", p.age);

    return 0;
}
```

---

## 🧠 Pourquoi utiliser typedef ?

✔️ Rend le code plus lisible
✔️ Évite de répéter `struct`
✔️ Facilite la maintenance

---

## ⚠️ Bonnes pratiques

* Donner des noms clairs aux structures
* Éviter les structures trop complexes
* Utiliser `typedef` pour simplifier l'utilisation

---

## 📚 Conclusion

Les structures permettent de modéliser des données complexes, et `typedef` aide à rendre le code plus propre et plus compréhensible.

👉 Ensemble, ils sont essentiels pour écrire des programmes C bien organisés.
