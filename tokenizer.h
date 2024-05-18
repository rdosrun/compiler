#include <stdio.h>
#include <string.h>
#include "hash.h"

#define MAX_TOKEN_LENGTH 1024
#define MAX_TOKENS 1024




struct node_list {
    bool break_option;
    char * value;
    struct node *next;
};
struct list {
    struct node_list * head;
    struct node_list * tail;
    struct node_list * current;
};
//struct list * L = (struct list *) malloc(sizeof(struct list));
char * Program_name;



char * sanitize (char *input)
{
    int i = 0;
    int count = 0;
    int end = 0;
    bool check = true;
    while(input[count] != '\0'){
        if(check && input[count] ==' '){
            i++;
        }else{
            check = false;
            end++;
            if(input[i] == ';'){
                break;
            }
        }
        count++;
    }
    char * output = (char *) malloc(sizeof(char) * (end-i));
    for(int j =i; j < end; j++){
        output[j] = input[j];
    }
    return output;
}

int write(char * value){
    FILE *fptr;
    if(Program_name == NULL){
        fptr = fopen("output.asm", "a");
    }else{
        fptr = fopen(strcat(Program_name,".asm"), "a");
    }
    fprintf(fptr, "%s", value);
    fclose(fptr);
}

char ** tokenize(char *input){
    int i = 0;
    int previous = 0;
    int token_count = 0;
    char * S_input = sanitize(input);
    char ** tokens= malloc(MAX_TOKENS*sizeof(char*));
    while(S_input[i] != '\0'){
        bool operators = (S_input[i]=='=' || S_input[i] == '-' || S_input[i]=='+' || S_input[i] =='*' || S_input[i] =='(' || S_input[i]==')');
        bool rm_operators = (S_input[i] == ' ' || S_input[i] == '\n' || S_input[i] == ';'||S_input[i] == ':');
        if(rm_operators || operators){
            tokens[token_count] = malloc(sizeof(char) * (i - previous));
            if(previous==(i-1)){
                if(previous==0){
                    for(int j = previous; j < i; j++){
                        tokens[token_count][j - previous] = S_input[j];
                    }
                    token_count++;
                }
            }else{
                previous++;
                for(int j = previous; j < i; j++){
                    tokens[token_count][j - previous] = S_input[j];
                }
                token_count++;
            }
            previous = i;
            if(operators){
                tokens[token_count] = malloc(sizeof(char));
                tokens[token_count][0] = S_input[i];
                token_count++;
            }
        }
        i++;

    }
    return tokens;

}

