//Demo on implementinga linked lists
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

//method to take input and remove the newline
char *input(void){
  static char buffer[SIZE];
  char *r;
  int x;

  //init buffer
  buffer[0] = '\0';

  r = fgets(buffer, SIZE, stdin);
  if(r == NULL) {
    fprintf(stderr, "ERROR: input invalid\n");
    exit(1);
  }

  for(x = 0; x < SIZE; x++) {
    //look for new line to remove
    if(buffer[x] == '\n') {
      buffer[x] = '\0';
      break;
    }
  }
  return buffer;
}

int main() {
  struct node{
    int id;
    char name[SIZE];
    float price;
    struct node *next;
  };
  struct node *first, *current;
  char temp[SIZE];

  //allocate memory for structure
  first = (struct node *)malloc(sizeof(struct node));
  if(first == NULL) {
    fprintf(stderr, "ERROR: memory not allocated\n");
    exit(1);
  }

  //assign first to current
  current = first;

  //initialize node values
  current-> id = 1;
  printf("Record %d Fruit: ", current-> id);
  strcpy(current-> name, input());
  printf("Price: ");
  strcpy(temp, input());
  current-> price = strtof(temp, NULL);
  current-> next = NULL;

  printf("%d: %s for %.2f/pound\n",
        current->id,
        current->name,
        current-> price
      );
      return 0;
}
