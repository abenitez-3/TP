#include <stdio.h>
#include <stdlib.h>  
#include "../Listing1.3/reciprocal.hpp"  

int main (int argc, char **argv){
  if (argc < 2) {
    fprintf(stderr, "Uso: %s <numero>\n", argv[0]);
    return 1;
  }
  
  int i;  
  i = atoi (argv[1]);  
  printf ("The reciprocal of %d is %g\n", i, reciprocal (i));  
  return 0;  
}