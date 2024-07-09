#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
// Seleção de bibliotecas.

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Você escolheu o registro de nomes.\n\n");
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // %s é para atribuir String.
	
	strcpy(arquivo, cpf); // Copia o valor das strings puxa da segunda pra primeira.
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // O "W" escreve o arquivo.
	fprintf(file,cpf); // Salva o valor da variável.
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
	
	printf("Você escolheu consultar os nomes.\n\n");
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // O "R" le o arquivo.
	
	if(file == NULL)
	{
		printf("O CPF informado não foi encontrado");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	
    system("pause");
}

int deletar()
{
	printf("Você escolheu deletar nomes.\n\n");
    system("pause");
}


int main()
{
	int opcao=0;
	int laco=1; // Determina a variável.
	
	for(laco=1;laco=1;)
	{
		system("cls");
    	setlocale(LC_ALL, "Portuguese"); // Seleciona o idioma.
    	printf("### Cartório da EBAC ###\n\n");
    	printf("Escolha a opção desejada no menu: \n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    
    	scanf("%d", &opcao); //Define o tipo da variável a atribui o valor digitado.
    
    	system("cls"); // Limpa o código.
    
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
    			printf("Essa opção não está disponível.\n\n");
    			system("pause");
    		break;
		
		}

	}
}
