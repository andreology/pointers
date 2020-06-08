//demo on sorting with pointers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  //init pointer to pointers
  char *weekdays[7] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"
	};
  char *temp;
  int x, y;

  //print original days list
  puts("Not sorted: ");
  for(x = 0; x < 7; x++)
    printf(" %s\n", weekdays[x]);

    //using bubble sort
    for( x = 0; x < 6; x++) {
      for(y = x + 1; y < 7; y++) {
        //sort alphabetically
        if(strcmp(weekdays[x], weekdays[y]) > 0) {
          temp = weekdays[x];
          weekdays[x] = weekdays[y];
          weekdays[y] = temp;
        }
      }
    }

    //output sorted list
    puts("Sorted: " );
    for(x = 0; x < 7; x++)
      printf(" %s\n", weekdays[x]);

      return 0;

}
