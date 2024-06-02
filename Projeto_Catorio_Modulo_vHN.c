#include <stdio.h>   //Biblioteca de comunica��o ao usuario
#include <stdlib.h>  //biblioteca  de aloca��o de espa�o de memoria
#include <locale.h>  //biblioteca de aloca��o de texto por regi�o (pa�s)
#include <string.h>  //biblioteca responsavel por cuidar das String

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);  //%s e toda vez que quero salvar uma String.
	
	strcpy(arquivo, cpf);  //Responsavel por copiar os valores das string
	
	FILE *file;  //Cria arquivo -> FILE = chamada do arquivo - file e o arquivo
	file = fopen(arquivo, "w");  //Cria o arquivo (e o"W" significa escrever)
	fprintf(file,cpf);  //Salva "f" valor da variavel
	fclose(file);  //Fecha o arquivo
	
	file = fopen(arquivo, "a");  // "a" de atualizacao
	fprintf(file," | ");
	fclose(file);
	
	printf("Digite o nome que ser� cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");  // "a" significa Abrir
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," | ");
	fclose(file);
	
	printf("Digite o sobrenome a cadastrar: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");  // "a" de atualiza��o
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");  // "a" de atualiza��o
	fprintf(file," | ");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que ser� consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");  // "R" significa Ler 
	
	if(file==NULL)  //NULL ira retornar == 0 (nada)
	{
		printf("N�o foi poss�vel abrir o arquivo (n�o localizado) ");
	}
	
	while(fgets(conteudo,200,file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");	
	}
	system("pause");	
}

int deletar()
{
	setlocale(LC_ALL,"Portuguese");
	char cpf[40];
	
	printf("Digite o CPF para deletar: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; // acessar bibliote FILE e puxar arquivo file
	file = fopen(cpf,"r");  //abrir arquivo
	
	if(file==NULL)
	{
	printf("O usuario n�o se encontra no sistema (deletado).\n");
	
	system("pause");
	}
}

int main() 
{
	int opcao=0;
	int laco=1;	

	for(laco=1;laco=1;)  //Faca, repita
	{
	
		system("cls");
	
		setlocale(LC_ALL,"Portuguese");
	
		printf("*** Cart�rio da EBAC *** \n\n"); //inicio do Menu
		printf("Escolha a op��o do menu:\n\n ");
		printf("\t1 - Registrar nomes:\n ");
		printf("\t2 - Consultar nomes:\n ");
		printf("\t3 - Deletar nomes:\n\n\n ");  
		printf("Op��o:");  //fim do Menu
	
		scanf("%d", &opcao);  //armazenando a escolha do usuario
	
		system("cls");  //responsavel por limpar a tela (deletar tudo que estiver 'escrito')
		
		switch(opcao)  //Chamada de func�es. Alterado "if" por opcoes,e uma escolha.
		{
			case 1:
			registro();  //chamada de func�es
			break;
			case 2:
			consulta();
			break;
			case 3:
			deletar();
			break;
			default:
			printf("Voce n�o escolheu uma op��o valida!\n");
			system("pause");
			break;
		}
	}
	
}
