#include <stdio.h>

#include "pilhas.h"

int main() {

    pilha p;

    stack_init(&p);
    push(&p, 'A');
    push(&p, 'B');
    push(&p, 'C');
    push(&p, 'D');
    print_stack(&p);

    printf("\ninvert list:\n");
    invert_stack(&p);
    print_stack(&p);

    return 0;

}

