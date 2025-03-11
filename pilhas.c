#include "pilhas.h"
#include <stdio.h>
#include <string.h>

///: inicializa a pilha p no estado vazio
void stack_init(pilha *p) { p->topo = 0; }

///: insere o elemento x no topo da pilha p
bool push(pilha *p, t_dado x) {

  if (p->topo == MAX_TAM)
    return false;

  p->itens[p->topo++] = x;

  return true;
}

///: remove e devolve o elemento do topo da pilha p
bool pop(pilha *p, t_dado *r) {

  if (p->topo == 0)
    return false;

  *r = p->itens[--p->topo];

  return true;
}

///: acessa o elemento do topo da pilha p devolvendo uma c�pia do seu valor
bool top(pilha p, t_dado *topo) {

  if (p.topo == 0)
    return false;

  *topo = p.itens[p.topo - 1];

  return true;
}

///: devolve verdadeiro se a pilha p estiver vazia e falso, caso contr�rio
bool stack_isempty(pilha p) { return p.topo == 0; }

///: devolve verdadeiro se a pilha p estiver cheia e falso, caso contr�rio
bool stack_isfull(pilha p) { return p.topo == MAX_TAM; }

void print_stack(pilha *p) {

  if (stack_isempty(*p)) {
    printf("Stack is empty");
    return;
  }

  pilha temp_stack;
  stack_init(&temp_stack);

  while (!stack_isempty(*p)) {
    t_dado element;
    pop(p, &element);
    printf("%c \n", element);
    push(&temp_stack, element);
  }

  // Put the items back
  while (!stack_isempty(temp_stack)) {
    t_dado element;
    pop(&temp_stack, &element);
    push(p, element);
  }
}

void invert_stack(pilha *p) {

  if (stack_isempty(*p)) {
    printf("Stack is empty");
    return;
  }

  pilha temp_stack;
  stack_init(&temp_stack);

  while (!stack_isempty(*p)) {
    t_dado element;
    pop(p, &element);           // Get the top item from the list
    push(&temp_stack, element); // Move the top items to the bottom
  }

  *p = temp_stack; // change original list
}

bool compare_stack(pilha p1, pilha p2) { return p1.topo > p2.topo; }

bool unstack(pilha *p) {

  printf("Elementos desempilhados: ");
  t_dado valor;
  while (pop(p, &valor)) {
    printf("\n %c", valor);
  }

  return true;
}

void read_numbers_stack(pilha *p) {
  int number;

  while (!stack_isfull(*p)) {
    printf("\nEnter an integer: ");
    scanf("%d", &number);

    if (number >= 0 && number <= 9) {
      char c[2];
      sprintf(c, "%d", number);
      push(p, c[0]);
    }
  }

  printf("a pilha está cheia.\n");
}

void read_numbers_order(pilha *p) {
  read_numbers_stack(p);
  invert_stack(p);
  printf("\nOrdem dos itens digitados: \n");
  print_stack(p);
}

void invertString(char *str) {
  printf("\nString original: %s", str);

  pilha p;
  stack_init(&p);

  int length = strlen(str);
  for (int i = 0; i < length; i++) {
    push(&p, str[i]);
  }

  printf("\nString invertida: ");

  for (int i = 0; i <= length; i++) {
    char c = ' ';
    pop(&p, &c);
    printf("%c", c);
  }
}

void get_evens_and_odds(pilha *even, pilha *numbers) {
  char c = ' ';
  int counter = 0;
  while (pop(numbers, &c)) {
    if (c % 2 == 0) {
      push(even, c);
    } else {
      counter++;
    }
  }

  printf("Números ímpares: %d", counter);
}
