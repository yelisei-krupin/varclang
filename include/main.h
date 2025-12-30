#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#define FILL_OUT malloc(100 * sizeof(int));


int part_i = 0;

struct Block {char value[100];};
struct Part {char value[50];};
struct Token {char key;int value;};
struct Part parts[100];
void v_Tokenizer(char *code, struct Block *b);
void l_Tokenizer(char *code, struct Block *b);
void p_b_Tokenizer(char *code);
// extern struct Block block1;
#endif
