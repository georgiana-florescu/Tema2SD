#ifndef AND_OR_TREE_H
#define AND_OR_TREE_H

typedef struct TNode {
    int data;
    struct TNode * next[9];
}TNode;

#ifndef NODE
#define NODE

typedef struct Node {
    char data[9];
    struct Node * next[9];
}Node;

#endif

//creeaza un nod nou
TNode * new_TNode(int n);

//insereaza nodurile in arbore recursiv
TNode * create_TTree(Node * root, TNode * head, char c, char curr, int num);

//sterge arborele si elibereaza memoria alocata
void free_TTree(TNode * root);

//insereaza arborele in fisierul de iesire
void print_TTree(TNode * root, FILE * fo, int n);

#endif