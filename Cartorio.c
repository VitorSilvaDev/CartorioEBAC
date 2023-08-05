#include <stdio.h> // biblioteca de comunicação de usuário 
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocação de texto por região 
#include <string.h> // biblioteca responsável por cuidar da string

int registro() // Funçao responsável por cadastrar os usuários no sistema
{
	// Início criação de variaveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// Final criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf ("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); // Responsável por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo e o "W" significa escrever (write)
	fprintf(file,cpf); // Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo,"a"); // Abre um arquivo no modo de inclusão (append)
	fprintf(file, ",");
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo,"a"); // Abre um arquivo no modo de inclusão (append)
	fprintf(file, nome); // Salva o valor da variável 
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo,"a"); // abre um arquivo no modo de inclusão (append)
	fprintf(file, ",");
	fclose(file); // fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informação do usuário 
	scanf("%s",sobrenome); // %s refere-se a string
	
	file = fopen(arquivo,"a"); // Abre um arquivo no modo de inclusão (append)
	fprintf(file, sobrenome); // Salva o valor da variável 
	fclose(file); // Fecha o arquivo 
	
	file = fopen(arquivo,"a"); // Abre um arquivo no modo de inclusão (append)
	fprintf(file, ",");
	fclose(file); // Fecha o arquivo 
	
	printf("digite cargo a ser cadastrado: "); // Coletando informação do ussuário 
	scanf("%s",cargo); //  %s refere-se a variável 
	
	file = fopen(arquivo,"a"); // abre um arquivo no modo de inclusão (append)
	fprintf(file, cargo); // Salva o valor da variável 
	fclose(file); // fecha o arquivo 
	
	system("pause"); // Responsável por "travar" a tela 
	
}

int consulta() // Função resposável por consultar o usuário no sistema 
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	//Inicio de criação de variável/string
   char cpf[40];
   char conteudo[200];
   // Final de criação de variaveis/string
   
   printf("Digite o CPF a ser consultado: "); // Coletando informação do usuário 
   scanf("%s",cpf); // %s refere-se a string
   
   FILE *file; // Cria o arquivo 
   file = fopen(cpf,"r"); // abre um arquivo no modo leitura 
   
   if (file == NULL)
   {
   		printf ("Não foi possível abrir o arquivo, não localizado!. \n");
   }
   
   while(fgets(conteudo, 200, file) !=NULL)
   {
   		printf ("\nEssas são as informações do usuário: ");
   		printf("%s", conteudo);
   		printf("\n\n");
   }
   
   system("pause"); // Resposável por travar a tela 
   
}


int deletar() // Função resposável por deletar o usuário do sistema
{
	// inicio de criação de variável/string
	char cpf[40];
	// Final de criação de variaveis/string
    
    printf("Digite o cpf do usuário a ser deletado: "); // Coletando indromação do usuário
    scanf ("%s",cpf); // %s refere-se a string
    
    remove (cpf); // Responsável por deletar o usuario 
    
    FILE *file; // Cria o arquivo 
    file = fopen (cpf, "r"); // abre o arquivo no modo leitura 
    
    if(file == NULL)
    {
    	printf(" O usuário não se encontra no sistema!\n");
    	system("pause");
	}

		
}


int main ()
	{
	int opcao=0; //Definindo Variaveis 
	int laco=1;
	
	for (laco=1;laco=1;) // Laço de repetição
	{
		
		system("cls"); // Responsável por limpar a tela 
		
		setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem 
	
		printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); // Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário 
	
		system("cls"); // Responsavel por limpar a tela
	
	
		switch(opcao) // inicio da seleção do menu
		{
			case 1:
			registro (); // chamada de funcções 
			break;
		
			case 2:	
			consulta ();
			break;
		
			case 3:
			deletar ();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!");
			return 0;
			break;
		
			default:
			printf("Essa opção não está disponível\n");
			system("pause");	
		
		} // fim da seleção
	
	}	
}
