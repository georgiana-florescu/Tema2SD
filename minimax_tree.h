#ifndef MINIMAX_TREE_H
#define MINIMAX_TREE_H

typedef struct MMNode {
    int data;
    int nodes;
    struct MMNode ** next;
}MMNode;

//creeaza un nod nou
MMNode * new_MMNode(int nodes);

//insereaza recursiv nodurile
MMNode * create_MMTree(FILE * fi, int height, int nodes, int minmax, int * tab, int pos);

//sterge intregul arbore si elibereaza memoria alocata
void free_MMTree(MMNode * root);

//insereaza arborele in fisierul de iesire
void print_MMTree(MMNode * root, FILE * fo, int n);

#endif