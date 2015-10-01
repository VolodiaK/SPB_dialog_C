#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>


struct elem
{
	char name[50];
	char street[30];
	char city[30];
	char number[15];
};

void addElem()
{
	elem newE;
	FILE *data = fopen("data", "ab");
	printf("Enter data about a new item\n");
	printf("Name: ");
	gets(newE.name);
	//scanf("%s", newE.name);
	printf("\nStreet: ");
	gets(newE.street);
	//scanf("%s", newE.street);
	printf("\nCity: ");
	gets(newE.city);
	//scanf("%s", newE.city);
	printf("\nNumber: ");
	gets(newE.number);
	fwrite(&newE, sizeof(struct elem), 1, data);
	fclose(data);

}

void showData()
{
	elem buf;
	FILE *data = fopen("data", "rb");
	fread(&buf, sizeof(struct elem), 1, data);
	do
	{
		printf("%s %s %s +%s \n", buf.name, buf.city, buf.street, buf.number);
		fread(&buf, sizeof(struct elem), 1, data);
	} while (!feof(data));
	fclose(data);
}

int main(void)
{
	for (int i = 0; i < 2; i++)
		addElem();
	showData();
	_getch();
	return 0;
}