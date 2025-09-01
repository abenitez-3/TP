#include <stdio.h>  
#include <unistd.h>  
int main ()  
{ 
   FILE* stream = popen ("sort", "w");  
   fprintf (stream, "This is a test.\n");  
   fprintf (stream, "Hola, Mundo.\n");  
   fprintf (stream, "Mi perro tiene pulgas.\n");  
   fprintf (stream, "Este programa es grandioso.\n");  
   fprintf (stream, "Un pescado, dos pescados.\n");  
   return pclose (stream);  
}  