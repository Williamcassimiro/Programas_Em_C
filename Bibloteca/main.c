#include <stdio.h>
#include <stdlib.h>
#include <string.h> // incluir biblioteca para manipular strings
#include <locale.h> // incluir biblioteca para pode usar acentuação nos textos
#include <unistd.h> // incluir biblioteca para poder limpar a tela sempre que necessário

// declaração da struct nó livro
struct NodeLivro
{
	char nome[50];
	int alunoRA;
	int emprestado;
	struct NodeLivro *proximo;
};
typedef struct NodeLivro nodeLivro; // definindo a struct NodeLivro como nodeLivro
									// isso facilita a criação de novos nós

// função que inicia a lista de livros, declarando o primeiro elemento como NULL
// recebe a lista de livros como parâmetro 
void iniciaListaLivro(nodeLivro *lista){
	lista->proximo = NULL;
}

// funçao que retorna 1 se a lista de livros estiver vazia ou 0 se a lista tiver pelo menos um elemento
int listaLivrosVazia(nodeLivro *livrosList){
	if (livrosList->proximo == NULL){
		return 1;
	}else{
		return 0;
	}
}

// declaracao da struct nó Aluno
struct NodeAluno
{
	char nome[20];
	int ra;
	int semestre;
	char curso[25];
	struct NodeAluno *proximo;
};
typedef struct NodeAluno nodeAluno; // definindo a struct NodeLivro como nodeLivro
									// isso facilita a criação de novos nós

// função que inicia a lista de alunos, declarando o primeiro elemento como NULL
// recebe a lista de alunos como parâmetro
void iniciaListaAluno(nodeAluno *lista){
	lista->proximo = NULL;
}

// funçao que retorna 1 se a lista de alunos estiver vazia ou 0 se a lista tiver pelo menos um elemento
int listaAlunosVazia(nodeAluno *alunosList){
	if (alunosList->proximo == NULL){
		return 1;
	}else{
		return 0;
	}
}

// função que procura um RA na lista de alunos.
// retorna 1 se encontrar algum aluno com o RA informado e 0 se nao encontrar
int verificarRA(nodeAluno *alunosList, int ra){
	nodeAluno *aux = alunosList->proximo;
	
	while(aux != NULL){
		if(aux->ra == ra){
			return 1;
		}
		aux = aux->proximo;
	}
	
	return 0;
}

// função que exibe a mensagem e faz o sistema ficar parado até alguma tecla ser apertada
void pause(){
	printf("Pressione enter para voltar ao menu...");
	getch(); //funcao q lê um caracter, ou seja, faz o sistema esperar o usuario apertar alguma tecla
	fflush(stdin); /* limpa o buffer do teclado (tira o \n do buffer, evitando erro na proxima vez que
					  for feita alguma leitura do teclado*/
}

// funcao que libera a memória de todos os nós criados para as listas de livros e alunos
void liberarMemoria(nodeLivro *livrosList, nodeAluno *alunosList){
	// utiliza um ponteiro para ver o primeiro nó da lista de livros
	nodeLivro *livros = livrosList->proximo;
	
	// executa a repeticão até chegar no fim da lista
	while(livros != NULL)
	{
		nodeLivro *aux = livros; // cria um ponteiro auxiliar apontando para o nó atual
		livros = livros->proximo; // muda o valor do ponteiro para o proximo nó da lista
		free(aux); // libera a memória alocada para o nó salvo no ponteiro aux
	}
	
	// o processo anteriormente descrito é identico para a lista de alunos
	nodeAluno *alunos = alunosList->proximo;
	
	while(alunos != NULL)
	{
		nodeAluno *aux = alunos;
		alunos = alunos->proximo;
		free(aux);
	}
}

// função que exibe informações de todos os livros salvos na lista encadeada
void mostrarLivros(nodeLivro *livrosList){
	
	// verifica se a lista é vazia
	if(listaLivrosVazia(livrosList)){
		printf("Lista de livros está vazia!!!\n");
		return; // se a lista for vazia, vai imprimir a mensagem acima e finalizar a função "mostrarLivros"
				// por causa desse "return;"
	}
	
	// para percorrer todos os nós da lista é necessário criar um ponteiro auxiliar que aponta para 
	// o primeiro elemento da lista (primeiro elemento da lista = livrosList->proximo)
	nodeLivro *aux;
	aux = livrosList->proximo;
	
	// o laço se repete enquanto o ponteiro auxiliar for diferente de nulo
	while(aux != NULL){
		// dentro do laço todas as informações são printadas na tela
		printf("Título do Livro: %s  -  ", aux->nome);
		
		if(aux->emprestado == 0){
			printf("Status: Disponível  -  ");
		}else{
			printf("Status: Emprestado  -  ");
		}
		
		printf("Emprestado para: %d\n", aux->alunoRA);
		
		// o valor do ponteiro auxiliar é alterado para ser igual ao proximo elemento da lista
		// o ultimo elemento da lista aponta o proximo elemento para NULL, fazendo o laço finalizar
		aux = aux->proximo;
	}
}

// funcao que mostra todos os alunos, segue a mesma ideia da que mostra todos os livros
void mostrarAlunos(nodeAluno *alunosList){
	if(listaAlunosVazia(alunosList)){
		printf("Lista de alunos está vazia!!!\n");
		return;
	}
	
	nodeAluno *aux;
	aux = alunosList->proximo;
	
	while(aux != NULL){
		printf("Nome do Aluno: %s  -  ", aux->nome);
		printf("RA: %d  -  ", aux->ra);
		printf("Curso: %s  -  ", aux->curso);
		printf("Semestre: %d\n", aux->semestre);
		
		
		aux = aux->proximo;
	}
}

// funcao para adicionar um novo livro na lista
void addLivro(nodeLivro *livrosList){
	// é alocada memória para o novo nó
	nodeLivro *novoLivro = (nodeLivro *) malloc(sizeof(nodeLivro));
	
	printf("Insira o nome do livro:\n");
	fflush(stdin);
	
	gets(novoLivro->nome);
	fflush(stdin);
	
	novoLivro->alunoRA = 0;

	novoLivro->emprestado = 0;
	
	nodeLivro *aux = livrosList->proximo; // cria uma variavel auxiliar que aponta para o primeiro elemento da lista
	livrosList->proximo = novoLivro; // muda o primeiro elemento da lista para o novo nó recem criado
	novoLivro->proximo = aux; // faz o novo nó apontar para o antigo primeiro elemento da lista
	
	printf("Incluido com sucesso!\n");
}

// funcao que exclui da lista um livro informado pelo usuario
void excluirLivro(nodeLivro *livrosList){
	
	char nome[20];
	
	printf("Insira o nome do livro que deseja excluir:\n");
	gets(nome);
	fflush(stdin);
	
	nodeLivro *aux = livrosList;
	
	// laço de repetição usado para procurar o livro informado pelo usuario
	while(aux->proximo != NULL){
		
		// comando if verificando se encontra um nome de livro correspondente ao que o usuario digitou
		if(strcmp(nome, aux->proximo->nome) == 0){
			
			nodeLivro *apagado = aux->proximo;
			aux->proximo = aux->proximo->proximo;
			free(apagado); // liberando a memória do nó apagado
			printf("Livro apagado com sucesso!!\n");
			return; // finaliza a funcao pois o livro foi encontrado e apagado
		}
		aux = aux->proximo;
	}
	
	// se o programa passar pelo while sem entrar no if significa que o livro informado nao existe na lista
	printf("Não foi encontrado nenhum livro com o nome informado!\n");
}

// função que mostra os livros emprestados por um determinado aluno
void mostrarEmprestimo(nodeLivro *livrosList, nodeAluno *alunosList){
	int ra;
	printf("Informe o RA do aluno:\n");
	scanf("%d", &ra);
	fflush(stdin);
	
	// verifica se o RA informado exite na lista de alunos, se nao existir finaliza a funçao
	if(!verificarRA(alunosList, ra)){
		printf("O RA informado não está cadastrado no sistema!\n");
		return;
	}
	
	printf("Livros emprestados pelo aluno:\n");
	
	// percorre toda a lista de livros imprimindo os que estao emprestados para o RA informado
	nodeLivro *aux = livrosList->proximo;
	while(aux != NULL)
	{
		if(aux->alunoRA == ra){
			printf("%s\n", aux->nome);
		}
		
		aux = aux->proximo;
	}
}

// funcao que realiza o emprestimo de um livro
void emprestarLivro(nodeLivro *livrosList, nodeAluno *alunosList){
	// verifica se existe algum livro cadastrado para ser emprestado
	if(listaLivrosVazia(livrosList)){
		printf("Não há livros cadastrados para serem emprestados!\n");
		return;
	}
	
	char nome[50];
	int achou = 0;
	
	printf("Insira o nome do livro que deseja emprestar:\n");
	gets(nome);
	fflush(stdin);
	
	nodeLivro *aux = livrosList->proximo;
	
	// laco de repeticao procurando pelo livro informado
	// se achar o livro, verifica se ele já está emprestado
	while(aux != NULL){
		
		if(strcmp(nome, aux->nome) == 0){
			achou = 1;
			if(aux->emprestado == 1){
		   		printf("O livro já está emprestado!\n");
				return;
			}
			break;
		}
		
		aux = aux->proximo;
	}
	
	if(achou == 0){
		printf("Livro não encontrado no acervo!\n");
		return;
	}
	
	// pede e valida o RA do aluno que deseja emprestar o livro
	do{
		printf("Informe o RA do aluno que está emprestando o livro:\n");
		scanf("%d", &aux->alunoRA);
		
		if(aux->alunoRA == 0){
			printf("O RA deve ser diferente de 0 (zero)!!\n");
		}else{
			if(!verificarRA(alunosList, aux->alunoRA)){
				printf("O RA informado não está cadastrado!\n");
				aux->alunoRA = 0;
			}
		}
	}while(aux->alunoRA == 0);
	
	// atualiza o status de emprestimo do livro
	aux->emprestado = 1;
	
	printf("Empréstimo realizado com sucesso!!\n");
}

// funcao que faz a devolucao de um livro
void devolverLivro(nodeLivro *livrosList){
	char nome[50];
	
	printf("Informe o nome do exemplar que deseja fazer devolução:\n");
	gets(nome);
	fflush(stdin);
	
	nodeLivro *aux = livrosList->proximo;
	// repeticao que procura o livro, verifica se ele esta emprestado
	// e faz a devolucao caso esteja
	while(aux != NULL){
		
		if(strcmp(nome, aux->nome) == 0){
			if(aux->emprestado == 0){
				printf("O livro não estava emprestado!\n");
				return;
			}
			aux->alunoRA = 0;
			aux->emprestado = 0;
			printf("Devolução realizada com suecsso!\n");
			return;
		}
		aux = aux->proximo;
	}
	
	printf("Livro não encontrado no acervo!\n");	
}

// funcao fodida pra ler os livros do txt
void lerTxtLivros(nodeLivro *livrosList){
	FILE *arq;
	char linha[80];
	char c;
		
	arq = fopen("livros.txt", "r");
	
	if(arq == NULL){
		printf("ERRO! O arquivo não foi aberto!\n");
		return;
	}
	
	// usa o fgets para ler uma linha inteira de uma vez
	// depois, para cada linha lida, é criado um novo nó de livro
	// e percorrido caracter por caracter da linha para ler os valores entre ';' e
	// salvar no nó
	while(fgets(linha, 80, arq) != NULL){
		
		nodeLivro *novo = (nodeLivro *) malloc(sizeof(nodeLivro));
		int pos = 0, base = 0;
		char nome[50], emprestado[2], alunoRA[10];
		
		do{
			c = linha[pos];
    		
    		if(c != ';'){
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
			
			if(c != '\n' && c != EOF){
				alunoRA[pos-base] = c;
			}
			
			pos++;
		}while(c != '\n' && c != EOF);
		
		alunoRA[pos-base-1] = '\0';
		novo->alunoRA = atoi(alunoRA);
		
		nodeLivro *aux = livrosList->proximo;
		livrosList->proximo = novo;
		novo->proximo = aux;
	}
	
	// fecha o arquivo
	fclose(arq);
}

// funcao pra ler os alunos no arquivo txt
// funciona igual ao de ler os livros, so um pouco mais comprida
void lerTxtAlunos(nodeAluno *alunosList){
	FILE *arq;
	char linha[80];
	char c;
		
	arq = fopen("alunos.txt", "r");
	
	if(arq == NULL){
		printf("ERRO! O arquivo não foi aberto!\n");
		return;
	}
	
	while(fgets(linha, 80, arq) != NULL){
		
		nodeAluno *novo = (nodeAluno *) malloc(sizeof(nodeAluno));
		int pos = 0, base = 0;
		char nome[50], semestre[10], alunoRA[15], curso[25];
		
		do{
			c = linha[pos];
    		
    		if(c != ';'){
				nome[pos] = c;
			}
			
			pos++;
		}while (c != ';');
		
		nome[pos-1] = '\0';
		strcpy(novo->nome, nome);
		
		base = pos;
		
		do{
			c = linha[pos];
			
			if(c != ';'){
				alunoRA[pos-base] = c;
			}
			
			pos++;
		}while(c != ';');
		
		alunoRA[pos-base-1] = '\0';
		novo->ra = atoi(alunoRA);
		
		base = pos;
		
		do{
			c = linha[pos];
			
			if(c != ';'){
				semestre[pos-base] = c;
			}
			
			pos++;
		}while(c != ';');
		
		semestre[pos-base-1] = '\0';
		novo->semestre = atoi(semestre);
		
		base = pos;
		
		do{
			c = linha[pos];
			
			if(c != '\n' && c != EOF){
				curso[pos-base] = c;
			}
			
			pos++;
		}while(c != '\n' && c != EOF);
		
		curso[pos-base-1] = '\0';
		strcpy(novo->curso, curso);
		
		nodeAluno *aux = alunosList->proximo;
		alunosList->proximo = novo;
		novo->proximo = aux;
	}
	
	fclose(arq);
}

// funcao q sobrescreve o arquivo txt de livros, salvando todas as altercoes nos livros cadastrados
// cada linha do txt se refere a um cadastro e todos os atributos estao separados por ';', como no
// exemplo do professor
void salvarLivros(nodeLivro *livrosList){
	FILE *arq;
		
	arq = fopen("livros.txt", "w");
		
	if(arq == NULL){
		printf("ERRO! O arquivo não foi aberto!\n");
		return;
	}
	
	nodeLivro *aux = livrosList->proximo;
	
	while(aux != NULL)
	{
		fprintf(arq, "%s;%d;%d\n", aux->nome, aux->emprestado, aux->alunoRA);
		aux = aux->proximo;
	}
	
	fclose(arq);
	
	printf("Livros salvos com sucesso!\n");
}

// funcao main, aqui q o codigo comeca a execucao
int main()
{
	// funcao para usar acentos nos printf
	setlocale(LC_ALL, "portuguese");
	
	nodeLivro *livrosList;
	livrosList = (nodeLivro *) malloc(sizeof(nodeLivro));
	iniciaListaLivro(livrosList);
	
	nodeAluno *alunosList;
	alunosList = (nodeAluno *) malloc(sizeof(nodeAluno));
	iniciaListaAluno(alunosList);
	
	lerTxtLivros(livrosList);
	lerTxtAlunos(alunosList);

	int opcao;

	do{
		system("cls"); // funcao para limpar a tela
	
		printf("Menu:\n");
		printf("1 - Incluir Livro\n");
		printf("2 - Excluir Livro\n");
		printf("3 - Emprestar Livro\n");
		printf("4 - Devolver Livro\n");
		printf("5 - Listar Livros\n");
		printf("6 - Salvar Livros\n");
		printf("7 - Listar Alunos\n");
		printf("8 - Mostrar Empréstimo\n");
		printf("9 - Sair\n\n");
		printf("Insira sua opção:\n");
		
		scanf("%d", &opcao);
		fflush(stdin);
		
		system("cls");

		switch(opcao){
			case 1:
				addLivro(livrosList);
				pause();
				break;
			case 2:
				excluirLivro(livrosList);
				pause();
				break;
			case 3:
				emprestarLivro(livrosList, alunosList);
				pause();
				break;
			case 4:
				devolverLivro(livrosList);
				pause();
				break;
			case 5:
				mostrarLivros(livrosList);
				pause();
				break;
			case 6:
				salvarLivros(livrosList);
				pause();
				break;
			case 7:
				mostrarAlunos(alunosList);
				pause();
				break;
			case 8:
				mostrarEmprestimo(livrosList, alunosList);
				pause();
				break;
			case 9:
				liberarMemoria(livrosList, alunosList);
				break;
			default:
				printf("Opção inválida, escolha outra!\n");
				pause();
				break;
		}
			
	}while (opcao != 9);

	return 0;
}