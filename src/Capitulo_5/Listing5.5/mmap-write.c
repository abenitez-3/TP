#include <stdlib.h>  
#include <stdio.h>  
#include <fcntl.h>  
#include <sys/mman.h>  
#include <sys/stat.h>  
#include <time.h>  
#include <unistd.h>  
#include <string.h>
#define FILE_LENGTH 0x100  
/* Return a uniformly random number in the range [low,high]. */  
int random_range (unsigned const low, unsigned const high)  
{ 
  unsigned const range = high - low + 1;  
  return low + (int) (((double) range) * rand () / (RAND_MAX + 1.0));  
}  
int main (int argc, char* const argv[])  
{ 
  int fd;  
  void* file_memory;  
  srand (time (NULL));  

  fd = open (argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);  

  // Ajustar correctamente el tamaño del archivo
  lseek(fd, FILE_LENGTH - 1, SEEK_SET);
  write(fd, "", 1);

  file_memory = mmap(0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
  close(fd);

  memset(file_memory, 0, FILE_LENGTH);

  sprintf((char*) file_memory, "%d\n", random_range(-100, 100));

  munmap(file_memory, FILE_LENGTH);
  return 0;  
}
