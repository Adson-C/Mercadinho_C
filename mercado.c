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
    printf("Cadastrar de Produto\n");
    printf("=====================\n");

    printf("Informe o nome do produto: \n");
    fgets(produtos[contador_produtos].nome, 30, stdin);

    printf("Informe o preço do produto: \n");
    scanf("%f", &produtos[contador_produtos].preco);
    getchar();
    printf("O produto %s foi cadastrado com sucesso!\n", strtok(produtos[contador_produtos].nome, "\n"));
    produtos[contador_produtos].codigo = contador_produtos + 1;
    contador_produtos++;
}
void listarProdutos(){
    if (contador_produtos == 0){
        printf("Listagem de Produtos\n");
        printf("====================\n");
        for(int i = 0; i < contador_produtos; i++){
            infoProduto(produtos[i]);
        printf("====================\n");
        Sleep(1);
        }
    }
    else{
            printf("Nenhum produto foi cadastrado!\n");
    }
}
void comprarProdutos(){
    if (contador_produtos == 0){
        printf("Informe o código do produto que deseja comprar: \n");
        printf("============> Produtos Disponíveis <===============\n");
        for(int i = 0; i < contador_produtos; i++){
            infoProduto(produtos[i]);
        printf("====================================\n");
        Sleep(1);
        }
        int codigo;
        scanf("%d", &codigo);
        getchar();

        int tem_mercado = 0;
        for(int i = 0; i < contador_produtos; i++){
            if(produtos[i].codigo == codigo){
                tem_mercado = 1;
                
                if (contador_carrinho > 0){
                    int * retorno = temNoCarrinho(codigo);

                    if (retorno[0] == 1){
                        carrinho[retorno[1]].quantidade++
                        printf("Adicionado a quantidade do produto %s já exitente no carrinho\n", strtok(carrinho[retorno[1]].produtos.nome, "\n"));
                        Sleep(2);
                        menu();
                    }else{
                        Produto p = pegarProdutoPorCodigo(codigo);
                        carrinho[contador_carrinho].produtos = p;
                        carrinho[contador_carrinho].quantidade = 1;
                        contador_carrinho++;
                        printf("O item %s foi adicionado ao carrinho\n", strtok(p.nome, "\n"));
                        Sleep(2);
                        menu();
                    }
                }else {
                    Produto p = pegarProdutoPorCodigo(codigo);
                    carrinho[contador_carrinho].produtos = p;
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("O item %s foi adicionado ao carrinho\n", strtok(p.nome, "\n"));
                    Sleep(2);
                    menu();
                }
            }
        }
        if ( tem_mercado < 1){
                printf("Não foi encontrado o produto com código %d\n", codigo);
                Sleep(2);
                menu();
        }
    }else{
        printf("Ainda não existem produtos para vender!\n");
        Sleep(3);
        menu();
    }
}
void visualizarCarrinho(){
    if (contador_carrinho > 0){
        printf("Produto do Carrinho\n");
        printf("====================\n");
        for(int i = 0; i < contador_carrinho; i++){
            printf("Quantidade: %d\n", carrinho[i].quantidade);
        printf("====================\n");
        Sleep(1);
        }

    }else{
        printf("Nenhum item no carrinho!\n");
    }
}
Produto pegarProdutoPorCodigo(int codigo){
    Produto p;
    for(int i = 0; i < contador_produtos; i++){
        if(produtos[i].codigo == codigo){
            p = produtos[i];
        }
    }
    return p;
}
int * temNoCarrinho(int codigo){
    int static retorno[] = {0, 0};
    for(int i = 0; i < contador_carrinho; i++){
        if(carrinho[i].produtos.codigo == codigo){
            retorno[0] = 1; // tem o produto com este codigo no carrinho
            retorno[1] = i; // indice do produto no carrinho
        }
    }
    return retorno;
}
void fecharPedido() {
    if (contador_carrinho > 0){
        float valor_total = 0.0;
        printf("Produtos do Carrinho\n");
        printf("====================\n");
        for(int i = 0; i < contador_carrinho; i++){
            Produto p = carrinho[i].produtos;
            int quantidade = carrinho[i].quantidade;
            valor_total += p.preco * quantidade;
            infoProduto(p);
            printf("Quantidade: %d\n", quantidade);
            printf("====================\n");
            Sleep(1);
        }
        printf("Sua compra total R$ %.2f\n", valor_total);
        // limpar o carrinho
        contador_carrinho = 0;
        printf("Obrigado por comprar conosco!\n");
        Sleep(5);
        menu();
    }else{
        printf("Você não tem nenhum item no carrinho ainda\n");
        Sleep(3);
        menu();
    }
}
