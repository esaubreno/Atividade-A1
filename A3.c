#include <stdio.h>
#include <stdlib.h>

int size = 10;

struct Cliente {
	char nome[30];
	int ano;
	int montante;
	int set;
};

struct Database {
	struct Cliente *row;
};

void Database_init(struct Database *db)
{
	int i;
	for(i = 0; i < size; i++){
		struct Cliente clt = {.set = 0};
		db->row[i] = clt;
	}
}

void Sort_montante(struct Database *db)
{
	int i, j;
	for(i = 0; i < size; i++) {
		for(j = i + 1; j < size; ++j) {
			if(db->row[i].set == 0) continue;
			if(db->row[j].set == 0) continue;
			if(db->row[i].montante > db->row[j].montante) {
				struct Cliente a = db->row[i];
				db->row[i] = db->row[j];
				db->row[j] = a;
			}
		}
	}
}

// Incluir novo Cliente e Sort
void Set_new(struct Database *db)
{
	int i;
	for(i = 0; i < size; i++) {
		if(db->row[i].set == 0) {
			db->row[i].set = 1;

			printf("Nome: ");
			scanf("%s", db->row[i].nome);

			printf("\nAno: ");
			scanf("%d", &db->row[i].ano);

			printf("\nMontante(int): ");
			scanf("%d", &db->row[i].montante);

			printf("\n");
			break;
		}
	}
	Sort_montante(db);
}

// Remover cliente
void Delete_clt(struct Database *db)
{
	int index;
	printf("Deletar cliente no index: ");
	scanf("%d", &index);
	
	struct Cliente clt = {.set = 0};
	db->row[index] = clt;
	Sort_montante(db);

	printf("\nCliente Deletado\n");
}

// Zerar montante
void Zerar(struct Database *db)
{
	for(int i = 0; i < size; i++) {
		if(db->row[i].set != 0) {
			db->row[i].montante = 0;
		}
	}
}

// Listar Cliente (por melhor comprador)
void List(struct Database *db)
{
	for(int i = 0; i < size; i++){
	if(db->row[i].set != 0){

	printf("Nome: %s\n", db->row[i].nome);
	printf("Ano: %d\n", db->row[i].ano);
	printf("Montante: %d\n", db->row[i].montante);
	printf("\n");

	}}
}

// Exebir um cliente especifico
void Clt_get(struct Database *db)
{
	int index;
	printf("Exibir cliente no index: ");
	scanf("%d", &index);

	if(db->row[index].set) {
	printf("Nome: %s\n", db->row[index].nome);
	printf("Ano: %d\n", db->row[index].ano);
	printf("Montante: %d\n", db->row[index].montante);
	printf("\n");
	} else printf("Cliente não encontrado\n");

}

// Expandir Database
void Expand(struct Database *db)
{
	db->row = realloc(db->row, size+10 * sizeof(struct Cliente));
	size += 10;
	printf("Database expandida\n");
}

int main(int argc, char *argv[])
{
	struct Database *db = malloc(sizeof(struct Database));
	if(!db) printf("Erro de memoria");

	db->row = malloc(10 * sizeof(struct Database));
	if(!db->row) printf("Erro de memoria");
	Database_init(db);

	while(1) {
	int option;

	printf( "1: Adicionar novo cliente\n"
		"2: Deletar um cliente\n"
		"3: Listar os clientes por montante\n"
		"4: Listar um cliente especifico\n"
		"5: Zerar montante\n"
		"6: Expandir database\n"
		"7: Sair\n\n"
	);
	scanf("%d", &option);

	switch(option) {
	case 1:
		Set_new(db);
		break;
	case 2:
		Delete_clt(db);
		break;
	case 3:
		List(db);
		break;
	case 4:
		Clt_get(db);
		break;
	case 5:
		Zerar(db);
		break;
	case 6:
		Expand(db);
		break;
	case 7:
		return 0;

	}}
	
	return 0;
}
