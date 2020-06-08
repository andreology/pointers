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
//auto fill in the struct node
void fill(struct node *s, int i) {
  char *fruit[] = { "apples", "bananas", "grapes", "strawberries", "watermelon" };
	float prices[] = { 1.20, 2.58, 2.09, 2.40, 0.51 };

  s-> id = i;
  strcpy(s-> name, fruit[i]);
  s-> price = prices[i];
}
//print the list
void output(struct node *s) {
  while(s != NULL) {
    printf("%d: %s for $%.2f/pound\n",
          s-> id + 1,
          s-> name,
          s-> price
        );
        s = s-> next;
  }
}
int main() {
  struct node *first,*temp, *current;
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
    fill(current, x);
  }

  current-> next = NULL;

  output(first);
  //removing the first structure from the lists
  puts("Removing 1st record:");
  temp = first;
  first = first-> next;
  //free storage assigned to temp
  free(temp);

  output(first);

      return 0;
}
