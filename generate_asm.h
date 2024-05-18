#include <hash.h>


char * proccess_expersions(char * input){
    //iterate through list of tokens
    L->current = L->head;
    while(L->current != NULL){
        if(L->current->next->break){
            //run mult_div check for

            L->current->value = mult_div(L->current->value);
            L->current->value = add_sub(L->current->value);
        }
    }
    //check multiplcation and division first
    //
    //go back to last start of token and do addition and subtraction
}


char * mult_div(char * input){
    //look up addr for variables
    //this work will work something like this
    //iterate through all of the chars
    char ** addrs = replace_var(input);
    int i =0;
    char * var1;
    char * var2;
    bool check = false;
    while(input[i]!='\0'){

        if(input[i]==' '){

        }
        if(input[i]=='*'){

        }else{

        }

    //generate the asm for the operation given
    //write asm to file
    //load value into a temp addr numbered by name tmp1 tmp2 ...tmpx
    //replace place of orginal expression with temp addr
    //return orginal expression

    }
}

char * add_sub(char * input){
    //look up addr for variables
    //iterate through all of the chars
    //keep a pointer at first half of mult/division
    //generate asm
    //write to file
}



char * parse_perentceis(char * input){
    /*char * S_input = sanitize(input);
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
            L->head->break = false;
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

    }*/
    return input;
}
char ** replace_var(char * input){
    // this function should return an array of addresses to be used by the
    // mult_div and add_sub functions
    char ** table = malloc(MAX_TOKENS*sizeof(char *));
    /*int i =0;
    int tmp_count=0;
    char tmp [MAX_TOKEN_LENGTH];
    bool check = false;
    int var_count = 0;
    while(input[i]!='\0'){
        bool lower_case_check = (input[i]>='a' && input[i]<='z');
        bool upper_case_check = (input[i]>='A' && input[i]<='Z');
        bool num_check = (input[i]>='0' && input[i]<='9');
        bool valid_special_char = (input[i]=='_');
        if (lower_case_check||upper_case_check||(num_check && check)||valid_special_char) {
            tmp[tmp_count++]=input[i];
            check = true;
        }else{
            tmp[tmp_count] ='\0';
            char * addr = look_up_by_value(tmp);
            //add value to array
            table[var_count++] = addr;
            marker = tmp_count;
            tmp_count = 0;
            check = false;
        }
        i++;
    }*/
    return table;

}
