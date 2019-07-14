
#include "def.h"
#include "parser.h"
#include "syntaxTree.h"
#include "symbolTable.h"
#include "semantic.h"
#include "tcode.h"
#include <stdio.h>

int main(int nArgs, char  **args) {
    telaFileName = args[nArgs-1]; // l'ultimo argomento da linea di comando sarà il nome del file

//    telaFileName = "prog";

    Pnode root = parse();

    syntaxTree(root); // stampa su file l'albero sintattico


    PLine rootLine = symbolTable(root);
    displayTable();

    semanticControl(root->child, rootLine);

    genTCode(rootLine, root->child);

    return(0);
}