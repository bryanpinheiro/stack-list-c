#include <stdio.h>
#include "pilhas.h"



///: inicializa a pilha p no estado vazio

void stack_init(pilha * p) {
    p->topo = 0;
}



///: insere o elemento x no topo da pilha p

bool push(pilha * p, t_dado x) {

    if(p->topo == MAX_TAM) return false;

    p->itens[p->topo++] = x;

    return true;
}

///: remove e devolve o elemento do topo da pilha p

bool pop(pilha * p, t_dado * r) {

    if (p->topo == 0) return false;

    *r = p->itens[--p->topo];

    return true;
}

///: acessa o elemento do topo da pilha p devolvendo uma cópia do seu valor

bool top(pilha p, t_dado * topo) {

    if (p.topo == 0) return false;

    *topo = p.itens[p.topo - 1];

    return true;
}

///: devolve verdadeiro se a pilha p estiver vazia e falso, caso contrário

bool stack_isempty(pilha p) {
    return p.topo == 0;
}

///: devolve verdadeiro se a pilha p estiver cheia e falso, caso contrário

bool stack_isfull(pilha p) {
    return p.topo == MAX_TAM;
}

void print_stack(pilha * p) {

    if (stack_isempty(*p)) {
        printf("Stack is empty");
        return;
    }

    pilha temp_stack;
    stack_init(&temp_stack);

    while(!stack_isempty(*p)) {
        t_dado element;
        pop(p, &element);
        printf("%c \n", element);
        push(&temp_stack, element);
    }

    //Put the items back
    while(!stack_isempty(temp_stack)) {
        t_dado element;
        pop(&temp_stack, &element);
        push(p, element);
    }

}

void invert_stack(pilha * p) {

    if (stack_isempty(*p)) {
        printf("Stack is empty");
        return;
    }

    pilha temp_stack;
    stack_init(&temp_stack);

    while(!stack_isempty(*p)) {
        t_dado element;
        pop(p, &element); //Get the top item from the list
        push(&temp_stack, element); // Move the top items to the bottom
    }

    *p = temp_stack; //change original list

}


