#include <stdio.h>
#include "tokenizer.h"

char * Program_name;
int mode;
/*
 *0 = Program
 *1 = var
 *2 = begin
 *3 = end
 */
int address_counter =0;

int declaration(){
    //needs a hash map for variable look up
    //should be of type <int, malloc(sizeof(int))>
}

int initalization(int lookup, int val){

}
char ** equation_parse(char ** tokens){
    //go through parentecies and make a stack of equations in order
    char ** equation_list = malloc(sizeof(char *)*MAX_TOKENS);
    int i =0;
    int j =0;
    while(tokens[i]!=NULL){
        if(tokens[i][0]=='('){
               char ** tmp2 = malloc(sizeof(char *)*MAX_TOKENS);
               j =i+1;
               while(tokens[j]!=NULL){
                    tmp2[j-i]=tokens[j];
                    //printf("%s\n",tmp2[j-i]);
                    j++;
               }
               char ** tmp = equation_parse(tmp2);
               j =0;
               while(tmp[j]!=NULL){
                    equation_list[j]=tmp[j];
                    printf("%s\n",equation_list[j]);
                    j++;
               }
               j++;

        }else if(tokens[i][0]==')'){
            return equation_list;
        }
        equation_list[j] = tokens[i];
        i++;
    }
    return equation_list;
}
int process (char ** tokens){
    if(tokens[0] == "Program"){
        Program_name = tokens[1];
    }else if(tokens[0] == "var"){
        mode = 1;
    }else if (tokens[0] == "begin"){
        mode = 2;
    }else if(tokens[0] == "end"){
        return 0;
    }else{
        if(mode == 1){
            int i = 0;
            while(tokens[i] != ":"){
               if (tokens[i] == "var"){
                   i++;
                   continue;
                }else{
                   //insert into hash map
                    insert(tokens[i],(address_counter++)*4);
                   //insert memory address
               }
           }
        }else{
            char ** tmp = equation_parse(tokens);
            int i =0;
            while(tmp[i]!=NULL){
                printf("%s\n",tokens[i++]);
            }

            //process math equations
            //
        }
    }
    return 0;
}

int read(){

    FILE *fptr;
    mode = 0;
    fptr = fopen("input.rhl", "r");
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fptr)) != -1) {
        // do stuff with line
        char ** tokens = tokenize(line);
        int i=0;
        char ** tmp = equation_parse(tokens);
        /*while(tokens[i]!=NULL){
            printf("%s\n",tokens[i++]);
        }
        //printf("===================================\n");
            i =0;
            while(tmp[i]!=NULL){
                printf("%s\n",tokens[i++]);
            }*/
        //proccess tokens
    }
    fclose(fptr);
}

int main (int argc, char * argv[]){
    //make hashmap

    //three parts of program


    //1 declaration
    //
    //2 assignment initalization
    //
    //3 execution
    read();
    //declaration();
    printf("hello world\n");
    return 0;
}


