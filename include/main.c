#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"
/*
        <A=5;B=5>(A+B;)	
*/
void v_Tokenizer(char *code, struct Block *b) {
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

void l_Tokenizer(char *code, struct Block *b) {
int i = 0, v_i = 0, flag = 0;
    char var_part[100];
    while(code[i] != '\0') {
        if(code[i] == '(') {
            flag = 1;
        } 
        else if(code[i] == ')') {
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

void p_b_Tokenizer(char *code) {
    int i = 0, v_i =0, flag=0;char v_part[50];
    /* <;A=5;;B=5;>(;A+B;) */    
    struct Part part;
    while(code[i] != '\0') {
        if(code[i] == ';' && code[i+1] != ';') {flag = 1;};
        if(code[i] == ';' && code[i+1] == ';') {flag =0;};
        if(flag == 1) {
            if(code[i] != ';') {
                v_part[v_i] = code[i];
                v_i++;
            }
        } else if(flag == 0) {
            v_part[v_i]='\0';
            strcpy(part.value, v_part);
            parts[part_i] = part;;
            part_i++;
            v_part[0] = '\0';
            part.value[0] = '\0';
            v_i=0; 
        }
        i++; 
    }
}
void t_p_b_Tokenizer(char *code) {
    char key=code[0];int i = 0;
    char val[10];
    char val2[10];
    int val_c=0, val2_c =0;
    while(code[i] != '\0') {
        if(isdigit(code[i])) {
            val[val_c] = code[i];
            val_c++;
        }
        if(isupper(code[i])) {
            val2[val2_c]=code[i];
            val2_c++;
        }
        i++;
    }
    val[val_c] = '\0';
    val2[val2_c] = '\0';
    struct Token_v1 t1;
    strcpy(t1.key,val2);
    t1.value=atoi(val);
    tokens[token_i] =t1;
    token_i++;
}

int main() {
    struct Block* block1;
    struct Block* block2;
    struct Part* p=malloc(sizeof(*p));
	v_Tokenizer("<;AOZGAR=1202;;BOZGAR=152;;DADAM=124;;>(;A+B;)", block1);
	l_Tokenizer("<;A=5;;B=5;;>(;A+B;;C+D;)", block2);
	p_b_Tokenizer(block1->value);
	t_p_b_Tokenizer(parts[0].value);
	t_p_b_Tokenizer(parts[1].value);
	t_p_b_Tokenizer(parts[2].value);

	for(int i = 0; i < 3;i++) {
	    printf("key: %s val: %d\n\n", tokens[i].key, tokens[i].value);
	}	
}
