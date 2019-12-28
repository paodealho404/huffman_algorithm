#ifndef huff_tree_h
#define huff_tree_h

#include "../header/header.h"

typedef struct huff_node HUFF_NODE;

struct huff_node {
    long long int frequency;
    void *key;
    HUFF_NODE *next, *right, *left;
};

HUFF_NODE *create_huff_node(long long int frequency, char key, HUFF_NODE *left, HUFF_NODE *right) {
    HUFF_NODE *new_huff_node = (HUFF_NODE *)malloc(sizeof(HUFF_NODE));
    char str[1] = {key};
    new_huff_node->key = malloc(sizeof(char *));
    new_huff_node->frequency = frequency;
    new_huff_node->key = str;
    new_huff_node->left = left;
    new_huff_node->right = right;
    printf("na chn: %c\n", *(char *)new_huff_node->key);
    return new_huff_node;
}

#endif