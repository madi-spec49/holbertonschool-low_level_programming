# 📚 Listes Doublement Chaînées en C

## 🔍 Introduction

Une **liste doublement chaînée** est une structure de données linéaire en langage **C** composée de nœuds. Chaque nœud contient :

* une **valeur**
* un pointeur vers le **nœud suivant** (`next`)
* un pointeur vers le **nœud précédent** (`prev`)

Elle permet de parcourir la liste dans les deux sens.

---

## 🧱 Structure d’un nœud en C

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
```

---

## ⚙️ Implémentation des opérations principales

### 🔹 Création d’un nœud

```c
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
```

---

### 🔹 Insertion en tête

```c
void insertFront(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head != NULL) {
        (*head)->prev = newNode;
        newNode->next = *head;
    }

    *head = newNode;
}
```

---

### 🔹 Insertion en fin

```c
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
```

---

### 🔹 Suppression d’un nœud

```c
void deleteNode(Node** head, int key) {
    Node* temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}
```

---

### 🔹 Parcours de la liste

#### ➤ Parcours avant

```c
void printForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
```

#### ➤ Parcours arrière

```c
void printBackward(Node* head) {
    Node* temp = head;

    if (temp == NULL) return;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
```

---

## 🧪 Exemple complet

```c
int main() {
    Node* head = NULL;

    insertFront(&head, 3);
    insertFront(&head, 1);
    insertEnd(&head, 5);

    printForward(head);   // 1 3 5
    printBackward(head);  // 5 3 1

    deleteNode(&head, 3);
    printForward(head);   // 1 5

    return 0;
}
```

---

## ✅ Avantages

* Parcours bidirectionnel
* Suppression efficace

---

## ❌ Inconvénients

* Utilise plus de mémoire
* Gestion des pointeurs plus complexe

---

## 🧠 Complexité

| Opération      | Complexité |
| -------------- | ---------- |
| Insertion tête | O(1)       |
| Insertion fin  | O(n)       |
| Suppression    | O(n)       |
| Parcours       | O(n)       |

---

## 📌 Conclusion

En **C**, les listes doublement chaînées offrent une grande flexibilité mais nécessitent une bonne gestion de la mémoire et des pointeurs.
