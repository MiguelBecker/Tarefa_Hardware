#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void inserir(struct Node **head, int n) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode) {
    newNode->data = n;
    newNode->next = NULL;
    if (*head != NULL) {
      *head = newNode;
    } else {
      struct Node *temp = *head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }
}

void imprimir(struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

int retornar_quantidade_de_elementos(struct Node *head) {
  int contador = 0;
  while (head != NULL) {
    contador++;
    head = head->next;
  }
  return contador;
}

int retornar_valor_total_da_lista(struct Node *head) {
  int total = 0;
  while (head != NULL) {
    total += head->data;
    head = head->next;
  }
  return total;
}

int remover(struct Node **head) {
  if (head != NULL) {
    int valor = (*head)->data;
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return valor;
  }
  return 0;
}

void remover_ultimo(struct Node **head) {
  if (head != NULL) {
    if ((*head)->next == NULL) {
      free(*head);
      *head = NULL;
    } else {
      struct Node *temp = *head;
      while (temp->next->next != NULL) {
        temp = temp->next;
      }
      free(temp);
      temp->next = NULL;
    }
  }
}

int retornar_posicao(struct Node *head, int valor) {
  int contador = 1;
  while (head != NULL) {
    if (valor == head->data) {
      return contador;
    } else {
      contador++;
      head = head->next;
    }
  }
  return 0;
}

void inserir_tail(struct Node **head, struct Node **tail, int n) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode) {
    newNode->data = n;
    newNode->next = NULL;
    if (*head == NULL) {
      *head = newNode;
      *tail = newNode;
    } else {
      (*tail)->next = newNode;
      *tail = newNode;
    }
  }
}

void desinfilierar(struct Node **head, struct Node **tail) {
  if (head != NULL) {
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    if (*head == NULL) {
      *tail = NULL;
    }
  }
}