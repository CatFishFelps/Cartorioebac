#include <stdio.h> //bibliotéca de comunicação com o usúario
#include <stdlib.h> //bibliotéca de alocação de espaço em memória
#include <locale.h> //bibliotéca de alocações de texto por região
#include <string.h> //bibliotéca responsável por cuidar dos strings

int registro() //Função responsável por cadastras os usuários no sistema	
{
	//Início da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação das variáveis
	
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário
	scanf("%s", cpf); //%s refere-se ao armazenamento de Strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings para outras
	
	FILE *file; //entra na pasta do programa
	file = fopen(arquivo, "w"); //cria um arquivo, "w" de write, para escrever
	fprintf(file,"CPF: ");
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre e edita o arquivo. comando "a" serve para editar o arquivo, "a" provavelmente de alter (alterar), e não edit(editar)
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
    file = fopen(cpf, "r"); // "r" de read, lê o cpf digitado
    
    if(file == NULL) //validação para ver se o CPF existe ou não dentro do arquivo
	{
    	printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
    
    printf("Essas são as informações do usuário: \n\n");
    
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Este Arquivo não existe!\n");
		system("pause");
	}
}

int main ()
{
	
	int opcao = 0; //definindo as variáveis
	int laco=1; //definindo as variáveis
	
	for(laco=1;laco=1;) //começo do laço de repetição
	{
		system("cls");
		
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	
	    printf("### Cartório da EBAC ###\n\n"); //início do Menu
     	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
    	printf("\t4 - Sair do Sistema\n\n");
    	printf("Opção: ");//fim do Menu
	
	    scanf("%d", &opcao);//armazenando a escolha do usuário. "%d" é o comando para armazenar o valor na variavel.
	
    	system("cls"); //responsável por limpar a tela
    	
    	
    	switch(opcao) //início do Switch Case (Menu)
    	{
    		case 1:
    		registro();//chamada de funções
    		break;
    		
    		case 2:
    		consulta();
	    	break;
	    	
	    	case 3:
	    	deletar();
    		break;
    		
    		case 4:
    	    printf("Obrigado pro útilizar o Sistema!\n");
    	    return 0;
    	    break;
    	    
    		default:
    		printf("Essa opção não está disponível!\n");
    		system("pause");
    		break;
		} //fim do Switch case (Menu)
	
   } //fim do laço de repetição
}
	
