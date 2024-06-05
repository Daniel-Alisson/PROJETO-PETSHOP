#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TAM 9
#define TAM2 50

struct produto {
	char nome[50];
	int quantidade;
	float preco;
} produto[TAM2];

struct item_carrinho {
    int id_produto;
    int quantidade;
};

struct animal {
	char nome[50];
	char raca[50];
	int idade;
	int id;
} animal[TAM2];

struct item_carrinho carrinho[TAM2]; // Array para armazenar o carrinho
int num_itens_carrinho = 0; // Quantidade de itens no carrinho

int in = 0; // VARIAVEL PARA CADASTRO
int fila[TAM], inicio = 0, final = 0;
int final_produtos = 0;
int final_animais = 0;
int cheia() {
	if(final == TAM) {
		return 1;
	} else {
		return 0;
	}	
}

int vazia() {
	if(inicio == final) {
		return 1;
	} else {
		return 0;
	}	
}

void inserir_fila(int valor) {
		fila[final] = valor;
		final++;
}

void remover() {
	inicio++;
}

void ver_inicio() {
	printf("O inicio da fila é [%d]\n", fila[inicio]);
}

void ver_final() {
	printf("O final da fila é [%d]\n", fila[final - 1]);
}

void listar_fila(){
	int i;
	
	printf("\tLISTAGEM DA FILA - BANHO/TOSA\n\n");
	for(i = inicio; i < final; i++) {
		printf("\t+---+\t");
	}
	printf("\n");
	for(i = inicio; i < final; i++) {
		printf("\t| %d |\t", fila[i]);
		if(i < final - 1) {
			printf("--->");
		}
	}
	printf("\n");
	for(i = inicio; i < final; i++) {
		printf("\t+---+\t");
	}
	printf("\n\n");
	system("pause");
	system("cls");
}

void buscar(int valor) {
	int i, num = 1;
	
	for(i = inicio; i < final; i++) {
		if(fila[i] == valor) {
			printf("Valor encontrado na posição [%d]\n", i);
			num = 0;
		}
	}
	
	if(num == 1) {
		printf("Valor não foi encontrado.\n");
	}
}

void inserir_produto() {
	int i, j, igual = 0, quantidade, op1;
	// ADCIONEI UMA LÓGICA PARA CASO O NOME DO PRODUTO SEJA IGUAL ENTÃO APENAS VAI ADICIIONAR A QUANTIDADE
    for(i = final_produtos; i < TAM2; i++) { 
        system("cls");
        
        printf("\t\tINSERINDO PRODUTO\n\n");
        printf("NOME: ");
        fgets(produto[i].nome, 50, stdin);
        produto[i].nome[strcspn(produto[i].nome, "\n")] = 0;
        for(j = 0; j < final_produtos; j++) {
            if(strcmp(produto[j].nome, produto[i].nome) == 0) {
                printf("O PRODUTO JÁ FOI CADASTRADO.\n\n");
                printf("QUANTIDADE ADICIONAL: ");
	        	scanf("%d", &quantidade);
				produto[j].quantidade += quantidade;
				igual = 1;
                break;
            }
        }
        if (igual == 0) {
            printf("QUANTIDADE: ");
	        scanf("%d", &produto[i].quantidade);
	        getchar();
	        printf("PREÇO: R$ ");
	        scanf("%f", &produto[i].preco);
	        getchar();
	        
	        final_produtos++; 
        }

        system("cls");
        printf("\t\tMENU\n\n");
        printf("[1] - ADICIONAR OUTRO PRODUTO\n");
        printf("[2] - SAIR\n\n");
        printf("OPÇÃO: ");
        scanf("%d", &op1);
        getchar();
        
        switch(op1) {
            case 1:
                continue;
            case 2:
                printf("\nRETORNANDO...\n");
                system("pause");
                system("cls");
                return;
        }
    }
}

void listar_produtos() {
	int i;
	printf("\t\tLISTAGEM DE PRODUTOS\n\n");
	if(final_produtos == 0){
		printf("NÃO TEM PRODUTOS CADASTRADOS!");
		printf("\n\n");
	}else{
		for(i = 0; i < final_produtos; i++) {
		printf("| NUMERO DO PRODUTO: [%d]\n", i);
		printf("| NOME: %s\n", produto[i].nome);
		printf("| QUANTIDADE: %d\n", produto[i].quantidade);
		printf("| PREÇO: R$ %.2f\n\n\n", produto[i].preco);	
		}
	}
	system("pause");
	system("cls");
}

void excluir_produto(){
	int i, j, produto_encontrado = 0;
    char nome_excluir[50];

    system("cls");
    printf("\t\tEXCLUIR PRODUTO\n\n");

    if (final_produtos == 0) {
        printf("NENHUM PRODUTO CADASTRADO.\n\n");
        system("pause");
        system("cls");
        return;
    }

    printf("DIGITE O NOME DO PRODUTO A SER EXCLUÍDO: ");
    fgets(nome_excluir, 50, stdin);
    nome_excluir[strcspn(nome_excluir, "\n")] = 0;

    for (i = 0; i < final_produtos; i++) {
        if (strcmp(produto[i].nome, nome_excluir) == 0) {
            produto_encontrado = 1;

            for (j = i; j < final_produtos - 1; j++) {
       			 produto[j] = produto[j + 1];
            }

            final_produtos--; 

            printf("PRODUTO '%s' EXCLUÍDO COM SUCESSO!\n\n", nome_excluir);
            system("pause");
            system("cls");
            return; 
        }
    }

    if (!produto_encontrado) {
        printf("Produto '%s' não encontrado.\n", nome_excluir);
        system("pause");
        system("cls");
    }
}

void finalizar_compra() {
    system("cls");
    printf("\t\tFINALIZAR COMPRA\n\n");

    if (num_itens_carrinho == 0) {
        printf("Carrinho vazio!\n");
        system("pause");
        return;
    }

    float valor_total = 0;
    int estoque_insuficiente = 0;
    
	int i;
    for (i = 0; i < num_itens_carrinho; i++){ 
        int id_produto = carrinho[i].id_produto;
        int quantidade = carrinho[i].quantidade;

        if (produto[id_produto].quantidade < quantidade) {
            estoque_insuficiente = 1;
            printf("Estoque insuficiente para o produto '%s'\n", produto[id_produto].nome);
        } else {
        	
            valor_total += produto[id_produto].preco * quantidade;

            produto[id_produto].quantidade -= quantidade;
        }
    }

    if (estoque_insuficiente) {
        system("pause");
        return;
    }

    printf("\nCOMPROVANTE DE COMPRA\n");
    printf("---------------------\n");
    printf("Data e hora: %s\n", __DATE__ " " __TIME__);
    printf("---------------------\n");
    for (i = 0; i < num_itens_carrinho; i++) {
        int id_produto = carrinho[i].id_produto;
        int quantidade = carrinho[i].quantidade;
        printf("Produto: %s\n", produto[id_produto].nome);
        printf("Quantidade: %d\n", quantidade);
        printf("Preço unitário: R$ %.2f\n", produto[id_produto].preco);
        printf("Subtotal: R$ %.2f\n\n", produto[id_produto].preco * quantidade);
    }
    printf("---------------------\n");
    printf("Valor total: R$ %.2f\n", valor_total);
    printf("---------------------\n");
    printf("Obrigado pela compra!\n");

    num_itens_carrinho = 0;

    system("pause");
}

void cadastrar_animal() {
	int i, op;
	system("cls");
	for(i = final_animais; i < TAM2; i++) { 
		system("cls");
		printf("\t\tMENU CADASTRO\n\n");
		printf("NOME: ");
		fgets(animal[i].nome, 50, stdin);
		printf("RAÇA: ");
		fgets(animal[i].raca, 50, stdin);
		printf("IDADE: ");
		scanf("%d", &animal[i].idade);
		getchar();
		printf("ID: ");
		scanf("%d", &animal[i].id);
		getchar();
		final_animais++;
		
		printf("\n\nDESEJA ADICIONAR O ANIMAL A FILA?\n");
		printf("[1] - SIM\n");
		printf("[2] - NÃO\n\n");
		printf("OPÇÃO: ");
		scanf("%d", &op);
		getchar();
		switch(op) {
			case 1:
				inserir_fila(animal[i].id);
				printf("O ANIMAL DE ESTIMAÇÃO FOI INSERIDO NA FILA DE BANHO/TOSA\n\n");
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				break;
			default:
				printf("VALOR INVÁLIDO");
		}
		
        printf("\t\tMENU\n\n");
        printf("[1] - CADASTRAR OUTRO ANIMAL\n");
        printf("[2] - SAIR\n\n");
        printf("OPÇÃO: ");
        scanf("%d", &op);
        getchar();
        
        switch(op) {
            case 1:
                continue;
            case 2:
                printf("\nRETORNANDO...\n");
                system("pause");
                system("cls");
                return;
        }
	}
}

void listar_animais() {
	int i, id;
	system("cls");
	printf("\t\tLISTAGEM DE ANIMAIS DE ESTIMAÇÃO\n\n");
	if(final_animais == 0) {
		printf("NÃO TEM ANIMAIS DE ESTIMAÇÃO CADASTRADOS!");
		printf("\n\n");
		system("pause");
	} else { 
		for(i = 0; i < final_animais; i++) {
			printf("| ID DO ANIMAL: [%d]\n", animal[i].id);
			printf("| NOME: %s", animal[i].nome);
			printf("| RAÇA: %s", animal[i].raca);
			printf("| IDADE: %d\n\n\n", animal[i].idade);
		}
		printf("DIGITE O ID A SER ADICIONADO: ");
		scanf("%d", &id);
		getchar();
		for(i = 0; i < final_animais; i++) {
			if(id == animal[i].id) {
				inserir_fila(animal[i].id);
				printf("O ANIMAL DE ESTIMAÇÃO FOI INSERIDO NA FILA DE BANHO/TOSA\n\n");
				system("pause");
				system("cls");
			}
		}
	}
	system("cls");
}


int main() {
	setlocale(LC_ALL,"");
	int op, valor;
	// SERVIÇOS - COMPRA/VENDA E BANHO/TOSA
	do {	
		printf("\t\tMENU PETSHOP\t\t\n\n");		
		printf("[1] - REALIZAR SERVIÇO\n");
		printf("[2] - LISTAR FILA\n");
		printf("[3] - INSERIR PRODUTO\n");
		printf("[4] - EXCLUIR PRODUTO\n");			
		printf("[5] - LISTAR PRODUTOS\n");			
		printf("[6] - SAIR\n\n");					
		
		// USAR PRA TESTAR A FILA SO TIRAR DO COMENTARIO
																							
		/*										
		printf("\n\nMENU DA FILA\n\n\n");
		printf("[7] - INSERIR\n");
		printf("[8] - REMOVER\n");
		printf("[9] - VER CHEIA\n");
		printf("[10] - VER VAZIA\n");
		printf("[11] - VER INICIO\n");
		printf("[12] - VER FINAL\n");
		printf("[13] - LISTAR\n");
		printf("[14] - BUSCAR\n");
		*/
		printf("OPÇÃO: ");
		scanf("%d",&op);
		getchar();
		system("cls");
		
		switch(op) {
			case 1:
				printf("\t\tMENU SERVIÇOS\n\n");
				printf("[1] - VENDA DE PRODUTOS\n");
				printf("[2] - FILA DE BANHO/TOSA\n");
				printf("[3] - RETORNAR\n\n");
				
				printf("OPÇÃO: ");
				scanf("%d", &op);
				getchar();
				
				switch(op) {
					case 1:
                        do {
                            system("cls");
                            printf("\t\tVENDA DE PRODUTOS\n\n");
                            printf("[1] - Listar Produtos\n");
                            printf("[2] - Adicionar Produto ao Carrinho\n");
                            printf("[3] - Finalizar Compra\n");
                            printf("[4] - Retornar\n\n");

                            printf("OPÇÃO: ");
                            scanf("%d", &op);
                            getchar();

                            switch(op) {
                                case 1:
                                    listar_produtos();
                                    break;
                                case 2:
                                    system("cls");
                                    printf("\t\tADICIONAR PRODUTO AO CARRINHO\n\n");

                                    listar_produtos(); // Mostrar a lista de produtos

                                    int id_produto, quantidade;
                                    printf("Digite o ID do produto: ");
                                    scanf("%d", &id_produto);
                                    getchar();

                                    printf("Digite a quantidade: ");
                                    scanf("%d", &quantidade);
                                    getchar();

                                    // Verifica se o produto existe e se a quantidade é válida
                                    if (id_produto >= 0 && id_produto < final_produtos && quantidade > 0) {
                                        // Adicionar produto ao carrinho
                                        carrinho[num_itens_carrinho].id_produto = id_produto;
                                        carrinho[num_itens_carrinho].quantidade = quantidade;
                                        num_itens_carrinho++;
                                        printf("Produto adicionado ao carrinho!\n");
                                    } else {
                                        printf("Produto inválido ou quantidade inválida!\n");
                                    }
                                    system("pause");
                                    break;
                                case 3:
                                    finalizar_compra();
                                    break;
                                case 4:
                                    // Retornar
                                    break;
                                default:
                                    printf("Opção inválida!\n");
                            }
                        } while(op != 4);
						break;
					case 2:
						system("cls");
						printf("\t\tMENU FILA\t\t\n\n");
						printf("[1] - ADICIONAR NA FILA\n");
						printf("[2] - REMOVER DA FILA\n");
						printf("[3] - RETORNAR\n\n");
						
						printf("OPÇÃO: ");
						scanf("%d", &op);
						getchar();
						
						switch(op) {
							case 1:
								system("cls");
								printf("\t\tMENU FILA\t\t\n\n");
								printf("[1] - CADASTRAR ANIMAL\n");
								printf("[2] - ESCOLHER NA LISTA\n");
								printf("[3] - RETORNAR\n\n");
								
								printf("OPÇÃO:");
								scanf("%d", &op);
								getchar();
								
								switch(op) {
									case 1:			// VAI SER INSERIDO OS DADOS DO ANIMAL E ADICIONADO NA FILA
										if(cheia() == 0) {
											system("cls");
											cadastrar_animal();
											system("cls");
										} else {
											printf("A FILA ESTÁ CHEIA\n");
										}
										break;
									case 2:
										// LISTAR OS ANIMAIS CADASTRADOS E ESCOLHER QUAL DELES VAI SER ADICIONADO NA FILA
										listar_animais();
										break;
									case 3:
										printf("RETORNANDO...\n");
										printf("");
										system("pause");
										system("cls");
										break;
								}
								break;
							case 2:
								if(vazia() == 0) {
									printf("O VALOR [%d] FOI REMOVIDO\n", fila[final_produtos]);
									remover();
								} else {
									printf("A FILA ESTÁ VAZIA\n");
								}	
								break;
							case 3:
								printf("RETORNANDO...\n");
								system("pause");
								system("cls");
								break;
						}
						break;
					case 3:
						printf("RETORNANDO...\n");
						system("pause");
						system("cls");
						break;
					default:
						break;
				}
				break;
			case 2:
				listar_fila();
				break;
			case 3: //FAZER A LISTAGEM ATÉ O PRODUTO QUE FOI CADASTRADO
				inserir_produto();
				break;
			case 4:
				excluir_produto();
				break;
			case 5:
				listar_produtos();
				break;
			case 6:
				printf("SAINDO...\n");
				break;
			default:
				printf("VALOR INVÁLIDO!\n");
				break;
				
			// 
			// PARA TESTAR A FILA	
			//
		
			case 7:
				if(cheia() == 0) {
					printf("DIGITE UM VALOR A SER ADICIONADO NA FILA: ");
					scanf("%d", &valor);
					inserir_fila(valor);
				} else {
					printf("A FILA ESTÁ CHEIA\n");
				}
				break;
			case 8:
				if(vazia() == 0) {
					printf("O VALOR [%d] FOI REMOVIDO\n", fila[final_produtos]);
					remover();
				} else {
					printf("A FILA ESTÁ VAZIA\n");
				}
				break;
			case 9:
				if(cheia() == 1) {
					printf("A FILA ESTÁ CHEIA\n");
				} else {
					printf("A FILA NÃO ESTÁ CHEIA\n");
				}
				break;
			case 10:
				if(vazia() == 1)
					printf("A FILA ESTÁ VAZIA\n");
				else
					printf("A FILA NÃO ESTÁ VAZIA\n");
				break;
			case 11:
				ver_inicio();
				break;
			case 12:
				ver_final();
				break;
			case 13:
				if(vazia() == 0) {
					listar_fila();
				} else {
					printf("A FILA ESTÁ VAZIA\n");
				}
				break;
			case 14:
				if(vazia() == 0) {
					printf("DIGITE UM VALOR A SER BUSCADO: ");
					scanf("%d",&valor);
					buscar(valor);
				} else {
					printf("A FILA ESTÁ VAZIA\n");
				}
				break;
		}	
	} while(op != 6);
}
