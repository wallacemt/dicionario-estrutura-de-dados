#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Nodo {
    char palavra[50];
    char traducao[50];
    char tipo[30];  
    char fraseExemplo[100];
    struct Nodo *proximo;
} Nodo;

typedef struct NodoArvore {
    char palavra[50];
    char traducao[50];
    char tipo[30];
    char fraseExemplo[100];
    struct NodoArvore *esquerda;
    struct NodoArvore *direita;
} NodoArvore;

void cadastrarPalavra(Nodo **raiz, NodoArvore **arvore);
void listarPalavras(Nodo *raiz);
void excluirPalavra(Nodo **raiz, char *palavra, NodoArvore **arvore);

NodoArvore* encontrarMinimo(NodoArvore* raiz);
NodoArvore* removerArvore(NodoArvore* raiz, const char* palavra);
NodoArvore* buscarPalavra(NodoArvore *raiz, char *palavra);

void alterarPalavra(NodoArvore *arvore, Nodo *lista, char *palavra);

void alterarNaLista(Nodo *lista, char *palavra, char *novoValor, const char *campo);

NodoArvore* inserirArvore(NodoArvore *raiz, Nodo *nova);


void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}



int lerOpcao() {
    int opcao;
    while (1) {
        printf("\033[1;32mEscolha uma opcao: \033[0m");
        if (scanf("%d", &opcao) != 1) {
            printf("\033[1;31mEntrada invalida! Por favor, insira um numero.\033[0m\n");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    }
    return opcao;
}


void lerString(char *str, int tamanho) {
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0';  
}


int comparaStrings(const char *str1, const char *str2) {
    return strcasecmp(str1, str2); 
}


void menu(Nodo **lista, NodoArvore **arvore) {
    int opcao;
    char palavra[50];
    
    do {
        limparTela(); 
        printf("\n");
        printf("\033[1;34m*******************************************************\n");
        printf("* \033[1;32m                 MENU DICIONARIO\033[1;34m               *\n");
        printf("*******************************************************\n");
        printf("* \033[1;33m1. Cadastrar Palavra\033[0m                                *\n");
        printf("* \033[1;33m2. Listar Palavras\033[0m                                  *\n");
        printf("* \033[1;33m3. Buscar Palavra\033[0m                                   *\n");
        printf("* \033[1;33m4. Alterar Palavra\033[0m                                  *\n");
        printf("* \033[1;33m5. Excluir Palavra\033[0m                                  *\n");
        printf("* \033[1;31m0. Sair\033[0m                                             *\n");
        printf("\033[1;34m*******************************************************\033[0m\n");
        
        opcao = lerOpcao();
        
        switch (opcao) {
            case 1:
                cadastrarPalavra(lista, arvore);
                limparTela(); 
                break;
            case 2:
                listarPalavras(*lista);
                printf("\nPressione Enter para voltar ao menu...");
                getchar();
                getchar(); 
                limparTela(); 
                break;
            case 3:
                printf("Digite a palavra a ser buscada: ");
                getchar();  
                lerString(palavra, 50);
                NodoArvore *encontrada = buscarPalavra(*arvore, palavra);
                if (encontrada != NULL) {
                    printf("\nPalavra encontrada!\n");
                    printf("Palavra: %s\n", encontrada->palavra);
                    printf("Traducao: %s\n", encontrada->traducao);
                    printf("Tipo gramatical: %s\n", encontrada->tipo);
                    printf("Frase de exemplo: %s\n", encontrada->fraseExemplo);
                } else {
                    printf("Palavra nao encontrada.\n");
                }
                printf("\nPressione Enter para voltar ao menu...");
                getchar();
                limparTela();  
                break;
            case 4:
                printf("Digite a palavra a ser alterada: ");
                getchar(); 
                lerString(palavra, 50);
                alterarPalavra(*arvore,*lista,  palavra);
                printf("\nPressione Enter para voltar ao menu...");
                getchar();
                limparTela();  
                break;
            case 5:
                printf("Digite a palavra a ser excluida: ");
                getchar();  
                lerString(palavra, 50);
                excluirPalavra(lista, palavra, arvore);
                printf("\nPressione Enter para voltar ao menu...");
                getchar();
                limparTela(); 
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}


void cadastrarPalavra(Nodo **lista, NodoArvore **arvore) {
    Nodo *nova = (Nodo*)malloc(sizeof(Nodo));
    
    if (nova == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }

    getchar();

    printf("\033[1;36mDigite a palavra: \033[0m");
    lerString(nova->palavra, 50);
    printf("\033[1;36mDigite a traducao em ingles: \033[0m");
    lerString(nova->traducao, 50);
    printf("\033[1;36mDigite o tipo gramatical (ex: substantivo, adjetivo): \033[0m");
    lerString(nova->tipo, 30);
    printf("\033[1;36mDigite uma frase de exemplo: \033[0m");
    lerString(nova->fraseExemplo, 100);
    
    nova->proximo = *lista;
    *lista = nova;

  
    *arvore = inserirArvore(*arvore, nova);
    
    printf("Palavra cadastrada com sucesso!\n");
}

void listarPalavras(Nodo *raiz) {
    Nodo *atual = raiz;
    if (atual == NULL) {
        printf("Nenhuma palavra cadastrada.\n");
        return;
    }
    
    while (atual != NULL) {
        printf("\033[0;32m\nPalavra: %s\n", atual->palavra);
        printf("Traducao: %s\n", atual->traducao);
        printf("Tipo gramatical: %s\n", atual->tipo);
        printf("Frase de exemplo: %s\n", atual->fraseExemplo);
        printf("------------------------\033[0m\n");
        atual = atual->proximo;
    }
}

NodoArvore* buscarPalavra(NodoArvore *raiz, char *palavra) {
    if (raiz == NULL || comparaStrings(raiz->palavra, palavra) == 0)
        return raiz;
    
    if (comparaStrings(palavra, raiz->palavra) < 0)
        return buscarPalavra(raiz->esquerda, palavra);
    
    return buscarPalavra(raiz->direita, palavra);
}

void alterarPalavra(NodoArvore *arvore, Nodo *lista, char *palavra) {
    NodoArvore *encontrado = buscarPalavra(arvore, palavra);
    if (encontrado != NULL) {
        printf("\n---------------------------------------------\n");
        printf("Palavra encontrada: %s\n", encontrado->palavra);
        printf("Traducao atual: %s\n", encontrado->traducao);
        printf("Tipo Gramatical atual: %s\n", encontrado->tipo);
        printf("Frase de exemplo atual: %s\n", encontrado->fraseExemplo);
        
        char novaPalavra[50], novaTraducao[50], novoTipo[30], novaFraseExemplo[100];
        int opcao;
        
        do {
            limparTela();
            printf("\nO que voce deseja alterar?\n");
            printf("1. Alterar palavra\n");
            printf("2. Alterar traducao\n");
            printf("3. Alterar tipo gramatical\n");
            printf("4. Alterar frase de exemplo\n");
            printf("0. Voltar\n");
            opcao = lerOpcao();
            getchar();
            
            switch (opcao) {
                case 1:
                    printf("Digite a nova palavra: ");
                    lerString(novaPalavra, 50);
                    strcpy(encontrado->palavra, novaPalavra);
                    alterarNaLista(lista, palavra, novaPalavra, "palavra");
                    printf("Palavra alterada com sucesso!\n");
                    break;
                case 2:
                    printf("Digite a nova traducao: ");
                    lerString(novaTraducao, 50);
                    strcpy(encontrado->traducao, novaTraducao);
                    alterarNaLista(lista, palavra, novaTraducao, "traducao");
                    printf("Traducao alterada com sucesso!\n");
                    break;
                case 3:
                    printf("Digite o novo tipo gramatical: ");
                    lerString(novoTipo, 30);
                    strcpy(encontrado->tipo, novoTipo);
                    alterarNaLista(lista, palavra, novoTipo, "tipo");
                    printf("Tipo gramatical alterado com sucesso!\n");
                    break;
                case 4:
                    printf("Digite a nova frase de exemplo: ");
                    lerString(novaFraseExemplo, 100);
                    strcpy(encontrado->fraseExemplo, novaFraseExemplo);
                    alterarNaLista(lista, palavra, novaFraseExemplo, "fraseExemplo");
                    printf("Frase de exemplo alterada com sucesso!\n");
                    break;
                case 0:
                    printf("Voltando ao menu.\n");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
            }
        } while (opcao != 0);
    } else {
        printf("Palavra nao encontrada.\n");
    }
}

void alterarNaLista(Nodo *lista, char *palavra, char *novoValor, const char *campo) {
    Nodo *atual = lista;
    while (atual != NULL) {
        if (comparaStrings(atual->palavra, palavra) == 0) {
            if (strcmp(campo, "palavra") == 0) {
                strcpy(atual->palavra, novoValor);
            } else if (strcmp(campo, "traducao") == 0) {
                strcpy(atual->traducao, novoValor);
            } else if (strcmp(campo, "tipo") == 0) {
                strcpy(atual->tipo, novoValor);
            } else if (strcmp(campo, "fraseExemplo") == 0) {
                strcpy(atual->fraseExemplo, novoValor);
            }
            return;
        }
        atual = atual->proximo;
    }
}


void excluirPalavra(Nodo **raiz, char *palavra, NodoArvore **arvore) {
    Nodo *atual = *raiz;
    Nodo *anterior = NULL;
    
    while (atual != NULL && comparaStrings(atual->palavra, palavra) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL) {
        printf("Palavra nao encontrada.\n");
        return;
    }
    
    if (anterior == NULL) { 
        *raiz = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);  
    *arvore = removerArvore(*arvore, palavra);

    printf("Palavra excluida com sucesso.\n");
}

NodoArvore* removerArvore(NodoArvore* raiz, const char* palavra) {
    if(raiz ==NULL){
        return NULL;
    }

    if(comparaStrings(palavra, raiz->palavra) == 0){
        //Nó Folha
        if(raiz->esquerda == NULL && raiz->direita == NULL){
            free(raiz);
            return NULL;
        }
        //Nó com 1 filho
        if(raiz->esquerda == NULL){
            NodoArvore* temp = raiz->direita;
            free(raiz);
            return temp;            
        }else if (raiz->direita == NULL){
            NodoArvore* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        //No com 2 Filhos
        NodoArvore* temp = encontrarMinimo(raiz->direita);
        strcpy(raiz->palavra, temp->palavra);
        strcpy(raiz->traducao, temp->traducao);
        strcpy(raiz->tipo, temp->tipo);
        strcpy(raiz->fraseExemplo, temp->fraseExemplo);

        //Remove o nó copiado
        raiz->direita = removerArvore(raiz->direita, temp->palavra);
    }else if(comparaStrings(palavra, raiz->palavra) < 0){
        raiz->esquerda = removerArvore(raiz->esquerda, palavra);
    }else{
        raiz->direita = removerArvore(raiz->direita, palavra);
    }
    return raiz;
}

NodoArvore* encontrarMinimo(NodoArvore* raiz){
    while(raiz && raiz->esquerda != NULL){
        raiz = raiz->esquerda;
    }
    return raiz;
}
NodoArvore* inserirArvore(NodoArvore *raiz, Nodo *nova) {
    if (raiz == NULL) {
        NodoArvore *novoNodo = (NodoArvore*)malloc(sizeof(NodoArvore));
        if (novoNodo == NULL) {
            printf("Erro de alocacao de memoria!\n");
            return NULL;
        }
        strcpy(novoNodo->palavra, nova->palavra);
        strcpy(novoNodo->traducao, nova->traducao);
        strcpy(novoNodo->tipo, nova->tipo);
        strcpy(novoNodo->fraseExemplo, nova->fraseExemplo);
        novoNodo->esquerda = novoNodo->direita = NULL;
        return novoNodo;
    }
    
    if (comparaStrings(nova->palavra, raiz->palavra) < 0) {
        raiz->esquerda = inserirArvore(raiz->esquerda, nova);
    } else {
        raiz->direita = inserirArvore(raiz->direita, nova);
    }
    return raiz;
}


int main() {
    Nodo *lista = NULL;     
    NodoArvore *arvore = NULL;

    menu(&lista, &arvore);

    return 0;
}
