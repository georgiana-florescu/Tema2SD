#include <stdio.h>

#include <stdlib.h>

#include "and_or_tree.h"

#include "tree.h"

TNode * new_TNode(int n) {
    TNode * temp = (TNode * ) malloc(sizeof(TNode));
    temp -> data = n;
    int i;
    for (i = 0; i < 9; i++) {
        temp -> next[i] = NULL;
    }
    return temp;
}

TNode * create_TTree(Node * root, TNode * head, char c, char curr, int num) {
    if (root -> next[0] == NULL) {
        int p = 0;
        if (endgame(root -> data) && c != curr)
            p = 1;
        head = new_TNode(p);
        return head;
    }
    if (c == curr) {
        int p = 0;
        head = new_TNode(0);
        int k;
        for (k = 0; k < num; k++) {
            head -> next[k] = create_TTree(root -> next[k], head -> next[k], c, 'O' + 'X' - curr, num - 1);
            p = p | head -> next[k] -> data;
        }
        head -> data = p;

    } else {
        int p = 1;
        head = new_TNode(0);
        int k;
        for (k = 0; k < num; k++) {
            head -> next[k] = create_TTree(root -> next[k], head -> next[k], c, 'O' + 'X' - curr, num - 1);
            p = p & head -> next[k] -> data;
        }
        head -> data = p;
    }
    return head;
}

void free_TTree(TNode * root) {
    TNode * head = root;
    if (head == NULL)
        return;
    int i;
    for (i = 0; i < 9; i++) {
        if (head -> next[i] != NULL)
            free_TTree(head -> next[i]);
    }
    free(head);
}

void print_TTree(TNode * root, FILE * fo, int n) {
    if (root == NULL)
        return;
    int i, j = 0;
    for (j; j < n; j++) {
        putc('\t', fo);
    }
    if (root -> data)
        putc('T', fo);
    else
        putc('F', fo);
    putc('\n', fo);
    for (i = 0; i < 9; i++) {
        print_TTree(root -> next[i], fo, n + 1);
    }
}