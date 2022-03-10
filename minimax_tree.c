#include <stdio.h>

#include <stdlib.h>

#include <limits.h>

#include "minimax_tree.h"

MMNode * new_MMNode(int nodes) {
    MMNode * temp = (MMNode * ) malloc(sizeof(MMNode));
    temp -> nodes = nodes;
    if (nodes == 0)
        temp -> next = NULL;
    else
        temp -> next = (MMNode ** ) malloc(sizeof(MMNode * ) * nodes);
    return temp;
}

MMNode * create_MMTree(FILE * fi, int height, int nodes, int minmax, int * tab, int pos) {
    char c;
    MMNode * temp = new_MMNode(nodes);
    int i = 0, vec[nodes], min = INT_MAX, max = INT_MIN;
    fseek(fi, tab[pos], SEEK_SET);
    for (i; i < nodes; i++) {
        c = (char) fgetc(fi);
        if (c == '\n')
            c = (char) fgetc(fi);
        if (c == '(') {
            fscanf(fi, "%d", & vec[i]);
            fseek(fi, 2, SEEK_CUR);
        } else if (c == '[') {
            vec[i] = 0;
            temp -> next[i] = new_MMNode(0);
            fscanf(fi, "%d", & temp -> next[i] -> data);
            fseek(fi, 2, SEEK_CUR);
        }
    }
    tab[pos] = ftell(fi);
    for (i = 0; i < nodes; i++) {
        if (vec[i] > 0)
            temp -> next[i] = create_MMTree(fi, height - 1, vec[i], 1 - minmax, tab, pos + 1);
        if (temp -> next[i] -> data < min)
            min = temp -> next[i] -> data;
        if (temp -> next[i] -> data > max)
            max = temp -> next[i] -> data;
    }
    if (minmax)
        temp -> data = max;
    else
        temp -> data = min;
    return temp;
}

void free_MMTree(MMNode * root) {
    MMNode * head = root;
    if (head == NULL) return;
    int i;
    for (i = 0; i < head -> nodes; i++) {
        if (head -> next[i] != NULL)
            free_MMTree(head -> next[i]);
    }
    free(head -> next);
    free(head);
}

void print_MMTree(MMNode * root, FILE * fo, int n) {
    if (root == NULL)
        return;
    int i, j = 0;
    for (j; j < n; j++) {
        putc('\t', fo);
    }
    fprintf(fo, "%d", root -> data);
    putc('\n', fo);
    for (i = 0; i < root -> nodes; i++) {
        print_MMTree(root -> next[i], fo, n + 1);
    }
}