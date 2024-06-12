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
    printf("C�digo: %d \nNome: %s \nPre�o: %.2f\n", prod.codigo, strtok(prod.nome, "\n"), prod.preco);
}

void menu(){
    printf("============================================\n");
    printf("==========>- Seja Bem-Vindo(a) -<============\n");
    printf("==========>- Adson - Mercado -<===============\n");
    printf("===============================================\n");

    printf("Selecione uma op��o abaixo:\n");
    printf("1 - Cadastrar um novo produto\n");
    printf("2 - Listar todos os produtos\n");
    printf("3 - Comprar produto\n");
    printf("4 - Visualizar carrinho\n");
    printf("5 - Fechar pedido\n");
    printf("6 - Sair\n");

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
            Sleep(2000);
            exit(0);
        default: 
            printf("Op��o inv�lida!\n");
            Sleep(1000);
            menu();
        break;
    }
}

void cadastrarProduto(){
    printf("Cadastrar de Produto\n");
    printf("=====================\n");

    printf("Informe o nome do produto: \n");
    fgets(produtos[contador_produtos].nome, 30, stdin);
    printf("O nome do produto %s foi cadastrado com sucesso!\n", strtok(produtos[contador_produtos].nome, "\n"));
    printf("Informe o pre�o do produto: \n");
    fflush(stdin);
    scanf("%f", &produtos[contador_produtos].preco);
    getchar();
    printf("O produto %s foi cadastrado com sucesso!\n", strtok(produtos[contador_produtos].nome, "\n"));
    produtos[contador_produtos].codigo = (contador_produtos + 1);

    contador_produtos++;
    Sleep(2000);
    menu();
}
void listarProdutos(){
    if (contador_produtos > 0){
        printf("Listagem de Produtos\n");
        printf("====================\n");
        for(int i = 0; i < contador_produtos; i++){
            infoProduto(produtos[i]);
            
        printf("====================\n");
        Sleep(1000);
        }
        Sleep(2000);
        menu();
    }
    else{
            printf("N�o temos ainda produtos cadastrados\n");
            Sleep(2000);
            menu();
    }
}
void comprarProdutos(){
    if (contador_produtos > 0){
        printf("Informe o c�digo do produto que deseja comprar: \n");
        printf("============> Produtos Dispon�veis <===============\n");
        for(int i = 0; i < contador_produtos; i++){
            infoProduto(produtos[i]);
        printf("====================================\n");
        Sleep(1000);
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
                        carrinho[retorno[1]].quantidade++;
                        printf("Adicionado a quantidade do produto %s j� exitente no carrinho\n", strtok(carrinho[retorno[1]].produtos.nome, "\n"));
                        Sleep(2000);
                        menu();
                    }else{
                        Produto p = pegarProdutoPorCodigo(codigo);
                        carrinho[contador_carrinho].produtos = p;
                        carrinho[contador_carrinho].quantidade = 1;
                        contador_carrinho++;
                        printf("O item %s foi adicionado ao carrinho\n", strtok(p.nome, "\n"));
                        Sleep(2000);
                        menu();
                    }
                }else {
                    Produto p = pegarProdutoPorCodigo(codigo);
                    carrinho[contador_carrinho].produtos = p;
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("O item %s foi adicionado ao carrinho\n", strtok(p.nome, "\n"));
                    Sleep(2000);
                    menu();
                }
            }
        }
        if ( tem_mercado < 1){
                printf("N�o foi encontrado o produto com c�digo %d\n", codigo);
                Sleep(2000);
                menu();
        }
    }else{
        printf("Ainda n�o existem produtos para vender!\n");
        Sleep(2000);
        menu();
    }
}
void visualizarCarrinho(){
    if (contador_carrinho > 0){
        printf("Produto do Carrinho\n");
        printf("====================\n");
        for(int i = 0; i < contador_carrinho; i++){
            infoProduto(carrinho[i].produtos);
            printf("Quantidade: %d\n", carrinho[i].quantidade);
        printf("====================\n");
        Sleep(1000);
        }
        Sleep(2000);
        menu();
    }else{
        printf("Nenhum item no carrinho!\n");
        Sleep(2000);
        menu();
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
            Sleep(1000);
        }
        printf("Sua compra total R$ %.2f\n", valor_total);
        // limpar o carrinho
        contador_carrinho = 0;
        printf("Obrigado por comprar conosco!\n");
        Sleep(3000);
        menu();
    }else{
        printf("Voc� n�o tem nenhum item no carrinho ainda\n");
        Sleep(3000);
        menu();
    }
}
