#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct {
    Produto produtos;
    int quantidade;
}Carrinho; 

void menu();
void infoProduto(Produto prod);
void cadastrarProduto();
void listarProdutos();
void comprarProdutos();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int * temNoCarrinho(int codigo);
void fecharPedido();

static int contador_produtos = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    menu();
    return 0;
}

void infoProduto(Produto prod){
    printf("Código: %d \nNome: %s \nPreço: %.2f\n", prod.codigo, strtok(prod.nome, "\n"), prod.preco);
}

void menu(){
    printf("============================================\n");
    printf("==========>- Seja Bem-Vindo(a) -<============\n");
    printf("==========>- Adson - Mercado -<===============\n");
    printf("===============================================\n");

    printf("Selecione uma opção abaixo:\n");
    printf("1 - Cadastrar um novo produto\n");
    printf("2 - Listar todos os produtos\n");
    printf("3 - Comprar produto\n");
    printf("4 - Visualizar carrinho\n");
    printf("5 - Fechar pedido\n");
    printf("6 - Sair\n");
    printf("===============================================\n");

    int opcao;
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
        case 1: cadastrarProduto();
        break;
        case 2: listarProdutos();
        break;
        case 3: comprarProdutos();
        break;
        case 4: visualizarCarrinho();
        break;
        case 5: fecharPedido();
        break;
        case 6:
            printf("Volte sempre...\n");
            exit(0);
        default: 
            printf("Opção inválida!\n");
            Sleep(2);
            menu();
        break;
    }
}

void cadastrarProduto(){
    // falta implementar
}
void listarProdutos(){
    // falta implementar
}
void comprarProdutos(){
    // falta implementar
}
void visualizarCarrinho(){
    // falta implementar
}
Produto pegarProdutoPorCodigo(int codigo){
    // falta implementar
}
int * temNoCarrinho(int codigo){
    // falta implementar
}
void fecharPedido() {
    // falta implementar
}
