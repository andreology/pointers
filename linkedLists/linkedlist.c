//Demo on implementinga linked lists with external struct
//then in driver five nodes are created in linked lists
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16
//define struct externally
// to ensure that its available to all functions
struct node{
  int id;
  char name[SIZE];
  float price;
  struct node *next;
};
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
//method to allocate a new structure
struct node *allocate(void){
  struct node *p;

  p = (struct node *)malloc(sizeof(struct node));
  if(p == NULL) {
    fprintf(stderr, "ERROR: memory not allocated");
    exit(1);
  }

  return p;
}
//fill in the struct node
void fill(struct node *s, int i) {
  char temp[SIZE];

  s-> id = i;
  printf("Record %d Fruit: ", i);
  strcpy(s->name, input());
  printf("Price: ");
  strcpy(temp, input());
  s-> price = strtof(temp, NULL);

}
//method to output the list
void output(struct node *s) {
  while(s != NULL) {
    printf("%d: %s for %.2f/pound\n",
          s-> id,
          s-> name,
          s-> price
        );
    s = s-> next;
  }
}


int main() {
  struct node *first, *current;
  //assign five nodes
  for(int x = 0; x < 5; x++){
    if(x == 0) {
      first = allocate();
      current = first;
    }else {
      //set the next structure
      current-> next = allocate();
      current = current-> next;
    }
    fill(current, x+1);
  }

  current-> next = NULL;

  output(first);

      return 0;
}
