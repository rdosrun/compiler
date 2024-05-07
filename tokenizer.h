#include <stdio.h>

#define MAX_TOKEN_LENGTH 1024
#define MAX_TOKENS 1024


struct node {
    bool break;
    char * value;
    struct node *next;
};
struct list {
    struct node * head;
    struct node * tail;
    struct node * current;
};
Sturct list * L = (struct list *) malloc(sizeof(struct list));

char * sanitize(char *input){
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
            if(input[i] != ';'){
                break;
            }
        }
        count++;
    }
    char * output = (char *) malloc(sizeof(char) * (end-i);

    for(int j =i; j < end; j++){
        output[j] = input[j];
    }
    return output;


}

char ** tokenize(char *input){
    int i = 0;
    int previous = 0;
    int token_count = 0;
    char * S_input = sanitize(input);
    char * tokens[MAX_TOKENS];
    while(S_input[i] != '\0'){
        if(S_input[i] == ' ' || S_input[i] == '\n' || S_input[i] == ';'|| S_input[i] == '='||S_input[i] == ':'){
            tokens[token_count] = malloc(sizeof(char) * (i - previous));
            for(int j = previous; j < i; j++){
                tokens[token_count][j - previous] = S_input[j];
                token_count++;
            }
        }

        i++;

    }
    return tokens;

}

char * parse_perentceis(char * input){
    S_input = sanitize(input);
    char * inside = (char *) malloc(sizeof(char) * MAX_TOKEN_LENGTH);
    bool check = true;
    while(S_input[i] != '\0'){

        if(S_input[i] == '('){
            check = false;
            i++;
            int j = 0;
            while(S_input[i] != ')'){
                inside[j] = S_input[i];
                i++;
                j++;
            }
            char * bits[MAX_TOKENS] = tokenize(inside);

        }
        i++;
    }
    if (check){
        if(L->head == NULL){
            L->head = malloc(sizeof(struct node));
            L->head->value =S_input;
            L->head->next = NULL;
            L->head->next->break = false;
            L->tail = L->head;
        }else{
            L->tail->next = malloc(sizeof(struct node));
            L->tail->next->value = S_input;
            L->tail->next->next = NULL;
            L->tail->next->break = false;
            L->tail = L->tail->next;
        }
            L->tail->next = malloc(sizeof(struct node));
            L->tail->next->break = true;
            L->tail->next->next = NULL;
            L->tail = L->tail->next;

    }
    return S_input;
}

char * proccess_expersions(char * input){
    //iterate through list of tokens
    L->current = L->head;
    while(L->current != NULL){

    }
    //check multiplcation and division first
    //
    //go back to last start of token and do addition and subtraction
}


char * mult_div(char * input){

}

char * add_sub(char * input){

}


