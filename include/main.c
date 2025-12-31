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

void b_logic(char *code1) {
    int i =0;int v_i = 0, flag = 0;
    char vpart[100];
    /* ;AOZGAR+BOZGAR;; */
    while(code1[i] != '\0') {
            if(code1[i] == ';' && code1[i+1] != ';') {flag = 1;};
            if(code1[i] == ';' && code1[i+1] == ';') {flag =0;};
            if(flag == 1) {
               if(code1[i] != ';') {
                 vpart[v_i] = code1[i];
                 v_i++;
               }
            }    
            else if(flag == 0) {
                vpart[v_i] = '\0';
                strcpy(parts_ls[parts_ls_i].value, vpart);
                v_i = 0;
                parts_ls_i++;
                vpart[v_i] = '\0';
            }
             i++;
        }
}

void b_p_logic(char *code) {
    int i = 0, v_i =0,v_i2=0, flag=0, temp = 0;
    struct Token_v2 token;
    char vpart[100];
    char vpart2[100];
    int leng = strlen(code);
        while(code[i]!='\0') {

        if(code[i-1] == '+' || code[i-1] == '/' || code[i-1] == '*' || code[i-1] == '-'){temp = 1;}
        if(temp ==1) {
            vpart2[v_i2]=code[i];
            v_i2++;
        }

        /* AOZGAR*BOZGAR */
        
        if(code[i] == '+' || code[i] == '/' || code[i] == '*' || code[i] == '-') {
            switch(code[i]) {
                case '+':
                    token.method = 0;
                    break;
                case '-':
                    token.method = 1;
                    break;
                case '*':
                    token.method = 2;
                    break;
                case '/':
                    token.method = 3;
                    break;
                default:
                    token.method=4;
                    break;
            }
            flag=1;
        }
        if(flag==0) {
             vpart[v_i] = code[i];
             v_i++;
        }
        i++;
    }   

    if(flag == 1) {
        vpart[v_i] = '\0';
        strcpy(token.key1, vpart);
        v_i = 0;
        vpart[0] = '\0';
    }
    
    vpart2[v_i2]= '\0';
    strcpy(token.key2, vpart2); 
    v_i2 = 0;
    vpart2[v_i2] = '\0';
    tokens_ls[tokens_lsi] = token;
    tokens_lsi++;
}

int real_logic(struct Token_v2 t) {
    int dat[3];
    int tokens_count = sizeof(tokens) / sizeof(tokens[0]);
    for(int i = 0; i < tokens_count; i++) {
        if(tokens[i].key[0] == '\0') continue; 
        if(strcmp(t.key1, tokens[i].key) == 0) {
            dat[0]=tokens[i].value;
            break;
        }
    }

        for(int i = 0; i < tokens_count; i++) {
            if(tokens[i].key[0] == '\0') continue; 
            if(strcmp(t.key2, tokens[i].key) == 0) {
            
                dat[1]= tokens[i].value;
                break;
            }
        }
    return dat[0];
    // printf("Topilgan qiymat: %d %d %d \n", val1, t.method, val2);
}

int calculate(int val1, int val2, struct Token_v2 t) {
    switch(t.method) {
        case 0:
            printf("%d", val1 + val2);
            break;
        case 1:
            printf("%d", val1 - val2);
            break;
        case 2:
            printf("%d", val1 * val2);
            break;
        case 3:
            printf("%d", val1 / val2);
            break;
        default:
            return 0;
            break;
    }
}


int main() {
    char *code="<;AOZGAR=1202;;BOZGAR=152;;HOLAM=123;;AMAKIM=33;;LALAM=10;;HHAM=1;;>(;AOZGAR*BOZGAR;;HOLAM-AMAKIM;;HOLAM*AMAKIM;;LALAM+HHAM)";
    struct Block* block1;
    struct Block* block2;
    struct Part* p=malloc(sizeof(*p));
	v_Tokenizer(code, block1);
	l_Tokenizer(code, block2);
	p_b_Tokenizer(block1->value);
	t_p_b_Tokenizer(parts[0].value);
	t_p_b_Tokenizer(parts[1].value);
	t_p_b_Tokenizer(parts[2].value);
	t_p_b_Tokenizer(parts[3].value);
	t_p_b_Tokenizer(parts[4].value);
	b_logic(block2->value);
	b_p_logic(parts_ls[0].value);
	b_p_logic(parts_ls[1].value);
	b_p_logic(parts_ls[2].value);
	b_p_logic(parts_ls[3].value);
	b_p_logic(parts_ls[4].value);
    int val1, val2;
    memset(&tokens_ls[tokens_lsi], 0, sizeof(tokens_ls[tokens_lsi]));
    memset(&tokens[token_i], 0, sizeof(tokens[token_i]));

    for(int i = 0;i < 10;i++) {
        if(tokens_ls[i].key1[0] != '\0') {
            int va1, val2;
            real_logic(tokens_ls[i], val1, val2);
            printf("%d %d", val1, val2);
        }
    }
}
