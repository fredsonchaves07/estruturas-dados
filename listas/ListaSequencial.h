#define MAX 100;

typedef struct {
    int matricula;
    char nome[100];
    float n1, n2, n3;
} aluno;

typedef struct lista Lista;

Lista * cria_lista();

void libera_lista(Lista *li);

int lista_invalida(Lista *li);

int tamanho_lista(Lista *li);

int lista_cheia(Lista *li);

int lista_vazia(Lista *li);

int insere_elemento_final(Lista *li, aluno a1);

int insere_elemento_inicio(Lista *li, aluno a1);

int insere_elemento_ordenado(Lista *li, aluno a1);

int remove_elemento_final(Lista *li);

int remove_elemento_inicio(Lista *li);

int remov_elemento_meio(Lista *li);

