#include <stdio.h>

#include <stdlib.h>

#include "tree.h"

Node * new_Node(char * v) {
    Node * temp = (Node * ) malloc(sizeof(Node));
    int i;
    for (i = 0; i < 9; i++) {
        temp -> data[i] = v[i];
        temp -> next[i] = NULL;
    }
    return temp;
}

int endgame(char * v) {
    int i;
    for (i = 0; i < 9; i += 3) {
        if (v[i] == v[i + 1] && v[i] == v[i + 2] && v[i] != '-')
            return 1;
    }
    for (i = 0; i < 3; i++) {
        if (v[i] == v[i + 3] && v[i] == v[i + 6] && v[i] != '-')
            return 1;
    }
    if (v[0] == v[4] && v[4] == v[8] && v[0] != '-')
        return 1;
    if (v[2] == v[4] && v[4] == v[6] && v[2] != '-')
        return 1;
    return 0;
}

Node * create_Tree(Node * root, char * v, char c, int num) {
    root = (new_Node(v));
    int i = 0, j = 0;
    for (i; i < num; i++) {
        if (endgame(v))
            break;
        for (j; j < 9; j++) {
            if (v[j] == '-') {
                v[j] = c;
                break;
            }
        }
        root -> next[i] = create_Tree(root -> next[i], v, 'O' + 'X' - c, num - 1);
        v[j++] = '-';
    }
    return root;
}

void free_Tree(Node * root) {
    if (root == NULL) return;
    int i;
    for (i = 0; i < 9; i++) {
        if (root -> next[i] != NULL)
            free_Tree(root -> next[i]);
    }
    free(root);
}

void print_Tree(Node * root, FILE * fo, int n) {
    if (root == NULL)
        return;
    int i = 0;
    for (i; i < 9; i += 3) {
        int j;
        for (j = 0; j < n; j++) {
            putc('\t', fo);
        }
        putc(root -> data[i], fo);
        putc(' ', fo);
        putc(root -> data[i + 1], fo);
        putc(' ', fo);
        putc(root -> data[i + 2], fo);
        putc('\n', fo);
    }
    putc('\n', fo);
    for (i = 0; i < 9; i++) {
        print_Tree(root -> next[i], fo, n + 1);
    }
}