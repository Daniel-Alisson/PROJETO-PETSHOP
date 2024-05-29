#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 9
#define TAM2 50

struct produto {
	char nome[50];
	int quantidade;
	float preco;
} produto[TAM2];

int in = 0; // VARIAVEL PARA CADASTRO
int fila[TAM], inicio = 0, final = 0;

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
	printf("O inicio da fila é [%d]\n", inicio);
}

void ver_final() {
	printf("O final da fila é [%d]\n", final);
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
		printf("--->");
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
	
	for(i = 0; i < final; i++) {
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
	int i;
	// CRIAR UM PONTEIRO PARA SALVAR O VALOR DE I, FAZER UM IF/ELSE PARA O CASO DE ADICIONA O MESMO PRODUTO, ENTÃO SO VAI SOMAR A QUANTIDADE Q TEM
	for(i = in; i < TAM2; i++) {
		system("cls");
		
		printf("\t\tINSERINDO PRODUTO\n\n");
		printf("NOME: ");
		fgets(produto[i].nome, 50, stdin);
		printf("QUANTIDADE: ");
		scanf("%d", &produto[i].quantidade);
		getchar();
		printf("PREÇO: R$ ");
		scanf("%f", &produto[i].preco);
		getchar();
		
		int op1;
		
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
				break;
		}
		if(op1 == 2) {
			system("pause");
			system("cls");
			break;
		}
	}
}

void listar_produtos() {
	int i;
	printf("\t\tLISTAGEM DE PRODUTOS\n\n");
	for(i = 0; i < final; i++) {
		printf("| NUMERO DO PRODUTO: [%d]\n", i);
		printf("| NOME: %s\n", produto[i].nome);
		printf("| QUANTIDADE: %d\n", produto[i].quantidade);
		printf("| PREÇO: R$ %.2f\n\n\n", produto[i].preco);	
	}
	system("pause");
	system("cls");
}

int main() {
	setlocale(LC_ALL,"");
	int op, valor;
													// SERVIÇOS - COMPRA/VENDA E BANHO/TOSA
	do {	
		printf("\t\tMENU PETSHOP\t\t\n\n");		
		printf("[1] - REALIZAR SERVIÇO\n");			// OK
				// [1.1] VENDA - FAZ UMA LISTAGEM DOS PRODUTOS, COM OPÇÃO DE ESCOLHA E NO FINAL O PRODUTO É REMOVIDO E O COMPRPADOR GANHA UM COMPROVANTE FALSIFICADO
				// [1.2] BANHO/TOSA - AQ É INSERIDO O ANIMAL, ONDE A GENTE FAZ O CADASTRO DO ANIMAL E PA
				// 		[1.2.1] ADICIONAR ANIMAL - ADICIONA O BICHO NA LISTA
				//			   [1.2.1.1] CADASTRAR
				//			   [1.2.1.2] ESCOLHER NA LISTA JÁ CADASTRADA
				//		[1.2.2] REMOVER ANIMAL - REMOVE DA FILA
				//		[1.2.3] RETORNAR - VOLTA AO MENU ANTERIOR EU ACHO
				// [1.3] RETORNAR - PRA VOLTAR AO MENU INICIAL MEMO
				// printf("[2] - CADASTRAR SERVIÇOS\n");		// N SEI MT BEM OQ FAZER AQ	, ACHO Q N VAI PRECISAR
		printf("[2] - LISTAR FILA - OK\n");			// LISTAR OQ TEM EM CADA SERVIÇO, ENTÃO É PRA MOSTRAR A FILA DE BANHO/TOSA, COMPRA E VENDA N PRECISA
				// [3.1] FAZ UMA FILA MASSA PO
		printf("[3] - INSERIR PRODUTO - OK\n");			// DEVE SER INFORMADO O NOME DO PRODUTO, PREÇO, QUANTIDADE E ETC, É BOM USAR STRUCT, VAI TER Q FICAR DISPONIVEL NA LSITAGEM DE PRODUTOS
		printf("[4] - EXCLUIR PRODUTO - SEM FAZER\n");			// ESCREVEU ERRADO ENTÃO REMOVE
		printf("[5] - LISTAR PRODUTOS - OK\n");			// OK
		printf("[6] - SAIR\n\n");					
													
													
													// USAR PRA TESTAR A FILA SO TIRAR DO COMENTARIO
													
													
												
		printf("\n\nMENU DA FILA\n\n\n");
		printf("[7] - INSERIR\n");
		printf("[8] - REMOVER\n");
		printf("[9] - VER CHEIA\n");
		printf("[10] - VER VAZIA\n");
		printf("[11] - VER INICIO\n");
		printf("[12] - VER FINAL\n");
		printf("[13] - LISTAR\n");
		printf("[14] - BUSCAR\n");
		
		printf("OPÇÃO: ");
		scanf("%d",&op);
		getchar();
		system("cls");
		
		switch(op) {
			case 1:
				printf("\t\tMENU SERVIÇOS\n\n");
				printf("[1] - VENDA DE PRODUTOS - SEM FAZER\n");
				printf("[2] - FILA DE BANHO/TOSA - \n");
				printf("[3] - RETORNAR\n\n");
				
				printf("OPÇÃO: ");
				scanf("%d", &op);
				getchar();
				
				switch(op) {
					case 1:
						//
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
											printf("DIGITE O NUMERO A SER ADICIONADO NA FILA: ");
											scanf("%d", &valor);
											inserir_fila(valor);
										} else {
											printf("A FILA ESTÁ CHEIA\n");
										}
										break;
									case 2:
										// ESCOLHER NA FILA
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
									printf("O VALOR [%d] FOI REMOVIDO\n", fila[final]);
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
				break;
			case 5:
				listar_produtos();
				break;
			case 6:
				printf("SAINDO...\n");
				break;
			default:
				printf("Valor inválido!\n");
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
					printf("O VALOR [%d] FOI REMOVIDO\n", fila[final]);
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
