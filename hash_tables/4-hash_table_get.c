#include "hash_tables.h"

/**
 * hash_table_get - A function that gets key and value froma hash table.
 * @ht: A pointer to hash table to pull value from.
 * @key: The key to get value from hash table.
 * Return: The value associated to key, or NULL if key was not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *node;

    if (!ht || !key || strlen(key) == 0)
        return NULL;

    index = key_index((const unsigned char *)key, ht->size);

    node = ht->array[index];
    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return node->value;
        node = node->next;
    }
    return NULL;
}
