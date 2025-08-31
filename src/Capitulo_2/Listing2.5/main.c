#include <stdio.h>
#include <string.h>
#include "temp_file.c"

int main() {
    char data[] = "Hola mundo!";
    size_t length = strlen(data) + 1;

    // Escribir en archivo temporal
    temp_file_handle tf = write_temp_file(data, length);

    // Leer desde archivo temporal
    size_t read_length;
    char* buffer = read_temp_file(tf, &read_length);

    printf("Leído del archivo temporal: %s\n", buffer);

    free(buffer);
    return 0;
}