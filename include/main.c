#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/*
	<A=5;B=5>(A+B;)	
*/

void s_Tokenizer(char *code, struct Block *b) {
    int i = 0, v_i = 0, flag = 0;
    char var_part[100];
    while(code[i] != '\0') {
        if(code[i] == '<') {
            flag = 1;
        } 
        else if(code[i] == '>') {
            flag = 0;
            var_part[v_i] = '\0'; 
            strcpy(b->value, var_part); 
            v_i = 0;
        }
        else if (flag == 1) {
            var_part[v_i] = code[i];
            v_i++;
        }
        i++;
    }       
}

int main() {
    struct Block* block1;
	s_Tokenizer("<A=5;B=5>(A+B;)", block1);
	printf("%s", block1->value);
}
