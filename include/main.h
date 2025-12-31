#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#define FILL_OUT malloc(100 * sizeof(int));


int part_i = 0;int token_i = 0, parts_ls_i = 0, tokens_lsi= 0;;
/*
        0 = +
        1 = -
        2 = *
        3 = /
*/

struct Block {char value[100];};
struct Part {char value[50];};
struct Token_v1 {char key[10];int value;};
struct Token_v2 {char key1[10];int method;char key2[10];};
struct Part parts[100];
struct Part parts_ls[100];
struct Token_v1 tokens[100];
struct Token_v2 tokens_ls[100];
void v_Tokenizer(char *code, struct Block *b);
void l_Tokenizer(char *code, struct Block *b);
void p_b_Tokenizer(char *code);
void t_p_b_Tokenier(char *code);
int real_logic(struct Token_v2 t);
// extern struct Block block1;
void b_logic(char *code1);
void b_p_logic(char *code);
#endif
