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
    // falta implementar
}

void cadastrarProduto(){
    // falta implementar
}
void listarProdutos(){
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
