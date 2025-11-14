

#include "Utils_client.h"
#include <string.h>

void inicializa_tudo(GestordeThreads *gestordeThreads,char username[USERNAME_LEN],char nf_c[FIFO_CONTROLLER_LEN] , char nf_cl[FIFO_CLIENTE_LEN]) {
    strcpy(gestordeThreads->username,username);
    strcpy(gestordeThreads->fifo_id_controller,nf_c);
    strcpy(gestordeThreads->fifo_id_cliente,nf_cl);  
    gestordeThreads->fd_cliente = -1;
    gestordeThreads->fd_controlller = -1;
    gestordeThreads->isRunning = true;
    //criar o fifo do cliente 
        //abrir o fifo do cliente para leitura e escrita
    //abrir o fifo do controloador
        //abrir para escrita
    //inicializa o mutex
    pthread_mutex_init(&gestordeThreads->mutex, NULL);
    //inicializa as threads
}

void limpar_tudo(GestordeThreads *gestordeThreads){
    
    //fazer o processo inverso do incializar
    // antes de chamar esta funcao no main, tenho de fazer um phrtead join para 
    // ficar a espera do valor de retorno das threads.
}

int login(GestordeThreads *gestordeThreads){

    //este metodo tem que ser chamado dentro da tsender,
    //porem a resposta e verificada no tlistener

}
int enviar_para_veiculo(GestordeThreads *gestordeThreads,Mensagem *mensagem){
    //sera chamada no tListener para enviar uma resposta?
}
//faze pergunta ao professor: "Temos de criar um fifo especificamente para o veiculo ou podemos"
//utilizar o mesmo fifo, tanto para o controlador tanto para o veiculo
void *tListener(void *args){
    //recebe mensagem do controlandor ou do veiculo(ambos pelo fifo do cliente)
    //se for uma mensafem do controlador vamos ler no fifo do cliente
    // e escrever no fifo do controlador

}