#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 10

struct node
{
    char * value;
    int address;
    struct node *next;
};

struct node * BUCKETS [MAX_BUCKETS];


//hash function
int hash(char * key){
    int i = 0;
    int value = 0;
    while(key[i] != '\0'){
        value = key[i++] + value;
    }
    return value % MAX_BUCKETS;
}

//insert
int insert(char* value, int address){
    int key = hash(value);
    if(BUCKETS[key] == NULL){
        struct node * temp1 = malloc(sizeof(struct node));
        temp1->value = value;
        temp1->address = address;
        temp1->next = NULL;
        BUCKETS[key] = temp1;
    }
    else{
        struct node * temp = BUCKETS[key];
        while(temp->next != NULL){
            temp = temp->next;
        }
        struct node * temp1 = malloc(sizeof(struct node));
        temp1->value = value;
        temp1->address = address;
        temp1->next = NULL;
        temp->next = temp1;
    }
}

//lookup by value
int lookup_by_value(char* value){
    int key = hash(value);
    if(BUCKETS[key] == NULL){
        return -1;
    }else{
        struct node * temp = BUCKETS[key];
        while(temp != NULL){
            if(temp->value == value){
                return temp->address;
            }
            temp = temp->next;
        }
        return -1;
    }
    return -1;
}

int main(){
    insert("hello", 1);
    insert("world", 2);
    insert("hello1", 3);
    insert("world1", 4);

    printf("%d\n", lookup_by_value("hello"));
    printf("%d\n", lookup_by_value("world"));
    printf("%d\n", lookup_by_value("hello1"));
    printf("%d\n", lookup_by_value("world1"));


    return 0;
}


