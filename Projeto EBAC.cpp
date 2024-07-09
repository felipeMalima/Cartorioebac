#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
// Sele��o de bibliotecas.

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Voc� escolheu o registro de nomes.\n\n");
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // %s � para atribuir String.
	
	strcpy(arquivo, cpf); // Copia o valor das strings puxa da segunda pra primeira.
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // O "W" escreve o arquivo.
	fprintf(file,cpf); // Salva o valor da vari�vel.
	fclose(file); // Fecha o arquivo.
	
	file = fopen(arquivo, "a"); // O "A" atualiza o arquivo.
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
    system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Voc� escolheu consultar os nomes.\n\n");
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // O "R" le o arquivo.
	
	if(file == NULL)
	{
		printf("O CPF informado n�o foi encontrado");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	
    system("pause");
}

int deletar()
{
	printf("Voc� escolheu deletar nomes.\n\n");
    system("pause");
}


int main()
{
	int opcao=0;
	int laco=1; // Determina a vari�vel.
	
	for(laco=1;laco=1;)
	{
		system("cls");
    	setlocale(LC_ALL, "Portuguese"); // Seleciona o idioma.
    	printf("### Cart�rio da EBAC ###\n\n");
    	printf("Escolha a op��o desejada no menu: \n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    
    	scanf("%d", &opcao); //Define o tipo da vari�vel a atribui o valor digitado.
    
    	system("cls"); // Limpa o c�digo.
    
    	switch(opcao)
    	{
			case 1:
			registro();
    		break;
		
			case 2:
			consultar();
    		break;
    		
    		case 3:
			deletar();
    		break;
    		
    		default:
    			printf("Essa op��o n�o est� dispon�vel.\n\n");
    			system("pause");
    		break;
		
		}

	}
}
