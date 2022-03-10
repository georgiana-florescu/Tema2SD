#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "tree.h"

#include "and_or_tree.h"

#include "minimax_tree.h"

int main(int argc, char ** argv) {
    FILE * fi = fopen(argv[2], "r");
    FILE * fo = fopen(argv[3], "w");
    if (!strncmp(argv[1], "-c3", 3)) {
        MMNode * mmroot;
        int i, height, * vec, nodes;
        char c;
        fscanf(fi, "%d", & height);
        c = fgetc(fi);
        vec = (int * ) calloc(height, sizeof(int));
        for (i = 0; i < height; i++) {
            vec[i] = ftell(fi);
            c = (char) fgetc(fi);
            while (c != '\n') {
                c = fgetc(fi);
            }
        }
        fseek(fi, vec[0] + 1, SEEK_SET);
        fscanf(fi, "%d", & nodes);
        fseek(fi, 0, SEEK_SET);
        mmroot = create_MMTree(fi, height, nodes, 1, vec, 1);
        print_MMTree(mmroot, fo, 0);
        free_MMTree(mmroot);
        free(vec);
    } else {
        char c, vec[9];
        c = (char) fgetc(fi);
        int i, num = 0;
        Node * root;
        for (i = 0; i < 9; i++) {
            vec[i] = (char) fgetc(fi);
            if (vec[i] == '-')
                num++;
            if (vec[i] != 'O' && vec[i] != 'X' && vec[i] != '-')
                i--;
        }
        root = create_Tree(root, vec, c, num);
        if (!strncmp(argv[1], "-c1", 3))
            print_Tree(root, fo, 0);
        else {
            TNode * troot = create_TTree(root, troot, c, c, num);
            print_TTree(troot, fo, 0);
            free_TTree(troot);
        }
        free_Tree(root);
    }
    fclose(fi);
    fclose(fo);
    return 0;
}