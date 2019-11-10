
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct tdata{
	
	int dia;
	int mes;
	int ano;
	
}TData;

typedef struct tendereco{
	
	char rua [50];
	int num;
	char complemento[10];
	char bairro[50];
	char cidade[50];
	char CEP[11];
	
}TEndereco;

typedef struct tlivro{
	
	char ISBN [13];
	char titulo [50];
	char editora [20];
	char localpublicacao [50];
	TData data;
	char autores [50];
	int nedicao;
	int livorsexistentes;
	int livrosemprestados;
	
}TLivro;

typedef struct user{
	
	char nome[50];
	char sobrenome[50];
	char RG[9];
	TData data;
	TEndereco endereco;
	char CPF[14];
	int tipo; // 1 -> professor, 2-> aluno, 3-> funcion�rio
	char matricula [15];
	char curso[50];
	char SIAPE [15];
	char departamento[10];
	int qtdeLivros;
	int multa = 0;
	
}TUsuario;

typedef struct temprestimo{
	
	char CPF[14];
	char ISBN [13];
	TData emprestimo;
	TData devolucao;
	TData entrega;
	
}TEmprestimo;

typedef struct moduloUsuario{
	
	TUsuario vetor [100];
	int indice;
	
}TModuloUsuario;

typedef struct moduloLivro{
	
	TLivro vetor [100];
	int indice;
	
}TModuloLivro;

typedef struct moduloEmprestimo{
	
	TEmprestimo vetor[100];
	int indice;
	
}TModuloEmprestimo;

void LerUsuario(TUsuario *user){
	
	printf("\n NOME: ");
	fflush(stdin);
	fgets(user->nome, 50, stdin);
	
	printf("\n SOBRENOME: ");
	fflush(stdin);
	fgets(user->sobrenome, 50, stdin);
	
	printf("\n INFORME O DIA DE NASCIMENTO: ");
	fflush(stdin);
	scanf("%d", &user->data.dia);
	
	printf("\n INFORME O MES DE NASCIMENTO: ");
	fflush(stdin);
	scanf("%d", &user->data.mes);
	
	printf("\n INFORME O ANO DE NASCIMENTO: ");
	fflush(stdin);
	scanf("%d", &user->data.ano);
	
	printf("\n CIDADE: ");
	fflush(stdin);
	fgets(user->endereco.cidade, 50, stdin);
	
	printf("\n BAIRRO: ");
	fflush(stdin);
	fgets(user->endereco.bairro, 50, stdin);
	
	printf("\n CEP: ");
	fflush(stdin);
	fgets(user->endereco.CEP, 11, stdin);
	
	printf("\n RUA: ");
	fflush(stdin);
	fgets(user->endereco.rua, 50, stdin);
	
	printf("\n NUMERO: ");
	fflush(stdin);
	scanf("%d", &user->endereco.num);
	
	printf("\n COMPLEMENTO: ");
	fflush(stdin);
	fgets(user->endereco.complemento, 10, stdin);
	
	printf("\n CPF: ");
	fflush(stdin);
	fgets(user->CPF, 14, stdin);
	
	do{
		printf("\n INFORME O TIPO: 1 - PROFESSOR || 2 - ALUNO  || 3 FUNCIONARIO: ");
		fflush(stdin);
		scanf("%d", &user->tipo);
		if(user->tipo <= 0 && user->tipo > 3){
			printf("NAO EXISTE ESSE TIPO DE USUARIO!! \nPREENCHA NOVAMENTE!!!");
		}
	}while(user->tipo <= 0 && user->tipo > 3);
	
	if(user->tipo <= 3 && user->tipo > 0){
		
		if(user->tipo == 2){
		printf("\n NOME DO CURSO: ");
		fflush(stdin);
		fgets(user->curso, 50, stdin);
		
		printf("\n MATRICULA: ");
		fflush(stdin);
		fgets(user->matricula, 15, stdin);
		}
		
		else{
			
			printf("\n SIAPE: ");
			fflush(stdin);
			fgets(user->SIAPE, 15, stdin);
	
			printf("\n DEPARTAMENTO: ");
			fflush(stdin);
			fgets(user->departamento, 10, stdin);	
		}
	}
	
	
}

void LerLivro(TLivro *livro){
	
	printf("\n INFORME O TITULO: ");
	fflush(stdin);
	fgets(livro->titulo, 50, stdin);
	
	printf("\n INFORME OS AUTORES: ");
	fflush(stdin);
	fgets(livro->autores, 50, stdin);
	
	printf("\n INFORME O ISBN: ");
	fflush(stdin);
	fgets(livro->ISBN, 13, stdin);
	
	printf("\n INFORME A EDITORA: ");
	fflush(stdin);
	fgets(livro->editora, 20, stdin);
	
	printf("\n INFORME O DIA DE PUBLICACAO: ");
	fflush(stdin);
	scanf("%d", &livro->data.dia);
	
	printf("\n INFORME O MES DE PUBLICACAO: ");
	fflush(stdin);
	scanf("%d", &livro->data.mes);
	
	printf("\n INFORME O ANO DE PUBLICACAO: ");
	fflush(stdin);
	scanf("%d", &livro->data.ano);
	
	printf("\n INFORME O LOCAL DA PUBLICACAO: ");
	fflush(stdin);	
	fgets(livro->localpublicacao, 50, stdin);
	
	printf("\n INFORME O NUMERO DE EDICAO: ");
	fflush(stdin);
	scanf("%d", &livro->nedicao);
	
	printf("\n INFORME O NUMERO DE LIVROS EXISTENTES: ");
	fflush(stdin);
	scanf("%d", &livro->livorsexistentes);
	
}

void LerEmprestimo(TEmprestimo *emprestimo){
	
	printf("\n INFORME SEU CPF: ");
	fflush(stdin);
	fgets(emprestimo->CPF, 14, stdin);
	
	printf("\n INFORME O ISBN DO LIVRO: ");
	fflush(stdin);
	fgets(emprestimo->ISBN, 13, stdin);
	
	printf("\n INFORME O DIA DA REALIZACAO DO EMPRESTIMO: ");
	scanf("%d", &emprestimo->emprestimo.dia);
	printf("\n INFORME O MES DA REALIZACAO DO EMPRESTIMO: ");
	scanf("%d", &emprestimo->emprestimo.mes);
	printf("\n INFORME O ANO DA REALIZACAO DO EMPRESTIMO: ");
	scanf("%d", &emprestimo->emprestimo.ano);
	
}

void ImprimirUsuario(TUsuario user){
	
	
	printf("\n\n NOME: %s ", user.nome);
	printf("\n\n SOBRENOME: %s ", user.sobrenome);
	printf("\n\n RG: %s ", user.RG);
	printf("\n\n DATA DE NASCIMENTO %d %d %d: ", user.data.ano, user.data.mes, user.data.dia);
	printf("\n\n CIDADE: %s ", user.endereco.cidade);
	printf("\n\n BAIRRO: %s ", user.endereco.bairro);
	printf("\n\n RUA: %s ", user.endereco.rua);
	printf("\n\n CEP: %s ", user.endereco.CEP);
	printf("\n\n NUM: %d ", user.endereco.num);
	printf("\n\n COMPLEMENTO: %s ", user.endereco.complemento);
	printf("\n\n QTDE DE LIVROS ADQUIRIDOS: %d", user.qtdeLivros);
	printf("\n\n CPF: %s ", user.CPF);
	printf("\n\n MULTA: %d ", user.multa);
	if(user.tipo == 2){
		printf("\n NOME DO CURSO %s ", user.curso);
		printf("\n MATRICULA %s ", user.matricula);	
		
	}	
	else{
		printf("\n SIAPE %s ", user.SIAPE);
		printf("\n DEPARTAMENTO %s ", user.departamento);
			
	}
	
}

void ImprimirLivro(TLivro book){
	
	printf("\n ISBN DO LIVRO %s ", book.ISBN);
	printf("\n TITULO DO LIVRO %s ", book.titulo);
	printf("\n EDITORA %s ", book.editora);
	printf("\n LOCAL DA PUBLICACAO %s ", book.localpublicacao);
	printf("\n DATA DE PUBLICACAO %d %d %d ", book.data.ano, book.data.mes, book.data.dia);
	printf("\n AUTORES %s ", book.autores);
	printf("\n NUMERO DA EDCIAO %d ", book.nedicao);
	printf("\n LIVROS EXISTENTES %d", book.livorsexistentes);
	printf("\n LIVROS EMPRESTADOS %d ", book.livrosemprestados);
		
}

void ImprimirEmprestimo(TEmprestimo emprestimo){
	
	printf("\n CPF DO USUARIO %s ", emprestimo.CPF);
	printf("\n ISBN DO LIVRO %s ", emprestimo.ISBN);
	printf("\n DATA DE EMPRESTIMO %d %d% d ", emprestimo.emprestimo.dia, emprestimo.emprestimo.mes, emprestimo.emprestimo.ano);
	printf("\n DATA DE DEVOLUCAO %d %d %d ", emprestimo.entrega.dia, emprestimo.entrega.mes, emprestimo.entrega.ano);
	
}

void IniciarModuloUsuario(TModuloUsuario *modulo){
	
	modulo->indice = 0;
		
}
void IniciarModuloLivro(TModuloLivro *modulo){
	
	modulo->indice = 0;
			
}

void IniciarModuloEmprestimo(TModuloEmprestimo *modulo){
	
	modulo->indice = 0;
			
}

void InserirUsuario(TModuloUsuario *modulo, TUsuario user){
	
	modulo->vetor[modulo->indice] = user;
	modulo->indice ++;
	
}

void InserirLivro(TModuloLivro *modulo, TLivro livro){
	
	modulo->vetor[modulo->indice] = livro;
	modulo->indice ++;
	
}

void InserirEmprestimo(TModuloEmprestimo *modulo, TEmprestimo emprestimo){
	
	modulo->vetor[modulo->indice] = emprestimo;
	modulo->indice ++;
	
	printf("\n EMPRESTIMO REALIZADO COM SUCESSO!! ");

}

int PesquisarUsuario(TModuloUsuario modulo, TUsuario user){
	
	int i;
	
	for(i=0; i<modulo.indice; i++){
		
		if(strcmp(user.CPF, modulo.vetor[i].CPF) == 0){
			printf("\n USUARIO ENCONTRADO!\n");
			return i;
		}
			
	}
	
	return -1;		
}	

int PesquisarLivro(TModuloLivro modulo, TLivro livro){
	
	int i;
	
	for(i=0; i<modulo.indice; i++){
		
		if(strcmp(livro.ISBN, modulo.vetor[i].ISBN) == 0){
			printf("\n LIVRO ENCONTRADO!\n ");
			return i;
		}
	}
	
	return -1;
}

int PesquisarEmprestimo(TModuloEmprestimo modulo, TEmprestimo emprestimo){
	
	int i;
	
	for(i=0; i<modulo.indice; i++){
		
		if(strcmp(emprestimo.ISBN, modulo.vetor[i].ISBN) == 0 && strcmp(emprestimo.CPF, modulo.vetor[i].CPF) == 0){
			if(emprestimo.emprestimo.ano == modulo.vetor[i].emprestimo.ano && emprestimo.emprestimo.mes == modulo.vetor[i].emprestimo.mes && emprestimo.emprestimo.dia == modulo.vetor[i].emprestimo.dia){
				printf("\n EMPRESTIMO ENCONTRADO!\n ");
				return i;	
			}
		}
				
	}
	
	return -1;
	
}

void AlterarUsuario(TModuloUsuario *modulo, TUsuario user){
	
	int indice;
	
	indice = PesquisarUsuario(*modulo, user);
	
	if(indice!= -1){
		printf("\n FACA AS ALTERACOES DESEJADAS: ");
		LerUsuario(&modulo->vetor[indice]);	
		printf("\nALTERACOES REALIZADAS COM SUCESSO");
	}
	else{
		printf("\n USUARIO NAO ENCONTRADO");
	}
			
}

void AlterarLivro(TModuloLivro *modulo, TLivro livro){
	
	int indice;
	
	indice = PesquisarLivro(*modulo, livro);
	
	if(indice!= -1){
		printf("\n FACA AS ALTERACOES DESEJADAS: ");
		LerLivro(&modulo->vetor[indice]);
		printf("\n LIVRO ALTERADO COM SUCESSO!");	
	}
	else{
		printf("\n LIVRO NAO ENCONTRADO");
	}
	
}


void AlterarEmprestimo(TModuloEmprestimo *modulo, TEmprestimo emprestimo){
	
	int indice;
	
	indice = PesquisarEmprestimo(*modulo, emprestimo);
	
	if(indice!= -1){
		
		printf("\n FACA AS ALTERACOES DESEJADAS: ");
		LerEmprestimo(&modulo->vetor[indice]);
		printf("\n EMPRESTIMO ALTERADO COM SUCESSO!");	
	
	}
	else{
		printf("\n EMPRESTIMO NAO ENCONTRADO");
	}
}

void ExcluirUsuario(TModuloUsuario *modulo, TUsuario user){
	
	int i, indice;
	
	
	indice = PesquisarUsuario(*modulo, user);
	
	if(indice != -1){
		
		for(i=indice; i<modulo->indice; i++){
		
			modulo->vetor[i] = modulo->vetor[i + 1 ];	
		}
		modulo->indice --;
		printf("\nUSUARIO EXCLUIDO COM SUCESSO! ");	

	}
		
		
}

void ExcluirLivro(TModuloLivro *modulo, TLivro livro){
	
	int i, indice;
	
	indice = PesquisarLivro(*modulo, livro);
	
	if(indice != -1){
		
		for(i=indice; i<modulo->indice; i++){
		
			modulo->vetor[i] = modulo->vetor[i + 1 ];	
		}
		modulo->indice --;
		printf("\nLIVRO EXCLUIDO COM SUCESSO! ");	

	}
}

void ExcluirEmprestimo(TModuloEmprestimo *modulo, TEmprestimo emprestimo){
	
	int i, indice;
	
	indice = PesquisarEmprestimo(*modulo, emprestimo);
	
	if(indice != -1){
		
		for(i=indice; i<modulo->indice; i++){
		
			modulo->vetor[i] = modulo->vetor[i + 1 ];	
		}
		modulo->indice --;
		printf("\nEMPRESTIMO EXCLUIDO COM SUCESSO! ");	

	}

}

void ImprimirTodosUsuarios(TModuloUsuario modulo){
	
	int i;
	
	for(i=0; i<modulo.indice; i++){
		
		ImprimirUsuario(modulo.vetor[i]);
	}
}

void ImprimirTodosLivros(TModuloLivro modulo){
	
	int i;
	
	for(i=0; i<modulo.indice; i++){
	
		ImprimirLivro(modulo.vetor[i]);
	}
}

void ImprimirTodosEmprestimos(TModuloEmprestimo modulo){
	
	int i;
	
	for(i=0; i<modulo.indice; i++){
		
		ImprimirEmprestimo(modulo.vetor[i]);
	}
}

void MSG_MENU(){
	
	printf("\n>>>>>>>>>>>>>> MENU: <<<<<<<<<<<<<<");
	printf("\n\n 1. MODULO 1 - LIVRO");
	printf("\n\n 2. MODULO 2 - USUARIO");
	printf("\n\n 3. MODULO 3 - EMPRESIMO");
	printf("\n\n 4. MODULO 4 - SAIR");
	
}

void MSG_SUBMENU(int numero_modulo){
	
	system("cls");
	
	if(numero_modulo == 3){
		printf("\n>>>>>>>>>>> MODULO %d: <<<<<<<<<<<<<<<", numero_modulo);
		printf("\n 1 - INSERIR");
		printf("\n 2 - PESQUISAR");
		printf("\n 3 - ALTERAR");
		printf("\n 4 - EXCLUIR");
		printf("\n 5 - DAR BAIXA NO EMPRESTIMO");
		printf("\n 6 - EFETUAR PAGAMENTO");
		printf("\n 7 - IMPRIMIR TODOS");
		printf("\n 8 - SAIR: ");
	}
	else{
		printf("\n>>>>>>>>>>> MODULO %d: <<<<<<<<<<<<<<<", numero_modulo);
		printf("\n 1 - INSERIR");
		printf("\n 2 - PESQUISAR");
		printf("\n 3 - ALTERAR");
		printf("\n 4 - EXCLUIR");
		printf("\n 5 - IMPRIMIR TODOS");
		printf("\n 6 - SAIR");	
	}
}

void SubMenuLivro(TModuloLivro *modulo, TLivro livro){
	
	int opcao = 0, indice;
	IniciarModuloLivro(modulo);
	
	do{
		MSG_SUBMENU(1);
		printf("\nDIGITE UMA OPCAO: ");
		fflush(stdin);
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:
				//INSERIR
				LerLivro(&livro);
				InserirLivro(modulo, livro);
				system("PAUSE");
				break;
				
			case 2:
				//PESQUISAR
				printf("INFORME O ISBN QUE DESEJA PESQUISAR: ");
				fflush(stdin);
				fgets(livro.ISBN, 13, stdin);
				indice = PesquisarLivro(*modulo, livro);
				
				if(indice != -1){
					
					ImprimirLivro(modulo->vetor[indice]);
				}
				else{
					printf("\n LIVRO NAO ENCONTRADO");
				}
				system("PAUSE");	
				break;
			
			case 3:
				//ALTERAR
				printf("INFORME O ISBN QUE DESEJA ALTERAR: ");
				fflush(stdin);
				fgets(livro.ISBN, 13, stdin);
				indice = PesquisarLivro(*modulo, livro);
				
				if(indice != -1){
					AlterarLivro(modulo, livro);
				}
				else{
					printf("\n LIVRO NAO ENCONTRADO");
				}
				system("PAUSE");	
				break;
		
			case 4:
				//EXCLUIR
				printf("INFORME O ISBN QUE DESEJA EXCLUIR: ");
				fflush(stdin);
				fgets(livro.ISBN, 13, stdin);
				indice = PesquisarLivro(*modulo, livro);
				
				if(indice != -1){
					ExcluirLivro(modulo, livro);
				}
				else{
					printf("\n LIVRO NAO ENCONTRADO");
				}
				system("PAUSE");	
				break;
				
			case 5:
				ImprimirTodosLivros(*modulo);
				system("PAUSE");
				break;	
		
			case 6:
				printf("\n SAINDO DO MODULO!");
				system("PAUSE");
				break;
			
			default:
				printf("\nDIGITE UMA OPCAO VALIDA!");
				system("PAUSE");
				
		}	
				
	}while(opcao != 6);
}

void SubMenuUsuario(TModuloUsuario *modulo, TUsuario usuario){
	
	
	int opcao = 0, indice;
	IniciarModuloUsuario(modulo);
	
	do{
		MSG_SUBMENU(2);
		printf("\nDIGITE UMA OPCAO: ");
		fflush(stdin);
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:
				//INSERIR
				LerUsuario(&usuario);
				InserirUsuario(modulo, usuario);
				system("PAUSE");
				break;
					
			case 2:
				//PESQUISAR
				printf("\nINFORME O CPF QUE DESEJA ENCONTRAR: ");
				fflush(stdin);
				fgets(usuario.CPF, 14, stdin);
				indice = PesquisarUsuario(*modulo, usuario);
				
				if(indice != -1){
	
					ImprimirUsuario(modulo->vetor[indice]);
				}
				else{
					printf("\nUSUARIO NAO ENCONTRADO! ");
				}
				system("PAUSE");
				break;
			
			case 3:
				//ALTERAR
				printf("\nINFORME O CPF QUE DESEJA ALTERAR: ");
				fflush(stdin);
				fgets(usuario.CPF, 14, stdin);
				indice = PesquisarUsuario(*modulo, usuario);
				
				if(indice != -1){
					
					AlterarUsuario(modulo, usuario);
				}
				else{
					printf("\nUSUARIO NAO ENCONTRADO! ");
				}
				system("PAUSE");
				break;
				
			case 4:
				//EXCLUIR
				printf("\nINFORME O CPF QUE DESEJA EXCLUIR: ");
				fflush(stdin);
				fgets(usuario.CPF, 14, stdin);
				indice = PesquisarUsuario(*modulo, usuario);
				
				if(indice != -1){
					    ExcluirUsuario(modulo, usuario);
				}
				else{
					printf("\nUSUARIO NAO ENCONTRADO! ");
				}
				system("PAUSE");
				break;
			
			case 5:
				
				ImprimirTodosUsuarios(*modulo);
				system("PAUSE");
				break;	
			
			case 6:
				printf("\n SAINDO DO MODULO!");
				system("PAUSE");
				break;
				
			default:
				printf("\nDIGITE UMA OPCAO VALIDA");	
				system("PAUSE");					
		}
	}while(opcao != 6);
	
}

int CalculoDiferencaDias(int mes, int limite, int diferencaDias){
	
	do{
		
		switch(mes){
			
			case 1 : 
				diferencaDias = 31 + diferencaDias;
				break;
			case 2:
				diferencaDias = 28 + diferencaDias;
				break;
			case 3:
				diferencaDias = 31 + diferencaDias;
				break;
			case 4:
				diferencaDias = 30 + diferencaDias;
				break;
			case 5:
				diferencaDias = 31 + diferencaDias;
				break;
			case 6:
				diferencaDias = 30 + diferencaDias;
				break;
			case 7:
				diferencaDias = 31 + diferencaDias;
				break;
			case 8:
				diferencaDias = 31 + diferencaDias;
				break;
			case 9:
				diferencaDias = 30 + diferencaDias;
				break;
			case 10:
				diferencaDias = 31 + diferencaDias;
				break;
			case 11:
				diferencaDias = 30 + diferencaDias;
				break;
			case 12:
				diferencaDias = 31 + diferencaDias;
				break;
		}
		mes++;
	}while(mes <= limite);
	
	return diferencaDias;
}

int CalcularAtraso(TEmprestimo emprestimo){
	
	int diferencaDias;
	
	if(emprestimo.devolucao.ano != emprestimo.entrega.ano){
		
		diferencaDias = emprestimo.devolucao.dia - emprestimo.entrega.dia;
		diferencaDias = CalculoDiferencaDias(emprestimo.entrega.mes, 12, diferencaDias);
		diferencaDias = CalculoDiferencaDias(1, emprestimo.devolucao.mes - 1, diferencaDias);
		diferencaDias = diferencaDias + (365 * (emprestimo.devolucao.ano - (emprestimo.entrega.ano + 1)));
	}
	else if(emprestimo.entrega.ano == emprestimo.devolucao.ano && emprestimo.entrega.mes != emprestimo.devolucao.mes){
		diferencaDias = emprestimo.devolucao.dia - emprestimo.entrega.dia;
		diferencaDias = CalculoDiferencaDias(emprestimo.entrega.mes, emprestimo.devolucao.mes -1 , diferencaDias);
	}
	else{
		diferencaDias = emprestimo.devolucao.dia - emprestimo.entrega.dia;
	}

	return diferencaDias;
	
}

TData CalcularDataEntrega(TData dataEmprestimo){
	
	TData dataEntrega;
	
	if(dataEmprestimo.mes == 2){
		
		if(dataEmprestimo.dia < 15){
			dataEntrega.dia = dataEmprestimo.dia + 14;
			dataEntrega.mes = dataEmprestimo.mes;
			dataEntrega.ano = dataEmprestimo.ano;
		}
		else{
			dataEntrega.dia = dataEmprestimo.dia - 14;
			dataEntrega.mes = dataEmprestimo.mes + 1;
			dataEntrega.ano = dataEmprestimo.ano;
		}	
	}
	
	else if(dataEmprestimo.mes == 1 || 3 || 5 || 7 || 8 || 10 || 12){
		
		if(dataEmprestimo.dia < 18){
			dataEntrega.dia = dataEmprestimo.dia + 14;
			dataEntrega.mes = dataEmprestimo.mes;
			dataEntrega.ano = dataEmprestimo.ano;	
		}
		else{
			
			if(dataEmprestimo.mes == 12){
				dataEntrega.dia = dataEmprestimo.dia - 17;
				dataEntrega.mes = 1;
				dataEntrega.ano = dataEmprestimo.ano + 1;
			}
			else{
				dataEntrega.dia = dataEmprestimo.dia - 17;
				dataEntrega.mes = dataEmprestimo.mes + 1;
				dataEntrega.ano = dataEmprestimo.ano;
			}		
		}
	}
	else{
		
		if(dataEmprestimo.dia < 17){
			dataEntrega.dia = dataEmprestimo.dia + 14;
			dataEntrega.mes = dataEmprestimo.mes;
			dataEntrega.ano = dataEmprestimo.ano;
		}
		else{
			dataEntrega.dia = dataEmprestimo.dia - 16;
			dataEntrega.mes = dataEmprestimo.mes + 1;
			dataEntrega.ano = dataEmprestimo.ano;
		}
	}	
	
	return dataEntrega;
}

void DarBaixaEmprestimo(TModuloEmprestimo *moduloE, TEmprestimo emprestimo, TModuloLivro *moduloL, TLivro livro, TModuloUsuario *moduloU, TUsuario usuario){
	
	int diferencaDias, indiceU, indiceL, opcao;
	
	diferencaDias = CalcularAtraso(emprestimo);
	
	if(diferencaDias > 0){
		
		indiceL = PesquisarLivro(*moduloL, livro);
		indiceU = PesquisarUsuario(*moduloU, usuario);
	
		if(indiceU != -1 && indiceL != -1){
			printf("TOTAL DE DIAS DE ATRASO %d: ", diferencaDias);
			moduloU->vetor[indiceU].multa = moduloU->vetor[indiceU].multa + (2 * diferencaDias);
			printf("\nDESEJA EFETUAR O PAGAMENTO NO VALOR DE = %.d reais? (1 - SIM | 2 - NAO): ", moduloU->vetor[indiceU].multa);
			fflush(stdin);
			scanf("%d", &opcao);
			if(opcao == 1){
				moduloU->vetor[indiceU].multa - (2 * diferencaDias);
				moduloU->vetor[indiceU].qtdeLivros -1;
				moduloL->vetor[indiceL].livrosemprestados - 1;
			}
			else{
				moduloL->vetor[indiceL].livrosemprestados - 1;
				moduloU->vetor[indiceU].qtdeLivros - 1;
				printf("\nMULTA ARQUIVADA! ");
			}
			
		}
		else{
			printf("\nUSUARIO OU LIVRO NAO ENCONTRADO! ");
		}
	}
	else{
		
		indiceL = PesquisarLivro(*moduloL, livro);
		if(indiceL != -1){
			moduloL->vetor[indiceL].livrosemprestados -1;
			moduloU->vetor[indiceU].qtdeLivros - 1;
			printf("\nBAIXA REALIZADA COM SUCESSO!");
		}
		else{
			printf("\nLIVRO NAO ENCONTRADO! ");
		}
		
	}
}

void EfetuarPagamento(TModuloEmprestimo *modulo, TEmprestimo emprestimo, TModuloLivro *moduloL, TLivro livro, TModuloUsuario *moduloU, TUsuario usuario){
	
	int indiceU, indiceL;
	
	
	indiceU = PesquisarUsuario(*moduloU, usuario);
	indiceL = PesquisarLivro(*moduloL, livro);
	
	if(indiceU != -1 && indiceL != -1){
		
		moduloU->vetor[indiceU].multa =  0;
		moduloL->vetor[indiceL].livrosemprestados - 1;
		printf("\nPAGAMENTO REALIZDO COM SUCESSO!");
	}
	else{
		printf("\nLIVRO OU USUARIO NAO ENCONTRADO! ");
	}
	
}

void SubMenuEmprestimo(TModuloEmprestimo *moduloE, TEmprestimo emprestimo, TModuloUsuario *moduloU, TUsuario usuario, TModuloLivro *moduloL, TLivro livro){
	
	int opcao = 0, indiceL, indiceU, indiceE, diferencaDias;
	float t;
	IniciarModuloEmprestimo(moduloE);
	
	do{
		MSG_SUBMENU(3);
		printf("\nDIGITE UMA OPCAO: ");
		fflush(stdin);
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:
				
				LerEmprestimo(&emprestimo);
				strcpy(livro.ISBN, emprestimo.ISBN);
				indiceL = PesquisarLivro(*moduloL, livro);
				strcpy(usuario.CPF, emprestimo.CPF);
				indiceU = PesquisarUsuario(*moduloU, usuario);
				t = moduloL->vetor[indiceL].livorsexistentes * 0,9;
				
				if(indiceL != -1 && indiceU != -1){
					if(moduloL->vetor[indiceL].livrosemprestados <= t ){
						if(moduloU->vetor[indiceU].tipo != 1){
							if(moduloU->vetor[indiceU].qtdeLivros <= 3){
								if(moduloU->vetor[indiceU].multa == 0){
									InserirEmprestimo(moduloE, emprestimo);
									moduloL->vetor[indiceL].livrosemprestados ++;
									moduloU->vetor[indiceU].qtdeLivros ++;
									emprestimo.entrega = CalcularDataEntrega(emprestimo.emprestimo);
									printf("\n DATA DE DEVOLUCAO: %d / %d / %d ", emprestimo.entrega.dia, emprestimo.entrega.mes, emprestimo.entrega.ano);	
								}
								else{
									printf("\nREALIZE O PAGAMENTO DAS MULTAS PENDENTES PARA REALIZAR O EMPRESTIMO! ");
								}
							
							}
							else{
							printf("\nUSUARIO JA ADQUIRIU A QUATIDADE MAXIMA DE LIVROS! ");
							}		
						}
						else{
							
							if(moduloU->vetor[indiceL].qtdeLivros <=5){
								if(moduloU->vetor[indiceU].multa == 0){
									InserirEmprestimo(moduloE, emprestimo);
									moduloU->vetor[indiceU].qtdeLivros ++;
									moduloL->vetor[indiceL].livrosemprestados ++;
									emprestimo.entrega = CalcularDataEntrega(emprestimo.emprestimo);
									printf("\nDATA DE DEVOLUCAO: %d / %d / %d", emprestimo.entrega.dia, emprestimo.entrega.mes, emprestimo.entrega.ano);
								}
								else{
									printf("\nREALIZE O PAGAMENTO DAS MULTAS PENDENTES PARA REALIZAR O EMPRESTIMO! ");
								}	
							}
							else{
								printf("\n USUARIO JA ADQUIRIU A QUANTIDADE MAXIMA DE LIVROS! ");
							}
						}
					}
					else{
						printf("\nQUANTIDADE DE LIVROS NO ACERVO INSUFICIENTES! ");
					}		
				}	
				else{
					printf("\nLIVRO OU USUARIO NAO ENCONTRADOS ");
				}	
				system("PAUSE");
				break;
			case 2:
				printf("\nDIGITE O ISBN PARA PESQUISAR: ");
				fflush(stdin);
				fgets(emprestimo.ISBN, 13, stdin);
				printf("\nDIGITE O CPF PARA PESQUISAR: ");
				fflush(stdin);
				fgets(emprestimo.CPF, 14, stdin);
				printf("\nINFORME O ANO DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.ano);
				printf("\nINFORME O MES DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.mes);
				printf("\nINFORME O DIA DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.dia);
				indiceE = PesquisarEmprestimo(*moduloE, emprestimo);
				
				if(indiceE != -1){
					
					ImprimirEmprestimo(moduloE->vetor[indiceE]);
				}
				else{
					printf("\nEMPRESTIMO NAO ENCONTRADO");
				}
				system("PAUSE");
				break;
			case 3:
				
				printf("\nDIGITE O ISBN PARA PESQUISAR: ");
				fflush(stdin);
				fgets(emprestimo.ISBN, 13, stdin);
				printf("\nDIGITE O CPF PARA PESQUISAR");
				fflush(stdin);
				fgets(emprestimo.CPF, 14, stdin);
				printf("\nINFORME O ANO DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.ano);
				printf("\nINFORME O MES DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.mes);
				printf("\nINFORME O DIA DA REALIZACAO DO EMPRESTIMO: ");
				indiceE = PesquisarEmprestimo(*moduloE, emprestimo);
				
				if(indiceE != -1){
					
					AlterarEmprestimo(moduloE, emprestimo);
				}
				else{
					printf("\nEMPRESTIMO NAO ENCONTRADO");
				}
				system("PAUSE");
				break;
			case 4:
				printf("\nDIGITE O ISBN PARA PESQUISAR: ");
				fflush(stdin);
				fgets(emprestimo.ISBN, 13, stdin);
				printf("\nDIGITE O CPF PARA PESQUISAR");
				fflush(stdin);
				fgets(emprestimo.CPF, 14, stdin);
				printf("\nINFORME O ANO DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.ano);
				printf("\nINFORME O MES DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.mes);
				printf("\nINFORME O DIA DA REALIZACAO DO EMPRESTIMO: ");
				indiceE = PesquisarEmprestimo(*moduloE, emprestimo);
				
				if(indiceE != -1){
					ExcluirEmprestimo(moduloE, emprestimo);
				}
				else{
					printf("\nEMPRESTIMO NAO ENCONTRADO");
				}
				system("PAUSE");
				break;
			case 5:
				printf("\nDIGITE O ISBN PARA VERIFICAR O EMPRESTIMO: ");
				fflush(stdin);
				fgets(emprestimo.ISBN, 13, stdin);
				printf("\nDIGITE O CPF PARA VERIFICAR O EMPRESTIMO: ");
				fflush(stdin);
				fgets(emprestimo.CPF, 14, stdin);
				printf("\nINFORME O DIA DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.dia);
				printf("\nINFORME O MES DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.mes);
				printf("\nINFORME O ANO DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.ano);
				indiceE = PesquisarEmprestimo(*moduloE, emprestimo);
				if(indiceE != -1){
					printf("\nINFORME O DIA DE DEVOLUCAO DO EMPRESTIMO: ");
					fflush(stdin);
					scanf("%d", &emprestimo.devolucao.dia);
					printf("\nINFORME O MES DE DEVOLUCAO DO EMPRESTIMO: ");
					fflush(stdin);
					scanf("%d", &emprestimo.devolucao.mes);
					printf("\nINFORME O ANO DE DEVOLUCAO DO EMPRESTIMO: ");
					fflush(stdin);
					scanf("%d", &emprestimo.devolucao.ano);
					
					strcpy(livro.ISBN, emprestimo.ISBN);
					strcpy(usuario.CPF, emprestimo.CPF);
					DarBaixaEmprestimo(moduloE, emprestimo, moduloL, livro, moduloU, usuario);
				}
				else{
					printf("\nEMPRESTIMO NAO ENCONTRADO");
				}
				system("PAUSE");
				break;
			case 6:
				printf("\nDIGITE O ISBN PARA PESQUISAR: ");
				fflush(stdin);
				fgets(emprestimo.ISBN, 13, stdin);
				printf("\nDIGITE O CPF PARA PESQUISAR: ");
				fflush(stdin);
				fgets(emprestimo.CPF, 14, stdin);
				printf("\nINFORME O DIA DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.dia);
				printf("\nINFORME O MES DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.mes);
				printf("\nINFORME O ANO DA REALIZACAO DO EMPRESTIMO: ");
				fflush(stdin);
				scanf("%d", &emprestimo.emprestimo.ano);
				indiceE = PesquisarEmprestimo(*moduloE, emprestimo);
				
				if(indiceE != -1){
					strcpy(usuario.CPF, emprestimo.CPF);
					strcpy(livro.ISBN, emprestimo.ISBN);
					EfetuarPagamento(moduloE, emprestimo, moduloL, livro, moduloU, usuario);
				}
				else{
					printf("\nUSUARIO OU EMPRESTIMO NAO ENCONTRADOS! ");
				}
				system("PAUSE");
				break;		
			case 7:
				ImprimirTodosEmprestimos(*moduloE);
				system("PAUSE");
				break;	
			case 8:
				printf("\nSAINDO DO MODULO! ");
				system("PAUSE");
				break;	
			default:
				printf("\nDIGITE UMA OPCAO VALIDA!: ");
				system("PAUSE");
										
		}
	}while(opcao != 8);
	
}

int main(){
	
	TUsuario usuario;
	TLivro livro;
	TEmprestimo emprestimo;
	
	TModuloUsuario moduloUsuario;
	TModuloLivro moduloLivro;
	TModuloEmprestimo moduloEmprestimo;
	int opcao = 0;
	
	do{
		system("cls");
		MSG_MENU();
		printf("\n\nDIGITE UMA OPCAO: ");
		fflush(stdin);
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:
				//CHAMADA PARA O SUBMENU DO LIVRO
				SubMenuLivro(&moduloLivro, livro);
				break;
			case 2:
				//CHAMADA PARA O SUBMENU DO USUARIO	
				SubMenuUsuario(&moduloUsuario, usuario);
				break;
			case 3:
				//CHAMADA PARA O SUBMENU DO EMPRESTIMO;
				SubMenuEmprestimo(&moduloEmprestimo, emprestimo, &moduloUsuario, usuario, &moduloLivro, livro);
				break;
			case 4:
				//CHAMADA PARA SAIR DO PROGRAMA
				printf(">>>>>>>> SAINDO DO PROGRAMA <<<<<<<<");
				system("PAUSE");
				break;
			default:
				printf("DIGITE UMA OPCAO VALIDA!");
				system("PAUSE");	
			
		}
	}while(opcao != 4);
	
	return 0;
}



