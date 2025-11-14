#include "Utils_client.h"
#include <stdio.h>




int main(int argc, char *argv[]) {
    
    if(argc != 2) {
        fprintf(stderr, "Uso: %s <username>\n", argv[0]);
        pthread_exit(ARGUMENTOS_INVALIDOS);
    }
    
    GestordeThreads gestor;
    memset(&gestor, 0, sizeof(GestordeThreads));
    inicializa_tudo(&gestor);


    return 0;
}