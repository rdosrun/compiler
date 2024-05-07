#include <stdio.h>
#include "hash.h"
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
int write(char * value){
    FILE *fptr;
    if(Program_name == NULL){
        fptr = fopen("output.asm", "a");
    }else{
        fptr = fopen(Program_name+".asm", "a");
    }
    fprintf(fptr, "%s", value);
    fclose(fptr);


}
int process(char ** tokens){
    if(tokens[0] == "Program"){
        Program_name = tokens[1];
    }else if(tokens[0] == "var"){
        mode = 1;
    }else if (tokens[0] == "begin"){
        mode = 2;
    }else if(tokens[0] == "end"){
        return;
    }else{
        if(mode == 1){
            int i = 0;
            while(tokens[i] != ":"){
               if (tokens[i] == "var"){
                   i++;
                   continue;
                }else{
                   //insert into hash map

                   //insert memory address
               }
           }
        }
    }

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
        //proccess tokens
    }
    fclose(fptr);
}

int main(int argc, char *argv[]){
    //make hashmap

    //three parts of program


    //1 declaration
    //
    //2 assignment initalization
    //
    //3 execution

    declaration();
    printf("hello world\n");
}


