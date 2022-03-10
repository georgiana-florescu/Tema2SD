#ifndef TREE_H
#define TREE_H

#ifndef NODE
#define NODE

typedef struct Node {
    char data[9];
    struct Node * next[9];
}Node;

#endif

//creeaza un nod nou
Node * new_Node(char * v);

//insereaza un nodurile in arbore recursiv
Node * create_Tree(Node * root, char * v, char c, int num);

//verifica daca exista un castigator in starea curenta
int endgame(char * v);

//sterge intregul arbore si elibereaza memoria alocata
void free_Tree(Node * root);

//insereaza arborele in fisierul de iesire
void print_Tree(Node * root, FILE * fo, int n);

#endif