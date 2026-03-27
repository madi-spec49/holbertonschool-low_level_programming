correction du code:

static void person_free_full(Person *p)
{
    if (!p)
        return;
    free(p->name);  /* libérer le champ avant le struct */
    free(p);
}

Explication :
strdup appelle malloc en interne pour copier la chaîne "Alice" (6 octets avec '\0').
Ce pointeur est stocké dans alice->name.
Quand person_free_partial(alice) est appelée, elle libère uniquement le struct Person avec free(p).
Le pointeur alice->name est alors perdu définitivement : plus aucune variable ne pointe dessus.
C'est un cas classique de lost ownership : la seule référence au bloc mémoire disparaît sans libération.

Warning 2 — Absence de fuite pour bob (comportement correct)
bob->name est libéré explicitement, puis bob lui-même.
Valgrind ne signale rien pour bob — c'est le comportement attendu.
Cela confirme que la fuite est spécifique à l'ordre de libération dans person_free_partial.