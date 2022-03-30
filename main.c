#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int timeTo;
    struct node *next;
} node;

typedef struct fila {
    node *head;
    node *tail;
}fila;

int *new_node(int info) {
    node *ptr = (node *)malloc(sizeof(node));
    ptr->timeTo = info;
    ptr->next = NULL;
    return ptr;
}

void init_fila(fila *f, int num,int info, int index) {
    node *ptr = new_node(info);
    if (index == 0){
        f->head = ptr;
        f->tail = ptr;
    } else {
        f->tail->next = ptr;
        f->tail = ptr;
    }
}

int remove_fila(fila *f) {
    node *ptr = f->head;
    int aux;

    aux = ptr->timeTo;
    f->head = ptr->next; 

    if (f->head == NULL) {
        f->tail == NULL;
    }

    free(ptr);

    return aux;
}

void print_fila(fila *f,int num){
    node *ptr = f->head;
    for (int i = 0;i<num;i++) {
        printf("%d \n",ptr->timeTo);
        ptr = ptr->next;
    }
}

int empty_fila(fila *f){
    return f->head == NULL;
}

void round_robin_process(fila *f){

}

int main() {
    fila *f1 =(fila *)malloc(sizeof(f1));
    f1->head = NULL;
    f1->tail = NULL;
    
    int num, q;

    scanf("%d %d", &num, &q);

    int process[num];

    for (int i = 0;i < num;i++){
        scanf("%d",&process[i]);
        init_fila(f1,num,process[i],i);
    }
    printf("\n");

    printf("comeco do round robin\n\n");

    while (!empty_fila(f1)) {
        round_robin_process(f1);
    }

    print_fila(f1,num);
}