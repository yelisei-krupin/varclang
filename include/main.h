#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#define FILL_OUT malloc(100 * sizeof(int));

struct Vars {char key[100];int val;};
struct Block {char value[100];};
struct Part {char value[50];};
void s_Tokenizer(char *code, struct Block *b);
// extern struct Block block1;
#endif
