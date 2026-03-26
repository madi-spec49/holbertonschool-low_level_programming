                    // Point entre et sortie //
static int *make_numbers(int n)
{
    int i = 0;
    int *arr = NULL;

    if (n <= 0)
        return NULL;
        
                    //     Appels récursifs   //
main()
  └── make_numbers(5)  // un seul appel donc pas de recursifs ici
        └── return arr

                    // Allocation de memoire //
arr = malloc(5 * sizeof(int))
→ réserve 20 bytes sur le HEAP
→ remplit [0, 11, 22, 33, 44]
→ retourne l'adresse 
LIBÉRATION
──────────
free(a)
→ les 20 bytes sont libérés
→ MAIS b pointe encore là !



b = a ne copie pas le tableau — il copie juste l'adresse
free(a) libère la mémoire — mais ne met pas b à NULL
Toujours faire b = NULL après free pour éviter les dangling pointers !



main() démarre
│
├── a = make_numbers(5)
│     └── malloc(20 bytes) → 0x4a8c480
│         [0][11][22][33][44]
│
├── b = a
│     └── b = 0x4a8c480 ← même adresse !
│
├── free(a)
│     └── heap libéré ❌
│         a et b = dangling pointers ⚠️
│
├── b[2] ← Invalid read ❌
├── b[3] = 1234 ← Invalid write ❌
│
└── return 0
      └── stack frame détruit