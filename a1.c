#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 10
#define MAX_SIZE 100

struct Car {
	char marca[MAX_SIZE];
	char modelo[MAX_SIZE];
	char ano[MAX_SIZE];
	char placa[MAX_SIZE];
	int set;
} arr_car[MAX_ROW];

void Database_init()
{
	int i;
	for(i = 0; i < MAX_ROW; i++) {
		struct Car c = {.set = 0};
		arr_car[i] = c;
	}
}

void Sort_array()
{
	int i, j;
	for(i = 0; i < MAX_ROW; i++) {
		for(j = i + 1; j < MAX_ROW; ++j) {
			if(arr_car[i].set == 0) continue;
			if(arr_car[j].set == 0) continue;
			if(atoi(arr_car[i].ano) > atoi(arr_car[j].ano)) {
				struct Car a = arr_car[i];
				arr_car[i] = arr_car[j];
				arr_car[j] = a;
			}
		}
	}
}

void Sort_modelo()
{
	int i, j;
	for(i = 0; i < MAX_ROW; i++) {
		for(j = i + 1; j < MAX_ROW; ++j) {
			if(arr_car[i].set == 0) continue;
			if(arr_car[j].set == 0) continue;
			if(arr_car[i].modelo[0] > arr_car[j].modelo[0]) { 
				struct Car a = arr_car[i];
				arr_car[i] = arr_car[j];
				arr_car[j] = a;
			}
		}
	}
}

void Set_car()
{
	int i;
	for(i = 0; i < MAX_ROW; i++) {
		if(arr_car[i].set == 0) {

		arr_car[i].set = 1;

		printf("Marca: ");
		fgets(arr_car[i].marca, MAX_SIZE, stdin);

		printf("Modelo :");
		fgets(arr_car[i].modelo, MAX_SIZE, stdin);

		printf("Ano: ");
		fgets(arr_car[i].ano, MAX_SIZE, stdin);

		printf("Placa: ");
		fgets(arr_car[i].placa, MAX_SIZE, stdin);

		break;
		}
	}
	Sort_array();
}

void print_car(struct Car arr)
{
	printf("\n//////////////////////////////////////////////\n");
	printf("Marca: %s\n", arr.marca);
	printf("Modelo: %s\n", arr.modelo);
	printf("Ano: %s\n", arr.ano);
	printf("Placa: %s\n", arr.placa);
}

void list_all()
{
	int i;
	for(i = 0; i < MAX_ROW; i++) {
		if(arr_car[i].set == 1) print_car(arr_car[i]);
	}
}

void list_ano()
{
	int i;
	char ano[MAX_SIZE];
	printf("Digite o ano: ");
	fgets(ano, MAX_SIZE, stdin);
	for(i = 0; i < MAX_ROW; i++) {
		if(arr_car[i].set == 1 && atoi(arr_car[i].ano) >= atoi(ano)) {
			print_car(arr_car[i]);
		}
	}
}

void list_modelo()
{
	Sort_modelo();
	int i;
	for(i = 0; i < MAX_ROW; i++) {
		if(arr_car[i].set == 1) print_car(arr_car[i]);
	}
	Sort_array();
}

int main(int argc, char *argv[])
{
	while(1) {

	printf( "\n//////////////////////////////////////////////\n"
		"Digite:\n"
		"'1', Para adicionar um novo veiculo\n"
		"'2', Para listar todos os veiculos\n"
		"'3', Para listar apartir de determinado ano\n"
		"'4', Para listar filtrando-se pelo modelo\n"
		"'5', Para sair do programa\n\n");

	char i[MAX_SIZE];
	fgets(i, MAX_SIZE, stdin);
	printf( "\n//////////////////////////////////////////////\n");
	if(i[0] == '1') Set_car();
	else if(i[0] == '2') list_all();
	else if(i[0] == '3') list_ano();
	else if(i[0] == '4') list_modelo();
	else if(i[0] == '5') exit(0);
	else printf("Comando Errado Tente Novamente\n");
	}
	
	return 0;
}
