# 🔐 Hash Table en C

Ce projet implémente une **table de hachage (hash table)** en langage C avec gestion des collisions.

## 📌 Description

Une table de hachage est une structure de données qui permet de stocker des paires **clé-valeur** et d’effectuer des opérations rapides comme :

- Insertion
- Recherche
- Suppression

Ce projet utilise une méthode de gestion des collisions (chaînage ou adressage ouvert selon ton implémentation).

---

## ⚙️ Fonctionnalités

- ✅ Insertion d’un élément (`insert`)
- 🔍 Recherche d’un élément (`search`)
- ❌ Suppression d’un élément (`delete`)
- 📊 Affichage de la table (`print`)

---

## 🧠 Principe

1. Une **fonction de hachage** transforme une clé en index.
2. Les données sont stockées dans un tableau.
3. En cas de collision :
   - soit chaînage (liste chaînée)
   - soit probing (linéaire, quadratique, etc.)

---

## 🗂️ Structure du projet
