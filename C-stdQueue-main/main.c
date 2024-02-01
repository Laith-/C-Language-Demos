#define _POSIX_C_SOURCE 200809L 
#define ASSIGNMENT_VERSION 1.1
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char *value;
  struct node *next;
  struct node *prev;
};
typedef struct node Node;

struct squeue {
   struct node* first;
   struct node* last;
};
typedef struct squeue * Squeue;
typedef const struct squeue * ConstSqueue;

enum direction {
    FORWARD,
    BACKWARD
};
typedef enum direction Direction;


Squeue initSqueue() {
  Squeue queue;
  queue = malloc(sizeof(queue));

  return queue;
}


void freeNode (struct node * Node)
{
  struct node * nextNode = Node->next;

  if (nextNode != NULL)
  {
    freeNode(nextNode);
  }
  free(nextNode);
}

void freeSqueue(Squeue squeue) {
  struct node * Node;
  Node = squeue->first;
  freeNode(Node);
  
  free(squeue);
}

bool isEmptySqueue( const struct squeue * squeue) {
    return squeue->first == NULL;
}


void addFrontSqueue(Squeue squeue, char* value) {
  char * val = value;
  struct node * oldNode = squeue->first;

  struct node * newNode;
  newNode->value = val;
  newNode->next = oldNode;

  oldNode->prev = newNode;

  squeue->first = newNode;
}


void addBackSqueue( Squeue squeue, char* value) {
  char * val = value;
  struct node * oldNode = squeue->last;

  struct node * newNode;
  newNode->value = val;
  newNode->prev = oldNode;

  oldNode->prev = newNode;

  squeue->last = newNode;
}


void print(struct node * Node)
{
  struct node * nextNode = Node->next;

  if (nextNode != NULL)
  {
    print(nextNode);
  }
  printf("%c",nextNode->value);
}

void printSqueue( const struct squeue * squeue, Direction dir) {
  if(isEmptySqueue(squeue)) {
    printf("Squeue Empty!\n");
  } else if (dir==FORWARD) {
    printf("Printing Forward\n");
    print(squeue->first);
  } else if (dir==BACKWARD) {
    printf("Printing Backward\n");
    print(squeue->last);
  } else {
    printf("%s","Invalid direction!");
  }
}

void reverseSqueue(Squeue squeue) {
  struct node * nextNode = Node->next;

  if (nextNode != NULL)
  {
    reverseSqueue(nextNode);
  }
  newNode->value = val;
  newNode->prev = oldNode;

  oldNode->prev = newNode;
}

#define BUFFSIZE 1024

void checkInput(int err) {
  if (!err || err == EOF) {
    printf("\nInvalid input!\n");
    exit(1);
  }
}

void testAddFront(Squeue sq1) {
  char value[BUFFSIZE] = { 0 };
  printf("Enter value\n");
  checkInput(scanf(" %1023[^\n]%*c", value));
  addFrontSqueue(sq1, value);
}


void testAddBack(Squeue sq1) {
  char value[BUFFSIZE] = { 0 };
  printf("Enter value\n");
  checkInput(scanf(" %1023[^\n]%*c", value));
  addBackSqueue(sq1, value);
}


void testPrint( const struct squeue * sq1, Direction dir ) {
  if(dir ==FORWARD) {
    printSqueue(sq1, FORWARD);
  } else if (dir == BACKWARD) {
    printSqueue(sq1, BACKWARD);
  }   
}

void testReverse( Squeue sq1 ) {
  if (isEmptySqueue(sq1)) {
    puts("Squeue Empty!");    
  } else {
    reverseSqueue(sq1);
    puts("Squeue Reversed!");
  }
}

enum menuOptions {
  QUIT,
  ADDFRONT,
  ADDBACK,
  PRINTFORWARD,
  PRINTBACKWARD,
  REVERSEQ,
  NMENUOPTIONS
};

void evalMenuOption(enum menuOptions option, Squeue sq1) {
  switch (option) {
  case ADDFRONT:
    testAddFront(sq1);
    break;
  case ADDBACK:
    testAddBack(sq1);
    break;
  case PRINTFORWARD:
    testPrint(sq1,FORWARD);
    break;
  case PRINTBACKWARD:
    testPrint(sq1,BACKWARD);
    break;
  case REVERSEQ:
    testReverse(sq1);
    break;
  default:
    break;
  } 
}

#define HEAVY 10000
// Heavily excercise your data structure to tease out problems with
// memory management.
void heavilyExerciseSqueue() {
  Squeue sq1 = initSqueue();
  Squeue sq2 = initSqueue();
  char buffer[BUFFSIZE];
  for (int i = 0; i < HEAVY; i++) {
    sprintf(buffer, "STR: %18d\t\t%p\n", i, (void*)&buffer[i%BUFFSIZE]);
    addFrontSqueue( sq1, buffer );
    assert(sq1->first->value != buffer);    
    assert(strcmp(sq1->first->value,buffer) == 0);
    char * sq1last = sq1->last->value;
    addBackSqueue( sq2, buffer );
    reverseSqueue( sq1 );
    assert(sq1->first->value == sq1last); // last is now first!
    reverseSqueue( sq2 );
  }
  freeSqueue(sq2);
  freeSqueue(sq1);
}

int main() {
  Squeue sq1 = initSqueue();
  int option=-1;
  printf("Enter the number to call a function\n1-addFront\n2-addBack\n");
  printf("3-printSqueue forward\n");
  printf("4-printSqueue backward\n5-reverseSqueue\n0-quit\n");
  do {
    printf("Enter option\n");
    checkInput(scanf("%d",&option));
    if(option >= 0 && option < NMENUOPTIONS) {
      evalMenuOption( option, sq1 );
    } else {
      printf("Invalid option!");
      exit(1);
    }
  } while ( option > 0 );
  freeSqueue(sq1);
  // Run some tests
  heavilyExerciseSqueue();
  return 0;
}
