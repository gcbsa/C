#define SUCESSO 0;
#define FALHA -1;
#define PONTEIRO_INVALIDO -2;
#define SEM_MEMORIA -3;

typedef struct lista Lista;

Lista * criar_lista();
int tamanho_lista(Lista * lista);
int existe_elemento(Lista * lista, int  elemento);
int encontrar_elemento(Lista * lista, int posicao, int * elemento);
int encontrar_posicao(Lista * lista, int * posicao, int elemento);
int inserir_lista(Lista * lista, int posicao, int elemento);
int atualizar_lista(Lista * lista, int posicao, int elemento);
int remover_lista(Lista * lista, int posicao);
int reverter_lista(Lista * lista);
int imprimir_lista(Lista * lista);
int esvaziar_lista(Lista * lista);
int destruir_lista(Lista * lista);
