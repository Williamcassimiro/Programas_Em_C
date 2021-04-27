#include <stdio.h>
#include <stdlib.h>
#include <string.h> // incluir biblioteca para manipular strings
#include <locale.h> // incluir biblioteca para pode usar acentuação nos textos
#include <unistd.h> // incluir biblioteca para poder limpar a tela sempre que necessário

// declaração da struct nó livro
struct NoLivro
{
	char nome[50];
	int alunoRA;
	int emprestado;
	struct NoLivro *proximo;
};
typedef struct NoLivro noLivro; // definindo a struct NoLivro como noLivro
									// isso facilita a criaçãoo de novos nos

// declaracao da struct nó Aluno
struct NoAluno
{
	char nome[20];
	int ra;
	int semestre;
	char curso[25];
	struct NoAluno *proximo;
};
typedef struct NoAluno noAluno; // definindo a struct NoLivro como noLivro
									//  isso facilita a criaçãoo de novos nos

// funÃ§Ã£o que inicia a lista de livros, declarando o primeiro elemento como NULL
// recebe a lista de livros como parametro
void iniciaListaLivro(noLivro *listaLivros)
{
	listaLivros->proximo = NULL;
}

// função que retorna 1 se a lista de livros estiver vazia ou 0 se a lista tiver pelo menos um elemento
int listaLivrosVazia(noLivro *listaLivros)
{
	if (listaLivros->proximo == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// função que inicia a lista de alunos, declarando o primeiro elemento como NULL
// recebe a lista de alunos como parametro
void iniciaListaAluno(noAluno *listaAlunos)
{
	listaAlunos->proximo = NULL;
}

// função que retorna 1 se a lista de alunos estiver vazia ou 0 se a lista tiver pelo menos um elemento
int listaAlunosVazia(noAluno *listaAlunos)
{
	if (listaAlunos->proximo == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// função que procura um RA na lista de alunos.
// retorna 1 se encontrar algum aluno com o RA digitado e 0 se nao encontrar
int verificarRA(noAluno *listaAlunos, int ra)
{
	noAluno *tmp = listaAlunos->proximo;

	while(tmp != NULL)
	{
		if(tmp->ra == ra)
		{
			return 1;
		}
		tmp = tmp->proximo;
	}

	return 0;
}


// função que exibe informações de todos os livros salvos na lista encadeada
void mostrarLivros(noLivro *listaLivros)
{

	// verifica se a lista é vazia
	if(listaLivrosVazia(listaLivros))
	{
		printf("Não há nenhum livro na lista de livros!\n");
		return; // se a lista for vazia, vai imprimir a mensagem acima e finalizar a função "mostrarLivros"
				// por causa desse "return;"
	}

	// para percorrer todos os nos da lista é necessÃ¡rio criar um ponteiro auxiliar que aponta para
	// o primeiro elemento da lista (primeiro elemento da lista = listaLivros->proximo)
	noLivro *tmp;
	tmp = listaLivros->proximo;

	// o laço se repete enquanto o ponteiro auxiliar for diferente de nulo
	while(tmp != NULL)
	{
		// dentro do laço todas as informações são printadas na tela
		printf("Título do Livro: %s  -  ", tmp->nome);

		if(tmp->emprestado == 0)
		{
			printf("Status: Disponível  -  ");
		}
		else
		{
			printf("Status: Emprestado  -  ");
		}

		printf("Emprestado para: %d\n", tmp->alunoRA);

		// o valor do ponteiro tmpiliar Ã© alterado para ser igual ao proximo elemento da lista
		// o ultimo elemento da lista aponta o proximo elemento para NULL, fazendo o laÃ§o finalizar
		tmp = tmp->proximo;
	}
}

// funcao que mostra todos os alunos, segue a mesma ideia da que mostra todos os livros
void mostrarAlunos(noAluno *listaAlunos)
{
	if(listaAlunosVazia(listaAlunos))
	{
		printf("Não há¡ nenhum aluno na lista de alunos\n");
		return;
	}

	noAluno *tmp;
	tmp = listaAlunos->proximo;

	while(tmp != NULL)
	{
		printf("Nome do Aluno: %s  -  ", tmp->nome);
		printf("RA: %d  -  ", tmp->ra);
		printf("Curso: %s  -  ", tmp->curso);
		printf("Semestre: %d\n", tmp->semestre);


		tmp = tmp->proximo;
	}
}

// funcao para adicionar um novo livro na lista
void addLivro(noLivro *listaLivros)
{
	// é alocada memoria para o novo no
	noLivro *novoLivro = (noLivro *) malloc(sizeof(noLivro));

	printf("Insira o nome do livro:\n");
	fflush(stdin);

	gets(novoLivro->nome);
	fflush(stdin);

	novoLivro->alunoRA = 0;

	novoLivro->emprestado = 0;

	noLivro *tmp = listaLivros->proximo; // cria uma variavel auxiliar que aponta para o primeiro elemento da lista
	listaLivros->proximo = novoLivro; // muda o primeiro elemento da lista para o novo no recem criado
	novoLivro->proximo = tmp; // faz o novo no apontar para o antigo primeiro elemento da lista

	printf("Incluido com sucesso!\n");
}

// funcao que exclui da lista um livro digitado pelo usuario
void excluirLivro(noLivro *listaLivros)
{

	char nome[20];

	printf("Insira o nome do livro que deseja excluir:\n");
	gets(nome);
	fflush(stdin);

	noLivro *tmp = listaLivros;

	// la♪5o de repetição usado para procurar o livro digitado pelo usuario
	while(tmp->proximo != NULL)
	{

		// comando if verificando se encontra um nome de livro correspondente ao que o usuario digitou
		if(strcmp(nome, tmp->proximo->nome) == 0)
		{

			noLivro *apagado = tmp->proximo;
			tmp->proximo = tmp->proximo->proximo;
			free(apagado); // liberando a memoria do no apagado
			printf("Livro apagado com sucesso!!\n");
			return; // finaliza a funcao pois o livro foi encontrado e apagado
		}
		tmp = tmp->proximo;
	}

	// se o programa passar pelo while sem entrar no if significa que o livro digitado nao existe na lista
	printf("Não foi encontrado nenhum livro com o nome digitado!\n");
}

// função que mostra os livros emprestados por um determinado aluno
void mostrarEmprestimo(noLivro *listaLivros, noAluno *listaAlunos)
{
	int ra;
	printf("Digite o RA do aluno:\n");
	scanf("%d", &ra);
	fflush(stdin);

	// verifica se o RA digitado exite na lista de alunos, se nao existir finaliza a função
	if(!verificarRA(listaAlunos, ra))
	{
		printf("O RA digitado não está cadastrado no sistema!\n");
		return;
	}

	printf("Livros emprestados pelo aluno:\n");

	// percorre toda a lista de livros imprimindo os que estao emprestados para o RA digitado
	noLivro *tmp = listaLivros->proximo;
	while(tmp != NULL)
	{
		if(tmp->alunoRA == ra)
		{
			printf("%s\n", tmp->nome);
		}

		tmp = tmp->proximo;
	}
}

// funcao que realiza o emprestimo de um livro
void emprestarLivro(noLivro *listaLivros, noAluno *listaAlunos)
{
	// verifica se existe algum livro cadastrado para ser emprestado
	if(listaLivrosVazia(listaLivros))
	{
		printf("Não há livros cadastrados para serem emprestados!\n");
		return;
	}

	char nome[50];
	int achou = 0;

	printf("Insira o nome do livro que deseja emprestar:\n");
	gets(nome);
	fflush(stdin);

	noLivro *tmp = listaLivros->proximo;

	// laco de repeticao procurando pelo livro digitado
	// se achar o livro, verifica se ele já está emprestado
	while(tmp != NULL)
	{

		if(strcmp(nome, tmp->nome) == 0)
		{
			achou = 1;
			if(tmp->emprestado == 1)
			{
		   		printf("O livro já está emprestado!\n");
				return;
			}
			break;
		}

		tmp = tmp->proximo;
	}

	if(achou == 0)
	{
		printf("Livro não encontrado no acervo!\n");
		return;
	}

	// pede e valida o RA do aluno que deseja emprestar o livro
	do{
		printf("Digite o RA do aluno que está emprestando o livro:\n");
		scanf("%d", &tmp->alunoRA);

		if(tmp->alunoRA == 0)
		{
			printf("O RA deve ser diferente de 0 (zero)!!\n");
		}
		else
		{
			if(!verificarRA(listaAlunos, tmp->alunoRA))
			{
				printf("O RA digitado não está cadastrado!\n");
				tmp->alunoRA = 0;
			}
		}
	}while(tmp->alunoRA == 0);

	// atualiza o status de emprestimo do livro
	tmp->emprestado = 1;

	printf("Empréstimo realizado com sucesso!!\n");
}

// funcao que faz a devolucao de um livro
void devolverLivro(noLivro *listaLivros)
{
	char nome[50];

	printf("Digite o nome do exemplar que deseja fazer devolução:\n");
	gets(nome);
	fflush(stdin);

	noLivro *tmp = listaLivros->proximo;
	// repeticao que procura o livro, verifica se ele esta emprestado
	// e faz a devolucao caso esteja
	while(tmp != NULL)
	{

		if(strcmp(nome, tmp->nome) == 0)
		{
			if(tmp->emprestado == 0)
			{
				printf("O livro não estava emprestado!\n");
				return;
			}
			tmp->alunoRA = 0;
			tmp->emprestado = 0;
			printf("Devolução realizada com suecsso!\n");
			return;
		}
		tmp = tmp->proximo;
	}

	printf("Livro não encontrado no acervo!\n");
}

// funcao fodida pra ler os livros do txt
void lerTxtLivros(noLivro *listaLivros)
{
	FILE *arq_ptr;
	char linha[80];
	char c;

	arq_ptr = fopen("livros.txt", "r");

	if(arq_ptr == NULL)
	{
		printf("ERRO! O arquivo não foi aberto!\n");
		return;
	}

	// usa o fgets para ler uma linha inteira de uma vez
	// depois, para cada linha lida, é criado um novo no de livro
	// e percorrido caracter por caracter da linha para ler os valores entre ';' e
	// salvar no no
	while(fgets(linha, 80, arq_ptr) != NULL)
	{

		noLivro *novo = (noLivro *) malloc(sizeof(noLivro));
		int pos = 0, base = 0;
		char nome[50], emprestado[2], alunoRA[10];

		do{
			c = linha[pos];

    		if(c != ';')
    		{
				nome[pos] = c;
			}

			pos++;
		}while (c != ';');

		nome[pos-1] = '\0';
		strcpy(novo->nome, nome);

		emprestado[0] = linha[pos];
		emprestado[1] = '\0';

		novo->emprestado = atoi(emprestado);

		pos += 2;
		base = pos;

		do{
			c = linha[pos];

			if(c != '\n' && c != EOF)
			{
				alunoRA[pos-base] = c;
			}

			pos++;
		}while(c != '\n' && c != EOF);

		alunoRA[pos-base-1] = '\0';
		novo->alunoRA = atoi(alunoRA);

		noLivro *tmp = listaLivros->proximo;
		listaLivros->proximo = novo;
		novo->proximo = tmp;
	}

	// fecha o arquivo
	fclose(arq_ptr);
}

// funcao pra ler os alunos no arquivo txt
// funciona igual ao de ler os livros, so um pouco mais comprida
void lerTxtAlunos(noAluno *listaAlunos)
{
	FILE *arq_ptr;
	char linha[80];
	char c;

	arq_ptr = fopen("alunos.txt", "r");

	if(arq_ptr == NULL)
	{
		printf("ERRO! O arquivo não foi aberto!\n");
		return;
	}

	while(fgets(linha, 80, arq_ptr) != NULL)
	{

		noAluno *novo = (noAluno *) malloc(sizeof(noAluno));
		int pos = 0, base = 0;
		char nome[50], semestre[10], alunoRA[15], curso[25];

		do{
			c = linha[pos];

    		if(c != ';')
    		{
				nome[pos] = c;
			}

			pos++;
		}while (c != ';');

		nome[pos-1] = '\0';
		strcpy(novo->nome, nome);

		base = pos;

		do{
			c = linha[pos];

			if(c != ';')
			{
				alunoRA[pos-base] = c;
			}

			pos++;
		}while(c != ';');

		alunoRA[pos-base-1] = '\0';
		novo->ra = atoi(alunoRA);

		base = pos;

		do{
			c = linha[pos];

			if(c != ';')
			{
				semestre[pos-base] = c;
			}

			pos++;
		}while(c != ';');

		semestre[pos-base-1] = '\0';
		novo->semestre = atoi(semestre);

		base = pos;

		do{
			c = linha[pos];

			if(c != '\n' && c != EOF)
			{
				curso[pos-base] = c;
			}

			pos++;
		}while(c != '\n' && c != EOF);

		curso[pos-base-1] = '\0';
		strcpy(novo->curso, curso);

		noAluno *tmp = listaAlunos->proximo;
		listaAlunos->proximo = novo;
		novo->proximo = tmp;
	}

	fclose(arq_ptr);
}

// funcao q sobrescreve o arquivos txt de livros, salvando todas as altercoes nos livros cadastrados
// cada linha do txt se refere a um cadastro e todos os atributos estao separados por ';', como no
// exemplo do professor
void salvarLivros(noLivro *listaLivros)
{
	FILE *arq_ptr;

	arq_ptr = fopen("livros.txt", "w");

	if(arq_ptr == NULL)
	{
		printf("ERRO! O arquivo não foi aberto!\n");
		return;
	}

	noLivro *tmp = listaLivros->proximo;

	while(tmp != NULL)
	{
		fprintf(arq_ptr, "%s;%d;%d\n", tmp->nome, tmp->emprestado, tmp->alunoRA);
		tmp = tmp->proximo;
	}

	fclose(arq_ptr);

	printf("Livros salvos com sucesso!\n");
}

// função que exibe a mensagem e faz o sistema ficar parado para alguma tecla ser apertada
void pause()
{
	printf("Pressione enter para voltar ao menu...");
	getch(); //funcao q lÃª um caracter, ou seja, faz o sistema esperar o usuario apertar alguma tecla
	fflush(stdin); /* limpa o buffer do teclado (tira o \n do buffer, evitando erro na proxima vez que
					  for feita alguma leitura do teclado*/
}

// funcao que libera a memoria de todos os nos criados para as listas de livros e alunos
void liberarMemoria(noLivro *listaLivros, noAluno *listaAlunos)
{
	// utiliza um ponteiro para ver o primeiro no da lista de livros
	noLivro *livros = listaLivros->proximo;

	// executa a repetição para chegar no fim da lista
	while(livros != NULL)
	{
		noLivro *tmp = livros; // cria um ponteiro auxiliar apontando para o nos atual
		livros = livros->proximo; // muda o valor do ponteiro para o proximo no da lista
		free(tmp); // libera a memoria alocada para o no salvo no ponteiro tmp
	}

	// o processo anteriormente descrito é identico para a lista de alunos
	noAluno *alunos = listaAlunos->proximo;

	while(alunos != NULL)
	{
		noAluno *tmp = alunos;
		alunos = alunos->proximo;
		free(tmp);
	}
}


// funcao main, aqui q o codigo comeca a execucao
int main()
{
	// funcao para usar acentos nos printf
	setlocale(LC_ALL, "portuguese");

	noLivro *listaLivros = (noLivro *) malloc(sizeof(noLivro));
	iniciaListaLivro(listaLivros);

	noAluno *listaAlunos = (noAluno *) malloc(sizeof(noAluno));
	iniciaListaAluno(listaAlunos);

	lerTxtLivros(listaLivros);
	lerTxtAlunos(listaAlunos);

	int operacao;

	do{

		printf("---------MENU---------\n\n");
		printf("1 --> Incluir Livro\n");
		printf("2 --> Excluir Livro\n");
		printf("3 --> Emprestar Livro\n");
		printf("4 --> Devolver Livro\n");
		printf("5 --> Listar Livros\n");
		printf("6 --> Salvar Livros\n");
		printf("7 --> Listar Alunos\n");
		printf("8 --> Mostrar Empréstimos\n");
		printf("9 --> Sair\n\n");
		printf("Insira a operação desejada:\n");

		scanf("%d", &operacao);
		fflush(stdin);

		system("cls");

		switch(operacao)
		{
			case 1:
				addLivro(listaLivros);
				pause();
				break;
			case 2:
				excluirLivro(listaLivros);
				pause();
				break;
			case 3:
				emprestarLivro(listaLivros, listaAlunos);
				pause();
				break;
			case 4:
				devolverLivro(listaLivros);
				pause();
				break;
			case 5:
				mostrarLivros(listaLivros);
				pause();
				break;
			case 6:
				salvarLivros(listaLivros);
				pause();
				break;
			case 7:
				mostrarAlunos(listaAlunos);
				pause();
				break;
			case 8:
				mostrarEmprestimo(listaLivros, listaAlunos);
				pause();
				break;
			case 9:
				liberarMemoria(listaLivros, listaAlunos);
				break;
			default:
				printf("Operação inválida, escolha outra!\n");
				pause();
				break;
		}

		system("cls"); // funcao para limpar a tela
	}while (operacao != 9);

	return 0;
}
