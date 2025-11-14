
#include <pthread.h>
#include <stdbool.h>


#ifndef UTILS_H
//VERIFICA ENUNCIADO SE MACRO ESTAO CORRETOS
#define MENSAGEM_LEN 256 //tamanho maximo da mensagem
#define FIFO_CLIENTE_LEN 64 //o fifo individual e cliado pelo cliente
#define FIFO_CONTROLLER "controlador_fifo" //controlador cria o fifo 
#define FIFO_CONTROLLER_LEN 64 //tamanho maximo do fifo do controlador
#define USERNAME_LEN 32 //tamanho maximo do username
#define LOCAL_LEN 128 //tamanho maximo do local
#define DESTINO_LEN 128 //tamanho maximo do destino
#define ARGUMENTOS_INVALIDOS -1


typedef enum{
    MSG, //0
    MSG_LOGIN_RESPOSTA,//1
    SAIR, //2
    ENTRAR, //3
    AGENDAR,//4
    CONSULTAR,//5
    CONSULTAR //6
}TipodeMSG;

//ESTRUTURA QUE DEFINE OS TIPOS DE MENSAGEM
typedef enum{
    ORIGEM_CONTROLADOR, //0
    ORIGEM_VEICULO //1
}OrigemMsg;
   
//pesquisar sobre o union dentro da steruct, para que serve 

typedef struct{
    TipodeMSG tipo_msg;
    OrigemMsg origem_msg;
    char username[USERNAME_LEN];
    char mensagem[MENSAGEM_LEN];
    int hora;
    int id;
    float distancia;
    char local[LOCAL_LEN];
    char destino[DESTINO_LEN];
    char fifo_id_cliente[FIFO_CLIENTE_LEN];
}Mensagem;

typedef struct{ 
    char username[USERNAME_LEN];
    
    char fifo_id_cliente[FIFO_CLIENTE_LEN];
    int fd_cliente;
    
    char fifo_id_controller[FIFO_CONTROLLER_LEN];
    int fd_controlller;
    
    //criar as threads
    //id thread array[2]?

    pthread_mutex_t mutex; //PRECISAR ACEDER O GESTOR DE THREADS DE FORMA SEGURA
    bool isRunning;

}GestordeThreads;


void *tListener(void *args);
void *tSender(void *args);
void inicializa_tudo(GestordeThreads *gestordeThreads, char username[USERNAME_LEN],char nf_c[FIFO_CONTROLLER_LEN] , char nf_cl[FIFO_CLIENTE_LEN]);
void limpar_tudo(GestordeThreads *gestordeThreads);

int login(GestordeThreads *gestordeThreads);
int enviar_para_controlador(GestordeThreads *gestordeThreads,Mensagem *mensagem);
int enviar_para_veiculo(GestordeThreads *gestordeThreads, Mensagem *mensagem);
int sair(GestordeThreads *gestordeThreads);

#define UTILS_H
#endif // CLIENTE_H