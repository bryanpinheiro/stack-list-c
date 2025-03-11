#ifndef _PILHAS_H_

#define _PILHAS_H_

#include <stdbool.h>

/** Tipo da Pilha (t_dado)

▼

int pilha[10];

▲

Capacidade da pilha (MAX_TAM)


*/

typedef char t_dado;

#define MAX_TAM 10

typedef struct {

  t_dado itens[MAX_TAM];

  int topo;

} pilha;

///: inicializa a pilha p no estado vazio
void stack_init(pilha *p);

///: insere o elemento x no topo da pilha p
bool push(pilha *p, t_dado x);

///: remove e devolve o elemento do topo da pilha p
bool pop(pilha *p, t_dado *r);

///: acessa o elemento do topo da pilha p devolvendo uma cópia do seu valor
bool top(pilha p, t_dado *topo);

///: devolve verdadeiro se a pilha p estiver vazia e falso, caso contrário
bool stack_isempty(pilha p);

///: devolve verdadeiro se a pilha p estiver cheia e falso, caso contrário
bool stack_isfull(pilha p);

void print_stack(pilha *p);

void invert_stack(pilha *p);

bool compare_stack(pilha p, pilha p2);

bool unstack(pilha *p);

void read_numbers_stack(pilha *p);

void read_numbers_order(pilha *p);

void invertString(char *str);

void get_evens_and_odds(pilha *even, pilha *numbers);

#endif // _PILHAS_H_
