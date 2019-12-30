#ifndef huff_tree_h
#define huff_tree_h

#include "../header/header.h"
#include "../hash/hash.h"
#include "../heap/heap.h"

typedef struct huff_node HUFF_NODE;
typedef struct hash_table HASH_TABLE;
typedef struct heap HEAP;

struct huff_node {
    long long int frequency;
    unsigned char key;
    HUFF_NODE *right, *left;
};

/** @param root: the huffman tree root*/
void print_huff_tree(HUFF_NODE *root);

/** @param root: the node that will be compared if it is a leaf*/
bool is_leaf(HUFF_NODE *root);

/** @param root: the node of the recursive function*/
/** @param hash_table: where the new mapping will be stored*/
/** @param compressed_file: the file that will have the new mapping wrote*/
/** @param mapping: the current mapping while traversing the tree*/
/** @param compressed_length: the actual length of the new mapping*/
/** @param trash_size: the reference of a var that holds the trash size*/
void bytes_mapping(HUFF_NODE *root, HASH_TABLE *hash_table, FILE *compressed_file, unsigned char mapping, int compressed_length, int *trash_size);

/** @param frequency: a number that represents the frequency of a byte in the file*/
/** @param key: the byte that appeared in the file*/
/** @param left: the left child of the huffman node*/
/** @param right: the right child of the huffman node*/
/** @return returns a huffman node with the parameters above*/
HUFF_NODE *create_huff_node(long long int frequency, unsigned char key, HUFF_NODE *left, HUFF_NODE *right);

/** @param root: the huffman tree*/
/** @param huff_tree_size: the reference of huff_tree_size*/
void get_huff_tree_size(HUFF_NODE *root, long long int *huff_tree_size);

/** @param queue: the queue that will generate the huffman tree*/
HUFF_NODE *build_tree(HEAP *queue);

#endif