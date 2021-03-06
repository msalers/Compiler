#ifndef UNTITLED_DEF_H
#define UNTITLED_DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MODULE 258
#define ID 259
#define LBRACE 260
#define RBRACE 261
#define COLON 262
#define SEMICOLON 263
#define COMMA 264 
#define CHAR 265
#define INT 266
#define REAL 267
#define STRING 268
#define BOOL 269
#define VOID 270
#define VAR 271
#define CONST 272
#define BEGIn 273
#define END 274 
#define IF 275
#define THEN 276
#define ELSE 277
#define ELSEIF 278
#define WHILE 279
#define DO 280
#define RETURN 281
#define READ 282
#define WRITE 283
#define AND 284
#define OR 285
#define NOT 286
#define ASSIGN 287
#define LE 288
#define GE 289
#define LT 290
#define GT 291
#define EQ 292
#define NEQ 293
#define PLUS 294
#define MINUS 295
#define AST 296
#define FRAC 297
#define INTCONST 298
#define REALCONST 299
#define CHARCONST 300
#define STRCONST 301
#define BOOLCONST 302
#define ERROR 303
#define RETURNNULL 304

char* telaFileName;

/*Elenco dei non terminali*/
typedef enum {
	NPROGRAM,
	NMODULE_DECL,
	NOPT_PARAM_LIST,
	NPARAM_LIST,
	NPARAM_DECL,
	NTYPE,
	NOPT_VAR_SECT,
	NDECL_LIST,
	NDECL,
	NID_LIST,
	NOPT_CONST_SECT, //10
	NCONST_LIST,
	NCONST_DECL,
	NOPT_MODULE_LIST,
	NMODULE_BODY,
	NSTAT_LIST,
	NSTAT,
	NASSIGN_STAT,
	NIF_STAT,
	NOPT_ELSEIF_STAT_LIST,
	NOPT_ELSE_STAT, //20
	NWHILE_STAT,
	NRETURN_STAT,
	NOPT_EXPR,
	NREAD_STAT,
	NWRITE_STAT,
	NEXPR_LIST,
	NEXPR,
	NEXPR1,
	NBOOLOP,
	NBOOL_TERM,
	NRELOP,
	NREL_TERM,
	NREL_TERM1,
	NLOW_BINOP,
	NLOW_TERM,
	NLOW_TERM1,
	NHIGH_BINOP,
	NFACTOR,
	NUNARYOP,
	NCONSTANT,
	NMODULE_CALL,
	NOPT_EXPR_LIST,
	NCOND_EXPR,
	NOPT_ELSEIF_EXPR_LIST
} Nonterminal;

/*Elenco dei tipi di nodo (che devono conservare dati)*/
typedef enum {
	T_CHAR,
	T_INT,
	T_REAL,
	T_STRING,
	T_BOOL,
	T_VOID,
	T_CHARCONST,
	T_INTCONST,
	T_REALCONST,
	T_STRCONST,
	T_BOOLCONST,
	T_ID,
	T_NONTERMINAL,
	T_AST,
	T_FRAC,
	T_MINUS,
	T_PLUS,
	T_NOT,
	T_LE,
	T_GE,
	T_LT,
	T_GT,
	T_EQ,
	T_NEQ,
	T_AND,
	T_OR,
	T_RETURNULL
} Typenode;

/*Definizione della union del Lexval*/
typedef union {
	int ival;
	float rval;
	char *sval;
} Lexval;

/*Definizione della struttura di un nodo*/
typedef struct structNode {
	Typenode type;
	Lexval value;
	struct structNode *child, *brother;
} Node;

typedef Node *Pnode; /*Definisco il tipo Pnode per semplicità*/

/*Metodi usati dal lexer.lex -> NON TOCCARE*/
char *strcpy(char*, const char*), *newstring(char*);

#endif