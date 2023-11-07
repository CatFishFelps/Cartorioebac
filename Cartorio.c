#include <stdio.h> //bibliot�ca de comunica��o com o us�ario
#include <stdlib.h> //bibliot�ca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibliot�ca de aloca��es de texto por regi�o
#include <string.h> //bibliot�ca respons�vel por cuidar dos strings

int registro() //Fun��o respons�vel por cadastras os usu�rios no sistema	
{
	//In�cio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o das vari�veis
	
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se ao armazenamento de Strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings para outras
	
	FILE *file; //entra na pasta do programa
	file = fopen(arquivo, "w"); //cria um arquivo, "w" de write, para escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre e edita o arquivo. comando "a" serve para editar o arquivo, "a" provavelmente de alter (alterar), e n�o edit(editar)
	fprintf(file,"\nNOME: "); //edita o arquivo
	fclose(file); //fecha o arquivo
	//FIM!!
	
	//ARMAZENANDO OS NOMES NO ARQUIVO CRIADO	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\nSOBRENOME: ");
	fclose(file);
	//FIM!!
	
	//ARMAZENANDO Os SOBRENOMEs NO ARQUIVO CRIADO
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\nCARGO: ");
	fclose(file);
	//FIM!!
	
	//ARMAZENANDO Os CARGOs NO ARQUIVO CRIADO
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file,"\n\n");
    fclose(file);
	//FIM!!	

}

int consulta()
{
	
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    //CONSULTANDO O CPF
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);//%s refere-se ao armazenamento de Strings
    
    FILE *file;
    file = fopen(cpf, "r"); // "r" de read, l� o cpf digitado
    
    if(file == NULL) //valida��o para ver se o CPF existe ou n�o dentro do arquivo
	{
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
    
    printf("Essas s�o as informa��es do usu�rio: \n\n");
    
    while(fgets(conteudo, 200, file) != NULL)
	{
    	printf("%s", conteudo);//%s refere-se ao armazenamento de Strings
	}
    
    system("pause");
    //FIM

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Este Arquivo n�o existe!\n");
		system("pause");
	}
}

int main ()
{
	
	int opcao = 0; //definindo as vari�veis
	int laco=1; //definindo as vari�veis
	
	for(laco=1;laco=1;) //come�o do la�o de repeti��o
	{
		system("cls");
		
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	
	    printf("### Cart�rio da EBAC ###\n\n"); //in�cio do Menu
     	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
    	printf("\t4 - Sair do Sistema\n\n");
    	printf("Op��o: ");//fim do Menu
	
	    scanf("%d", &opcao);//armazenando a escolha do usu�rio. "%d" � o comando para armazenar o valor na variavel.
	
    	system("cls"); //respons�vel por limpar a tela
    	
    	
    	switch(opcao) //in�cio do Switch Case (Menu)
    	{
    		case 1:
    		registro();//chamada de fun��es
    		break;
    		
    		case 2:
    		consulta();
	    	break;
	    	
	    	case 3:
	    	deletar();
    		break;
    		
    		case 4:
    	    printf("Obrigado pro �tilizar o Sistema!\n");
    	    return 0;
    	    break;
    	    
    		default:
    		printf("Essa op��o n�o est� dispon�vel!\n");
    		system("pause");
    		break;
		} //fim do Switch case (Menu)
	
   } //fim do la�o de repeti��o
}
	
