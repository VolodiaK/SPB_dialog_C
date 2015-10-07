#include <stdio.h>
#include <stdlib.h>

struct number {
	char country[4];
	unsigned int num;
};

struct elem {
	char name[50];
	char street[30];
	char city[30];
	struct number num;
};

void addElem() {
	struct elem newE;
	FILE *data = fopen("data", "ab");
	printf("Enter data about a new item\n");
	printf("Name: ");
	scanf("%s", newE.name);
	printf("\nStreet: ");
	scanf("%s", newE.street);
	printf("\nCity: ");
	scanf("%s", newE.city);
	printf("\nNumber: ");
	char temp[15];
	scanf("%s", temp);
	for (int i = 0; i < 4; i++) {
		newE.num.country[i] = temp[i];
	}
	temp[4] = '\0';
	char temp1[11];
	for (int i = 4; i < 15; i++) {
		temp1[i-4] = temp[i];
	}
	newE.num.num = atoi(temp1);
	fwrite(&newE, sizeof(struct elem), 1, data);
	fclose(data);
}

void showData() {
	struct elem buf;
	FILE *data = fopen("data", "rb");
	fread(&buf, sizeof(struct elem), 1, data);
	do {
		printf("%s %s %s +%s-%d \n", buf.name, buf.city, buf.street, buf.num.country, buf.num.num);
		fread(&buf, sizeof(struct elem), 1, data);
	} while (!feof(data));
	fclose(data);
}

int main(void) {
	for (int i = 0; i < 1; i++) {
		addElem();
	}
	showData();
	return 0;
}
