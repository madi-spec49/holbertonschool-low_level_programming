# Rapport de Crash — `crash_example.c`

## 1. Cause Racine

Le programme passe `n = 0` à `allocate_numbers(n)`.
La fonction retourne immédiatement `NULL` grâce à la garde `if (n <= 0) return NULL;`.
De retour dans `main`, la valeur de retour n'est **jamais vérifiée**.
Le programme écrit ensuite `nums[0] = 42` à travers un pointeur NULL — c'est un **déréférencement de pointeur NULL**.

**Ce crash est 100% déterministe et statique.**
Inutile d'exécuter le programme pour le conclure : la valeur de `n` est codée en dur à `0`.

---

## 2. Chaîne Causale Complète

```
int n = 0;
        |
        v
allocate_numbers(0)
        |
        | n <= 0  ->  return NULL
        v
nums = NULL
        |
        | aucune verification de NULL dans main
        v
nums[0] = 42   <- ecriture a l'adresse 0x0
        |
        v
SIGSEGV — Segmentation Fault
```

### Explication étape par étape

**Étape 1 — n est initialisé à 0**
```c
int n = 0;
```
Aucune valeur n'est assignée à `n` avant utilisation. Il reste à `0` pendant toute l'exécution.

**Étape 2 — allocate_numbers retourne NULL**
```c
if (n <= 0)
    return NULL;
```
La garde rejette correctement `n = 0` et retourne `NULL`.
Aucune allocation sur le tas n'a jamais lieu.

**Étape 3 — main ignore la valeur de retour**
```c
nums = allocate_numbers(n);
nums[0] = 42;   /* aucun if (!nums) */
```
`nums` vaut maintenant `NULL` (adresse `0x0`).
Le programme le déréférence immédiatement sans aucune vérification.

**Étape 4 — Accès mémoire invalide**
Écrire à l'adresse `0x0` est interdit par le système d'exploitation.
Le CPU lève une faute de protection mémoire.
L'OS envoie `SIGSEGV` au processus, le terminant immédiatement.

---

## 3. Catégorie de Comportement Indéfini

| Champ              | Détail                                              |
|--------------------|-----------------------------------------------------|
| **Catégorie**      | Déréférencement de pointeur NULL                    |
| **Norme C**        | Comportement indéfini — ISO C11 §6.5.3.2 ¶4        |
| **Type d'accès**   | Écriture (`nums[0] = 42`)                           |
| **Adresse**        | `0x0` (NULL)                                        |
| **Conséquence**    | SIGSEGV / segmentation fault (Linux/x86-64)         |

Ce n'est **pas** une corruption de tas, un use-after-free, ou un débordement de tampon.
C'est un simple **déréférencement de pointeur NULL en écriture**.

Le comportement est indéfini par la norme C, mais sur tout OS moderne avec protection mémoire,
le résultat pratique est toujours une segmentation fault car la page zéro n'est jamais mappée.

---

## 4. Ce que Valgrind Rapporterait

```
==PID== Invalid write of size 4
==PID==    at 0x...: main (crash_example.c:23)
==PID==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==PID==
==PID== Process terminating with default action of signal 11 (SIGSEGV)
==PID==  Access not within mapped region at address 0x0
==PID==    at 0x...: main (crash_example.c:23)
```

Valgrind classe ceci comme une **écriture invalide** à l'adresse `0x0`.
Il pointe correctement vers `crash_example.c:23` — la ligne `nums[0] = 42`.

---

## 5. Critique des Explications IA

### Affirmation IA n°1 — Classification incorrecte

> "Le crash est causé par un débordement de tampon car le tableau est trop petit pour contenir la valeur 42."

**Pourquoi c'est faux :**
Un débordement de tampon se produit quand une allocation valide existe mais est accédée au-delà de ses limites.
Ici, **aucune allocation n'a eu lieu** — `malloc` n'a jamais été appelé car `n = 0` a déclenché
le retour anticipé.
Il n'y a pas de tampon à déborder. Le crash est un déréférencement de pointeur NULL, pas un débordement.
Cette mauvaise classification mène à de mauvaises corrections (ex : augmenter la taille d'allocation),
ce qui ne résoudrait pas le vrai problème.

---

### Affirmation IA n°2 — Chaîne causale incomplète

> "Le programme plante car `free(nums)` est appelé sur un pointeur NULL."

**Pourquoi c'est faux :**
`free(NULL)` est **explicitement défini comme une opération sans effet** par ISO C11 §7.22.3.3 ¶2 — c'est sûr et ne cause aucun crash.
Le crash se produit à la ligne `nums[0] = 42`, **avant** que `free` soit jamais atteint.
Le programme ne parvient jamais à `free(nums)` car il se termine sur le déréférencement.
Cette explication inverse la chaîne causale et identifie mal à la fois le site du crash et sa cause.

---

## 6. Correction

```c
int main(void)
{
    int *nums = NULL;
    int n = 5;   /* utiliser une valeur positive valide */

    printf("crash_example: version corrigee\n");
    printf("  requesting n=%d\n", n);
    nums = allocate_numbers(n);
    if (!nums)   /* toujours verifier la valeur de retour */
    {
        fprintf(stderr, "  allocation echouee\n");
        return 1;
    }
    nums[0] = 42;
    printf("  nums[0]=%d\n", nums[0]);
    free(nums);
    return 0;
}
```

**Deux corrections appliquées :**
1. `n = 0` → `n = 5` — passer une valeur positive valide pour que l'allocation ait lieu.
2. Ajout du `if (!nums)` — programmation défensive contre l'échec d'allocation.

---

## 7. Résumé

| Champ               | Détail                                          |
|---------------------|-------------------------------------------------|
| **Type de crash**   | Segmentation fault (SIGSEGV)                    |
| **Cause racine**    | Déréférencement de pointeur NULL en écriture    |
| **Déclencheur**     | `n = 0` -> `allocate_numbers` retourne NULL     |
| **Vérification manquante** | Pas de `if (!nums)` avant `nums[0] = 42` |
| **Catégorie UB**    | Déréférencement NULL — ISO C11 §6.5.3.2         |
| **Déterministe ?**  | Oui — n est codé en dur, le crash est garanti   |