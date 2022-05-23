#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void menu();
void cadastro();
void cadastrados();
void alterar();

char nome[30][50], cpf[30][14], email[30][50], telefone[30][20];
int cat, c=0, f=0, d=0;
char op;

int main (){
	system("color F0");
	menu();
}

void menu(){ // MENU 
	setlocale(LC_ALL, "Portuguese");
	Sleep(200);
	printf ("\n**MENU**\n(1)Cadastro\n(2)Cadastrados\n(3)Alterar um cadastro\n(4)Finalizar programa\nSelecione a categoria: ");
	scanf("%d", &cat);
	system("cls");
	switch (cat){
		case 1:
			cadastro();
			break;
		case 2:
			cadastrados();
			break;
		case 3:
			alterar();
			break;
		case 4:
			printf("Saindo.");
			system("exit");
			break;
		default:
			system("cls");
			printf("Opção inválida!\n");
			system("pause");
			menu();
			break;
	}
}

void cadastro(){
	
	printf("\nInforme o nome da pessoa: ");
	scanf("%s", nome[c]);
	printf("Informe o CPF da pessoa: ");
	scanf("%s", cpf[c]);
	printf("Informe o e-mail da pessoa: ");
	scanf("%s", email[c]);
	printf("Informe o telefone da pessoa: ");
	scanf("%s", telefone[c]);
	printf("Gravar os dados:\nNome: %s | CPF: %s | E-mail: %s | Telefone: %s\nSim ou não? ", nome[f], cpf[f], email[f], telefone[f]);
	scanf("%s", &op);
	if((op != 's') && (op != 'S')){
		menu();
	}
	else{
		c++;
		f=c;
		menu();
	}
}	

void cadastrados(){
	f=0;
	while(f<c){
		printf("\nNome: %s CPF: %s E-mail: %s e Telefone: %s\n", nome[f], cpf[f], email[f], telefone[f]);
		f++;
	}
	
	menu();
}
void alterar(){
	if(f==0){
		printf("Não existem cadastros.\n");
		menu();
	}
	f=0;
	while(f<c){
		printf("Cadastro %d\nNome: %s CPF: %s E-mail: %s e Telefone: %s\n",f , nome[f], cpf[f], email[f], telefone[f]);
		f++;
	}
	printf("\nQual cadastro deseja alterar? ");
	scanf("%d", &d);
	
	printf("\nInforme o nome da pessoa: ");
	scanf("%s", nome[d]);
	printf("Informe o CPF da pessoa: ");
	scanf("%s", cpf[d]);
	printf("Informe o e-mail da pessoa: ");
	scanf("%s", email[d]);
	printf("Informe o telefone da pessoa: ");
	scanf("%s", telefone[d]);
	menu();
}
