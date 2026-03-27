# 📚 Singly Linked List en C

## 📖 Description

Une **singly linked list** (liste simplement chaînée) est une structure de données où chaque élément (nœud) contient :

* une **valeur**
* un **pointeur vers le nœud suivant**

---

## 🧠 Structure d’un nœud en C

```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

---

## ⚙️ Opérations principales

### ➕ Insertion en tête

```c
void insertAtHead(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
```

---

### ➕ Insertion en fin

```c
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}
```

---

### ➖ Suppression d’un élément

```c
void deleteNode(Node** head, int key) {
    Node* current = *head;
    Node* prev = NULL;

    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;

    prev->next = current->next;
    free(current);
}
```

---

### 🔍 Affichage de la liste

```c
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
```

---

## 💻 Exemple complet

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtEnd(Node** head, int data);
void printList(Node* head);

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printList(head);

    return 0;
}
```

---

## 📊 Complexité

| Opération      | Complexité |
| -------------- | ---------- |
| Insertion tête | O(1)       |
| Insertion fin  | O(n)       |
| Recherche      | O(n)       |
| Suppression    | O(n)       |

---

## ⚠️ Remarques importantes

* Toujours utiliser `malloc()` pour allouer la mémoire
* Ne pas oublier `free()` pour éviter les fuites mémoire
* Vérifier les pointeurs `NULL` pour éviter les erreurs

---

## 📌 Conclusion

La liste simplement chaînée en C est une structure fondamentale pour comprendre la gestion de la mémoire et les pointeurs.

---
