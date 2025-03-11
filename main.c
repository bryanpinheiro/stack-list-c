#include <stdbool.h>
#include <stdio.h>

#include "pilhas.h"

int main() {

  pilha p;

  stack_init(&p);
  push(&p, 'A');
  push(&p, 'B');
  push(&p, 'C');
  push(&p, 'D');

  printf("Topo antes: %d\n", p.topo);
  t_dado removido;
  pop(&p, &removido);
  printf("Topo depois: %d\n", p.topo);
  push(&p, 'E');

  printf("\nPilha inicial:\n");
  print_stack(&p);

  printf("\n0 - Inverter pilha:\n");
  invert_stack(&p);
  print_stack(&p);

  printf("\n1 - Inverter string:\n");
  invertString("Bryan");

  printf("\n\n3 - Pilhas de ímpares e pares.\n");
  pilha even, numbers;
  stack_init(&even);
  read_numbers_stack(&numbers);
  get_evens_and_odds(&even, &numbers);
  printf("\nPares: \n");
  print_stack(&even);

  printf("\n4 - Ler números e exibir na ordem:\n");
  pilha pnumeros;
  read_numbers_order(&pnumeros);

  printf("\n5 - Ler números até ficar cheia:\n");
  pilha pnumeros2;
  read_numbers_stack(&pnumeros2);
  print_stack(&pnumeros2);

  printf("\n6 - Desempilhar pilhas:\n");
  unstack(&p);

  printf("\n7 - Comparar pilhas:\n");
  pilha p2;
  stack_init(&p2);
  push(&p2, 'Z');
  push(&p2, 'X');
  push(&p2, 'Y');
  push(&p2, 'O');
  push(&p2, 'P');

  bool isBigger = compare_stack(p, p2);
  if (isBigger) {
    printf("A pilha p1 é maior que a pilha p2");
  } else {
    printf("A pilha p2 é maior que a pilha p1");
  }

  return 0;
}
