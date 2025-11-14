
#ifndef CLIENTE_H

#define FIFO_CLIENTE_LEN 64 //o fifo individual e cliado pelo cliente
#define FIFO_CONTROLLER "controlador_fifo" //controlador cria o fifo 
#define USERNAME_LEN 32 //tamanho maximo do username

typedef enum{
    MSG, //0
    MSG_LOGIN_RESPOSTA,//1
    SAIR, //2
    ENTRAR, //3s
}TipodeMSG;

//ESTRUTURA QUE DEFINE OS TIPOS DE MENSAGEM
typedef enum{
    ORIGEM_CONTROLADOR, //0
    ORIGEM_VEICULO //1
}OrigemMsg;
   
typedef struct{
    TipodeMSG tipo_msg;
    OrigemMsg origem_msg;
    char username[USERNAME_LEN];
    char mensagem[256];
    char fifo_cliente[FIFO_CLIENTE_LEN];
}MensagemSevidor;


#define CLIENTE_H
#endif // CLIENTE_H