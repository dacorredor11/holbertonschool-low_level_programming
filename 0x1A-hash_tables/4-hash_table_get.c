#include "hash_tables.h"

/**
 * hash_table_get - get the value of the hash table
 * @ht: Hash table
 * @key: Given key
 * Return: value
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *node = ht->array[index];

	if (!key || !ht)
		return (NULL);

	if (node == 0)
		return (NULL);

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);

		node = node->next;
	}
	return (NULL);
}
