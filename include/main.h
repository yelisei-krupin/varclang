#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#define FILL_OUT malloc(100 * sizeof(int));

struct Block {char value[100];};
struct Part {char value[50];};
struct Token {char key;int value;};
void v_Tokenizer(char *code, struct Block *b);
void l_Tokenizer(char *code, struct Block *b);
void v_b_Tokenizer(char *code, struct Token *token);
// extern struct Block block1;
#endif
